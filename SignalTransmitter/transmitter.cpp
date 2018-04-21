#include "transmitter.h"
#include <QSensor>
#include <QDebug>
//#include <QPointF>
#include <QBluetoothServiceInfo>
#include <QtCore>
#include <QUrl>
#include <QHostAddress>

#ifdef Q_OS_ANDROID
#include <QAndroidJniObject>
#include <QAndroidJniEnvironment>
#endif


Transmitter::Transmitter() :
    QObject()
{
    device = new QBluetoothLocalDevice(this);
    accelerometer = new QAccelerometer(this);

    /* NEW */
    compass = new QCompass(this);
    /* NEW */

    tunnel = NULL;

#ifdef Q_OS_ANDROID
    //    registerNativeMethods();
#endif

    // try to move this to constructor
    discoveryAgent = new QBluetoothServiceDiscoveryAgent(QBluetoothAddress(), this);

    connect(discoveryAgent, SIGNAL(serviceDiscovered(QBluetoothServiceInfo)),
            this, SLOT(displayService(QBluetoothServiceInfo)));
    connect(discoveryAgent, SIGNAL(finished()), this, SLOT(onFinished()));
    //    connect(discoveryAgent, SIGNAL(error(QBluetoothServiceDiscoveryAgent::Error)),
    //            this, SLOT(serviceScanError(QBluetoothServiceDiscoveryAgent::Error)));
    discoveryAgent->setUuidFilter(QBluetoothUuid(serviceUuid));
    //    discoveryAgent->setUuidFilter(QBluetoothUuid(QBluetoothUuid::Rfcomm));

    //    showAvailableSensors();
    setupWifiSocket();
    connect(compass, SIGNAL(readingChanged()),
            this, SLOT(sendcompassData()));
    compass->setSkipDuplicates(true);

}

Transmitter::~Transmitter()
{
    delete accelerometer;

    /* NEW */
    delete compass;
}

//void BlueMice::onInterfaceReady(QObject *object, QUrl url)
//{
//    qDebug() << "interface ready";
//}

void Transmitter::startService()
{
    accelerometer->setAccelerationMode(QAccelerometer::User);
    accelerometer->setAlwaysOn(accelerometer->isFeatureSupported(QSensor::AlwaysOn));
    accelerometer->setSkipDuplicates(accelerometer->isFeatureSupported(QSensor::SkipDuplicates));

    qDebug() << "starting report service..." << accelerometer->start();
    sendFrontEndMessage("sending acceleration signals...");
    connect(accelerometer, SIGNAL(readingChanged()), this, SLOT(onNewDataAvailable()));

    //    orientationSpy = new QOrientationSensor(this);
    //    connect(orientationSpy, SIGNAL(readingChanged()),
    //            this, SLOT(onOrientationChanged()));
    //    orientationSpy->start();
}

void Transmitter::stopService()
{
    qDebug() << "stopping report service...";
    sendFrontEndMessage("accelerometer stopped.");
    accelerometer->stop();
}

void Transmitter::discover()
{
    if ( device->hostMode() == QBluetoothLocalDevice::HostPoweredOff ) {
        device->powerOn();
    }



    //    discoveryAgent->start(QBluetoothServiceDiscoveryAgent::FullDiscovery);
    discoveryAgent->start(QBluetoothServiceDiscoveryAgent::MinimalDiscovery);

    sendFrontEndMessage("Scanning Digiten server..");
}

void Transmitter::displayService(QBluetoothServiceInfo service)
{
    //    qDebug () << "target found.. setting up ";
    //    sendFrontEndMessage("Target found. Setting up...");
    //    qDebug () << service.device().address().toString();

    QString newBtDeviceName = service.device().name();

    // first add it to internal backend variabel
    serverList.insert(newBtDeviceName, service);

    // display it in QML ListView
    addNewHostFound(newBtDeviceName);

    // split here
    //    return;


}

