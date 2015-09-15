#ifndef SIGNALPROCESSOR_H
#define SIGNALPROCESSOR_H

#include <QWidget>

class SignalProcessor : public QWidget
{
    Q_OBJECT

public:
    SignalProcessor(QWidget *parent = 0);
    ~SignalProcessor();
};

#endif // SIGNALPROCESSOR_H
