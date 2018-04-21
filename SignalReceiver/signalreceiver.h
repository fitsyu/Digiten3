#ifndef SIGNALRECEIVER_H
#define SIGNALRECEIVER_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QBluetoothServer>
#include <QBluetoothServiceInfo>
#include <QBluetoothSocket>
#include <QBluetoothLocalDevice>

namespace Ui {
class SignalReceiver;
}

static const QString serviceUuid(QStringLiteral("e8e10f95-1a70-4b27-9ccf-02010264e9c7"));

class SignalReceiver : public QWidget
{
    Q_OBJECT

public:
    explicit SignalReceiver(QWidget *parent = 0);
    ~SignalReceiver();

signals:
    void newButtonPress(QByteArray btCode);
    void newAccelerationData(QByteArray xyz);

    // use this signal to start/stop your process
    void connected();
    void disconnected();

private slots:
    void toggleShown();
    void pairingDisplayed(QBluetoothAddress address, QString pin);
    void pairingFinished(QBluetoothAddress address, QBluetoothLocalDevice::Pairing pairing );

    void startServer();
    void clientConnected();
    void clientDisconnected();
    void serverError(QBluetoothServer::Error);
    void RECEIVE();


    void turnOnAccelerometer();
    void turnOffAccelerometer();

    void turnOnMagnetometer();
    void turnOffMagnetometer();

private:
    void setUpUI();

private:
    Ui::SignalReceiver *ui;
    QSystemTrayIcon *TrayIcon;

    QBluetoothServer *server;
    QBluetoothServiceInfo *service;
    QBluetoothSocket *socket;       //server side socket
    QBluetoothLocalDevice *localDevice;
};

#endif // SIGNALRECEIVER_H
