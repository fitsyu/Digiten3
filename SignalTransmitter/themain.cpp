#include "transmitter.h"
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Transmitter *ghost = new Transmitter;
        QQmlApplicationEngine engine;
        engine.rootContext()->setContextProperty("Transmitter", ghost);


//    QStringList cOdel;
//    cOdel << "bt host 1" << "bt host 2";
//    engine.rootContext()->setContextProperty("hostModel", QVariant::fromValue(cOdel));

    engine.load(QUrl("qrc:/interfaces/Main.qml"));

//    QObject::connect(&engine, SIGNAL(objectCreated(QObject*,QUrl)),
//                     ghost, SLOT(onInterfaceReady(QObject*,QUrl)));

    QObject* qmlfront_end = engine.rootObjects().at(0);
    ghost->setFrontend(qmlfront_end);

    return a.exec();
}
