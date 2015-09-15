#ifndef TRAININGCONFIGURATION_H
#define TRAININGCONFIGURATION_H

#include <QString>
#include <QList>

struct gesture {
    int ID;
    QString gesture_name;
    int samples_required;
    QString command;
};

struct TrainingConfiguration
{
    QString dataset_name;
    QString info_text;
    unsigned int num_dimensions;
    QList<gesture> gestures;
};

#endif // TRAININGCONFIGURATION_H
