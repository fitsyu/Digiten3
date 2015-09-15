#include "instructor.h"
#include <QDebug>


Instructor::Instructor(QWidget *parent) :
    QWidget(parent)
{
    setWindowOpacity(0.7);

    // put this widget automatically in center of caller
    setWindowFlags(Qt::SplashScreen);

    label = new QLabel(this);

    label->setText("THE Great Instructor");
    label->setAlignment(Qt::AlignHCenter);
    label->setWordWrap(true);
    label->setAutoFillBackground(true);
    label->setStyleSheet("color: white; font: bold 25px");

    label->setFixedWidth(400);
    label->setFixedHeight(60);

    int WI = 400;
    int HE = 200;
    int X = (WI - label->width()) / 2;
    int Y = (HE - label->height()) / 2;

    label->setGeometry(X, Y, 400, 40);

    timer = new QTimer(this);
    gesture_count = 0;
    gesture_type_count = 0;

    activeGestureIndex = 0;
}

void Instructor::trainUser(const QList<gesture> y_trainings) // YOUR training session
{
    setTrainings(y_trainings);
    callibrate();
    connect(this, SIGNAL(callibrationFinished()),
            this, SLOT(DoNextTraining()));
}

void Instructor::callibrate()
{
    words = "Stay in neutral position for ";
    words_time = 15;

    // counting back
    connect(timer, SIGNAL(timeout()),
            this, SLOT(updateCallibrationProgress()));
    timer->start(1000);

}

void Instructor::updateCallibrationProgress()
{
    label->setText(QString("%0 %1s").arg(words).arg(words_time--));
    show();
    if (words_time < 0) {
        timer->stop();
        hide();
        emit callibrationFinished();
    }
}

void Instructor::DoNextTraining()
{
    if (activeGestureIndex < configuration.gestures.count()){
        activeGesture = &configuration.gestures.at(activeGestureIndex);
        tellToSwing();
    }

    activeGestureIndex++;
}

void Instructor::tellToSwing()
{
    words = activeGesture->command;
    words_time = 0;

    label->setText(words);
    show();

    // fake signal
    //    QTimer::singleShot(5000, this, SLOT(onNewGestureCaptured()));

    // the loading dots . . .
    timer->stop();
    disconnect(timer, SIGNAL(timeout()), this, SLOT(updateCallibrationProgress()));
    connect(timer, SIGNAL(timeout()), this, SLOT(listening()));
    timer->start();
}

void Instructor::listening()
{
    QString dots;
    for(int dot=0; dot<words_time; dot++){
        dots.append(" . ");
    }

    label->setText(QString("%0 \n%1").arg(words).arg(dots));
    words_time++;
    if (words_time > 3){
        words_time = 0;
    }
}

void Instructor::onNewGestureCaptured()
{
    timer->stop();
    gesture_count++;

    float sample_num = activeGesture->samples_required;
    label->setText(QString("Gesture recorded %1/%2 [%3%]")
                     .arg(gesture_count)
                     .arg(sample_num)
                     .arg( round(gesture_count/sample_num*100) )
                     );
    show();

    if (gesture_count < sample_num)
        QTimer::singleShot(1500, this, SLOT(tellToSwing()));
    else
        QTimer::singleShot(1000, this, SLOT(onTrainingCompleted()));

}

void Instructor::onTrainingCompleted()
{
    gesture_type_count++;
    if (gesture_type_count < configuration.gestures.count()){
        gesture_count = 0; // reset
        label->setText("Starting next gesture training..");
        emit nextGestureTrainingStarted();
        show();
        QTimer::singleShot(3000, this, SLOT(DoNextTraining()));
    } else {
        emit trainingCompleted();
        label->setText("Training complete");
        show();
        QTimer::singleShot(3000, this, SLOT(hide()));
    }
}

void Instructor::speak(int gestureCode)
{
    switch (gestureCode){
    case 0:
        label->setText("UNKNOWN");
        break;
    case 1:
        label->setText("SPIN");       // W
        break;
    case 2:
        label->setText("SLICE");      // M
        break;
    default:
        return;
    }

    show();
    QTimer::singleShot(1000, this, SLOT(hide()));
}

void Instructor::setTrainings(const QList<gesture> &value)
{
    configuration.gestures = value;
}

void Instructor::configTraining()
{
    // construct gui with all options
    config_widget = new TrainingConfigWidget;

    config_widget->show();
    connect(config_widget, SIGNAL(configured(TrainingConfiguration)),
            this, SLOT(startTraining(TrainingConfiguration)));
}

void Instructor::startTraining(TrainingConfiguration configuration)
{
    this->configuration = configuration;
    emit trainingPrepared(this->configuration);
    trainUser(this->configuration.gestures);
}
