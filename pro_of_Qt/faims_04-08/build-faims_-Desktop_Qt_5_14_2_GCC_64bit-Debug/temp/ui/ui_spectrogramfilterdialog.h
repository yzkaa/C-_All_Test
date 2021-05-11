/********************************************************************************
** Form generated from reading UI file 'spectrogramfilterdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPECTROGRAMFILTERDIALOG_H
#define UI_SPECTROGRAMFILTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SpectrogramFilterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QCheckBox *cb_dataTableName;
    QLineEdit *le_dataTableName;
    QCheckBox *cb_gasType;
    QLineEdit *le_gasType;
    QCheckBox *cb_gasVolume;
    QLineEdit *le_gasVolume;
    QCheckBox *cb_dataNum;
    QComboBox *cbb_dataNum;
    QCheckBox *cb_remarks;
    QLineEdit *le_remarks;
    QCheckBox *cb_time;
    QLabel *label;
    QLabel *label_2;
    QDateTimeEdit *timeStart;
    QDateTimeEdit *timeEnd;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_sure;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_cancel;

    void setupUi(QDialog *SpectrogramFilterDialog)
    {
        if (SpectrogramFilterDialog->objectName().isEmpty())
            SpectrogramFilterDialog->setObjectName(QString::fromUtf8("SpectrogramFilterDialog"));
        SpectrogramFilterDialog->resize(373, 286);
        verticalLayout = new QVBoxLayout(SpectrogramFilterDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(30, 10, 30, 10);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cb_dataTableName = new QCheckBox(SpectrogramFilterDialog);
        cb_dataTableName->setObjectName(QString::fromUtf8("cb_dataTableName"));

        gridLayout->addWidget(cb_dataTableName, 0, 0, 1, 1);

        le_dataTableName = new QLineEdit(SpectrogramFilterDialog);
        le_dataTableName->setObjectName(QString::fromUtf8("le_dataTableName"));

        gridLayout->addWidget(le_dataTableName, 0, 1, 1, 1);

        cb_gasType = new QCheckBox(SpectrogramFilterDialog);
        cb_gasType->setObjectName(QString::fromUtf8("cb_gasType"));

        gridLayout->addWidget(cb_gasType, 1, 0, 1, 1);

        le_gasType = new QLineEdit(SpectrogramFilterDialog);
        le_gasType->setObjectName(QString::fromUtf8("le_gasType"));

        gridLayout->addWidget(le_gasType, 1, 1, 1, 1);

        cb_gasVolume = new QCheckBox(SpectrogramFilterDialog);
        cb_gasVolume->setObjectName(QString::fromUtf8("cb_gasVolume"));

        gridLayout->addWidget(cb_gasVolume, 2, 0, 1, 1);

        le_gasVolume = new QLineEdit(SpectrogramFilterDialog);
        le_gasVolume->setObjectName(QString::fromUtf8("le_gasVolume"));

        gridLayout->addWidget(le_gasVolume, 2, 1, 1, 1);

        cb_dataNum = new QCheckBox(SpectrogramFilterDialog);
        cb_dataNum->setObjectName(QString::fromUtf8("cb_dataNum"));

        gridLayout->addWidget(cb_dataNum, 3, 0, 1, 1);

        cbb_dataNum = new QComboBox(SpectrogramFilterDialog);
        cbb_dataNum->setObjectName(QString::fromUtf8("cbb_dataNum"));

        gridLayout->addWidget(cbb_dataNum, 3, 1, 1, 1);

        cb_remarks = new QCheckBox(SpectrogramFilterDialog);
        cb_remarks->setObjectName(QString::fromUtf8("cb_remarks"));

        gridLayout->addWidget(cb_remarks, 4, 0, 1, 1);

        le_remarks = new QLineEdit(SpectrogramFilterDialog);
        le_remarks->setObjectName(QString::fromUtf8("le_remarks"));

        gridLayout->addWidget(le_remarks, 4, 1, 1, 1);

        cb_time = new QCheckBox(SpectrogramFilterDialog);
        cb_time->setObjectName(QString::fromUtf8("cb_time"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cb_time->sizePolicy().hasHeightForWidth());
        cb_time->setSizePolicy(sizePolicy);

        gridLayout->addWidget(cb_time, 5, 0, 1, 1);

        label = new QLabel(SpectrogramFilterDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 6, 0, 1, 1);

        label_2 = new QLabel(SpectrogramFilterDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 7, 0, 1, 1);

        timeStart = new QDateTimeEdit(SpectrogramFilterDialog);
        timeStart->setObjectName(QString::fromUtf8("timeStart"));

        gridLayout->addWidget(timeStart, 6, 1, 1, 1);

        timeEnd = new QDateTimeEdit(SpectrogramFilterDialog);
        timeEnd->setObjectName(QString::fromUtf8("timeEnd"));

        gridLayout->addWidget(timeEnd, 7, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_sure = new QPushButton(SpectrogramFilterDialog);
        btn_sure->setObjectName(QString::fromUtf8("btn_sure"));

        horizontalLayout->addWidget(btn_sure);

        horizontalSpacer = new QSpacerItem(127, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_cancel = new QPushButton(SpectrogramFilterDialog);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        horizontalLayout->addWidget(btn_cancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SpectrogramFilterDialog);

        QMetaObject::connectSlotsByName(SpectrogramFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *SpectrogramFilterDialog)
    {
        SpectrogramFilterDialog->setWindowTitle(QCoreApplication::translate("SpectrogramFilterDialog", "Dialog", nullptr));
        cb_dataTableName->setText(QCoreApplication::translate("SpectrogramFilterDialog", "\346\225\260\346\215\256\350\241\250\345\220\215\347\247\260\357\274\232", nullptr));
        cb_gasType->setText(QCoreApplication::translate("SpectrogramFilterDialog", "\346\260\224\344\275\223\347\261\273\345\210\253\357\274\232", nullptr));
        cb_gasVolume->setText(QCoreApplication::translate("SpectrogramFilterDialog", "\346\260\224\344\275\223\344\275\223\347\247\257\357\274\232", nullptr));
        cb_dataNum->setText(QCoreApplication::translate("SpectrogramFilterDialog", "\346\225\260\346\215\256\346\235\241\346\225\260\357\274\232", nullptr));
        cb_remarks->setText(QCoreApplication::translate("SpectrogramFilterDialog", "\345\244\207\346\263\250\344\277\241\346\201\257\357\274\232", nullptr));
        cb_time->setText(QCoreApplication::translate("SpectrogramFilterDialog", "\346\227\266\351\227\264\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("SpectrogramFilterDialog", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("SpectrogramFilterDialog", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", nullptr));
        btn_sure->setText(QCoreApplication::translate("SpectrogramFilterDialog", "\347\241\256\345\256\232", nullptr));
        btn_cancel->setText(QCoreApplication::translate("SpectrogramFilterDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpectrogramFilterDialog: public Ui_SpectrogramFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPECTROGRAMFILTERDIALOG_H
