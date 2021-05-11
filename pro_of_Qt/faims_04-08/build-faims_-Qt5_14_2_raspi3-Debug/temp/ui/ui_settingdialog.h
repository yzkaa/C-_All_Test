/********************************************************************************
** Form generated from reading UI file 'settingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDIALOG_H
#define UI_SETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QComboBox *serialPortInfoListBox;
    QLabel *descrptionlabel;
    QLabel *manufacturerlabel;
    QLabel *serialnumberlabel;
    QLabel *locationlabel;
    QLabel *vidlabel;
    QLabel *pidlabel;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *baudrateBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *databitsBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QComboBox *parityBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QComboBox *stopbitBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QComboBox *flowcontrolBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *searchButton;
    QPushButton *applyButton;

    void setupUi(QDialog *SettingDialog)
    {
        if (SettingDialog->objectName().isEmpty())
            SettingDialog->setObjectName(QString::fromUtf8("SettingDialog"));
        SettingDialog->resize(343, 289);
        gridLayout = new QGridLayout(SettingDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(SettingDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 221));
        groupBox->setMaximumSize(QSize(16777215, 221));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        serialPortInfoListBox = new QComboBox(groupBox);
        serialPortInfoListBox->setObjectName(QString::fromUtf8("serialPortInfoListBox"));
        serialPortInfoListBox->setMinimumSize(QSize(69, 22));
        serialPortInfoListBox->setMaximumSize(QSize(69, 22));

        verticalLayout_2->addWidget(serialPortInfoListBox);

        descrptionlabel = new QLabel(groupBox);
        descrptionlabel->setObjectName(QString::fromUtf8("descrptionlabel"));

        verticalLayout_2->addWidget(descrptionlabel);

        manufacturerlabel = new QLabel(groupBox);
        manufacturerlabel->setObjectName(QString::fromUtf8("manufacturerlabel"));

        verticalLayout_2->addWidget(manufacturerlabel);

        serialnumberlabel = new QLabel(groupBox);
        serialnumberlabel->setObjectName(QString::fromUtf8("serialnumberlabel"));

        verticalLayout_2->addWidget(serialnumberlabel);

        locationlabel = new QLabel(groupBox);
        locationlabel->setObjectName(QString::fromUtf8("locationlabel"));

        verticalLayout_2->addWidget(locationlabel);

        vidlabel = new QLabel(groupBox);
        vidlabel->setObjectName(QString::fromUtf8("vidlabel"));

        verticalLayout_2->addWidget(vidlabel);

        pidlabel = new QLabel(groupBox);
        pidlabel->setObjectName(QString::fromUtf8("pidlabel"));

        verticalLayout_2->addWidget(pidlabel);


        verticalLayout_4->addLayout(verticalLayout_2);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(SettingDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 221));
        groupBox_2->setMaximumSize(QSize(16777215, 221));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        baudrateBox = new QComboBox(groupBox_2);
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->setObjectName(QString::fromUtf8("baudrateBox"));
        baudrateBox->setMinimumSize(QSize(69, 22));
        baudrateBox->setMaximumSize(QSize(69, 22));

        horizontalLayout_2->addWidget(baudrateBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        databitsBox = new QComboBox(groupBox_2);
        databitsBox->addItem(QString());
        databitsBox->addItem(QString());
        databitsBox->addItem(QString());
        databitsBox->addItem(QString());
        databitsBox->setObjectName(QString::fromUtf8("databitsBox"));
        databitsBox->setMinimumSize(QSize(69, 22));
        databitsBox->setMaximumSize(QSize(69, 22));

        horizontalLayout_3->addWidget(databitsBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        parityBox = new QComboBox(groupBox_2);
        parityBox->addItem(QString());
        parityBox->setObjectName(QString::fromUtf8("parityBox"));
        parityBox->setMinimumSize(QSize(69, 22));
        parityBox->setMaximumSize(QSize(69, 22));

        horizontalLayout_4->addWidget(parityBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        stopbitBox = new QComboBox(groupBox_2);
        stopbitBox->setObjectName(QString::fromUtf8("stopbitBox"));
        stopbitBox->setMinimumSize(QSize(69, 22));
        stopbitBox->setMaximumSize(QSize(69, 22));

        horizontalLayout_5->addWidget(stopbitBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        flowcontrolBox = new QComboBox(groupBox_2);
        flowcontrolBox->setObjectName(QString::fromUtf8("flowcontrolBox"));
        flowcontrolBox->setMinimumSize(QSize(69, 22));
        flowcontrolBox->setMaximumSize(QSize(69, 22));

        horizontalLayout_6->addWidget(flowcontrolBox);


        verticalLayout->addLayout(horizontalLayout_6);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(198, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        searchButton = new QPushButton(SettingDialog);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setMinimumSize(QSize(75, 31));
        searchButton->setMaximumSize(QSize(75, 31));
        searchButton->setAutoDefault(false);

        horizontalLayout->addWidget(searchButton);

        applyButton = new QPushButton(SettingDialog);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));
        applyButton->setMinimumSize(QSize(75, 31));
        applyButton->setMaximumSize(QSize(75, 31));
        applyButton->setAutoDefault(false);

        horizontalLayout->addWidget(applyButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 2);


        retranslateUi(SettingDialog);

        QMetaObject::connectSlotsByName(SettingDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingDialog)
    {
        SettingDialog->setWindowTitle(QCoreApplication::translate("SettingDialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SettingDialog", "Select Serial Port", nullptr));
        descrptionlabel->setText(QCoreApplication::translate("SettingDialog", "Description:", nullptr));
        manufacturerlabel->setText(QCoreApplication::translate("SettingDialog", "Manufacturer:", nullptr));
        serialnumberlabel->setText(QCoreApplication::translate("SettingDialog", "Serial number:", nullptr));
        locationlabel->setText(QCoreApplication::translate("SettingDialog", "Location:", nullptr));
        vidlabel->setText(QCoreApplication::translate("SettingDialog", "Vendor ID:", nullptr));
        pidlabel->setText(QCoreApplication::translate("SettingDialog", "Product ID:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SettingDialog", "Select Parameters", nullptr));
        label->setText(QCoreApplication::translate("SettingDialog", "BaudRate:", nullptr));
        baudrateBox->setItemText(0, QCoreApplication::translate("SettingDialog", "9600", nullptr));
        baudrateBox->setItemText(1, QCoreApplication::translate("SettingDialog", "19200", nullptr));
        baudrateBox->setItemText(2, QCoreApplication::translate("SettingDialog", "38400", nullptr));
        baudrateBox->setItemText(3, QCoreApplication::translate("SettingDialog", "57600", nullptr));
        baudrateBox->setItemText(4, QCoreApplication::translate("SettingDialog", "115200", nullptr));

        label_2->setText(QCoreApplication::translate("SettingDialog", "Data bits:", nullptr));
        databitsBox->setItemText(0, QCoreApplication::translate("SettingDialog", "5", nullptr));
        databitsBox->setItemText(1, QCoreApplication::translate("SettingDialog", "6", nullptr));
        databitsBox->setItemText(2, QCoreApplication::translate("SettingDialog", "7", nullptr));
        databitsBox->setItemText(3, QCoreApplication::translate("SettingDialog", "8", nullptr));

        label_3->setText(QCoreApplication::translate("SettingDialog", "Parity:", nullptr));
        parityBox->setItemText(0, QCoreApplication::translate("SettingDialog", "None", nullptr));

        label_4->setText(QCoreApplication::translate("SettingDialog", "Stop bits:", nullptr));
        label_5->setText(QCoreApplication::translate("SettingDialog", "Flow control:", nullptr));
        searchButton->setText(QCoreApplication::translate("SettingDialog", "Search", nullptr));
        applyButton->setText(QCoreApplication::translate("SettingDialog", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingDialog: public Ui_SettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
