/*
 * this is the test drive file
 * to test this library
 * you need to change the TEMPLATE
 * variable in your .pro file from
 * lib to app:
 * TEMPLATE = app
 * to use this file.
 *
 */



#include <QApplication>
#include <QDBusConnection>
#include "signalreceiver.h"
#include "dbusadaptor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SignalReceiver w;
    w.show();

    // D-BUS
    new DBusAdaptor(&w);
    // make sure service registered by first unregister it
    QDBusConnection::sessionBus().unregisterService("com.digiten.Receiver");
    QDBusConnection::sessionBus().registerService("com.digiten.Receiver");
    QDBusConnection::sessionBus().registerObject("/", &w);


    // turn on sensor when game started
    // and turn it off when game finished
    // GAME -- D-BUS -- RECEIVER
    QDBusConnection::sessionBus().connect(
                "com.digiten.Game",
                "/", "",
                "started",
                &w,
                SLOT(turnOnAccelerometer())
                );
    QDBusConnection::sessionBus().connect(
                "com.digiten.Game",
                "/", "",
                "finished",
                &w,
                SLOT(turnOffAccelerometer())
                );


    //TODO: notify when losing connection

    return a.exec();
}
