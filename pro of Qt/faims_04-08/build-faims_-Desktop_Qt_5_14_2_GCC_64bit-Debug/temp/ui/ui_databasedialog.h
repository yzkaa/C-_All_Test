/********************************************************************************
** Form generated from reading UI file 'databasedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEDIALOG_H
#define UI_DATABASEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataBaseDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_topBtnArea;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_out;
    QPushButton *pushButton_load;
    QPushButton *pushButton_search;
    QPushButton *pushButton_clear;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *Layout_functionArea;
    QTreeWidget *treeWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QGridLayout *Layout_tabWidget;
    QTableView *tableView;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_pageInfor;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_startPage;
    QPushButton *pushButton_proPage;
    QLabel *label;
    QPushButton *pushButton_nextPage;
    QPushButton *pushButton_endPage;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QPushButton *pushButton_jumpPage;

    void setupUi(QDialog *DataBaseDialog)
    {
        if (DataBaseDialog->objectName().isEmpty())
            DataBaseDialog->setObjectName(QString::fromUtf8("DataBaseDialog"));
        DataBaseDialog->resize(791, 438);
        verticalLayout_2 = new QVBoxLayout(DataBaseDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_topBtnArea = new QWidget(DataBaseDialog);
        widget_topBtnArea->setObjectName(QString::fromUtf8("widget_topBtnArea"));
        horizontalLayout = new QHBoxLayout(widget_topBtnArea);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_out = new QPushButton(widget_topBtnArea);
        pushButton_out->setObjectName(QString::fromUtf8("pushButton_out"));

        horizontalLayout->addWidget(pushButton_out);

        pushButton_load = new QPushButton(widget_topBtnArea);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));

        horizontalLayout->addWidget(pushButton_load);

        pushButton_search = new QPushButton(widget_topBtnArea);
        pushButton_search->setObjectName(QString::fromUtf8("pushButton_search"));

        horizontalLayout->addWidget(pushButton_search);

        pushButton_clear = new QPushButton(widget_topBtnArea);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));

        horizontalLayout->addWidget(pushButton_clear);

        horizontalSpacer = new QSpacerItem(333, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(widget_topBtnArea);

        Layout_functionArea = new QHBoxLayout();
        Layout_functionArea->setObjectName(QString::fromUtf8("Layout_functionArea"));
        treeWidget = new QTreeWidget(DataBaseDialog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        Layout_functionArea->addWidget(treeWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(DataBaseDialog);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        Layout_tabWidget = new QGridLayout(widget_2);
        Layout_tabWidget->setObjectName(QString::fromUtf8("Layout_tabWidget"));
        Layout_tabWidget->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(widget_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        Layout_tabWidget->addWidget(tableView, 0, 0, 1, 1);


        verticalLayout->addWidget(widget_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        label_pageInfor = new QLabel(DataBaseDialog);
        label_pageInfor->setObjectName(QString::fromUtf8("label_pageInfor"));

        gridLayout->addWidget(label_pageInfor, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_startPage = new QPushButton(DataBaseDialog);
        pushButton_startPage->setObjectName(QString::fromUtf8("pushButton_startPage"));

        horizontalLayout_2->addWidget(pushButton_startPage);

        pushButton_proPage = new QPushButton(DataBaseDialog);
        pushButton_proPage->setObjectName(QString::fromUtf8("pushButton_proPage"));

        horizontalLayout_2->addWidget(pushButton_proPage);

        label = new QLabel(DataBaseDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"Agency FB\";"));

        horizontalLayout_2->addWidget(label);

        pushButton_nextPage = new QPushButton(DataBaseDialog);
        pushButton_nextPage->setObjectName(QString::fromUtf8("pushButton_nextPage"));

        horizontalLayout_2->addWidget(pushButton_nextPage);

        pushButton_endPage = new QPushButton(DataBaseDialog);
        pushButton_endPage->setObjectName(QString::fromUtf8("pushButton_endPage"));

        horizontalLayout_2->addWidget(pushButton_endPage);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_2 = new QLabel(DataBaseDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(DataBaseDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        label_3 = new QLabel(DataBaseDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        pushButton_jumpPage = new QPushButton(DataBaseDialog);
        pushButton_jumpPage->setObjectName(QString::fromUtf8("pushButton_jumpPage"));

        horizontalLayout_2->addWidget(pushButton_jumpPage);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);


        Layout_functionArea->addLayout(verticalLayout);


        verticalLayout_2->addLayout(Layout_functionArea);


        retranslateUi(DataBaseDialog);

        QMetaObject::connectSlotsByName(DataBaseDialog);
    } // setupUi

    void retranslateUi(QDialog *DataBaseDialog)
    {
        DataBaseDialog->setWindowTitle(QCoreApplication::translate("DataBaseDialog", "Dialog", nullptr));
        pushButton_out->setText(QCoreApplication::translate("DataBaseDialog", "\345\257\274\345\207\272", nullptr));
        pushButton_load->setText(QCoreApplication::translate("DataBaseDialog", "\345\257\274\345\205\245", nullptr));
        pushButton_search->setText(QCoreApplication::translate("DataBaseDialog", "\346\243\200\347\264\242", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("DataBaseDialog", "\345\210\240\351\231\244", nullptr));
        label_pageInfor->setText(QCoreApplication::translate("DataBaseDialog", "TextLabel", nullptr));
        pushButton_startPage->setText(QCoreApplication::translate("DataBaseDialog", "\351\246\226\351\241\265", nullptr));
        pushButton_proPage->setText(QCoreApplication::translate("DataBaseDialog", "\344\270\212\344\270\200\351\241\265", nullptr));
        label->setText(QCoreApplication::translate("DataBaseDialog", "/", nullptr));
        pushButton_nextPage->setText(QCoreApplication::translate("DataBaseDialog", "\344\270\213\344\270\200\351\241\265", nullptr));
        pushButton_endPage->setText(QCoreApplication::translate("DataBaseDialog", "\345\260\276\351\241\265", nullptr));
        label_2->setText(QCoreApplication::translate("DataBaseDialog", "\350\267\263\350\275\254\350\207\263:", nullptr));
        label_3->setText(QCoreApplication::translate("DataBaseDialog", "\351\241\265", nullptr));
        pushButton_jumpPage->setText(QCoreApplication::translate("DataBaseDialog", "\350\267\263\350\275\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataBaseDialog: public Ui_DataBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEDIALOG_H
