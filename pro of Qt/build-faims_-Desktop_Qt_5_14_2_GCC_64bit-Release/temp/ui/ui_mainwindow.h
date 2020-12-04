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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionQuit;
    QAction *actionConfigure;
    QAction *actionClear;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QAction *actionSave_Data;
    QAction *actionSave_Chart;
    QAction *actionQuit_2;
    QAction *actionOpen_file;
    QAction *actionChartThemeLight;
    QAction *actionChartThemeBlueCerulean;
    QAction *actionChartThemeDark;
    QAction *actionChartThemeBrownSand;
    QAction *actionChartThemeBlueNcs;
    QAction *actionChartThemeHighContrast;
    QAction *actionChartThemeBlueIcy;
    QAction *actionChartThemeQt;
    QAction *actionfilter;
    QAction *actionFilter;
    QAction *actionSetLegend;
    QAction *actionCancel_Filter;
    QAction *actionChartThemeCustom;
    QAction *actionSolidLine;
    QAction *actionDashLine;
    QAction *actionDotLine;
    QAction *actionDashDotLine;
    QAction *actionDashDotDotLine;
    QAction *actionCustomDashLine;
    QAction *actionUpload;
    QAction *actionDataBase_Configure;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_8;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *System_Parameters;
    QVBoxLayout *verticalLayout;
    QCheckBox *autozerocheckBox;
    QCheckBox *negativecurrentcheckBox;
    QHBoxLayout *horizontalLayout;
    QLabel *zeroerrorlabel;
    QLineEdit *zeroerrorlineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *zerodriftlabel;
    QLineEdit *zerodriftlineEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *showsystemButton;
    QPushButton *setsystemButton;
    QGroupBox *Work_Mode;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *Mode1checkBox;
    QCheckBox *Mode2checkBox;
    QCheckBox *Mode3checkBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *svaluelineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *cvaluelineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QLineEdit *tvaluelineEdit;
    QGroupBox *Data_Receive_Area;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *receivetextEdit;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *recover;
    QPushButton *startButton;
    QPushButton *clearButton;
    QWidget *chartWidget;
    QHBoxLayout *chartLayout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuCalls;
    QMenu *menuTools;
    QMenu *menuChartTheme;
    QMenu *menuHelp;
    QMenu *menuFiles;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1129, 560);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QString::fromUtf8("actionConfigure"));
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        actionSave_Data = new QAction(MainWindow);
        actionSave_Data->setObjectName(QString::fromUtf8("actionSave_Data"));
        actionSave_Chart = new QAction(MainWindow);
        actionSave_Chart->setObjectName(QString::fromUtf8("actionSave_Chart"));
        actionQuit_2 = new QAction(MainWindow);
        actionQuit_2->setObjectName(QString::fromUtf8("actionQuit_2"));
        actionOpen_file = new QAction(MainWindow);
        actionOpen_file->setObjectName(QString::fromUtf8("actionOpen_file"));
        actionChartThemeLight = new QAction(MainWindow);
        actionChartThemeLight->setObjectName(QString::fromUtf8("actionChartThemeLight"));
        actionChartThemeBlueCerulean = new QAction(MainWindow);
        actionChartThemeBlueCerulean->setObjectName(QString::fromUtf8("actionChartThemeBlueCerulean"));
        actionChartThemeDark = new QAction(MainWindow);
        actionChartThemeDark->setObjectName(QString::fromUtf8("actionChartThemeDark"));
        actionChartThemeBrownSand = new QAction(MainWindow);
        actionChartThemeBrownSand->setObjectName(QString::fromUtf8("actionChartThemeBrownSand"));
        actionChartThemeBlueNcs = new QAction(MainWindow);
        actionChartThemeBlueNcs->setObjectName(QString::fromUtf8("actionChartThemeBlueNcs"));
        actionChartThemeHighContrast = new QAction(MainWindow);
        actionChartThemeHighContrast->setObjectName(QString::fromUtf8("actionChartThemeHighContrast"));
        actionChartThemeBlueIcy = new QAction(MainWindow);
        actionChartThemeBlueIcy->setObjectName(QString::fromUtf8("actionChartThemeBlueIcy"));
        actionChartThemeQt = new QAction(MainWindow);
        actionChartThemeQt->setObjectName(QString::fromUtf8("actionChartThemeQt"));
        actionfilter = new QAction(MainWindow);
        actionfilter->setObjectName(QString::fromUtf8("actionfilter"));
        actionFilter = new QAction(MainWindow);
        actionFilter->setObjectName(QString::fromUtf8("actionFilter"));
        actionSetLegend = new QAction(MainWindow);
        actionSetLegend->setObjectName(QString::fromUtf8("actionSetLegend"));
        actionCancel_Filter = new QAction(MainWindow);
        actionCancel_Filter->setObjectName(QString::fromUtf8("actionCancel_Filter"));
        actionChartThemeCustom = new QAction(MainWindow);
        actionChartThemeCustom->setObjectName(QString::fromUtf8("actionChartThemeCustom"));
        actionSolidLine = new QAction(MainWindow);
        actionSolidLine->setObjectName(QString::fromUtf8("actionSolidLine"));
        actionDashLine = new QAction(MainWindow);
        actionDashLine->setObjectName(QString::fromUtf8("actionDashLine"));
        actionDotLine = new QAction(MainWindow);
        actionDotLine->setObjectName(QString::fromUtf8("actionDotLine"));
        actionDashDotLine = new QAction(MainWindow);
        actionDashDotLine->setObjectName(QString::fromUtf8("actionDashDotLine"));
        actionDashDotDotLine = new QAction(MainWindow);
        actionDashDotDotLine->setObjectName(QString::fromUtf8("actionDashDotDotLine"));
        actionCustomDashLine = new QAction(MainWindow);
        actionCustomDashLine->setObjectName(QString::fromUtf8("actionCustomDashLine"));
        actionUpload = new QAction(MainWindow);
        actionUpload->setObjectName(QString::fromUtf8("actionUpload"));
        actionDataBase_Configure = new QAction(MainWindow);
        actionDataBase_Configure->setObjectName(QString::fromUtf8("actionDataBase_Configure"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_8 = new QHBoxLayout(centralWidget);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(198, 16777215));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        System_Parameters = new QGroupBox(groupBox);
        System_Parameters->setObjectName(QString::fromUtf8("System_Parameters"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(System_Parameters->sizePolicy().hasHeightForWidth());
        System_Parameters->setSizePolicy(sizePolicy);
        System_Parameters->setMaximumSize(QSize(175, 16777215));
        verticalLayout = new QVBoxLayout(System_Parameters);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, 11, -1);
        autozerocheckBox = new QCheckBox(System_Parameters);
        autozerocheckBox->setObjectName(QString::fromUtf8("autozerocheckBox"));

        verticalLayout->addWidget(autozerocheckBox);

        negativecurrentcheckBox = new QCheckBox(System_Parameters);
        negativecurrentcheckBox->setObjectName(QString::fromUtf8("negativecurrentcheckBox"));
        negativecurrentcheckBox->setChecked(false);

        verticalLayout->addWidget(negativecurrentcheckBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        zeroerrorlabel = new QLabel(System_Parameters);
        zeroerrorlabel->setObjectName(QString::fromUtf8("zeroerrorlabel"));

        horizontalLayout->addWidget(zeroerrorlabel);

        zeroerrorlineEdit = new QLineEdit(System_Parameters);
        zeroerrorlineEdit->setObjectName(QString::fromUtf8("zeroerrorlineEdit"));

        horizontalLayout->addWidget(zeroerrorlineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        zerodriftlabel = new QLabel(System_Parameters);
        zerodriftlabel->setObjectName(QString::fromUtf8("zerodriftlabel"));

        horizontalLayout_2->addWidget(zerodriftlabel);

        zerodriftlineEdit = new QLineEdit(System_Parameters);
        zerodriftlineEdit->setObjectName(QString::fromUtf8("zerodriftlineEdit"));

        horizontalLayout_2->addWidget(zerodriftlineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        showsystemButton = new QPushButton(System_Parameters);
        showsystemButton->setObjectName(QString::fromUtf8("showsystemButton"));

        horizontalLayout_3->addWidget(showsystemButton);

        setsystemButton = new QPushButton(System_Parameters);
        setsystemButton->setObjectName(QString::fromUtf8("setsystemButton"));

        horizontalLayout_3->addWidget(setsystemButton);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_4->addWidget(System_Parameters);

        Work_Mode = new QGroupBox(groupBox);
        Work_Mode->setObjectName(QString::fromUtf8("Work_Mode"));
        Work_Mode->setEnabled(true);
        Work_Mode->setMaximumSize(QSize(16777215, 16777213));
        verticalLayout_2 = new QVBoxLayout(Work_Mode);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, 12, -1);
        Mode1checkBox = new QCheckBox(Work_Mode);
        Mode1checkBox->setObjectName(QString::fromUtf8("Mode1checkBox"));
        Mode1checkBox->setMinimumSize(QSize(119, 20));
        Mode1checkBox->setMaximumSize(QSize(119, 20));
        Mode1checkBox->setChecked(true);

        verticalLayout_2->addWidget(Mode1checkBox);

        Mode2checkBox = new QCheckBox(Work_Mode);
        Mode2checkBox->setObjectName(QString::fromUtf8("Mode2checkBox"));
        Mode2checkBox->setMinimumSize(QSize(119, 20));
        Mode2checkBox->setMaximumSize(QSize(119, 20));

        verticalLayout_2->addWidget(Mode2checkBox);

        Mode3checkBox = new QCheckBox(Work_Mode);
        Mode3checkBox->setObjectName(QString::fromUtf8("Mode3checkBox"));
        Mode3checkBox->setMinimumSize(QSize(119, 20));
        Mode3checkBox->setMaximumSize(QSize(119, 20));

        verticalLayout_2->addWidget(Mode3checkBox);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(Work_Mode);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        svaluelineEdit = new QLineEdit(Work_Mode);
        svaluelineEdit->setObjectName(QString::fromUtf8("svaluelineEdit"));
        svaluelineEdit->setMinimumSize(QSize(61, 21));
        svaluelineEdit->setMaximumSize(QSize(61, 21));

        horizontalLayout_4->addWidget(svaluelineEdit);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(Work_Mode);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        cvaluelineEdit = new QLineEdit(Work_Mode);
        cvaluelineEdit->setObjectName(QString::fromUtf8("cvaluelineEdit"));
        cvaluelineEdit->setMinimumSize(QSize(61, 20));
        cvaluelineEdit->setMaximumSize(QSize(61, 20));

        horizontalLayout_5->addWidget(cvaluelineEdit);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(Work_Mode);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_6->addWidget(label_3);

        tvaluelineEdit = new QLineEdit(Work_Mode);
        tvaluelineEdit->setObjectName(QString::fromUtf8("tvaluelineEdit"));
        tvaluelineEdit->setMinimumSize(QSize(61, 21));
        tvaluelineEdit->setMaximumSize(QSize(61, 21));

        horizontalLayout_6->addWidget(tvaluelineEdit);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_4->addWidget(Work_Mode);

        splitter->addWidget(groupBox);
        Data_Receive_Area = new QGroupBox(splitter);
        Data_Receive_Area->setObjectName(QString::fromUtf8("Data_Receive_Area"));
        Data_Receive_Area->setMaximumSize(QSize(190, 16777215));
        verticalLayout_3 = new QVBoxLayout(Data_Receive_Area);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        receivetextEdit = new QTextEdit(Data_Receive_Area);
        receivetextEdit->setObjectName(QString::fromUtf8("receivetextEdit"));

        verticalLayout_3->addWidget(receivetextEdit);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        recover = new QPushButton(Data_Receive_Area);
        recover->setObjectName(QString::fromUtf8("recover"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(9);
        font.setBold(false);
        font.setWeight(50);
        recover->setFont(font);

        horizontalLayout_7->addWidget(recover);

        startButton = new QPushButton(Data_Receive_Area);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setBold(false);
        font1.setWeight(50);
        startButton->setFont(font1);
        startButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_7->addWidget(startButton);

        clearButton = new QPushButton(Data_Receive_Area);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        horizontalLayout_7->addWidget(clearButton);


        verticalLayout_3->addLayout(horizontalLayout_7);

        splitter->addWidget(Data_Receive_Area);
        chartWidget = new QWidget(splitter);
        chartWidget->setObjectName(QString::fromUtf8("chartWidget"));
        chartLayout = new QHBoxLayout(chartWidget);
        chartLayout->setSpacing(6);
        chartLayout->setContentsMargins(11, 11, 11, 11);
        chartLayout->setObjectName(QString::fromUtf8("chartLayout"));
        splitter->addWidget(chartWidget);

        horizontalLayout_8->addWidget(splitter);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1129, 22));
        menuCalls = new QMenu(menuBar);
        menuCalls->setObjectName(QString::fromUtf8("menuCalls"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuChartTheme = new QMenu(menuTools);
        menuChartTheme->setObjectName(QString::fromUtf8("menuChartTheme"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuFiles = new QMenu(menuBar);
        menuFiles->setObjectName(QString::fromUtf8("menuFiles"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFiles->menuAction());
        menuBar->addAction(menuCalls->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuCalls->addAction(actionConnect);
        menuCalls->addAction(actionDisconnect);
        menuTools->addAction(actionConfigure);
        menuTools->addAction(actionClear);
        menuTools->addAction(actionFilter);
        menuTools->addAction(actionCancel_Filter);
        menuTools->addAction(menuChartTheme->menuAction());
        menuTools->addAction(actionSetLegend);
        menuChartTheme->addAction(actionChartThemeLight);
        menuChartTheme->addAction(actionChartThemeBlueCerulean);
        menuChartTheme->addAction(actionChartThemeDark);
        menuChartTheme->addAction(actionChartThemeBrownSand);
        menuChartTheme->addAction(actionChartThemeBlueNcs);
        menuChartTheme->addAction(actionChartThemeHighContrast);
        menuChartTheme->addAction(actionChartThemeBlueIcy);
        menuChartTheme->addAction(actionChartThemeQt);
        menuChartTheme->addAction(actionChartThemeCustom);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_Qt);
        menuFiles->addAction(actionOpen_file);
        menuFiles->addAction(actionSave_Data);
        menuFiles->addAction(actionSave_Chart);
        menuFiles->addAction(actionQuit_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        actionDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        actionConfigure->setText(QCoreApplication::translate("MainWindow", "Configure", nullptr));
        actionClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About System", nullptr));
        actionAbout_Qt->setText(QCoreApplication::translate("MainWindow", "About Qt", nullptr));
        actionSave_Data->setText(QCoreApplication::translate("MainWindow", "Save Datas", nullptr));
        actionSave_Chart->setText(QCoreApplication::translate("MainWindow", "Save Chart", nullptr));
        actionQuit_2->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        actionOpen_file->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
        actionChartThemeLight->setText(QCoreApplication::translate("MainWindow", "ChartThemeLight", nullptr));
        actionChartThemeBlueCerulean->setText(QCoreApplication::translate("MainWindow", "ChartThemeBlueCerulean", nullptr));
        actionChartThemeDark->setText(QCoreApplication::translate("MainWindow", "ChartThemeDark", nullptr));
        actionChartThemeBrownSand->setText(QCoreApplication::translate("MainWindow", "ChartThemeBrownSand", nullptr));
        actionChartThemeBlueNcs->setText(QCoreApplication::translate("MainWindow", "ChartThemeBlueNcs", nullptr));
        actionChartThemeHighContrast->setText(QCoreApplication::translate("MainWindow", "ChartThemeHighContrast", nullptr));
        actionChartThemeBlueIcy->setText(QCoreApplication::translate("MainWindow", "ChartThemeBlueIcy", nullptr));
        actionChartThemeQt->setText(QCoreApplication::translate("MainWindow", "ChartThemeQt", nullptr));
        actionfilter->setText(QCoreApplication::translate("MainWindow", "filter", nullptr));
        actionFilter->setText(QCoreApplication::translate("MainWindow", "Filter", nullptr));
        actionSetLegend->setText(QCoreApplication::translate("MainWindow", "SetLegend", nullptr));
        actionCancel_Filter->setText(QCoreApplication::translate("MainWindow", "Cancel Filter", nullptr));
        actionChartThemeCustom->setText(QCoreApplication::translate("MainWindow", "ChartThemeCustom", nullptr));
        actionSolidLine->setText(QCoreApplication::translate("MainWindow", "SolidLine", nullptr));
        actionDashLine->setText(QCoreApplication::translate("MainWindow", "DashLine", nullptr));
        actionDotLine->setText(QCoreApplication::translate("MainWindow", "DotLine", nullptr));
        actionDashDotLine->setText(QCoreApplication::translate("MainWindow", "DashDotLine", nullptr));
        actionDashDotDotLine->setText(QCoreApplication::translate("MainWindow", "DashDotDotLine", nullptr));
        actionCustomDashLine->setText(QCoreApplication::translate("MainWindow", "CustomDashLine", nullptr));
        actionUpload->setText(QCoreApplication::translate("MainWindow", "Upload", nullptr));
        actionDataBase_Configure->setText(QCoreApplication::translate("MainWindow", "DataBase Configure", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "FAIMS Configure", nullptr));
        System_Parameters->setTitle(QCoreApplication::translate("MainWindow", "System Parameters", nullptr));
        autozerocheckBox->setText(QCoreApplication::translate("MainWindow", "Auto Zero", nullptr));
        negativecurrentcheckBox->setText(QCoreApplication::translate("MainWindow", "Negative Current", nullptr));
        zeroerrorlabel->setText(QCoreApplication::translate("MainWindow", "Zero Error:", nullptr));
        zeroerrorlineEdit->setText(QCoreApplication::translate("MainWindow", "0.5", nullptr));
        zerodriftlabel->setText(QCoreApplication::translate("MainWindow", "Zero Drift:", nullptr));
        zerodriftlineEdit->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        showsystemButton->setText(QCoreApplication::translate("MainWindow", "Show", nullptr));
        setsystemButton->setText(QCoreApplication::translate("MainWindow", "Set", nullptr));
        Work_Mode->setTitle(QCoreApplication::translate("MainWindow", "Work Mode", nullptr));
        Mode1checkBox->setText(QCoreApplication::translate("MainWindow", "RealTime Mode", nullptr));
        Mode2checkBox->setText(QCoreApplication::translate("MainWindow", "Data Processing", nullptr));
        Mode3checkBox->setText(QCoreApplication::translate("MainWindow", "Keithley Mode", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "CV Span:", nullptr));
        svaluelineEdit->setText(QCoreApplication::translate("MainWindow", "13", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Density:", nullptr));
        cvaluelineEdit->setText(QCoreApplication::translate("MainWindow", "1000", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Step Size:", nullptr));
        tvaluelineEdit->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        Data_Receive_Area->setTitle(QCoreApplication::translate("MainWindow", "Data Receive Area", nullptr));
        recover->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        menuCalls->setTitle(QCoreApplication::translate("MainWindow", "Calls", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuChartTheme->setTitle(QCoreApplication::translate("MainWindow", "ChartTheme", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuFiles->setTitle(QCoreApplication::translate("MainWindow", "Files", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
