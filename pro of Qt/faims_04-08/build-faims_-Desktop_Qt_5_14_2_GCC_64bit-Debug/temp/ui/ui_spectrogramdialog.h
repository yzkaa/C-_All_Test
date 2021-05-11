/********************************************************************************
** Form generated from reading UI file 'spectrogramdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPECTROGRAMDIALOG_H
#define UI_SPECTROGRAMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpectrogramDialog
{
public:
    QHBoxLayout *Layout_mainWidget;
    QWidget *widget_functionArea;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_changeAxis;
    QGridLayout *Layout_ChangeAxis;
    QGridLayout *Layout_XYAxisInPut;
    QLabel *label;
    QLineEdit *lineEdit_xStart;
    QLabel *label_2;
    QLineEdit *lineEdit_yEnd;
    QLineEdit *lineEdit_xEnd;
    QLineEdit *lineEdit_yStart;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_Change;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_DisplayEnhancement;
    QHBoxLayout *Layout_DisplayEnhancement;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *comboBox_Enhance;
    QGroupBox *groupBox_DisplayOptimization;
    QGridLayout *Layout_DisplayOptimization;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QComboBox *comboBox_BackgroundColorSelect;
    QLabel *label_9;
    QComboBox *comboBox_DataClearMode;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_Remove;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_Back;
    QHBoxLayout *Layout_Openbutton;
    QPushButton *pushButton_OpenFile;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_SaveSpectrogram;
    QWidget *widget_drawArea;

    void setupUi(QDialog *SpectrogramDialog)
    {
        if (SpectrogramDialog->objectName().isEmpty())
            SpectrogramDialog->setObjectName(QString::fromUtf8("SpectrogramDialog"));
        SpectrogramDialog->resize(472, 434);
        Layout_mainWidget = new QHBoxLayout(SpectrogramDialog);
        Layout_mainWidget->setObjectName(QString::fromUtf8("Layout_mainWidget"));
        widget_functionArea = new QWidget(SpectrogramDialog);
        widget_functionArea->setObjectName(QString::fromUtf8("widget_functionArea"));
        verticalLayout = new QVBoxLayout(widget_functionArea);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_changeAxis = new QGroupBox(widget_functionArea);
        groupBox_changeAxis->setObjectName(QString::fromUtf8("groupBox_changeAxis"));
        Layout_ChangeAxis = new QGridLayout(groupBox_changeAxis);
        Layout_ChangeAxis->setObjectName(QString::fromUtf8("Layout_ChangeAxis"));
        Layout_XYAxisInPut = new QGridLayout();
        Layout_XYAxisInPut->setObjectName(QString::fromUtf8("Layout_XYAxisInPut"));
        label = new QLabel(groupBox_changeAxis);
        label->setObjectName(QString::fromUtf8("label"));

        Layout_XYAxisInPut->addWidget(label, 0, 0, 1, 1);

        lineEdit_xStart = new QLineEdit(groupBox_changeAxis);
        lineEdit_xStart->setObjectName(QString::fromUtf8("lineEdit_xStart"));

        Layout_XYAxisInPut->addWidget(lineEdit_xStart, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_changeAxis);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        Layout_XYAxisInPut->addWidget(label_2, 0, 2, 1, 1);

        lineEdit_yEnd = new QLineEdit(groupBox_changeAxis);
        lineEdit_yEnd->setObjectName(QString::fromUtf8("lineEdit_yEnd"));

        Layout_XYAxisInPut->addWidget(lineEdit_yEnd, 1, 3, 1, 1);

        lineEdit_xEnd = new QLineEdit(groupBox_changeAxis);
        lineEdit_xEnd->setObjectName(QString::fromUtf8("lineEdit_xEnd"));

        Layout_XYAxisInPut->addWidget(lineEdit_xEnd, 0, 3, 1, 1);

        lineEdit_yStart = new QLineEdit(groupBox_changeAxis);
        lineEdit_yStart->setObjectName(QString::fromUtf8("lineEdit_yStart"));

        Layout_XYAxisInPut->addWidget(lineEdit_yStart, 1, 1, 1, 1);

        label_5 = new QLabel(groupBox_changeAxis);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        Layout_XYAxisInPut->addWidget(label_5, 1, 2, 1, 1);

        label_6 = new QLabel(groupBox_changeAxis);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        Layout_XYAxisInPut->addWidget(label_6, 1, 0, 1, 1);


        Layout_ChangeAxis->addLayout(Layout_XYAxisInPut, 0, 0, 1, 2);

        pushButton_Change = new QPushButton(groupBox_changeAxis);
        pushButton_Change->setObjectName(QString::fromUtf8("pushButton_Change"));

        Layout_ChangeAxis->addWidget(pushButton_Change, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(93, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Layout_ChangeAxis->addItem(horizontalSpacer, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox_changeAxis);

        groupBox_DisplayEnhancement = new QGroupBox(widget_functionArea);
        groupBox_DisplayEnhancement->setObjectName(QString::fromUtf8("groupBox_DisplayEnhancement"));
        Layout_DisplayEnhancement = new QHBoxLayout(groupBox_DisplayEnhancement);
        Layout_DisplayEnhancement->setObjectName(QString::fromUtf8("Layout_DisplayEnhancement"));
        label_7 = new QLabel(groupBox_DisplayEnhancement);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        Layout_DisplayEnhancement->addWidget(label_7);

        horizontalSpacer_2 = new QSpacerItem(75, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Layout_DisplayEnhancement->addItem(horizontalSpacer_2);

        comboBox_Enhance = new QComboBox(groupBox_DisplayEnhancement);
        comboBox_Enhance->setObjectName(QString::fromUtf8("comboBox_Enhance"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_Enhance->sizePolicy().hasHeightForWidth());
        comboBox_Enhance->setSizePolicy(sizePolicy);

        Layout_DisplayEnhancement->addWidget(comboBox_Enhance);


        verticalLayout->addWidget(groupBox_DisplayEnhancement);

        groupBox_DisplayOptimization = new QGroupBox(widget_functionArea);
        groupBox_DisplayOptimization->setObjectName(QString::fromUtf8("groupBox_DisplayOptimization"));
        Layout_DisplayOptimization = new QGridLayout(groupBox_DisplayOptimization);
        Layout_DisplayOptimization->setObjectName(QString::fromUtf8("Layout_DisplayOptimization"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_8 = new QLabel(groupBox_DisplayOptimization);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        comboBox_BackgroundColorSelect = new QComboBox(groupBox_DisplayOptimization);
        comboBox_BackgroundColorSelect->setObjectName(QString::fromUtf8("comboBox_BackgroundColorSelect"));

        gridLayout->addWidget(comboBox_BackgroundColorSelect, 0, 2, 1, 1);

        label_9 = new QLabel(groupBox_DisplayOptimization);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 1, 0, 1, 1);

        comboBox_DataClearMode = new QComboBox(groupBox_DisplayOptimization);
        comboBox_DataClearMode->setObjectName(QString::fromUtf8("comboBox_DataClearMode"));

        gridLayout->addWidget(comboBox_DataClearMode, 1, 2, 1, 1);

        label_10 = new QLabel(groupBox_DisplayOptimization);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 2, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(groupBox_DisplayOptimization);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        gridLayout->addWidget(doubleSpinBox, 2, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 1, 1, 1);


        Layout_DisplayOptimization->addLayout(gridLayout, 0, 0, 1, 3);

        pushButton_Remove = new QPushButton(groupBox_DisplayOptimization);
        pushButton_Remove->setObjectName(QString::fromUtf8("pushButton_Remove"));

        Layout_DisplayOptimization->addWidget(pushButton_Remove, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(9, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Layout_DisplayOptimization->addItem(horizontalSpacer_3, 1, 1, 1, 1);

        pushButton_Back = new QPushButton(groupBox_DisplayOptimization);
        pushButton_Back->setObjectName(QString::fromUtf8("pushButton_Back"));

        Layout_DisplayOptimization->addWidget(pushButton_Back, 1, 2, 1, 1);


        verticalLayout->addWidget(groupBox_DisplayOptimization);

        Layout_Openbutton = new QHBoxLayout();
        Layout_Openbutton->setObjectName(QString::fromUtf8("Layout_Openbutton"));
        pushButton_OpenFile = new QPushButton(widget_functionArea);
        pushButton_OpenFile->setObjectName(QString::fromUtf8("pushButton_OpenFile"));

        Layout_Openbutton->addWidget(pushButton_OpenFile);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Layout_Openbutton->addItem(horizontalSpacer_4);

        pushButton_SaveSpectrogram = new QPushButton(widget_functionArea);
        pushButton_SaveSpectrogram->setObjectName(QString::fromUtf8("pushButton_SaveSpectrogram"));

        Layout_Openbutton->addWidget(pushButton_SaveSpectrogram);


        verticalLayout->addLayout(Layout_Openbutton);


        Layout_mainWidget->addWidget(widget_functionArea);

        widget_drawArea = new QWidget(SpectrogramDialog);
        widget_drawArea->setObjectName(QString::fromUtf8("widget_drawArea"));

        Layout_mainWidget->addWidget(widget_drawArea);

        Layout_mainWidget->setStretch(0, 1);
        Layout_mainWidget->setStretch(1, 3);

        retranslateUi(SpectrogramDialog);

        QMetaObject::connectSlotsByName(SpectrogramDialog);
    } // setupUi

    void retranslateUi(QDialog *SpectrogramDialog)
    {
        SpectrogramDialog->setWindowTitle(QCoreApplication::translate("SpectrogramDialog", "Dialog", nullptr));
        groupBox_changeAxis->setTitle(QCoreApplication::translate("SpectrogramDialog", "Change Axis", nullptr));
        label->setText(QCoreApplication::translate("SpectrogramDialog", "X:start", nullptr));
        label_2->setText(QCoreApplication::translate("SpectrogramDialog", "end", nullptr));
        label_5->setText(QCoreApplication::translate("SpectrogramDialog", "end", nullptr));
        label_6->setText(QCoreApplication::translate("SpectrogramDialog", "Y:start", nullptr));
        pushButton_Change->setText(QCoreApplication::translate("SpectrogramDialog", "Change", nullptr));
        groupBox_DisplayEnhancement->setTitle(QCoreApplication::translate("SpectrogramDialog", "Display enhancement", nullptr));
        label_7->setText(QCoreApplication::translate("SpectrogramDialog", "Enhance", nullptr));
        groupBox_DisplayOptimization->setTitle(QCoreApplication::translate("SpectrogramDialog", "Display Optimization ", nullptr));
        label_8->setText(QCoreApplication::translate("SpectrogramDialog", "Background Color Select:", nullptr));
        label_9->setText(QCoreApplication::translate("SpectrogramDialog", "Noise Data Clear Mode:", nullptr));
        label_10->setText(QCoreApplication::translate("SpectrogramDialog", "Clear Start In:", nullptr));
        pushButton_Remove->setText(QCoreApplication::translate("SpectrogramDialog", "Remove", nullptr));
        pushButton_Back->setText(QCoreApplication::translate("SpectrogramDialog", "Back", nullptr));
        pushButton_OpenFile->setText(QCoreApplication::translate("SpectrogramDialog", "Open file", nullptr));
        pushButton_SaveSpectrogram->setText(QCoreApplication::translate("SpectrogramDialog", "Save Spectrogram", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpectrogramDialog: public Ui_SpectrogramDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPECTROGRAMDIALOG_H
