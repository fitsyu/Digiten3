#include "signalreceiver.h"
#include "ui_signalreceiver.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QBluetoothServer>
#include <QTimer>
//#include "centering.h"

SignalReceiver::SignalReceiver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignalReceiver),
    localDevice(new QBluetoothLocalDevice(this))
{
    setUpUI();
    startServer();

    connect(localDevice, SIGNAL(pairingDisplayPinCode(QBluetoothAddress,QString)),
            this, SLOT(pairingDisplayed(QBluetoothAddress,QString)));
    connect(localDevice, SIGNAL(pairingDisplayConfirmation(QBluetoothAddress,QString)),
            this, SLOT(pairingDisplayed(QBluetoothAddress,QString)));
    connect(localDevice, SIGNAL(pairingFinished(QBluetoothAddress,QBluetoothLocalDevice::Pairing)),
            this, SLOT(pairingFinished(QBluetoothAddress,QBluetoothLocalDevice::Pairing)));

    connect ( ui->btQuit, SIGNAL(clicked()), this, SLOT(close()));

    show();
}

SignalReceiver::~SignalReceiver()
{
    delete ui;
}

void SignalReceiver::toggleShown()
{
    static bool shown = true;
    if ( shown )    hide();
    else            show();

    // toggle
    shown = !shown;
}

void SignalReceiver::pairingDisplayed(QBluetoothAddress address, QString pin)
{
    qDebug() << address.toString() << pin;

    // HACK!
    localDevice->pairingConfirmation(true);
}

void SignalReceiver::pairingFinished(QBluetoothAddress address, QBluetoothLocalDevice::Pairing pairing)
{
    qDebug() << address.toString() << pairing;
}

void SignalReceiver::setUpUI()
{
    ui->setupUi(this);

    setWindowTitle("Signal Receiver");
    setWindowOpacity(.87);
    setWindowFlags( Qt::FramelessWindowHint );

//    move( center_point(this) );

    TrayIcon = new QSystemTrayIcon(this);
    TrayIcon->setIcon(QIcon(":/icon/blankracket.png"));
    connect (TrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
             this, SLOT(toggleShown()));
    TrayIcon->show();
}

void SignalReceiver::startServer()
{
    if ( localDevice->hostMode() == QBluetoothLocalDevice::HostPoweredOff )
        localDevice->powerOn();


    server = new QBluetoothServer(QBluetoothServiceInfo::RfcommProtocol, this);
    server->setSecurityFlags(QBluetooth::NoSecurity);
    connect(server, SIGNAL(newConnection()), this, SLOT(clientConnected()));
    connect(server, SIGNAL(error(QBluetoothServer::Error)),
            this, SLOT(serverError(QBluetoothServer::Error)));


    const QBluetoothUuid uuid(serviceUuid);
    server->listen(uuid, QStringLiteral("Controller Target"));
    ui->message->setText(
                         "Waiting for device bluetooth connection ..\n\n"
                         "( tap CONNECT button on the controller )"
                );

    qDebug() << "server started";
}

void SignalReceiver::clientConnected()
{
    if ( !server->hasPendingConnections() ){
        ui->message->setText("No server pending connection");
        QTimer::singleShot(2000, this, SLOT(startServer()));
        return;
    }

    socket = server->nextPendingConnection();
    if ( !socket ) {
        ui->message->setText("Failed to create socket!");
        QTimer::singleShot(2000, this, SLOT(startServer()));
        return;
    }

    localDevice->requestPairing(socket->localAddress(), QBluetoothLocalDevice::AuthorizedPaired);
    socket->setParent(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(RECEIVE()));
    connect (socket, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));

    TrayIcon->setIcon(QIcon(":/icon/fullracket.png"));
    QTimer::singleShot(2000, this, SLOT(hide()));


    ui->message->setText("Connected!");
    emit connected();


    // try request compass data
    turnOnMagnetometer();
//    turnOnAccelerometer();
}

void SignalReceiver::clientDisconnected()
{
    socket->deleteLater();
    TrayIcon->setIcon(QIcon(":/icon/blankracket.png"));

    ui->message->setText("Disconnected!");
    show();

    emit disconnected();
    QTimer::singleShot(2000, this, SLOT(startServer()));
}

void SignalReceiver::RECEIVE()
{
    QByteArray stream;
    stream = socket->readLine();

    // A|B|C|D
    if (stream.length() == 1){
        qDebug() << stream;
        emit newButtonPress(stream.right(1));
        return;
    }

    // Direction
    if (stream.length() == 2){
        qDebug() << stream;
        emit newButtonPress(stream.right(2));
        return;
    }

    qDebug() << stream;
    // acceleration
    emit newAccelerationData(stream);
}

void SignalReceiver::turnOnAccelerometer()
{
    qDebug() << "sending command to turnOnAccelerometer";
    socket->write("accelerometer.ON");
}

void SignalReceiver::turnOffAccelerometer()
{
    qDebug() << "sending command to turnOffAccelerometer";
    socket->write("accelerometer.OFF");
}

void SignalReceiver::turnOnMagnetometer()
{
    qDebug() << "sending command to turn ON compass";
    socket->write("compass.ON");
}

void SignalReceiver::turnOffMagnetometer()
{
    qDebug() << "sending command to turn OFF compass";
    socket->write("compass.OFF");
}

void SignalReceiver::serverError(QBluetoothServer::Error error)
{
    QString errorMsg;
    switch (error){
    case 0:
        errorMsg = "No error";
        break;
    case 1:
        errorMsg = "An unknown error occurred.";
        break;
    case 2:
        errorMsg = "The Bluetooth adapter is powered off.";
        break;
    case 3:
        errorMsg = "An input output error occurred.";
        break;
    case 4:
        errorMsg = "The service or port was already registered.";
        break;
    case 5:
        errorMsg = "The Protocol is not supported on this platform.";
        break;
    }
    ui->message->setText(errorMsg);
    show();
}



