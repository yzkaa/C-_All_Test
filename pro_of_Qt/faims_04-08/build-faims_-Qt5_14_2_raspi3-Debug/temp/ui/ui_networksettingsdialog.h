/********************************************************************************
** Form generated from reading UI file 'networksettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKSETTINGSDIALOG_H
#define UI_NETWORKSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_NetworkSettingsDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_currentIP;
    QLabel *label_2;
    QLineEdit *lineEdit_currentPort;
    QLabel *label_3;
    QLineEdit *lineEdit_targetIP;
    QLabel *label_4;
    QLineEdit *lineEdit_targetPort;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButto_connect;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_quit;

    void setupUi(QDialog *NetworkSettingsDialog)
    {
        if (NetworkSettingsDialog->objectName().isEmpty())
            NetworkSettingsDialog->setObjectName(QString::fromUtf8("NetworkSettingsDialog"));
        NetworkSettingsDialog->resize(313, 166);
        gridLayout = new QGridLayout(NetworkSettingsDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(30, 10, 30, 10);
        label = new QLabel(NetworkSettingsDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_currentIP = new QLineEdit(NetworkSettingsDialog);
        lineEdit_currentIP->setObjectName(QString::fromUtf8("lineEdit_currentIP"));

        gridLayout->addWidget(lineEdit_currentIP, 0, 1, 1, 1);

        label_2 = new QLabel(NetworkSettingsDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_currentPort = new QLineEdit(NetworkSettingsDialog);
        lineEdit_currentPort->setObjectName(QString::fromUtf8("lineEdit_currentPort"));

        gridLayout->addWidget(lineEdit_currentPort, 1, 1, 1, 1);

        label_3 = new QLabel(NetworkSettingsDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_targetIP = new QLineEdit(NetworkSettingsDialog);
        lineEdit_targetIP->setObjectName(QString::fromUtf8("lineEdit_targetIP"));

        gridLayout->addWidget(lineEdit_targetIP, 2, 1, 1, 1);

        label_4 = new QLabel(NetworkSettingsDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_targetPort = new QLineEdit(NetworkSettingsDialog);
        lineEdit_targetPort->setObjectName(QString::fromUtf8("lineEdit_targetPort"));

        gridLayout->addWidget(lineEdit_targetPort, 3, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButto_connect = new QPushButton(NetworkSettingsDialog);
        pushButto_connect->setObjectName(QString::fromUtf8("pushButto_connect"));

        horizontalLayout->addWidget(pushButto_connect);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_quit = new QPushButton(NetworkSettingsDialog);
        pushButton_quit->setObjectName(QString::fromUtf8("pushButton_quit"));

        horizontalLayout->addWidget(pushButton_quit);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 2);


        retranslateUi(NetworkSettingsDialog);

        QMetaObject::connectSlotsByName(NetworkSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *NetworkSettingsDialog)
    {
        NetworkSettingsDialog->setWindowTitle(QCoreApplication::translate("NetworkSettingsDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("NetworkSettingsDialog", "currentIP:", nullptr));
        label_2->setText(QCoreApplication::translate("NetworkSettingsDialog", "currentPort:", nullptr));
        label_3->setText(QCoreApplication::translate("NetworkSettingsDialog", "targetIP:", nullptr));
        label_4->setText(QCoreApplication::translate("NetworkSettingsDialog", "targetPort;", nullptr));
        pushButto_connect->setText(QCoreApplication::translate("NetworkSettingsDialog", "set", nullptr));
        pushButton_quit->setText(QCoreApplication::translate("NetworkSettingsDialog", "quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NetworkSettingsDialog: public Ui_NetworkSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKSETTINGSDIALOG_H
