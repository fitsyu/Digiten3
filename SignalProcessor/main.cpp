#include "signalprocessor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SignalProcessor w;
    w.show();

    return a.exec();
}
