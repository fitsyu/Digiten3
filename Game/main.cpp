#include "game.h"
#include "gamemenu.h"
#include "dbusadaptor.h"
#include <QApplication>
#include <QDBusConnection>
#include <QSplashScreen>
#include <QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen splashScreen(QPixmap(":/img/splash szreen.jpg"));

//    splashScreen.resize(1360, 768);
    splashScreen.showFullScreen();


//    Game g(argc, argv);
//    QObject::connect(&g, SIGNAL(finished()), &a, SLOT(quit()));
//    QTimer::singleShot(5000, &g, SLOT(start()));

    splashScreen.showMessage("Loading game menu..", Qt::AlignRight | Qt::AlignTop , Qt::white);
    qApp->processEvents();
    GameMenu menu;
//    menu.show();


    splashScreen.showMessage("Connecting to D-Bus..", Qt::AlignRight | Qt::AlignTop , Qt::white);
    qApp->processEvents();
    // RECEIVER -- D-BUS -- MENU
    bool connectedToReceiver =
    QDBusConnection::sessionBus().connect(
                "com.digiten.Receiver",
                "/", "",
                "newButtonPress",
                &menu,
                SLOT(handleRemoteButtonPress(QByteArray))
                );



    if ( !connectedToReceiver ){
        qFatal("unable to connect to Receiver");
        return 1;
    }

    splashScreen.showMessage("Loading game..", Qt::AlignRight | Qt::AlignTop , Qt::white);
    qApp->processEvents();
    Game game(argc, argv);

    QObject::connect(&menu, SIGNAL(newGame(QMap<QString,int>)),
                     &game, SLOT(startGame(QMap<QString, int>)));

    QObject::connect(&game, SIGNAL(started()), &menu, SLOT(hide()));
    QObject::connect(&game, SIGNAL(finished()), &menu, SLOT(show()));

    splashScreen.showMessage("Connecting to D-Bus..", Qt::AlignRight | Qt::AlignTop , Qt::white);
    qApp->processEvents();
    // RECEIVER -- D-BUS -- GAME
    QDBusConnection::sessionBus().connect(
                "com.digiten.Receiver",
                "/", "",
                "newButtonPress",
                &game,
                SLOT(handleRemoteButtonPress(QByteArray))
                );

    // PROCESSOR -- D-BUS -- GAME
    bool connectedToProcessor =
    QDBusConnection::sessionBus().connect(
                "com.digiten.Processor",
                "/", "",
                "gestureDetected",
                &game,
                SLOT(handleGesture(int))
                );

    // DBUS: local
    new GameDBusAdaptron(&game);
    QDBusConnection::sessionBus().registerService("com.digiten.Game");
    QDBusConnection::sessionBus().registerObject("/", &game);

    if ( !connectedToProcessor ){
        qFatal("unable to connect to Processor");
        return 1;
    }

    splashScreen.showMessage("launching game menu..", Qt::AlignRight | Qt::AlignTop, Qt::white);
    QTimer::singleShot(5000, &menu, SLOT(showFullScreen()));

    QTimer::singleShot(6000, &splashScreen, SLOT(close()) );
    return a.exec();

//    Game game(argc, argv);
//    QMap<QString, int> configuration;
//    configuration["player"] = 1;
//    configuration["venue"] = 1;
//    game.startGame(configuration);
//    return a.exec();
}
