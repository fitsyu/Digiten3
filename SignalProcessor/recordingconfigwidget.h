#ifndef TRAININGCONFIGWIDGET_H
#define TRAININGCONFIGWIDGET_H

#include "trainingconfiguration.h"

#include <QWidget>

namespace Ui {
class TrainingConfigWidget;
}

class RecordingConfigWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RecordingConfigWidget(QWidget *parent = 0);
    ~RecordingConfigWidget();

public slots:
    void addGesture();
    void removeGesture();
    void startRecording();

signals:
    void configured(TrainingConfiguration);

private:
    Ui::TrainingConfigWidget *ui;
};

#endif // TRAININGCONFIGWIDGET_H
