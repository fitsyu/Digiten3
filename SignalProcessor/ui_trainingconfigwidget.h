/********************************************************************************
** Form generated from reading UI file 'trainingconfigwidgetLh2229.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TRAININGCONFIGWIDGETLH2229_H
#define TRAININGCONFIGWIDGETLH2229_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrainingConfigWidget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *txDatasetName;
    QLineEdit *txInfoText;
    QTableWidget *gesturesTable;
    QPushButton *btAdd;
    QPushButton *btRemove;
    QPushButton *btStart;
    QSpinBox *num_dimension;

    void setupUi(QWidget *TrainingConfigWidget)
    {
        if (TrainingConfigWidget->objectName().isEmpty())
            TrainingConfigWidget->setObjectName(QStringLiteral("TrainingConfigWidget"));
        TrainingConfigWidget->resize(711, 508);
        label = new QLabel(TrainingConfigWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 60, 131, 16));
        label_2 = new QLabel(TrainingConfigWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 90, 141, 16));
        label_3 = new QLabel(TrainingConfigWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 120, 141, 16));
        label_4 = new QLabel(TrainingConfigWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 10, 651, 30));
        label_4->setStyleSheet(QStringLiteral("font: 75 bold italic 16pt \"Ubuntu\";"));
        label_4->setAlignment(Qt::AlignCenter);
        txDatasetName = new QLineEdit(TrainingConfigWidget);
        txDatasetName->setObjectName(QStringLiteral("txDatasetName"));
        txDatasetName->setGeometry(QRect(200, 60, 480, 22));
        txInfoText = new QLineEdit(TrainingConfigWidget);
        txInfoText->setObjectName(QStringLiteral("txInfoText"));
        txInfoText->setGeometry(QRect(200, 90, 480, 22));
        gesturesTable = new QTableWidget(TrainingConfigWidget);
        if (gesturesTable->columnCount() < 4)
            gesturesTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        gesturesTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        gesturesTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        gesturesTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        gesturesTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (gesturesTable->rowCount() < 3)
            gesturesTable->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        gesturesTable->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        gesturesTable->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        gesturesTable->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        gesturesTable->setItem(0, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        gesturesTable->setItem(0, 1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        gesturesTable->setItem(0, 2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        gesturesTable->setItem(0, 3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        gesturesTable->setItem(1, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        gesturesTable->setItem(1, 1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        gesturesTable->setItem(1, 2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        gesturesTable->setItem(1, 3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        gesturesTable->setItem(2, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        gesturesTable->setItem(2, 1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        gesturesTable->setItem(2, 2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        gesturesTable->setItem(2, 3, __qtablewidgetitem18);
        gesturesTable->setObjectName(QStringLiteral("gesturesTable"));
        gesturesTable->setGeometry(QRect(10, 180, 591, 251));
        gesturesTable->setAlternatingRowColors(true);
        gesturesTable->horizontalHeader()->setDefaultSectionSize(122);
        gesturesTable->horizontalHeader()->setStretchLastSection(true);
        gesturesTable->verticalHeader()->setVisible(false);
        btAdd = new QPushButton(TrainingConfigWidget);
        btAdd->setObjectName(QStringLiteral("btAdd"));
        btAdd->setGeometry(QRect(610, 180, 80, 50));
        btRemove = new QPushButton(TrainingConfigWidget);
        btRemove->setObjectName(QStringLiteral("btRemove"));
        btRemove->setGeometry(QRect(610, 240, 80, 50));
        btStart = new QPushButton(TrainingConfigWidget);
        btStart->setObjectName(QStringLiteral("btStart"));
        btStart->setGeometry(QRect(10, 440, 690, 60));
        btStart->setStyleSheet(QStringLiteral("font: 75 14pt \"Ubuntu\";"));
        num_dimension = new QSpinBox(TrainingConfigWidget);
        num_dimension->setObjectName(QStringLiteral("num_dimension"));
        num_dimension->setGeometry(QRect(200, 120, 51, 30));
        num_dimension->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        num_dimension->setMinimum(1);
        num_dimension->setValue(4);

        retranslateUi(TrainingConfigWidget);

        QMetaObject::connectSlotsByName(TrainingConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *TrainingConfigWidget)
    {
        TrainingConfigWidget->setWindowTitle(QString());
        label->setText(QApplication::translate("TrainingConfigWidget", "Dataset Name", 0));
        label_2->setText(QApplication::translate("TrainingConfigWidget", "Information Text", 0));
        label_3->setText(QApplication::translate("TrainingConfigWidget", "Number of Dimensions", 0));
        label_4->setText(QApplication::translate("TrainingConfigWidget", "Recording Configuration", 0));
        txDatasetName->setPlaceholderText(QApplication::translate("TrainingConfigWidget", "don't use space char here", 0));
        txInfoText->setPlaceholderText(QApplication::translate("TrainingConfigWidget", "this may contain space char", 0));
        QTableWidgetItem *___qtablewidgetitem = gesturesTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("TrainingConfigWidget", "ID", 0));
        QTableWidgetItem *___qtablewidgetitem1 = gesturesTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("TrainingConfigWidget", "Gesture Name", 0));
        QTableWidgetItem *___qtablewidgetitem2 = gesturesTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("TrainingConfigWidget", "Required Sample", 0));
        QTableWidgetItem *___qtablewidgetitem3 = gesturesTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("TrainingConfigWidget", "Command", 0));
        QTableWidgetItem *___qtablewidgetitem4 = gesturesTable->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("TrainingConfigWidget", "New Row", 0));
        QTableWidgetItem *___qtablewidgetitem5 = gesturesTable->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("TrainingConfigWidget", "New Row", 0));
        QTableWidgetItem *___qtablewidgetitem6 = gesturesTable->verticalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("TrainingConfigWidget", "New Row", 0));

        const bool __sortingEnabled = gesturesTable->isSortingEnabled();
        gesturesTable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem7 = gesturesTable->item(0, 0);
        ___qtablewidgetitem7->setText(QApplication::translate("TrainingConfigWidget", "1", 0));
        QTableWidgetItem *___qtablewidgetitem8 = gesturesTable->item(0, 1);
        ___qtablewidgetitem8->setText(QApplication::translate("TrainingConfigWidget", "forehand", 0));
        QTableWidgetItem *___qtablewidgetitem9 = gesturesTable->item(0, 2);
        ___qtablewidgetitem9->setText(QApplication::translate("TrainingConfigWidget", "5", 0));
        QTableWidgetItem *___qtablewidgetitem10 = gesturesTable->item(0, 3);
        ___qtablewidgetitem10->setText(QApplication::translate("TrainingConfigWidget", "do forehand shot", 0));
        QTableWidgetItem *___qtablewidgetitem11 = gesturesTable->item(1, 0);
        ___qtablewidgetitem11->setText(QApplication::translate("TrainingConfigWidget", "2", 0));
        QTableWidgetItem *___qtablewidgetitem12 = gesturesTable->item(1, 1);
        ___qtablewidgetitem12->setText(QApplication::translate("TrainingConfigWidget", "backhand", 0));
        QTableWidgetItem *___qtablewidgetitem13 = gesturesTable->item(1, 2);
        ___qtablewidgetitem13->setText(QApplication::translate("TrainingConfigWidget", "5", 0));
        QTableWidgetItem *___qtablewidgetitem14 = gesturesTable->item(1, 3);
        ___qtablewidgetitem14->setText(QApplication::translate("TrainingConfigWidget", "do backhand shot", 0));
        QTableWidgetItem *___qtablewidgetitem15 = gesturesTable->item(2, 0);
        ___qtablewidgetitem15->setText(QApplication::translate("TrainingConfigWidget", "3", 0));
        QTableWidgetItem *___qtablewidgetitem16 = gesturesTable->item(2, 1);
        ___qtablewidgetitem16->setText(QApplication::translate("TrainingConfigWidget", "service", 0));
        QTableWidgetItem *___qtablewidgetitem17 = gesturesTable->item(2, 2);
        ___qtablewidgetitem17->setText(QApplication::translate("TrainingConfigWidget", "5", 0));
        QTableWidgetItem *___qtablewidgetitem18 = gesturesTable->item(2, 3);
        ___qtablewidgetitem18->setText(QApplication::translate("TrainingConfigWidget", "do service shot", 0));
        gesturesTable->setSortingEnabled(__sortingEnabled);

        btAdd->setText(QApplication::translate("TrainingConfigWidget", "&Add", 0));
        btRemove->setText(QApplication::translate("TrainingConfigWidget", "&Remove", 0));
        btStart->setText(QApplication::translate("TrainingConfigWidget", "Start Recording Now", 0));
        num_dimension->setSuffix(QString());
    } // retranslateUi

};

namespace Ui {
    class TrainingConfigWidget: public Ui_TrainingConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TRAININGCONFIGWIDGETLH2229_H
