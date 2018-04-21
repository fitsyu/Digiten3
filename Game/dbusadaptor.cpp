#include "dbusadaptor.h"

GameMenuDBusAdaptron::GameMenuDBusAdaptron(GameMenu *object)
    :QDBusAbstractAdaptor(object),
      _menu(object)
{

}


GameDBusAdaptron::GameDBusAdaptron(Game *object)
    :QDBusAbstractAdaptor(object),
      _game(object)
{
    connect(_game, SIGNAL(started()), this, SIGNAL(started()));
    connect(_game, SIGNAL(finished()), this, SIGNAL(finished()));
}
