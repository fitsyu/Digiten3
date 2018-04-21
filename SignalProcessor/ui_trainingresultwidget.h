/********************************************************************************
** Form generated from reading UI file 'trainingresultwidgetwZ2229.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TRAININGRESULTWIDGETWZ2229_H
#define TRAININGRESULTWIDGETWZ2229_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrainingResultWidget
{
public:
    QFrame *frame;
    QCheckBox *cbAB;
    QCheckBox *cbBAG;
    QCheckBox *cbDT;
    QCheckBox *cbDTW;
    QCheckBox *cbFSM;
    QCheckBox *cbGMM;
    QCheckBox *cbHMMC;
    QCheckBox *cbHMMD;
    QCheckBox *cbKNN;
    QCheckBox *cbMD;
    QCheckBox *cbRF;
    QCheckBox *cbSM;
    QCheckBox *cbSVM;
    QCheckBox *cbANBC;
    QProgressBar *pbAB;
    QProgressBar *pbANBC;
    QProgressBar *pbBAG;
    QProgressBar *pbDT;
    QProgressBar *pbDTW;
    QProgressBar *pbFSM;
    QProgressBar *pbGMM;
    QProgressBar *pbHMMC;
    QProgressBar *pbHMMD;
    QProgressBar *pbKNN;
    QProgressBar *pbRF;
    QProgressBar *pbSM;
    QProgressBar *pbMD;
    QProgressBar *pbSVM;
    QLabel *tAB;
    QLabel *accAB;
    QLabel *tANBC;
    QLabel *accANBC;
    QLabel *tBAG;
    QLabel *accBAG;
    QLabel *tDT;
    QLabel *tFSM;
    QLabel *accFSM;
    QLabel *tDTW;
    QLabel *accDTW;
    QLabel *accDT;
    QLabel *tGMM;
    QLabel *tHMMD;
    QLabel *accHMMD;
    QLabel *tHMMC;
    QLabel *accHMMC;
    QLabel *accGMM;
    QLabel *tKNN;
    QLabel *tRF;
    QLabel *accRF;
    QLabel *tMD;
    QLabel *accMD;
    QLabel *accKNN;
    QLabel *tSVM;
    QLabel *accSVM;
    QLabel *tSM;
    QLabel *accSM;
    QPushButton *uDTW;
    QPushButton *uHMMC;
    QPushButton *uGMM;
    QPushButton *uFSM;
    QPushButton *uHMMD;
    QPushButton *uKNN;
    QPushButton *uRF;
    QPushButton *uMD;
    QPushButton *uAB;
    QPushButton *uANBC;
    QPushButton *uDT;
    QPushButton *uBAG;
    QPushButton *uSVM;
    QPushButton *uSM;
    QPushButton *btSelectAll;
    QPushButton *btStartTesting;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *lbTestFileName;
    QPushButton *btTrainAgain;

    void setupUi(QWidget *TrainingResultWidget)
    {
        if (TrainingResultWidget->objectName().isEmpty())
            TrainingResultWidget->setObjectName(QStringLiteral("TrainingResultWidget"));
        TrainingResultWidget->resize(751, 637);
        frame = new QFrame(TrainingResultWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(30, 110, 690, 450));
        frame->setStyleSheet(QLatin1String("#frame\n"
"{\n"
"border-width: 2;\n"
"border-style: solid;\n"
"border-color: rgb(255, 170, 0);\n"
"\n"
"}\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        cbAB = new QCheckBox(frame);
        cbAB->setObjectName(QStringLiteral("cbAB"));
        cbAB->setEnabled(false);
        cbAB->setGeometry(QRect(20, 20, 150, 20));
        cbBAG = new QCheckBox(frame);
        cbBAG->setObjectName(QStringLiteral("cbBAG"));
        cbBAG->setEnabled(false);
        cbBAG->setGeometry(QRect(20, 80, 150, 20));
        cbDT = new QCheckBox(frame);
        cbDT->setObjectName(QStringLiteral("cbDT"));
        cbDT->setEnabled(false);
        cbDT->setGeometry(QRect(20, 110, 150, 20));
        cbDTW = new QCheckBox(frame);
        cbDTW->setObjectName(QStringLiteral("cbDTW"));
        cbDTW->setGeometry(QRect(20, 140, 150, 20));
        cbDTW->setChecked(true);
        cbFSM = new QCheckBox(frame);
        cbFSM->setObjectName(QStringLiteral("cbFSM"));
        cbFSM->setGeometry(QRect(20, 170, 150, 20));
        cbGMM = new QCheckBox(frame);
        cbGMM->setObjectName(QStringLiteral("cbGMM"));
        cbGMM->setGeometry(QRect(20, 200, 150, 20));
        cbHMMC = new QCheckBox(frame);
        cbHMMC->setObjectName(QStringLiteral("cbHMMC"));
        cbHMMC->setGeometry(QRect(20, 230, 150, 20));
        cbHMMC->setChecked(true);
        cbHMMD = new QCheckBox(frame);
        cbHMMD->setObjectName(QStringLiteral("cbHMMD"));
        cbHMMD->setGeometry(QRect(20, 260, 150, 20));
        cbKNN = new QCheckBox(frame);
        cbKNN->setObjectName(QStringLiteral("cbKNN"));
        cbKNN->setGeometry(QRect(20, 290, 150, 20));
        cbMD = new QCheckBox(frame);
        cbMD->setObjectName(QStringLiteral("cbMD"));
        cbMD->setGeometry(QRect(20, 320, 150, 20));
        cbRF = new QCheckBox(frame);
        cbRF->setObjectName(QStringLiteral("cbRF"));
        cbRF->setGeometry(QRect(20, 350, 150, 20));
        cbSM = new QCheckBox(frame);
        cbSM->setObjectName(QStringLiteral("cbSM"));
        cbSM->setGeometry(QRect(20, 380, 150, 20));
        cbSVM = new QCheckBox(frame);
        cbSVM->setObjectName(QStringLiteral("cbSVM"));
        cbSVM->setGeometry(QRect(20, 410, 150, 20));
        cbANBC = new QCheckBox(frame);
        cbANBC->setObjectName(QStringLiteral("cbANBC"));
        cbANBC->setGeometry(QRect(20, 50, 150, 20));
        pbAB = new QProgressBar(frame);
        pbAB->setObjectName(QStringLiteral("pbAB"));
        pbAB->setGeometry(QRect(180, 20, 290, 20));
        pbAB->setValue(0);
        pbANBC = new QProgressBar(frame);
        pbANBC->setObjectName(QStringLiteral("pbANBC"));
        pbANBC->setGeometry(QRect(180, 50, 290, 20));
        pbANBC->setValue(0);
        pbBAG = new QProgressBar(frame);
        pbBAG->setObjectName(QStringLiteral("pbBAG"));
        pbBAG->setGeometry(QRect(180, 80, 290, 20));
        pbBAG->setValue(0);
        pbDT = new QProgressBar(frame);
        pbDT->setObjectName(QStringLiteral("pbDT"));
        pbDT->setGeometry(QRect(180, 110, 290, 20));
        pbDT->setValue(0);
        pbDTW = new QProgressBar(frame);
        pbDTW->setObjectName(QStringLiteral("pbDTW"));
        pbDTW->setGeometry(QRect(180, 140, 290, 20));
        pbDTW->setValue(0);
        pbFSM = new QProgressBar(frame);
        pbFSM->setObjectName(QStringLiteral("pbFSM"));
        pbFSM->setGeometry(QRect(180, 170, 290, 20));
        pbFSM->setValue(0);
        pbGMM = new QProgressBar(frame);
        pbGMM->setObjectName(QStringLiteral("pbGMM"));
        pbGMM->setGeometry(QRect(180, 200, 290, 20));
        pbGMM->setValue(0);
        pbHMMC = new QProgressBar(frame);
        pbHMMC->setObjectName(QStringLiteral("pbHMMC"));
        pbHMMC->setGeometry(QRect(180, 230, 290, 20));
        pbHMMC->setValue(0);
        pbHMMD = new QProgressBar(frame);
        pbHMMD->setObjectName(QStringLiteral("pbHMMD"));
        pbHMMD->setGeometry(QRect(180, 260, 290, 20));
        pbHMMD->setValue(0);
        pbKNN = new QProgressBar(frame);
        pbKNN->setObjectName(QStringLiteral("pbKNN"));
        pbKNN->setGeometry(QRect(180, 290, 290, 20));
        pbKNN->setValue(0);
        pbRF = new QProgressBar(frame);
        pbRF->setObjectName(QStringLiteral("pbRF"));
        pbRF->setGeometry(QRect(180, 350, 290, 20));
        pbRF->setValue(0);
        pbSM = new QProgressBar(frame);
        pbSM->setObjectName(QStringLiteral("pbSM"));
        pbSM->setGeometry(QRect(180, 380, 290, 20));
        pbSM->setValue(0);
        pbMD = new QProgressBar(frame);
        pbMD->setObjectName(QStringLiteral("pbMD"));
        pbMD->setGeometry(QRect(180, 320, 290, 20));
        pbMD->setValue(0);
        pbSVM = new QProgressBar(frame);
        pbSVM->setObjectName(QStringLiteral("pbSVM"));
        pbSVM->setGeometry(QRect(180, 410, 290, 20));
        pbSVM->setValue(0);
        tAB = new QLabel(frame);
        tAB->setObjectName(QStringLiteral("tAB"));
        tAB->setGeometry(QRect(540, 20, 50, 20));
        tAB->setStyleSheet(QStringLiteral("font: 75 12pt \"Ubuntu\";"));
        accAB = new QLabel(frame);
        accAB->setObjectName(QStringLiteral("accAB"));
        accAB->setGeometry(QRect(480, 20, 50, 20));
        accAB->setStyleSheet(QStringLiteral("font: 75 12pt  \"Ubuntu\";"));
        tANBC = new QLabel(frame);
        tANBC->setObjectName(QStringLiteral("tANBC"));
        tANBC->setGeometry(QRect(540, 50, 50, 20));
        tANBC->setStyleSheet(QStringLiteral("font: 75 12pt \"Ubuntu\";"));
        accANBC = new QLabel(frame);
        accANBC->setObjectName(QStringLiteral("accANBC"));
        accANBC->setGeometry(QRect(480, 50, 50, 20));
        accANBC->setStyleSheet(QStringLiteral("font: 75 12pt  \"Ubuntu\";"));
        tBAG = new QLabel(frame);
        tBAG->setObjectName(QStringLiteral("tBAG"));
        tBAG->setGeometry(QRect(540, 80, 50, 20));
        tBAG->setStyleSheet(QStringLiteral("font: 75 12pt \"Ubuntu\";"));
        accBAG = new QLabel(frame);
        accBAG->setObjectName(QStringLiteral("accBAG"));
        accBAG->setGeometry(QRect(480, 80, 50, 20));
        accBAG->setStyleSheet(QStringLiteral("font: 75 12pt  \"Ubuntu\";"));
        tDT = new QLabel(frame);
        tDT->setObjectName(QStringLiteral("tDT"));
        tDT->setGeometry(QRect(540, 110, 50, 20));
        tDT->setStyleSheet(QStringLiteral("font: 75 12pt \"Ubuntu\";"));
        tFSM = new QLabel(frame);
        tFSM->setObjectName(QStringLiteral("tFSM"));
        tFSM->setGeometry(QRect(540, 170, 50, 20));
        tFSM->setStyleSheet(QStringLiteral("font: 75 12pt \"Ubuntu\";"));
        accFSM = new QLabel(frame);
        accFSM->setObjectName(QStringLiteral("accFSM"));
        accFSM->setGeometry(QRect(480, 170, 50, 20));
        accFSM->setStyleSheet(QStringLiteral("font: 75 12pt  \"Ubuntu\";"));
        tDTW = new QLabel(frame);
        tDTW->setObjectName(QStringLiteral("tDTW"));
        tDTW->setGeometry(QRect(540, 140, 50, 20));
        tDTW->setStyleSheet(QStringLiteral("font: 75 12pt \"Ubuntu\";"));
        accDTW = new QLabel(frame);
        accDTW->setObjectName(QStringLiteral("accDTW"));
        accDTW->setGeometry(QRect(480, 140, 50, 20));
        accDTW->setStyleSheet(QStringLiteral("font: 75 12pt  \"Ubuntu\";"));
        accDT = new QLabel(frame);
        accDT->setObjectName(QStringLiteral("accDT"));
        accDT->setGeometry(QRect(480, 110, 50, 20));
        accDT->setStyleSheet(QStringLiteral("font: 75 12pt  \"Ubuntu\";"));
        tGMM = new QLabel(frame);
        tGMM->setObjectName(QStringLiteral("tGMM"));
        tGMM->setGeometry(QRect(540, 200, 50, 20));
        tGMM->setStyleSheet(QStringLiteral("font: 75 12pt \"Ubuntu\";"));
        tHMMD = new QLabel(frame);
        tHMMD->setObjectName(QStringLiteral("tHMMD"));
        tHMMD->setGeometry(QRect(540, 260, 50, 20));
        tHMMD->setStyleSheet(QStringLiteral("font: 75 12pt \"Ubuntu\";"));
        accHMMD = new QLabel(frame);
        accHMMD->setObjectName(QStringLiteral("accHMMD"));
        accHMMD->setGeometry(QRect(480, 260, 50, 20));
        accHMMD->setStyleSheet(QStringLiteral("font: 75 12pt  \"Ubuntu\";"));
        tHMMC = new QLabel(frame);
        tHMMC->setObjectName(QStringLiteral("tHMMC"));
        tHMMC->setGeometry(QRect(540, 230, 50, 20));
        tHMMC->setStyleSheet(QStringLiteral("font: 75 12pt \"Ubuntu\";"));
        accHMMC = new QLabel(frame);
        accHMMC->setObjectName(QStringLiteral("accHMMC"));
        accHMMC->setGeometry(QRect(480, 230, 50, 20));
        accHMMC->setStyleSheet(QStringLiteral("font: 75 12pt  \"Ubuntu\";"));
        accGMM = new QLabel(frame);
        accGMM->setObjectName(QStringLiteral("accGMM"));
        accGMM->setGeometry(QRect(480, 200, 50, 20));
        accGMM->setStyleSheet(QStringLiteral("font: 75 12pt  \"Ubuntu\";"));
        tKNN = new QLabel(frame);
        tKNN->setObjectName(QStringLiteral("tKNN"));
        tKNN->setGeometry(QRect(540, 290, 50, 20));
        tKNN->setStyleSheet(QStringLiteral("font: 75 12pt \"Ubuntu\";"));
        tRF = new QLabel(frame);
        tRF->setObjectName(QStringLiteral("tRF"));
        tRF->setGeometry(QRect(540, 350, 50, 20));
        tRF->setStyleSheet(QStringLiteral("font: 75 12pt \"Ubuntu\";"));
        accRF = new QLabel(frame);
        accRF->setObjectName(QStringLiteral("accRF"));
        accRF->setGeometry(QRect(480, 350, 50, 20));
        accRF->setStyleSheet(QStringLiteral("font: 75 12pt  \"Ubuntu\";"));
        tMD = new QLabel(frame);
        tMD->setObjectName(QStringLiteral("tMD"));
        tMD->setGeometry(QRect(540, 320, 50, 20));
        tMD->setStyleSheet(QStringLiteral("font: 75 12pt \"Ubuntu\";"));
        accMD = new QLabel(frame);
        accMD->setObjectName(QStringLiteral("accMD"));
        accMD->setGeometry(QRect(480, 320, 50, 20));
        accMD->setStyleSheet(QStringLiteral("font: 75 12pt  \"Ubuntu\";"));
        accKNN = new QLabel(frame);
        accKNN->setObjectName(QStringLiteral("accKNN"));
        accKNN->setGeometry(QRect(480, 290, 50, 20));
        accKNN->setStyleSheet(QStringLiteral("font: 75 12pt  \"Ubuntu\";"));
        tSVM = new QLabel(frame);
        tSVM->setObjectName(QStringLiteral("tSVM"));
        tSVM->setGeometry(QRect(540, 410, 50, 20));
        tSVM->setStyleSheet(QStringLiteral("font: 75 12pt \"Ubuntu\";"));
        accSVM = new QLabel(frame);
        accSVM->setObjectName(QStringLiteral("accSVM"));
        accSVM->setGeometry(QRect(480, 410, 50, 20));
        accSVM->setStyleSheet(QStringLiteral("font: 75 12pt  \"Ubuntu\";"));
        tSM = new QLabel(frame);
        tSM->setObjectName(QStringLiteral("tSM"));
        tSM->setGeometry(QRect(540, 380, 50, 20));
        tSM->setStyleSheet(QStringLiteral("font: 75 12pt \"Ubuntu\";"));
        accSM = new QLabel(frame);
        accSM->setObjectName(QStringLiteral("accSM"));
        accSM->setGeometry(QRect(480, 380, 50, 20));
        accSM->setStyleSheet(QStringLiteral("font: 75 12pt  \"Ubuntu\";"));
        uDTW = new QPushButton(frame);
        uDTW->setObjectName(QStringLiteral("uDTW"));
        uDTW->setGeometry(QRect(600, 140, 60, 20));
        uHMMC = new QPushButton(frame);
        uHMMC->setObjectName(QStringLiteral("uHMMC"));
        uHMMC->setGeometry(QRect(600, 230, 60, 20));
        uGMM = new QPushButton(frame);
        uGMM->setObjectName(QStringLiteral("uGMM"));
        uGMM->setGeometry(QRect(600, 200, 60, 20));
        uFSM = new QPushButton(frame);
        uFSM->setObjectName(QStringLiteral("uFSM"));
        uFSM->setGeometry(QRect(600, 170, 60, 20));
        uHMMD = new QPushButton(frame);
        uHMMD->setObjectName(QStringLiteral("uHMMD"));
        uHMMD->setGeometry(QRect(600, 260, 60, 20));
        uKNN = new QPushButton(frame);
        uKNN->setObjectName(QStringLiteral("uKNN"));
        uKNN->setGeometry(QRect(600, 290, 60, 20));
        uRF = new QPushButton(frame);
        uRF->setObjectName(QStringLiteral("uRF"));
        uRF->setGeometry(QRect(600, 350, 60, 20));
        uMD = new QPushButton(frame);
        uMD->setObjectName(QStringLiteral("uMD"));
        uMD->setGeometry(QRect(600, 320, 60, 20));
        uAB = new QPushButton(frame);
        uAB->setObjectName(QStringLiteral("uAB"));
        uAB->setGeometry(QRect(600, 20, 60, 20));
        uANBC = new QPushButton(frame);
        uANBC->setObjectName(QStringLiteral("uANBC"));
        uANBC->setGeometry(QRect(600, 50, 60, 20));
        uDT = new QPushButton(frame);
        uDT->setObjectName(QStringLiteral("uDT"));
        uDT->setGeometry(QRect(600, 110, 60, 20));
        uBAG = new QPushButton(frame);
        uBAG->setObjectName(QStringLiteral("uBAG"));
        uBAG->setGeometry(QRect(600, 80, 60, 20));
        uSVM = new QPushButton(frame);
        uSVM->setObjectName(QStringLiteral("uSVM"));
        uSVM->setGeometry(QRect(600, 410, 60, 20));
        uSM = new QPushButton(frame);
        uSM->setObjectName(QStringLiteral("uSM"));
        uSM->setGeometry(QRect(600, 380, 60, 20));
        btSelectAll = new QPushButton(TrainingResultWidget);
        btSelectAll->setObjectName(QStringLiteral("btSelectAll"));
        btSelectAll->setGeometry(QRect(30, 570, 80, 30));
        btSelectAll->setStyleSheet(QStringLiteral(""));
        btSelectAll->setCheckable(true);
        btStartTesting = new QPushButton(TrainingResultWidget);
        btStartTesting->setObjectName(QStringLiteral("btStartTesting"));
        btStartTesting->setGeometry(QRect(270, 570, 200, 60));
        btStartTesting->setStyleSheet(QStringLiteral("font: italic 14pt \"Ubuntu\";"));
        label_3 = new QLabel(TrainingResultWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 60, 151, 40));
        label_3->setStyleSheet(QStringLiteral("font: 75 20pt \"Ubuntu\";"));
        label_4 = new QLabel(TrainingResultWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(260, 70, 120, 30));
        label_4->setStyleSheet(QStringLiteral("font: 75 16pt \"Ubuntu\";"));
        label_5 = new QLabel(TrainingResultWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(490, 80, 110, 30));
        label_5->setStyleSheet(QStringLiteral("font: 75 20pt \"Ubuntu\";"));
        label_6 = new QLabel(TrainingResultWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(590, 40, 60, 30));
        label_6->setStyleSheet(QStringLiteral("font: 75 14pt \"Ubuntu\";"));
        lbTestFileName = new QLabel(TrainingResultWidget);
        lbTestFileName->setObjectName(QStringLiteral("lbTestFileName"));
        lbTestFileName->setGeometry(QRect(40, 20, 671, 31));
        btTrainAgain = new QPushButton(TrainingResultWidget);
        btTrainAgain->setObjectName(QStringLiteral("btTrainAgain"));
        btTrainAgain->setGeometry(QRect(620, 570, 100, 31));

        retranslateUi(TrainingResultWidget);

        QMetaObject::connectSlotsByName(TrainingResultWidget);
    } // setupUi

    void retranslateUi(QWidget *TrainingResultWidget)
    {
        TrainingResultWidget->setWindowTitle(QApplication::translate("TrainingResultWidget", "Algorithms Training", 0));
        cbAB->setText(QApplication::translate("TrainingResultWidget", "Ada Boost", 0));
        cbBAG->setText(QApplication::translate("TrainingResultWidget", "B AG", 0));
        cbDT->setText(QApplication::translate("TrainingResultWidget", "Decision Tree", 0));
        cbDTW->setText(QApplication::translate("TrainingResultWidget", "DTW", 0));
        cbFSM->setText(QApplication::translate("TrainingResultWidget", "Finite State Machine", 0));
        cbGMM->setText(QApplication::translate("TrainingResultWidget", "GMM", 0));
        cbHMMC->setText(QApplication::translate("TrainingResultWidget", "HMM Continuous", 0));
        cbHMMD->setText(QApplication::translate("TrainingResultWidget", "HMM Discrete", 0));
        cbKNN->setText(QApplication::translate("TrainingResultWidget", "KNN", 0));
        cbMD->setText(QApplication::translate("TrainingResultWidget", "MinDist", 0));
        cbRF->setText(QApplication::translate("TrainingResultWidget", "Random Forest", 0));
        cbSM->setText(QApplication::translate("TrainingResultWidget", "Softmax", 0));
        cbSVM->setText(QApplication::translate("TrainingResultWidget", "SVM", 0));
        cbANBC->setText(QApplication::translate("TrainingResultWidget", "ANBC", 0));
        tAB->setText(QApplication::translate("TrainingResultWidget", "0s", 0));
        accAB->setText(QApplication::translate("TrainingResultWidget", "0%", 0));
        tANBC->setText(QApplication::translate("TrainingResultWidget", "0s", 0));
        accANBC->setText(QApplication::translate("TrainingResultWidget", "0%", 0));
        tBAG->setText(QApplication::translate("TrainingResultWidget", "0s", 0));
        accBAG->setText(QApplication::translate("TrainingResultWidget", "0%", 0));
        tDT->setText(QApplication::translate("TrainingResultWidget", "0s", 0));
        tFSM->setText(QApplication::translate("TrainingResultWidget", "0s", 0));
        accFSM->setText(QApplication::translate("TrainingResultWidget", "0%", 0));
        tDTW->setText(QApplication::translate("TrainingResultWidget", "0s", 0));
        accDTW->setText(QApplication::translate("TrainingResultWidget", "0%", 0));
        accDT->setText(QApplication::translate("TrainingResultWidget", "0%", 0));
        tGMM->setText(QApplication::translate("TrainingResultWidget", "0s", 0));
        tHMMD->setText(QApplication::translate("TrainingResultWidget", "0s", 0));
        accHMMD->setText(QApplication::translate("TrainingResultWidget", "0%", 0));
        tHMMC->setText(QApplication::translate("TrainingResultWidget", "0s", 0));
        accHMMC->setText(QApplication::translate("TrainingResultWidget", "0%", 0));
        accGMM->setText(QApplication::translate("TrainingResultWidget", "0%", 0));
        tKNN->setText(QApplication::translate("TrainingResultWidget", "0s", 0));
        tRF->setText(QApplication::translate("TrainingResultWidget", "0s", 0));
        accRF->setText(QApplication::translate("TrainingResultWidget", "0%", 0));
        tMD->setText(QApplication::translate("TrainingResultWidget", "0s", 0));
        accMD->setText(QApplication::translate("TrainingResultWidget", "0%", 0));
        accKNN->setText(QApplication::translate("TrainingResultWidget", "0%", 0));
        tSVM->setText(QApplication::translate("TrainingResultWidget", "9s", 0));
        accSVM->setText(QApplication::translate("TrainingResultWidget", "100%", 0));
        tSM->setText(QApplication::translate("TrainingResultWidget", "0s", 0));
        accSM->setText(QApplication::translate("TrainingResultWidget", "0%", 0));
        uDTW->setText(QApplication::translate("TrainingResultWidget", "save", 0));
        uHMMC->setText(QApplication::translate("TrainingResultWidget", "save", 0));
        uGMM->setText(QApplication::translate("TrainingResultWidget", "save", 0));
        uFSM->setText(QApplication::translate("TrainingResultWidget", "save", 0));
        uHMMD->setText(QApplication::translate("TrainingResultWidget", "save", 0));
        uKNN->setText(QApplication::translate("TrainingResultWidget", "save", 0));
        uRF->setText(QApplication::translate("TrainingResultWidget", "save", 0));
        uMD->setText(QApplication::translate("TrainingResultWidget", "save", 0));
        uAB->setText(QApplication::translate("TrainingResultWidget", "save", 0));
        uANBC->setText(QApplication::translate("TrainingResultWidget", "save", 0));
        uDT->setText(QApplication::translate("TrainingResultWidget", "save", 0));
        uBAG->setText(QApplication::translate("TrainingResultWidget", "save", 0));
        uSVM->setText(QApplication::translate("TrainingResultWidget", "save", 0));
        uSM->setText(QApplication::translate("TrainingResultWidget", "save", 0));
        btSelectAll->setText(QApplication::translate("TrainingResultWidget", "Select all", 0));
        btStartTesting->setText(QApplication::translate("TrainingResultWidget", "Start testing !", 0));
        label_3->setText(QApplication::translate("TrainingResultWidget", "Algorithms", 0));
        label_4->setText(QApplication::translate("TrainingResultWidget", "Progress", 0));
        label_5->setText(QApplication::translate("TrainingResultWidget", "Accuracy", 0));
        label_6->setText(QApplication::translate("TrainingResultWidget", "Time", 0));
        lbTestFileName->setText(QApplication::translate("TrainingResultWidget", "Test file: ", 0));
        btTrainAgain->setText(QApplication::translate("TrainingResultWidget", "Train again >>", 0));
    } // retranslateUi

};

namespace Ui {
    class TrainingResultWidget: public Ui_TrainingResultWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TRAININGRESULTWIDGETWZ2229_H
