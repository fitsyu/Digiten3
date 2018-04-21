#-------------------------------------------------
#
# Project created by QtCreator 2015-07-03T05:52:49
#
#-------------------------------------------------

QT       += core gui bluetooth dbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SignalReceiver
TEMPLATE = app #lib


SOURCES += main.cpp\
        signalreceiver.cpp \
    dbusadaptor.cpp

HEADERS  += signalreceiver.h \
    dbusadaptor.h

FORMS    += signalreceiver.ui

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    resource.qrc

