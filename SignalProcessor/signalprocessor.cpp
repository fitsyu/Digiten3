#include "signalprocessor.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>

SignalProcessor::SignalProcessor(QString opmode, QString modelFile, QObject *parent)
    :QObject(parent)
{
    flat = 0;

    sampleCount = 0;
    isInTraining = false;
    trainingStarted = false;
    callibrated = false;

    instructor = new Instructor;

    // from instructor
    connect(instructor, SIGNAL(recordingPrepared(TrainingConfiguration)),
            this, SLOT(configTrainingDataset(TrainingConfiguration)));
    connect(instructor, SIGNAL(callibrationFinished()),
            this, SLOT(setCallibrated()));
    connect(instructor, SIGNAL(nextGestureRecordingStarted()),
            this, SLOT(reconfigTrainingDataset()));
    connect(instructor, SIGNAL(recordingCompleted()),
            this, SLOT(saveSamplesAndTrain()));

    // to instructor
    connect(this, SIGNAL(newGestureCaptured()),
            instructor, SLOT(onNewGestureCaptured()));

    // signal viewer
    signalViewer = new Graph2;
    signalViewer->plot->yAxis->setLabel("Raw Acceleration");
    signalViewer->plot->xAxis->setLabel("Time");
    signalViewer->resize(800, 500);
    signalViewer->show();

    connect( this, SIGNAL(newRawAcceleration(QVector3D)),
                      signalViewer, SLOT(appendSample(QVector3D)));

    if (opmode == "training"){
        qDebug() << "doing training";
        isInTraining = true;
        instructor->configRecording();
    } else if (opmode == "testing"){
        qDebug() << "doing testing" << modelFile;
        isInTraining = false;
        setUpRecognizer(modelFile);
    } else if (opmode == "gaming"){
        qDebug() << "doing gaming" << modelFile;
        isInTraining = false;
        setUpRecognizer(modelFile);

        disconnect( this, SIGNAL(newRawAcceleration(QVector3D)),
                    signalViewer, SLOT(appendSample(QVector3D)));
        signalViewer->close();
    } else {
        qFatal( "invalid mode" );
    }
}

void SignalProcessor::configTrainingDataset(TrainingConfiguration conf)
{
    trainingData.setDatasetName(conf.dataset_name.toStdString());
    trainingData.setInfoText(conf.info_text.toStdString());
    trainingData.setNumDimensions(conf.num_dimensions);

    //    labelledTrainingData.setDatasetName(conf.dataset_name.toStdString());
    //    labelledTrainingData.setInfoText(conf.info_text.toStdString());
    //    labelledTrainingData.setNumDimensions(conf.num_dimensions);

    currentGestureID = conf.gestures.at(0).ID; // non null gesture

    this->conf = conf;
}

void SignalProcessor::trainOrNot()
{
    QMessageBox message;
    message.setText("Do you want to train?");
    message.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    if ( message.exec() == QMessageBox::Yes){
        isInTraining = true;
        instructor->configRecording();
    } else {
        isInTraining = false;


        // if not training
        QString GRT_ModelFileName = QFileDialog::getOpenFileName(
                    0,
                    "Open a GRT Model File", // caption
                    "",                      // dir: is current dir
                    "GRT model (*.grt)"      // filter
                    );

        //        GRT::DTW recognizer;
        ////        if dtw
        //        qDebug() << GRT_ModelFileName.contains("DTW");
        //        QFile file(GRT_ModelFileName);
        //        if (!file.open(QFile::Text | QFile::ReadOnly)) {qDebug() << "can't open the file"; }
        //        while (!file.atEnd()){
        //            QByteArray line = file.readLine();
        //            if (line.contains("info text")){
        //                qDebug() << line;
        //                break;
        //            }
        //        }
        setUpRecognizer(GRT_ModelFileName);

    }
    emit ready(); // we start receive signals from now on not otherwise
}

void SignalProcessor::setUpRecognizer(QString modelFileName)
{
    qDebug() << "setting up recognizer..";
    if (modelFileName.contains("DTW") ){
        recognizer = new GRT::DTW();
        static_cast<GRT::DTW*>(recognizer)->enableNullRejection(true);
        static_cast<GRT::DTW*>(recognizer)->enableTrimTrainingData(true, .1, 90);
    } else {
        recognizer = new GRT::HMM(GRT::HMM_CONTINUOUS);
    }


    if (!recognizer->load(modelFileName.toStdString())){
        qDebug() << "file:" << modelFileName;
        qFatal("cannot initialize recognizer model");

    }

    QSettings settings("fitsyu.com", "Digiten 3");
    upper_limit = settings.value("upper_limit").toReal();
    lower_limit = settings.value("lower_limit").toReal();

    qDebug() << "recognizer set with type: " <<
                QString::fromStdString(recognizer->getClassifierType());
}

