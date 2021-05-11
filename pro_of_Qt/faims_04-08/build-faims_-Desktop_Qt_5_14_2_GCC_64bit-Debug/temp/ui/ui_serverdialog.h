/********************************************************************************
** Form generated from reading UI file 'serverdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERDIALOG_H
#define UI_SERVERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *Layout_topArea;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_ip;
    QLabel *label_2;
    QLineEdit *lineEdit_port;
    QPushButton *pushButton_connect;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_fileSelect;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_send;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_Clear;

    void setupUi(QDialog *ServerDialog)
    {
        if (ServerDialog->objectName().isEmpty())
            ServerDialog->setObjectName(QString::fromUtf8("ServerDialog"));
        ServerDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(ServerDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(ServerDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        Layout_topArea = new QHBoxLayout(widget);
        Layout_topArea->setObjectName(QString::fromUtf8("Layout_topArea"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_ip = new QLineEdit(widget);
        lineEdit_ip->setObjectName(QString::fromUtf8("lineEdit_ip"));

        gridLayout->addWidget(lineEdit_ip, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_port = new QLineEdit(widget);
        lineEdit_port->setObjectName(QString::fromUtf8("lineEdit_port"));

        gridLayout->addWidget(lineEdit_port, 1, 1, 1, 1);


        Layout_topArea->addLayout(gridLayout);

        pushButton_connect = new QPushButton(widget);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));

        Layout_topArea->addWidget(pushButton_connect);


        verticalLayout->addWidget(widget);

        textEdit = new QTextEdit(ServerDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_fileSelect = new QPushButton(ServerDialog);
        pushButton_fileSelect->setObjectName(QString::fromUtf8("pushButton_fileSelect"));

        horizontalLayout->addWidget(pushButton_fileSelect);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_send = new QPushButton(ServerDialog);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));

        horizontalLayout->addWidget(pushButton_send);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_Clear = new QPushButton(ServerDialog);
        pushButton_Clear->setObjectName(QString::fromUtf8("pushButton_Clear"));

        horizontalLayout->addWidget(pushButton_Clear);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ServerDialog);

        QMetaObject::connectSlotsByName(ServerDialog);
    } // setupUi

    void retranslateUi(QDialog *ServerDialog)
    {
        ServerDialog->setWindowTitle(QCoreApplication::translate("ServerDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ServerDialog", "Server IP:", nullptr));
        label_2->setText(QCoreApplication::translate("ServerDialog", "Port\357\274\232", nullptr));
        pushButton_connect->setText(QCoreApplication::translate("ServerDialog", "connect", nullptr));
        pushButton_fileSelect->setText(QCoreApplication::translate("ServerDialog", "File select", nullptr));
        pushButton_send->setText(QCoreApplication::translate("ServerDialog", "Send", nullptr));
        pushButton_Clear->setText(QCoreApplication::translate("ServerDialog", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerDialog: public Ui_ServerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERDIALOG_H
