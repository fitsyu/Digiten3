#include "signalreceiver.h"
#include "ui_signalreceiver.h"

SignalReceiver::SignalReceiver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignalReceiver)
{
    ui->setupUi(this);
}

SignalReceiver::~SignalReceiver()
{
    delete ui;
}
