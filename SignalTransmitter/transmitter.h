#ifndef BLUEMICE_H
#define BLUEMICE_H

#include <QObject>
#include <QAccelerometer>
#include <QCompass>
#include <QOrientationSensor>
#include <QBluetoothServiceDiscoveryAgent>
#include <QBluetoothSocket>
#include <QBluetoothLocalDevice>

// Wifi.start
#include <QTcpSocket>
// Wifi.end


static const QString serviceUuid(QStringLiteral("e8e10f95-1a70-4b27-9ccf-02010264e9c7"));
class Transmitter : public QObject
{
    Q_OBJECT

public:
    explicit Transmitter();
    ~Transmitter();

    QObject *getFrontend() const;
    void setFrontend(QObject *value);

public slots:
    //    void onInterfaceReady(QObject*object, QUrl url);
    void startService();
    void stopService();
    void onNewDataAvailable();

    void discover();
    void displayService(QBluetoothServiceInfo service);
    void tryConnectingToDigitenServer(QString btDeviceName);
    void disconnectFromServer();

    void directConnect();
    void serverIsSaying();
    void onError(QBluetoothSocket::SocketError error);
    void onConnected();
    void onStateChanged(QBluetoothSocket::SocketState state);

    void onFinished();

    void clickButton(int buttonID);
    void toggleAccelerometer();
    void togglecompass();

    void onOrientationChanged();


    // compass call
    //..
    void startSendcompassData();
    void stopSendcompassData();
    void sendcompassData();


    void showAvailableSensors();

    // wifi.start
    void setupWifiSocket();
    void readReceivedData();
    void sendData(QByteArray data);


    void connectTo(QString hostIPAddress, int portNumber);
    void disconnectFromWifiServer();

    void onWifiConnected();
    void onWifiDisconnected();

    void onStateChange(QAbstractSocket::SocketState state);
    void onSocketError(QAbstractSocket::SocketError error);
    // wifi.end
private:
    QAccelerometer *accelerometer;
    bool accON;
//    QOrientationSensor *orientationSpy;

    QCompass *compass;
    bool compassON;

    QBluetoothServiceDiscoveryAgent *discoveryAgent;
    QBluetoothSocket *tunnel;
    QBluetoothLocalDevice *device;

    QHash<QString,QBluetoothServiceInfo> serverList;


    // front end
    QObject* frontend;
    void sendFrontEndMessage(QString msg);

    void addNewHostFound(QString address);

    // JNI
#ifdef Q_OS_ANDROID
    void registerNativeMethods();
#endif
    static void cVolUpPressed();
    static void cVolDownPressed();


    // Wifi.start
    QTcpSocket* wifi_socket;
    // Wifi.end

};

#endif // BLUEMICE_H
