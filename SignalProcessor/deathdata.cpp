#include "deathdata.h"
#include <QDebug>

DeathData::DeathData(QObject *parent) :
    QObject(parent)
{
    timerGue = new QTimer(this);
    connect(timerGue, SIGNAL(timeout()), this, SLOT(emitData()));

    key = 0;
}

void DeathData::setSourcefile(QString fileName)
{
    source = new QFile(fileName);
    source->open(QFile::ReadOnly | QFile::Text);

    QList<QByteArray> buffer;
    int key;
    QVector3D datum;
    while (!source->atEnd()) {
        buffer = source->readLine().split(',');
//        qDebug() << buffer.length();
        if (buffer.length() == 8)
            if (buffer.at(1).toInt()){
                key = buffer.at(1).toInt();

                datum.setX( buffer.at(2).toDouble() );
                datum.setY( buffer.at(3).toDouble() );
                datum.setZ( buffer.at(4).toDouble() );

                data.insert(key, datum);
            }
    }
    delete source;
}

void DeathData::stream(int delay)
{
    // assumes data has been filled
    timerGue->start(delay);
}

void DeathData::emitData()
{
//    qDebug() << key;
//    if ( key >= 102) {
//        qDebug() << data.value(data.keys().at(key)).x();
//        return;
//    }

    emit newXYZ( data.value(data.keys().at(key)) );
//    qDebug() << data.value(data.keys().at(key));

    // next
    int timeA, timeB, timeDelta;
    timeA = data.keys().at(key);

    ++key;
    if ( key < data.keys().length() )
    {
        timeB = data.keys().at(key);

        timeDelta = abs(timeA - timeB);
        stream(timeDelta);
    }
    else {
        qDebug() << "no data left";
        timerGue->stop();
    }

}
