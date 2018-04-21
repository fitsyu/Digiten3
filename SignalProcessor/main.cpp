#include "signalprocessor.h"
//#include "graph2.h"
#include "dbusadaptor.h"
#include <QApplication>
#include <QDBusInterface>
#include <QDebug>
//#include "../SignalReceiver/signalreceiver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    SignalReceiver receiver;
    //    receiver.show();

    // Training Or Not
    // -train
    // -test
    // -no-graph
    QString opmode = "";
    QString modelFile = "";
    if ( a.arguments().count()>1 ){
        foreach (QString option, a.arguments()){
            if (option == "-train"){
                opmode = "training";
                break;
            }
            if (option == "-test"){
                opmode = "testing";
                modelFile = a.arguments().last();
                break;
            }
            if (option == "-game"){
                opmode = "gaming";  // hide signal viewer
                modelFile = a.arguments().last();
                break;
            }
        }
    }

    SignalProcessor processor(opmode, modelFile);

    /**
      if ! game
        prosessor.showViewer
      */



    //    QObject::connect( &receiver, SIGNAL(new3DGeometry(QVector3D)),
    //                      &processor, SLOT(receive(QVector3D)));

    // DBUS: local
    new DBusAdaptor(&processor);
    QDBusConnection::sessionBus().registerService("com.digiten.Processor");
    QDBusConnection::sessionBus().registerObject("/", &processor);

    // DBUS: remote
    QDBusInterface receiver_bus(
                "com.digiten.Receiver",       // service
                "/",                          // path
                "",                           // interface
                QDBusConnection::sessionBus() // connection
                );
    if ( receiver_bus.isValid() ) {
        bool connectedToDBus =
                QDBusConnection::sessionBus().connect(
                    receiver_bus.service(),
                    receiver_bus.path(),
                    receiver_bus.interface(),
                    "newAccelerationData",
                    &processor,
                    SLOT(PROCESS(QByteArray))
                    );

        if ( !connectedToDBus ) {}
    } // TODO: if dbus not valid what todo?

    return a.exec();
}
