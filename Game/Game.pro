#-------------------------------------------------
#
# Project created by QtCreator 2015-07-03T07:15:19
#
#-------------------------------------------------

QT       += core gui dbus multimedia

#CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game
TEMPLATE = app


#LIBS    += -L../SignalReceiver/ -lSignalReceiver
#LIBS   += -I/usr/local/include/GRT -lgrt
#LIBS    += -L../SignalProcessor/ -lSignalProcessor

LIBS += -L/usr/local/lib64/panda3d
#LIBS += -L/usr/local/panda3d1.9/lib64/panda3d
LIBS += -lp3framework -lpanda -lpandafx -lpandaexpress -lp3dtoolconfig -lp3dtool -lp3pystub -lp3direct -lpandaphysics

INCLUDEPATH += /usr/local/include/panda3d
#INCLUDEPATH += /usr/local/panda3d1.9/include/panda3d
#INCLUDEPATH += /usr/include/eigen3
INCLUDEPATH += /usr/include/python2.7


SOURCES += main.cpp\
        game.cpp \
    gamemenu.cpp \
    dbusadaptor.cpp \
    darkshield.cpp
#    p3util/cOnscreenText.cpp

HEADERS  += game.h \
    gamemenu.h \
    dbusadaptor.h \
    darkshield.h
#    p3util/cOnscreenText.h

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    sumber-daya-sistem.qrc

FORMS += \
    gamemenu.ui

