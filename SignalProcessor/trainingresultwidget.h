#ifndef TRAININGRESULTWIDGET_H
#define TRAININGRESULTWIDGET_H

#include <QTime>
#include <QWidget>
#include <GRT/GRT.h>

#include <QThread>
class AlgorithmTester: public QThread
{
    Q_OBJECT
public:
    GRT::TimeSeriesClassificationData trainingdata;
    GRT::TimeSeriesClassificationData testdata;
    GRT::Classifier* classifier;
    void run();

signals:
    void new_progress(int);
    void training_started();
    void training_failed();
    void testing_started();
    void prediction_fails_on_sample(int);
    void testing_finished(int accuracy, int time_taken);
};

namespace Ui {
class TrainingResultWidget;
}

class TrainingResultWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TrainingResultWidget(QWidget *parent = 0);
    ~TrainingResultWidget();

    void setDatasetFile(QString filename);

private slots:
    void selectAllToggle();
    void do_test_algorithms();
    void use_this_algorithm();

    void increase_progress_bar_value();
signals:
    void progress_increased();

private:
    Ui::TrainingResultWidget *ui;
//    QTime testing_time;

    GRT::AdaBoost* _ab;
    GRT::ANBC* _anbc;
    GRT::BAG*  _bag;
    GRT::DecisionTree* _dt;
    GRT::DTW* _dtw;
    GRT::FiniteStateMachine* _fsm;
    GRT::GMM* _gmm;
    GRT::HMM* _hmmc;
    GRT::HMM* _hmmd;
    GRT::KNN* _knn;
    GRT::MinDist* _md;
    GRT::RandomForests* _rf;
    GRT::Softmax* _sm;
    GRT::SVM* _svm;

    GRT::Classifier* classifier;
    void setClassifierType(QString algorithm);

//    AlgorithmTester* tester;
};


#endif // TRAININGRESULTWIDGET_H
