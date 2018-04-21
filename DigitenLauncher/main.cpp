#include "digitenlauncher.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DigitenLauncher w;
    w.show();

    return a.exec();
}
