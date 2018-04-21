#include "trainingresultwidget.h"
#include "ui_trainingresultwidget.h"
#include <QDebug>
#include "centering.h"

TrainingResultWidget::TrainingResultWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TrainingResultWidget)
{
    ui->setupUi(this);
    move ( center_point(this) );

    connect (ui->btSelectAll, SIGNAL(clicked()),
             this, SLOT(selectAllToggle()));
    connect (ui->btStartTesting, SIGNAL(clicked()),
             this, SLOT(do_test_algorithms()));

//    connect(ui->uDTW, SIGNAL(clicked()), this, SLOT(use_this_algorithm()));
//    connect(ui->uHMMC, SIGNAL(clicked()), this, SLOT(use_this_algorithm()));
    foreach (QPushButton* btUse, ui->frame->findChildren<QPushButton*>()){
        connect(btUse, SIGNAL(clicked()), this, SLOT(use_this_algorithm()));
    }


    connect (this, SIGNAL(progress_increased()),
             this, SLOT(increase_progress_bar_value()));



    // algorithms initialization
//    _ab     = new GRT::AdaBoost;
//    _ab->setWeakClassifier( *(new GRT::DecisionStump) );

    _anbc   = new GRT::ANBC;
//    _bag    =  GRT::Classifier::createInstanceFromString("BAG");


//    _dt    = new GRT::DecisionTree;
//    _dt->setDecisionTreeNode( *(new GRT::DecisionTreeClusterNode) );
//    _dt->setNumSplittingSteps( 1000 );
//    _dt->setMaxDepth( 10 );
//    _dt->setMinNumSamplesPerNode( 10 );


    _dtw    = new GRT::DTW;
    _fsm    = new GRT::FiniteStateMachine;
    _gmm    = new GRT::GMM;
    _hmmc   = new GRT::HMM(GRT::HMM_CONTINUOUS);
    _hmmd   = new GRT::HMM(GRT::HMM_DISCRETE);
    _knn    = new GRT::KNN;
    _md     = new GRT::MinDist;
    _rf     = new GRT::RandomForests;
    _sm     = new GRT::Softmax;
    _svm    = new GRT::SVM;

    qDebug() << "algorithms constructed";

//    tester = new AlgorithmTester;
//    connect (tester, SIGNAL(new_progress(int)),
//             this, SLOT(increase_progress_bar_value()));
}

TrainingResultWidget::~TrainingResultWidget()
{
    delete ui;
//    delete _ab;
    delete _anbc;
//    delete _bag;
//    delete _dt;
    delete _dtw;
    delete _fsm;
    delete _gmm;
    delete _hmmc;
    delete _hmmd;
    delete _knn;
    delete _md;
    delete _rf;
    delete _sm;
    delete _svm;

//    delete tester;
    qDebug() << "destroyed";
}

void TrainingResultWidget::setDatasetFile(QString filename)
{
    ui->lbTestFileName->setText(ui->lbTestFileName->text()+filename);
}

void TrainingResultWidget::selectAllToggle()
{
    if (ui->btSelectAll->isChecked()){
        foreach(QCheckBox* cb, ui->frame->findChildren<QCheckBox*>()){
            if(cb->isEnabled()) cb->setChecked(true);
        }
        ui->btSelectAll->setText("All selected");
    } else {
        foreach(QCheckBox* cb, ui->frame->findChildren<QCheckBox*>()){
            cb->setChecked(false);
        }
        ui->btSelectAll->setText("Select all");
    }
}

