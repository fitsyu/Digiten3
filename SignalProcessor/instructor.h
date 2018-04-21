#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include "trainingconfiguration.h"
#include "recordingconfigwidget.h"

class Instructor : public QWidget
{
    Q_OBJECT
public:
    Instructor(QWidget *parent=NULL);

    void recordUserMotions(const QList<gesture> y_trainings);

public slots:
    void callibrate();
    void updateCallibrationProgress();
    void DoNextRecording();
    void tellToSwing();
    void listening();
    void onNewGestureCaptured();
    void onRecordingCompleted();
    void speak(int gestureCode);
    void setTrainings(const QList<gesture> &value);
    void configRecording();
    void startRecording(TrainingConfiguration configuration);

signals:
    void recordingPrepared(TrainingConfiguration);
    void callibrationFinished();
    void nextGestureRecordingStarted();
    void recordingCompleted();

private:
    QLabel* label;
    TrainingConfiguration configuration;
    const gesture* activeGesture;
    int activeGestureIndex;

    QTimer* timer;
    unsigned int gesture_count;
    int gesture_type_count;

    QString words;
    int words_time;

    RecordingConfigWidget* config_widget;

};

#endif /*INSTRUCTOR_H*/
