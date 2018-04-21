#ifndef DBUSADAPTOR_H
#define DBUSADAPTOR_H

#include <QObject>

class DBusAdaptor : public QObject
{
    Q_OBJECT
public:
    explicit DBusAdaptor(QObject *parent = 0);

signals:

public slots:
};

#endif // DBUSADAPTOR_H
