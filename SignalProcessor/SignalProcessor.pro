#-------------------------------------------------
#
# Project created by QtCreator 2015-07-03T07:12:54
#
#-------------------------------------------------

QT       += core gui printsupport bluetooth dbus

CONFIG += c++11
LIBS   += -I/usr/local/include/GRT -lgrt

#LIBS    += -L../SignalReceiver/ -lSignalReceiver

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SignalProcessor
TEMPLATE = app #lib


SOURCES += main.cpp\
        signalprocessor.cpp \
    centering.cpp \
    graph2.cpp \
    instructor.cpp \
    qcustomplot.cpp \
    trainingconfiguration.cpp \
    trainingresultwidget.cpp \
    dbusadaptor.cpp \
    recordingconfigwidget.cpp


HEADERS  += signalprocessor.h \
    centering.h \
    graph2.h \
    instructor.h \
    qcustomplot.h \
    trainingconfiguration.h \
    trainingresultwidget.h \
    dbusadaptor.h \
    recordingconfigwidget.h

CONFIG += mobility
MOBILITY = 

FORMS += \
    trainingconfigwidget.ui \
    trainingresultwidget.ui

