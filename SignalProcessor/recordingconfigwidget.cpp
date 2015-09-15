#include "trainingconfigwidget.h"
#include "ui_trainingconfigwidget.h"

#include <QMessageBox>
#include "centering.h"

TrainingConfigWidget::TrainingConfigWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TrainingConfigWidget)
{
    ui->setupUi(this);


    connect (ui->btAdd, SIGNAL(clicked()),
             this, SLOT(addGesture()));
    connect(ui->btRemove, SIGNAL(clicked()),
            this, SLOT(removeGesture()));
    connect (ui->btStart, SIGNAL(clicked()),
             this, SLOT(startTraining()));


    move ( center_point(this) );
}

TrainingConfigWidget::~TrainingConfigWidget()
{
    delete ui;
}

void TrainingConfigWidget::addGesture()
{
    ui->gesturesTable->insertRow(ui->gesturesTable->rowCount());
}

void TrainingConfigWidget::removeGesture()
{
    ui->gesturesTable->removeRow(ui->gesturesTable->currentRow());
}

void TrainingConfigWidget::startTraining()
{
    // prechecks
    QMessageBox box;
    box.setIcon(QMessageBox::Warning);
    if (ui->txDatasetName->text().isEmpty()){
        box.setText("Dataset name should not be empty!");
        box.exec();
        return;
    }

    if (ui->txDatasetName->text().contains(" ")){
        box.setText("Dataset name should not contain space!");
        box.exec();
        return;
    }

    if (ui->gesturesTable->rowCount() == 0){
        box.setText("No gesture to record!");
        box.exec();
        return;
    }

    TrainingConfiguration newConfig;
    newConfig.dataset_name      = ui->txDatasetName->text();
    newConfig.info_text         = ui->txInfoText->text();
    newConfig.num_dimensions    = ui->num_dimension->value();

    for (int r=0; r<ui->gesturesTable->rowCount(); ++r){
        gesture* G = new gesture;
        G->ID               = ui->gesturesTable->item(r, 0)->text().toInt();
        G->gesture_name     = ui->gesturesTable->item(r, 1)->text();
        G->samples_required = ui->gesturesTable->item(r, 2)->text().toInt();
        G->command          = ui->gesturesTable->item(r, 3)->text();
        newConfig.gestures.append(*G);
    }


    emit configured(newConfig);
    close();
}
