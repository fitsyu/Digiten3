#include "dbusadaptor.h"


DBusAdaptor::DBusAdaptor(SignalProcessor *object)
    :QDBusAbstractAdaptor(object),
      _processor(object)
{
    // forward to outside world
    connect (_processor, SIGNAL(gestureDetected(int)),
             this, SIGNAL(gestureDetected(int)));
}


