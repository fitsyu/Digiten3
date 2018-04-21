TEMPLATE = app

QT += core gui widgets sensors quick bluetooth

android {
    QT +=androidextras
}

TARGET = RemoteRacketController
TEMPLATE = app


SOURCES += \
    transmitter.cpp \
    themain.cpp

HEADERS  += \
    transmitter.h

OTHER_FILES += *.qml

FORMS    +=

CONFIG += mobility
MOBILITY =

RESOURCES += \
    sumber-daya-alam.qrc

DISTFILES += \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/AndroidManifest.xml \
    android/gradlew.bat \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/HardButtonListener.java

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
