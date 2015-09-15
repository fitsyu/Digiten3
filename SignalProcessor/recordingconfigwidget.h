#ifndef TRAININGCONFIGWIDGET_H
#define TRAININGCONFIGWIDGET_H

#include "trainingconfiguration.h"

#include <QWidget>

namespace Ui {
class TrainingConfigWidget;
}

class TrainingConfigWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TrainingConfigWidget(QWidget *parent = 0);
    ~TrainingConfigWidget();

public slots:
    void addGesture();
    void removeGesture();
    void startTraining();

signals:
    void configured(TrainingConfiguration);

private:
    Ui::TrainingConfigWidget *ui;
};

#endif // TRAININGCONFIGWIDGET_H
