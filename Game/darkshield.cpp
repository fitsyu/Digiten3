#include "darkshield.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>

DarkShield::DarkShield(QWidget *parent) : QWidget(parent)
{

    _title = "here is TITLE";
    _info  = "and some informations";

    titleFace = new QLabel(this);
    infoFace = new QLabel(this);

    // set up UI
    this->setStyleSheet("background: black");
    this->setWindowOpacity(0.81);

    int dwidth  = qApp->desktop()->width();
    int dheight = qApp->desktop()->height();

    resize(dwidth, dheight);

    titleFace->setStyleSheet("background: black; color: green; border: 2 solid white");
    titleFace->resize(800, 200);
    titleFace->move( (dwidth-titleFace->width())/2, (0.1*dheight) );
    titleFace->setFont(QFont("Ubuntu", 32));
    titleFace->setAlignment(Qt::AlignCenter);

    infoFace->setStyleSheet("background: black; color: green; border: 2 solid white");
    infoFace->resize(800, 400);
    infoFace->move( (dwidth-infoFace->width())/2, (titleFace->y()+titleFace->height()+20) );
    infoFace->setFont(QFont("Ubuntu", 45));
    infoFace->setAlignment(Qt::AlignCenter | Qt::AlignJustify);

    titleFace->setText(_title);
    infoFace->setText(_info);
}

void DarkShield::setTitle(const QString title)
{
    _title = title;
    titleFace->setText(title);
}

void DarkShield::setInfo(const QString info)
{
    _info = info;
    infoFace->setText(info);
}

void DarkShield::keyPressEvent(QKeyEvent *ev)
{
    switch (ev->key()){
    case Qt::Key_A:
        emit a_pressed();
        break;
    case Qt::Key_B:
        emit b_pressed();
        break;
    case Qt::Key_C:
        emit c_pressed();
        break;
    case Qt::Key_D:
        emit d_pressed();
        break;
    default: break;
    }
}

void DarkShield::surprise()
{
    setWindowOpacity(0.81);
    showFullScreen();

    emit appeared();
}

void DarkShield::disappear()
{
    setWindowOpacity(0);
    hide();

    emit disappeared();
    disconnect();
}

