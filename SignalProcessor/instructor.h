#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include "trainingconfiguration.h"
#include "trainingconfigwidget.h"

class Instructor : public QWidget
{
    Q_OBJECT
public:
    Instructor(QWidget *parent=NULL);

    void trainUser(const QList<gesture> y_trainings);

public slots:
    void callibrate();
    void updateCallibrationProgress();
    void DoNextTraining();
    void tellToSwing();
    void listening();
    void onNewGestureCaptured();
    void onTrainingCompleted();
    void speak(int gestureCode);
    void setTrainings(const QList<gesture> &value);
    void configTraining();
    void startTraining(TrainingConfiguration configuration);

signals:
    void trainingPrepared(TrainingConfiguration);
    void callibrationFinished();
    void nextGestureTrainingStarted();
    void trainingCompleted();

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

    TrainingConfigWidget* config_widget;

};

#endif /*INSTRUCTOR_H*/