/**
 * @brief SignalProcessor::receive
 * @param sample
 * this is overloaded slot of original
 * convert sample to QVector3D
 */
void SignalProcessor::PROCESS(QByteArray sample)
{
    // format x,y,z
    QVector3D v3d;
    QList<QByteArray> extracted = sample.split(',');
    v3d.setX( extracted.at(0).toFloat() );
    v3d.setY( extracted.at(1).toFloat() );
    v3d.setZ( extracted.at(2).toFloat() );

    PROCESS(v3d);
}

void SignalProcessor::PROCESS(QVector3D sample)
{
    // [1] sample count based callibration
//    if (isInTraining){
//        if (sampleCount != 512 ){
//            ++sampleCount;
//            qDebug() << QString("callibrating... please wait! [%1/512]")
//                        .arg( QString::number(sampleCount) );

//            callibrate(sample.z());
//            return;
//        }
//    }

    // [1] time based callibration
    if (isInTraining){
        if(!callibrated) {
            callibrate(sample.z()); // TODO: use all 3 samples
            return;
        }
    }


    // when there is motion we record it
    if ( motion_check(sample.z()) ) {
        GRT::VectorDouble data;
        data.push_back(motionrecords.getSize()+1);
        data.push_back(sample.x());
        data.push_back(sample.y());
        data.push_back(sample.z());
        //        labelledTrainingData.addSample(currentGestureID, data);
        motionrecords.push_back( data );
    }
    // now the motion is stopped
    // we can read what type it is
    else {
        if (motionrecords.getSize() > 0){

            if (firstGestureCaptured){
                if (isInTraining){
                    // record for training
                    emit newGestureCaptured(); // tell the instructor to stop listening
                    trainingData.addSample(currentGestureID, motionrecords );
                }
                else {
                    // read recorded gesture
                    if (!recognizer->predict(motionrecords)){
                        qDebug() << "predicition fails";
                        motionrecords.clear();
                        return;
                    }
                    GRT::UINT detectedGestureID = recognizer->getPredictedClassLabel();
                    // this is it
//                    instructor->speak(  detectedGestureID  );
                    emit gestureDetected( detectedGestureID );
                }
            }
            else {
                firstGestureCaptured = true;
            }

            motionrecords.clear();
        }
    }

    emit newRawAcceleration(sample);

    time++;
}

void SignalProcessor::reconfigTrainingDataset()
{
    static int idx_increaser = 1;
    currentGestureID = conf.gestures.at(idx_increaser).ID;
    idx_increaser++;
}

void SignalProcessor::saveSamplesAndTrain()
{
    isInTraining = false;

    QString fileName;
    fileName = "Records/Motion samples record as of "+
            QDateTime::currentDateTime().toString()+".grt";

    trainingData.saveDatasetToFile( fileName.toStdString() );
    //    labelledTrainingData.saveDatasetToFile( fileName.toStdString()+".L");
    QSettings settings("fitsyu.com", "Digiten 3");
    settings.setValue("upper_limit", upper_limit);
    settings.setValue("lower_limit", lower_limit);

    settings.sync();

    qDebug() << upper_limit << lower_limit;
    qDebug() << settings.value("upper_limit").toReal()
             << settings.value("lower_limit").toReal();

    trw = new TrainingResultWidget;
    trw->setDatasetFile(fileName);
    trw->show();

    disconnect( this, SIGNAL(newRawAcceleration(QVector3D)),
                      signalViewer, SLOT(appendSample(QVector3D)));
//    signalViewer->close();
}

void SignalProcessor::startTrainingGuide()
{
    isInTraining = true;
    instructor->configRecording();
}

bool SignalProcessor::motion_check(double acc)
{

    if ( acc >= lower_limit-1 && acc <= upper_limit+1 )
        /*                       ^                                   ^
                            lower limit                         upper limit
                            both are minimum and maximum value during
                            calibration routine
        */
        ++flat;
    else
        flat=0;

    if ( flat >= 10 ){
        return false; // no motion
    }
    return true;
}

void SignalProcessor::callibrate(qreal val)
{
    upper_limit = qMax(upper_limit, val);
    lower_limit = qMin(lower_limit, val);
}

void SignalProcessor::setCallibrated()
{
    callibrated = true;
}
