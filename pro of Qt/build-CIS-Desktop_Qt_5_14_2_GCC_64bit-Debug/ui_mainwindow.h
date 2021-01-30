/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *mainWeiget;
    QHBoxLayout *horizontalLayout;
    QPushButton *select_picture;
    QPushButton *exit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        mainWeiget = new QWidget(centralwidget);
        mainWeiget->setObjectName(QStringLiteral("mainWeiget"));
        horizontalLayout = new QHBoxLayout(mainWeiget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        select_picture = new QPushButton(mainWeiget);
        select_picture->setObjectName(QStringLiteral("select_picture"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(select_picture->sizePolicy().hasHeightForWidth());
        select_picture->setSizePolicy(sizePolicy);
        select_picture->setMinimumSize(QSize(60, 50));
        select_picture->setMaximumSize(QSize(200, 200));

        horizontalLayout->addWidget(select_picture);

        exit = new QPushButton(mainWeiget);
        exit->setObjectName(QStringLiteral("exit"));
        sizePolicy.setHeightForWidth(exit->sizePolicy().hasHeightForWidth());
        exit->setSizePolicy(sizePolicy);
        exit->setMaximumSize(QSize(200, 200));

        horizontalLayout->addWidget(exit);


        verticalLayout->addWidget(mainWeiget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 28));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        select_picture->setText(QString());
        exit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
