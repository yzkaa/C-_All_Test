/********************************************************************************
** Form generated from reading UI file 'allsettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLSETTINGSDIALOG_H
#define UI_ALLSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AllSettingsDialog
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;

    void setupUi(QDialog *AllSettingsDialog)
    {
        if (AllSettingsDialog->objectName().isEmpty())
            AllSettingsDialog->setObjectName(QString::fromUtf8("AllSettingsDialog"));
        AllSettingsDialog->resize(482, 349);
        gridLayout = new QGridLayout(AllSettingsDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(AllSettingsDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(AllSettingsDialog);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(AllSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *AllSettingsDialog)
    {
        AllSettingsDialog->setWindowTitle(QCoreApplication::translate("AllSettingsDialog", "Dialog", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("AllSettingsDialog", "Serial port  ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("AllSettingsDialog", "Database", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AllSettingsDialog: public Ui_AllSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLSETTINGSDIALOG_H
