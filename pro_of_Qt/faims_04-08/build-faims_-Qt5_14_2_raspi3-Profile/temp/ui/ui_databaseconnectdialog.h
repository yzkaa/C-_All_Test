/********************************************************************************
** Form generated from reading UI file 'databaseconnectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASECONNECTDIALOG_H
#define UI_DATABASECONNECTDIALOG_H

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

class Ui_DatabaseConnectDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_userName;
    QLabel *label_2;
    QLineEdit *lineEdit_passWord;
    QLabel *label_3;
    QLineEdit *lineEdit_ip;
    QLabel *label_4;
    QLineEdit *lineEdit_port;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButto_connect;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_quit;

    void setupUi(QDialog *DatabaseConnectDialog)
    {
        if (DatabaseConnectDialog->objectName().isEmpty())
            DatabaseConnectDialog->setObjectName(QString::fromUtf8("DatabaseConnectDialog"));
        DatabaseConnectDialog->resize(309, 171);
        gridLayout = new QGridLayout(DatabaseConnectDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(30, 10, 30, 10);
        label = new QLabel(DatabaseConnectDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_userName = new QLineEdit(DatabaseConnectDialog);
        lineEdit_userName->setObjectName(QString::fromUtf8("lineEdit_userName"));

        gridLayout->addWidget(lineEdit_userName, 0, 1, 1, 1);

        label_2 = new QLabel(DatabaseConnectDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_passWord = new QLineEdit(DatabaseConnectDialog);
        lineEdit_passWord->setObjectName(QString::fromUtf8("lineEdit_passWord"));

        gridLayout->addWidget(lineEdit_passWord, 1, 1, 1, 1);

        label_3 = new QLabel(DatabaseConnectDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_ip = new QLineEdit(DatabaseConnectDialog);
        lineEdit_ip->setObjectName(QString::fromUtf8("lineEdit_ip"));

        gridLayout->addWidget(lineEdit_ip, 2, 1, 1, 1);

        label_4 = new QLabel(DatabaseConnectDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_port = new QLineEdit(DatabaseConnectDialog);
        lineEdit_port->setObjectName(QString::fromUtf8("lineEdit_port"));

        gridLayout->addWidget(lineEdit_port, 3, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButto_connect = new QPushButton(DatabaseConnectDialog);
        pushButto_connect->setObjectName(QString::fromUtf8("pushButto_connect"));

        horizontalLayout->addWidget(pushButto_connect);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_quit = new QPushButton(DatabaseConnectDialog);
        pushButton_quit->setObjectName(QString::fromUtf8("pushButton_quit"));

        horizontalLayout->addWidget(pushButton_quit);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 2);


        retranslateUi(DatabaseConnectDialog);

        QMetaObject::connectSlotsByName(DatabaseConnectDialog);
    } // setupUi

    void retranslateUi(QDialog *DatabaseConnectDialog)
    {
        DatabaseConnectDialog->setWindowTitle(QCoreApplication::translate("DatabaseConnectDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DatabaseConnectDialog", "userName:", nullptr));
        label_2->setText(QCoreApplication::translate("DatabaseConnectDialog", "passWord:", nullptr));
        label_3->setText(QCoreApplication::translate("DatabaseConnectDialog", "IP:", nullptr));
        label_4->setText(QCoreApplication::translate("DatabaseConnectDialog", "port:", nullptr));
        pushButto_connect->setText(QCoreApplication::translate("DatabaseConnectDialog", "set", nullptr));
        pushButton_quit->setText(QCoreApplication::translate("DatabaseConnectDialog", "quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DatabaseConnectDialog: public Ui_DatabaseConnectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASECONNECTDIALOG_H
