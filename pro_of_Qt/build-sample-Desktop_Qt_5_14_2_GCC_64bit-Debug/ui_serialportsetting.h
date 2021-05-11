/********************************************************************************
** Form generated from reading UI file 'serialportsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORTSETTING_H
#define UI_SERIALPORTSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialPortSetting
{
public:
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
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *searchButton;
    QPushButton *applyButton;

    void setupUi(QDialog *SerialPortSetting)
    {
        if (SerialPortSetting->objectName().isEmpty())
            SerialPortSetting->setObjectName(QString::fromUtf8("SerialPortSetting"));
        SerialPortSetting->resize(390, 310);
        groupBox = new QGroupBox(SerialPortSetting);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(19, 29, 140, 221));
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

        groupBox_2 = new QGroupBox(SerialPortSetting);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(190, 30, 179, 221));
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

        layoutWidget = new QWidget(SerialPortSetting);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 260, 362, 33));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(198, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        searchButton = new QPushButton(layoutWidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setMinimumSize(QSize(75, 31));
        searchButton->setMaximumSize(QSize(75, 31));
        searchButton->setAutoDefault(false);

        horizontalLayout->addWidget(searchButton);

        applyButton = new QPushButton(layoutWidget);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));
        applyButton->setMinimumSize(QSize(75, 31));
        applyButton->setMaximumSize(QSize(75, 31));
        applyButton->setAutoDefault(false);

        horizontalLayout->addWidget(applyButton);


        retranslateUi(SerialPortSetting);

        QMetaObject::connectSlotsByName(SerialPortSetting);
    } // setupUi

    void retranslateUi(QDialog *SerialPortSetting)
    {
        SerialPortSetting->setWindowTitle(QCoreApplication::translate("SerialPortSetting", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SerialPortSetting", "Select Serial Port", nullptr));
        descrptionlabel->setText(QCoreApplication::translate("SerialPortSetting", "Description:", nullptr));
        manufacturerlabel->setText(QCoreApplication::translate("SerialPortSetting", "Manufacturer:", nullptr));
        serialnumberlabel->setText(QCoreApplication::translate("SerialPortSetting", "Serial number:", nullptr));
        locationlabel->setText(QCoreApplication::translate("SerialPortSetting", "Location:", nullptr));
        vidlabel->setText(QCoreApplication::translate("SerialPortSetting", "Vendor ID:", nullptr));
        pidlabel->setText(QCoreApplication::translate("SerialPortSetting", "Product ID:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SerialPortSetting", "Select Parameters", nullptr));
        label->setText(QCoreApplication::translate("SerialPortSetting", "BaudRate:", nullptr));
        label_2->setText(QCoreApplication::translate("SerialPortSetting", "Data bits:", nullptr));
        label_3->setText(QCoreApplication::translate("SerialPortSetting", "Parity:", nullptr));
        label_4->setText(QCoreApplication::translate("SerialPortSetting", "Stop bits:", nullptr));
        label_5->setText(QCoreApplication::translate("SerialPortSetting", "Flow control:", nullptr));
        searchButton->setText(QCoreApplication::translate("SerialPortSetting", "Search", nullptr));
        applyButton->setText(QCoreApplication::translate("SerialPortSetting", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SerialPortSetting: public Ui_SerialPortSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORTSETTING_H
