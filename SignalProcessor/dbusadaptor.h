#ifndef DBUSADAPTOR_H
#define DBUSADAPTOR_H

#include <QDBusAbstractAdaptor>
#include "signalprocessor.h"

class DBusAdaptor : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.digiten.Processor")

public:
    DBusAdaptor(SignalProcessor* object);

signals:
    void gestureDetected(int);

private slots:

private:
    SignalProcessor* _processor;
};

#endif // DBUSADAPTOR_H
