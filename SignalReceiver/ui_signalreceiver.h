/********************************************************************************
** Form generated from reading UI file 'signalreceiverTT1803.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SIGNALRECEIVERTT1803_H
#define SIGNALRECEIVERTT1803_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignalReceiver
{
public:
    QLabel *message;
    QPushButton *btQuit;

    void setupUi(QWidget *SignalReceiver)
    {
        if (SignalReceiver->objectName().isEmpty())
            SignalReceiver->setObjectName(QStringLiteral("SignalReceiver"));
        SignalReceiver->resize(445, 252);
        message = new QLabel(SignalReceiver);
        message->setObjectName(QStringLiteral("message"));
        message->setGeometry(QRect(0, 10, 421, 221));
        message->setStyleSheet(QStringLiteral("font: 63 italic 14pt \"Ubuntu\";"));
        message->setAlignment(Qt::AlignCenter);
        btQuit = new QPushButton(SignalReceiver);
        btQuit->setObjectName(QStringLiteral("btQuit"));
        btQuit->setGeometry(QRect(350, 201, 81, 41));

        retranslateUi(SignalReceiver);

        QMetaObject::connectSlotsByName(SignalReceiver);
    } // setupUi

    void retranslateUi(QWidget *SignalReceiver)
    {
        SignalReceiver->setWindowTitle(QApplication::translate("SignalReceiver", "BlueMiced", 0));
        message->setText(QApplication::translate("SignalReceiver", "Waiting for device bluetooth connection ..\n"
"\n"
"( tap CONNECT button on the application )", 0));
        btQuit->setText(QApplication::translate("SignalReceiver", "&Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class SignalReceiver: public Ui_SignalReceiver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SIGNALRECEIVERTT1803_H
