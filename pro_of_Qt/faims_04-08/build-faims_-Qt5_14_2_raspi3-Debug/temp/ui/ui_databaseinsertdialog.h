/********************************************************************************
** Form generated from reading UI file 'databaseinsertdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEINSERTDIALOG_H
#define UI_DATABASEINSERTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DatabaseInsertDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEdit_gasType;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_gasVolume;
    QLineEdit *lineEdit_startRF;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_sure;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *DatabaseInsertDialog)
    {
        if (DatabaseInsertDialog->objectName().isEmpty())
            DatabaseInsertDialog->setObjectName(QString::fromUtf8("DatabaseInsertDialog"));
        DatabaseInsertDialog->resize(389, 442);
        verticalLayout = new QVBoxLayout(DatabaseInsertDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(DatabaseInsertDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_2 = new QLabel(DatabaseInsertDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(DatabaseInsertDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_gasType = new QLineEdit(DatabaseInsertDialog);
        lineEdit_gasType->setObjectName(QString::fromUtf8("lineEdit_gasType"));

        gridLayout->addWidget(lineEdit_gasType, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        lineEdit_gasVolume = new QLineEdit(DatabaseInsertDialog);
        lineEdit_gasVolume->setObjectName(QString::fromUtf8("lineEdit_gasVolume"));

        gridLayout->addWidget(lineEdit_gasVolume, 1, 1, 1, 1);

        lineEdit_startRF = new QLineEdit(DatabaseInsertDialog);
        lineEdit_startRF->setObjectName(QString::fromUtf8("lineEdit_startRF"));

        gridLayout->addWidget(lineEdit_startRF, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        groupBox = new QGroupBox(DatabaseInsertDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout_2->addWidget(textEdit, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_sure = new QPushButton(DatabaseInsertDialog);
        pushButton_sure->setObjectName(QString::fromUtf8("pushButton_sure"));

        horizontalLayout->addWidget(pushButton_sure);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_cancel = new QPushButton(DatabaseInsertDialog);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout->addWidget(pushButton_cancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DatabaseInsertDialog);

        QMetaObject::connectSlotsByName(DatabaseInsertDialog);
    } // setupUi

    void retranslateUi(QDialog *DatabaseInsertDialog)
    {
        DatabaseInsertDialog->setWindowTitle(QCoreApplication::translate("DatabaseInsertDialog", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("DatabaseInsertDialog", "\350\265\267\345\247\213RF\347\224\265\345\216\213\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("DatabaseInsertDialog", "\346\260\224\344\275\223\344\275\223\347\247\257\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("DatabaseInsertDialog", "\346\260\224\344\275\223\347\247\215\347\261\273\357\274\232", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DatabaseInsertDialog", "\345\244\207\346\263\250\344\277\241\346\201\257", nullptr));
        pushButton_sure->setText(QCoreApplication::translate("DatabaseInsertDialog", "\347\241\256\345\256\232", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("DatabaseInsertDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DatabaseInsertDialog: public Ui_DatabaseInsertDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEINSERTDIALOG_H
