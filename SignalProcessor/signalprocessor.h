#ifndef GATE_H
#define GATE_H

#include <QObject>
#include <QVector3D>
#include <QTime>
#include <QTimer>
//#include <GRT/DataStructures/TimeSeriesClassificationData.h>
#include <GRT/GRT.h>
//#include "/usr/local/include/GRT/GRT.h"
#include "instructor.h"
#include "trainingresultwidget.h"

#include "graph2.h"


class SignalProcessor : public QObject
{
    Q_OBJECT
public:
    explicit SignalProcessor(QString opmode, QString modelFile="", QObject *parent = 0);

    void setUpRecognizer(QString modelFileName);

public slots:
    void PROCESS(QByteArray sample);
    void PROCESS(QVector3D sample);
    void saveSamplesAndTrain();

    void startTrainingGuide();

    void setCallibrated();
    void reconfigTrainingDataset();
    void configTrainingDataset(TrainingConfiguration conf);

signals:
    void gestureDetected(int);

    void ready();
    // all
    void newRawAcceleration(QVector3D sample);

    void callibrationStarts();
    void callibrationStops();

    void newGestureCaptured();

private:
    void trainOrNot();


private:
    // movement check
    bool motion_check(double acc);
    int flat;


    bool isTraining;   // this guy tell us wether captured gesture should be saved or not

    // Calibration
    void callibrate(qreal val);
    int sampleCount;
    QTime callibration_duration;
    qreal upper_limit;
    qreal lower_limit;
    bool callibrationStarted;
    bool callibrationFinished;

    GRT::MatrixDouble motionrecords;
    qreal time;

    GRT::ClassificationData labelledTrainingData;
    GRT::TimeSeriesClassificationData trainingData;
    GRT::UINT currentGestureID;
    GRT::Classifier* recognizer;

    Instructor* instructor;
    bool isInTraining, trainingStarted, callibrated;
    TrainingConfiguration conf;


    /*
     * it turns out that it
     * always emit newGestureCaptured();
     * every after callibration.
     * we protect it by this variable
    */
    bool firstGestureCaptured = false;
    /*
     * * once this variable become 1
     * we can emit newGestureCaptured();
     * from then on
     *
     */


    TrainingResultWidget* trw;

    Graph2 *signalViewer;
};

#endif



