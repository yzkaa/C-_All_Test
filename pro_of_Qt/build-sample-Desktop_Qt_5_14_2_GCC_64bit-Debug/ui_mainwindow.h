/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *select;
    QAction *clear;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionConfigure;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_8;
    QPushButton *modifyButton;
    QLabel *portNameLabel;
    QLabel *BaudRateLabel;
    QLabel *dataBitsLabel;
    QLabel *parityLabel;
    QLabel *stopBitsLabel;
    QLabel *flowControlLabel;
    QPlainTextEdit *dataShow;
    QPushButton *startButton;
    QPushButton *clearButton;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *chartWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QVBoxLayout *chartLayout;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_3;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu1;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        select = new QAction(MainWindow);
        select->setObjectName(QString::fromUtf8("select"));
        clear = new QAction(MainWindow);
        clear->setObjectName(QString::fromUtf8("clear"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QString::fromUtf8("actionConfigure"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setSizeConstraint(QLayout::SetDefaultConstraint);
        modifyButton = new QPushButton(centralwidget);
        modifyButton->setObjectName(QString::fromUtf8("modifyButton"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(modifyButton->sizePolicy().hasHeightForWidth());
        modifyButton->setSizePolicy(sizePolicy);
        modifyButton->setMinimumSize(QSize(80, 40));

        verticalLayout_8->addWidget(modifyButton);

        portNameLabel = new QLabel(centralwidget);
        portNameLabel->setObjectName(QString::fromUtf8("portNameLabel"));

        verticalLayout_8->addWidget(portNameLabel);

        BaudRateLabel = new QLabel(centralwidget);
        BaudRateLabel->setObjectName(QString::fromUtf8("BaudRateLabel"));

        verticalLayout_8->addWidget(BaudRateLabel);

        dataBitsLabel = new QLabel(centralwidget);
        dataBitsLabel->setObjectName(QString::fromUtf8("dataBitsLabel"));

        verticalLayout_8->addWidget(dataBitsLabel);

        parityLabel = new QLabel(centralwidget);
        parityLabel->setObjectName(QString::fromUtf8("parityLabel"));

        verticalLayout_8->addWidget(parityLabel);

        stopBitsLabel = new QLabel(centralwidget);
        stopBitsLabel->setObjectName(QString::fromUtf8("stopBitsLabel"));

        verticalLayout_8->addWidget(stopBitsLabel);

        flowControlLabel = new QLabel(centralwidget);
        flowControlLabel->setObjectName(QString::fromUtf8("flowControlLabel"));

        verticalLayout_8->addWidget(flowControlLabel);

        dataShow = new QPlainTextEdit(centralwidget);
        dataShow->setObjectName(QString::fromUtf8("dataShow"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dataShow->sizePolicy().hasHeightForWidth());
        dataShow->setSizePolicy(sizePolicy1);

        verticalLayout_8->addWidget(dataShow);

        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setMinimumSize(QSize(80, 40));

        verticalLayout_8->addWidget(startButton);

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setMinimumSize(QSize(80, 40));

        verticalLayout_8->addWidget(clearButton);


        horizontalLayout_2->addLayout(verticalLayout_8);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        verticalLayout_6->addLayout(horizontalLayout);

        chartWidget = new QStackedWidget(centralwidget);
        chartWidget->setObjectName(QString::fromUtf8("chartWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout_4 = new QHBoxLayout(page);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(label_4);

        chartLayout = new QVBoxLayout();
        chartLayout->setObjectName(QString::fromUtf8("chartLayout"));

        verticalLayout_2->addLayout(chartLayout);


        horizontalLayout_4->addLayout(verticalLayout_2);

        chartWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        horizontalLayout_3 = new QHBoxLayout(page_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        chartWidget->addWidget(page_2);

        verticalLayout_6->addWidget(chartWidget);


        horizontalLayout_2->addLayout(verticalLayout_6);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu1 = new QMenu(menubar);
        menu1->setObjectName(QString::fromUtf8("menu1"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu1->menuAction());
        menu->addAction(select);
        menu->addAction(clear);
        menu1->addAction(actionConnect);
        menu1->addAction(actionDisconnect);
        menu1->addAction(actionConfigure);

        retranslateUi(MainWindow);

        chartWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        select->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        actionDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        actionConfigure->setText(QCoreApplication::translate("MainWindow", "Configure", nullptr));
        modifyButton->setText(QCoreApplication::translate("MainWindow", "Modify", nullptr));
        portNameLabel->setText(QString());
        BaudRateLabel->setText(QString());
        dataBitsLabel->setText(QString());
        parityLabel->setText(QString());
        stopBitsLabel->setText(QString());
        flowControlLabel->setText(QString());
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\263\242\345\275\242\345\233\276", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menu1->setTitle(QCoreApplication::translate("MainWindow", "Serial Port", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
