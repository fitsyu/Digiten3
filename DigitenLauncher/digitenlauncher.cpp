#include "digitenlauncher.h"
#include "ui_digitenlauncher.h"

#include <QDebug>
#include <QProcess>

DigitenLauncher::DigitenLauncher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DigitenLauncher)
{
    ui->setupUi(this);


    setWindowFlags(Qt::FramelessWindowHint | Qt::SplashScreen);

}

DigitenLauncher::~DigitenLauncher()
{
    delete ui;
}

bool DigitenLauncher::launchTheGame()
{
    qDebug() << "launching receiver..";
//    QProcess; 


    qDebug() << "launching processor..";
    qDebug() << "launching game..";
}