void Transmitter::tryConnectingToDigitenServer(QString btDeviceName)
{
    QBluetoothServiceInfo service = serverList[btDeviceName];



    tunnel = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol, this);

    //    qDebug () << "connecting to service";
    sendFrontEndMessage("connecting to the Digiten server.");
    tunnel->connectToService(service);

    connect(tunnel, SIGNAL(readyRead()), this, SLOT(serverIsSaying()));
    connect(tunnel, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(tunnel, SIGNAL(error(QBluetoothSocket::SocketError)), this,
            SLOT(onError(QBluetoothSocket::SocketError)));
    connect(tunnel, SIGNAL(stateChanged(QBluetoothSocket::SocketState)), this,
            SLOT(onStateChanged(QBluetoothSocket::SocketState)));
    //        discoveryAgent->stop();
}

void Transmitter::disconnectFromServer()
{
    serverList.remove(tunnel->peerName());

    // assumed tunnel to be closed soon
    // TODO: listen on disconnected to signal
    // then react on QML
    tunnel->disconnectFromService();

}

void Transmitter::directConnect()  // seems it's not supported yet
{
    //    "1C:65:9D:B4:75:A3" my axioo address
    QBluetoothAddress axiooaddress("1C:65:9D:B4:75:A3");
    tunnel = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);

    qDebug () << "connecting to service";
    tunnel->connectToService(axiooaddress, 2);

    connect(tunnel, SIGNAL(readyRead()), this, SLOT(serverIsSaying()));
    connect(tunnel, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(tunnel, SIGNAL(error(QBluetoothSocket::SocketError)), this,
            SLOT(onError(QBluetoothSocket::SocketError)));
    connect(tunnel, SIGNAL(stateChanged(QBluetoothSocket::SocketState)), this,
            SLOT(onStateChanged(QBluetoothSocket::SocketState)));
}

void Transmitter::onNewDataAvailable()
{
    if (tunnel){
        qreal devX = accelerometer->reading()->x();
        qreal devY = accelerometer->reading()->y();
        qreal devZ = accelerometer->reading()->z();

        //    qDebug () << data;
        /**
     * @brief x,y,z
     */
        QByteArray data = QString(
                    "ac:"+
                    QString::number(devX)+','+
                    QString::number(devY)+','+
                    QString::number(devZ)
                    ).toUtf8();
        tunnel->write(data);
    } else {
        sendFrontEndMessage("tunnel closed!");
    }

}

void Transmitter::onConnected()
{
    //    qDebug() << "connected to server!";
    //    sendFrontEndMessage("Connected!");
    QMetaObject::invokeMethod(
                frontend,
                "setConnectedDeviceName",
                Q_ARG(QVariant, tunnel->peerName())
                );

    discoveryAgent->stop();
}

void Transmitter::onStateChanged(QBluetoothSocket::SocketState state)
{
    qDebug () << "client state" << state;
    switch (state) {
    case QBluetoothSocket::UnconnectedState:
        sendFrontEndMessage("not connected");
        break;
    case QBluetoothSocket::ServiceLookupState:
        sendFrontEndMessage("looking for service");
        break;
    case QBluetoothSocket::ConnectingState:
        sendFrontEndMessage("connecting...");
        break;
    case QBluetoothSocket::ConnectedState:
        sendFrontEndMessage("connected.");
        break;
    case QBluetoothSocket::BoundState:
        sendFrontEndMessage("bound.");
        break;
    case QBluetoothSocket::ClosingState:
        sendFrontEndMessage("closing...");
        break;
    case QBluetoothSocket::ListeningState:
        sendFrontEndMessage("listening..");
        break;
    default:
        break;
    }
}

void Transmitter::onFinished()
{
    qDebug() << "finished scanning";
    sendFrontEndMessage("scanning finished.");
    //    qDebug() << "tunnel's state" << tunnel->state();  // not yet constructed
    //    qDebug() << discoveryAgent->errorString();
    //    sendFrontEndMessage(discoveryAgent->errorString());
}

