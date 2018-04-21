#include "digitenlauncher.h"
#include "ui_digitenlauncher.h"

DigitenLauncher::DigitenLauncher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DigitenLauncher)
{
    ui->setupUi(this);
}

DigitenLauncher::~DigitenLauncher()
{
    delete ui;
}
