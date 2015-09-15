#include "signalreceiver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SignalReceiver w;
    w.show();

    return a.exec();
}