void Transmitter::clickButton(int buttonID)
{
    /**
      * abcd buttons written as is
      * direction button prefixed by _
      */

    QIODevice* air_cable;
    if ( tunnel ){
        air_cable = tunnel;
    } else if ( wifi_socket ){
        air_cable = wifi_socket;
    }
    else {
        sendFrontEndMessage("no cable");
        return;
    }



    switch (buttonID) {
    case 0:
        air_cable->write("A");
        qDebug() << "click A";
        break;
    case 1:
        air_cable->write("B");
        qDebug() << "click B";
        break;
    case 2:
        air_cable->write("C");
        qDebug() << "click C";
        break;
    case 3:
        air_cable->write("D");
        qDebug() << "click D";
        break;
    case 4:
        air_cable->write("_U");
        qDebug() << "click UP";
        break;
    case 5:
        air_cable->write("_D");
        qDebug() << "click DOWN";
        break;
    case 6:
        air_cable->write("_R");
        qDebug() << "click RIGHT";
        break;
    case 7:
        air_cable->write("_L");
        qDebug() << "click LEFT";
        break;
    default:
        qDebug() << "unknown button clicked";
        break;
    }


}

void Transmitter::toggleAccelerometer()
{
    accON = !accON;
    if (accON)
        startService();
    else
        stopService();
    sendFrontEndMessage( (accON?"accelerometer enabled":"accelerometer disabled") );
}

void Transmitter::togglecompass()
{
    compassON = !compassON;
    if (compassON)
        startSendcompassData();
    else
        stopSendcompassData();
    sendFrontEndMessage( (compassON?"compass enabled":"compass disabled") );
}

void Transmitter::onOrientationChanged()
{
    //    tunnel->write(
    //                QString(
    //                    "orientation:"+
    //                    QString::number(orientationSpy->reading()->orientation())
    //                    ).toUtf8()
    //                );
}



void Transmitter::sendFrontEndMessage(QString msg)
{
    QMetaObject::invokeMethod(
                frontend,
                "readMsg",
                Q_ARG(QVariant, msg)
                );
}

void Transmitter::addNewHostFound(QString address)
{
    QMetaObject::invokeMethod(
                frontend,
                "addNewHostFound",
                Q_ARG(QVariant, address)
                );
}

