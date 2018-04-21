/**
 *
 *  HEADER FOR BOTH GAME AND GAMEMENU DBUS ADAPTRON
 *
 */
#ifndef DBUSADAPTOR_H
#define DBUSADAPTOR_H

#include <QDBusAbstractAdaptor>

#include "gamemenu.h"

class GameMenuDBusAdaptron : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.digiten.GameMenu")

public:
    GameMenuDBusAdaptron(GameMenu* object);

signals:

private slots:

private:
    GameMenu* _menu;
};
// ================================================================
#include "game.h"
class GameDBusAdaptron : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.digiten.Game")

public:
    GameDBusAdaptron(Game* object);

signals:
    void started();
    void finished();

private slots:

private:
    Game* _game;
};

#endif // DBUSADAPTOR_H
