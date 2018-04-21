/*
 * This class is created to enable you to simulate
 * the flow of accelerometer data from device without
 * using the device itself.
 * First use turn on Accelerometer App on device
 * record the data then save it to a file.
 * Then use that file as source for this object.
 *
*/

#ifndef DEATHDATA_H
#define DEATHDATA_H

#include <QFile>
#include <QObject>
#include <QTimer>
#include <QMap>
#include <QVector3D>

class DeathData : public QObject
{
    Q_OBJECT
public:
    explicit DeathData(QObject *parent = 0);
    void setSourcefile(QString fileName);
    void stream(int delay);

signals:
    void newXYZ(QVector3D);
private slots:
    void emitData();

private:
    QTimer *timerGue;
    QFile *source;
    QMap<int, QVector3D > data;
    int key;
};

#endif // DEATHDATA_H