void TrainingResultWidget::do_test_algorithms()
{
    // 1. load the dataset from previous recording activity
    foreach(QCheckBox* cb, ui->frame->findChildren<QCheckBox*>()){
        if (cb->isChecked()){
            // test this algorithm by:
            // 2. choose algorithm
            QString algorithm = cb->objectName().mid(2); // cb....


            setClassifierType(algorithm);
//            classifier = GRT::Classifier::createInstanceFromString("dtw");
//            classifier = AdaBoost;
//            ui->lbTestFileName->setText(QString::fromStdString(classifier->getClassifierType()));
//            qDebug() << QString::fromStdString(classifier->getClassifierType());
//            return;

//            GRT::BAG bag;
//            bag.addClassifierToEnsemble( GRT::ANBC() );
//            bag.addClassifierToEnsemble( GRT::MinDist(3));
//            classifier = &bag;

//            GRT::DecisionTree dt;
//            dt.setDecisionTreeNode( GRT::DecisionTreeClusterNode() );
//            dt.setNumSplittingSteps( 1000 );
//            dt.setMaxDepth( 10 );
//            dt.setMinNumSamplesPerNode( 10 );
//            classifier = &dt;

            GRT::TimeSeriesClassificationData dataset;
//            qDebug() << ui->lbTestFileName->text().mid(11); //.toStdString();
            string dataset_file = ui->lbTestFileName->text().mid(11).toStdString();
            dataset.load(dataset_file);
//            dataset.load("DTW/YetAnotherTrainingData.grt");

            GRT::TimeSeriesClassificationData test_dataset;
//            test_dataset = dataset.partition(80);
//            test_dataset.load("DTW/YetAnotherTrainingData.grt");
            test_dataset.load(dataset_file);


            // let use thread from here on
//            tester->trainingdata = dataset;
//            tester->testdata = test_dataset;
//            tester->classifier = this->classifier;
//            tester->start();

//            dtw.enableNullRejection(true);
//            dtw.enableTrimTrainingData()
            QProgressBar* pb = ui->frame->findChild<QProgressBar*>("pb"+algorithm);

            pb->setMaximum(0);

            qDebug() << "testing..." << QString::fromStdString(classifier->getClassType());

            if (!classifier->train(dataset) ){
                qDebug() << ("failed to train dataset");
                pb->setStyleSheet("background: red");
                pb->setMaximum(100);
                continue;
            };

            pb->setMaximum(test_dataset.getNumSamples());
            pb->setValue(0);
            double accuracy = 0;
            // 3. reset timer
            QTime testing_time;
            testing_time.start();
            for(GRT::UINT i=0; i<test_dataset.getNumSamples(); i++){
                //Get the i'th test sample - this is a timeseries
                GRT::UINT classLabel = test_dataset[i].getClassLabel();
                GRT::MatrixDouble timeseries = test_dataset[i].getData();

                //Perform a prediction using the classifier
//                if( !dtw.predict( timeseries ) ){
                if (!classifier->predict(timeseries)) {
                    qDebug() << "Failed to perform prediction for test sampel: " << i <<"\n";
                    pb->setStyleSheet("background: red");
                    continue;
                }

                //Get the predicted class label
//                GRT::UINT predictedClassLabel = dtw.getPredictedClassLabel();
                GRT::UINT predictedClassLabel = classifier->getPredictedClassLabel();
//                double maximumLikelihood = dtw.getMaximumLikelihood();


                //Update the accuracy
                if( classLabel == predictedClassLabel ) accuracy++;

//                 cout << "TestSample: " << i <<  "\tClassLabel: " << classLabel << "\tPredictedClassLabel: " << predictedClassLabel << "\tMaximumLikelihood: " << maximumLikelihood << endl;
                 // 3. update its progressbar

//                emit progress_increased(); // sama aja
                pb->setValue(i+1);
                QCoreApplication::flush();
                QCoreApplication::processEvents();
            }



            // 4. set accuracy value
            QLabel* acc = ui->frame->findChild<QLabel*>("acc"+algorithm);
            acc->setText(QString::number(accuracy/double(test_dataset.getNumSamples())*100.0)+"%");
            // 5. set time ellapsed value
            QLabel* t = ui->frame->findChild<QLabel*>("t"+algorithm);
            t->setText(QString::number(testing_time.elapsed())+"ms");
        }
    }
}

void TrainingResultWidget::use_this_algorithm()
{
    setClassifierType(sender()->objectName().mid(1));
    classifier->save(
                "Records/"+
                classifier->getClassifierType()
                +"-model.grt"
                );
}

void TrainingResultWidget::increase_progress_bar_value()
{
    ui->pbDTW->setValue(ui->pbDTW->value()+1);
}

void TrainingResultWidget::setClassifierType(QString algorithm)
{
    if (algorithm ==  "AdaBoost") classifier = _ab;
    if (algorithm ==  "ANBC") classifier = _anbc;
    if (algorithm ==  "BAG") classifier = _bag;
    if (algorithm ==  "DT") classifier = _dt;
    if (algorithm ==  "DTW") classifier = _dtw;
    if (algorithm ==  "FSM") classifier = _fsm;
    if (algorithm ==  "GMM") classifier = _gmm;
    if (algorithm ==  "HMMC") classifier = _hmmc;
    if (algorithm ==  "HMMD") classifier = _hmmd;
    if (algorithm ==  "KNN") classifier = _knn;
    if (algorithm ==  "MD") classifier = _md;
    if (algorithm ==  "RF") classifier = _rf;
    if (algorithm ==  "SM") classifier = _sm;
    if (algorithm ==  "SVM") classifier = _svm;

    qDebug() << "classifier set" << algorithm;
}


void AlgorithmTester::run()
{
    qDebug() << "testing..." << QString::fromStdString(classifier->getClassType());
    emit training_started();
    if (!classifier->train(trainingdata) ){
//        qDebug() << ("failed to train dataset");
        emit training_failed();
        return;
    };

//    pb->setMaximum(test_dataset.getNumSamples());
//    pb->setValue(0);
    emit testing_started();
    double accuracy = 0;
    // 3. reset timer
    QTime testing_time;
    testing_time.start();
    for(GRT::UINT i=0; i<testdata.getNumSamples(); i++){
        //Get the i'th test sample - this is a timeseries
        GRT::UINT classLabel = testdata[i].getClassLabel();
        GRT::MatrixDouble timeseries = testdata[i].getData();

        if (!classifier->predict(timeseries)) {
//            qDebug() << "Failed to perform prediction for test sampel: " << i <<"\n";
//            pb->setStyleSheet("background: red");
            emit prediction_fails_on_sample(i);
            continue;
        }

        //Get the predicted class label
//                GRT::UINT predictedClassLabel = dtw.getPredictedClassLabel();
        GRT::UINT predictedClassLabel = classifier->getPredictedClassLabel();
//                double maximumLikelihood = dtw.getMaximumLikelihood();

        //Update the accuracy
        if( classLabel == predictedClassLabel ) accuracy++;
        emit new_progress(i+1);
    }

    emit testing_finished(accuracy, testing_time.elapsed());
}
