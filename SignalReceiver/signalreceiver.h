#ifndef SIGNALRECEIVER_H
#define SIGNALRECEIVER_H

#include <QWidget>

namespace Ui {
class SignalReceiver;
}

class SignalReceiver : public QWidget
{
    Q_OBJECT

public:
    explicit SignalReceiver(QWidget *parent = 0);
    ~SignalReceiver();

private:
    Ui::SignalReceiver *ui;
};

#endif // SIGNALRECEIVER_H