#ifdef Q_OS_ANDROID
void Transmitter::registerNativeMethods()
{
    JNINativeMethod methods[] {
        {"jVolUpPressed", "()V", reinterpret_cast<void *>(cVolUpPressed)},
        {"jVolDownPressed", "()V", reinterpret_cast<void *>(cVolDownPressed)}
    };

    QAndroidJniObject javaClass("org/qtprojects/hardbuttonlistener/HardButtonListener");
    qDebug() << javaClass.isValid();
    QAndroidJniEnvironment env;
    jclass objectClass = env->GetObjectClass(javaClass.object<jobject>());
    env->RegisterNatives(objectClass,
                         methods,
                         sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(objectClass);
}
#endif

void Transmitter::cVolUpPressed()
{
    //    sendFrontEndMessage("vol up pressed");
    qDebug() << "vol up";
}

void Transmitter::cVolDownPressed()
{
    //    sendFrontEndMessage("vol down pressed");
    qDebug() << "vol down";
}

QObject *Transmitter::getFrontend() const
{
    return frontend;
}

void Transmitter::setFrontend(QObject *value)
{
    frontend = value;
}

void Transmitter::serverIsSaying()
{
    // data from server will be here
    // 1. listSensors
    // 2. turnOnSensor(sensor)
    // 3. turnOffSensor(sensor)
    QByteArray stream;
    stream = tunnel->readLine();


    if (stream.contains("accelerometer.ON")){
        startService();
        return;
    }

    if (stream.contains("accelerometer.OFF")){
        stopService();
        return;
    }

    if (stream.contains("compass.ON")){
        startSendcompassData();
        return;
    }

    if (stream.contains("compass.OFF")){
        stopSendcompassData();
        return;
    }
}

void Transmitter::onError(QBluetoothSocket::SocketError error)
{
    qDebug() << error;
}


//=========== COMPASS =================
void Transmitter::startSendcompassData()
{

    compass->start(); // THIS IS IT

    sendFrontEndMessage("sending compass signals...");
}

void Transmitter::stopSendcompassData()
{
    compass->stop();
    sendFrontEndMessage("compass stopped");
}

void Transmitter::sendcompassData()
{
    if (wifi_socket){
        qreal azimuth = compass->reading()->azimuth();

        QByteArray data = QString(
                    "az:"+QString::number(azimuth)
                    ).toUtf8();
        wifi_socket ->write(data);
    } else {
        sendFrontEndMessage("tunnel closed!");
    }
}

void Transmitter::showAvailableSensors()
{
    QByteArray availableSensors;
    foreach (QByteArray sensorName, QSensor::sensorTypes() ){
        availableSensors.append(sensorName);
        availableSensors.append("\n");
    }

    sendFrontEndMessage(availableSensors);
}

void Transmitter::setupWifiSocket()
{
    wifi_socket = new QTcpSocket(this);
    connect (wifi_socket, SIGNAL(readyRead()), this, SLOT(readReceivedData()));
    connect(wifi_socket, SIGNAL(connected()), this, SLOT(onWifiConnected()));
    connect(wifi_socket, SIGNAL(disconnected()), this, SLOT(onWifiDisconnected()));

    connect(wifi_socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(onStateChange(QAbstractSocket::SocketState)));

    connect(wifi_socket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(onSocketError(QAbstractSocket::SocketError)));
}

void Transmitter::readReceivedData()
{
    QByteArray receivedData = wifi_socket->readAll();
    sendFrontEndMessage(receivedData);
}

void Transmitter::sendData(QByteArray data)
{
    if (wifi_socket->isOpen()){
        wifi_socket->write(data);
    } else {
        sendFrontEndMessage("wifi socket closed.");
    }
}

void Transmitter::connectTo(QString hostIPAddress, int portNumber)
{
    sendFrontEndMessage("re-creating tcp socket..");
    wifi_socket->abort();

    sendFrontEndMessage("connecting to wifi server..");
    QHostAddress hostAddress = QHostAddress(hostIPAddress);
    wifi_socket->connectToHost(hostAddress, portNumber);
}

void Transmitter::disconnectFromWifiServer()
{
    sendFrontEndMessage("disconnecting from server..");
    wifi_socket->disconnectFromHost();
}

void Transmitter::onWifiConnected()
{
    sendFrontEndMessage("connected.");
    QMetaObject::invokeMethod(frontend, "hideWifiConnectionSetup");
}

void Transmitter::onWifiDisconnected()
{
    sendFrontEndMessage("disconnected.");
    QMetaObject::invokeMethod(frontend, "showWifiConnectionSetup");
}

void Transmitter::onStateChange(QAbstractSocket::SocketState state)
{
    QString stateString;
    switch (state){
    case QAbstractSocket::UnconnectedState:
        stateString = "disconnected."; break;
    case QAbstractSocket::HostLookupState:
        stateString = "Looking up host.."; break;
    case QAbstractSocket::ConnectingState:
        stateString = "connecting.."; break;
    case QAbstractSocket::ConnectedState:
        stateString = "connected."; break;
    case QAbstractSocket::BoundState:
        stateString = "bounded."; break;
    case QAbstractSocket::ClosingState:
        stateString = "closing.."; break;
    case QAbstractSocket::ListeningState:
        stateString = "listening.."; break;

    }
    QMetaObject::invokeMethod(frontend, "setSocketState", Q_ARG(QVariant, stateString));
}

void Transmitter::onSocketError(QAbstractSocket::SocketError error)
{
    QMetaObject::invokeMethod(frontend, "setSocketState", Q_ARG(QVariant, QString("<b>error: %1</b><br>%2")
                                                                .arg(
                                                                    QString::number(error),
                                                                    wifi_socket->errorString()
                                                                    )
                                                                )
                              );
}
