#ifndef DBUSADAPTOR_H
#define DBUSADAPTOR_H

#include <QObject>

class DBusAdaptor : public QDBusAbstractAdaptor
{
public:
    DBusAdaptor();
    ~DBusAdaptor();
};

#endif // DBUSADAPTOR_H
