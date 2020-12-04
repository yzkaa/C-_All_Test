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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
    QMenuBar *menuBar;
    QMenu *menuCalls;
    QMenu *menuTools;
    QMenu *menuChartTheme;
    QMenu *menuHelp;
    QMenu *menuFiles;
    QMenu *menuDate;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1129, 560);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QStringLiteral("actionConfigure"));
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        actionSave_Data = new QAction(MainWindow);
        actionSave_Data->setObjectName(QStringLiteral("actionSave_Data"));
        actionSave_Chart = new QAction(MainWindow);
        actionSave_Chart->setObjectName(QStringLiteral("actionSave_Chart"));
        actionQuit_2 = new QAction(MainWindow);
        actionQuit_2->setObjectName(QStringLiteral("actionQuit_2"));
        actionOpen_file = new QAction(MainWindow);
        actionOpen_file->setObjectName(QStringLiteral("actionOpen_file"));
        actionChartThemeLight = new QAction(MainWindow);
        actionChartThemeLight->setObjectName(QStringLiteral("actionChartThemeLight"));
        actionChartThemeBlueCerulean = new QAction(MainWindow);
        actionChartThemeBlueCerulean->setObjectName(QStringLiteral("actionChartThemeBlueCerulean"));
        actionChartThemeDark = new QAction(MainWindow);
        actionChartThemeDark->setObjectName(QStringLiteral("actionChartThemeDark"));
        actionChartThemeBrownSand = new QAction(MainWindow);
        actionChartThemeBrownSand->setObjectName(QStringLiteral("actionChartThemeBrownSand"));
        actionChartThemeBlueNcs = new QAction(MainWindow);
        actionChartThemeBlueNcs->setObjectName(QStringLiteral("actionChartThemeBlueNcs"));
        actionChartThemeHighContrast = new QAction(MainWindow);
        actionChartThemeHighContrast->setObjectName(QStringLiteral("actionChartThemeHighContrast"));
        actionChartThemeBlueIcy = new QAction(MainWindow);
        actionChartThemeBlueIcy->setObjectName(QStringLiteral("actionChartThemeBlueIcy"));
        actionChartThemeQt = new QAction(MainWindow);
        actionChartThemeQt->setObjectName(QStringLiteral("actionChartThemeQt"));
        actionfilter = new QAction(MainWindow);
        actionfilter->setObjectName(QStringLiteral("actionfilter"));
        actionFilter = new QAction(MainWindow);
        actionFilter->setObjectName(QStringLiteral("actionFilter"));
        actionSetLegend = new QAction(MainWindow);
        actionSetLegend->setObjectName(QStringLiteral("actionSetLegend"));
        actionCancel_Filter = new QAction(MainWindow);
        actionCancel_Filter->setObjectName(QStringLiteral("actionCancel_Filter"));
        actionChartThemeCustom = new QAction(MainWindow);
        actionChartThemeCustom->setObjectName(QStringLiteral("actionChartThemeCustom"));
        actionSolidLine = new QAction(MainWindow);
        actionSolidLine->setObjectName(QStringLiteral("actionSolidLine"));
        actionDashLine = new QAction(MainWindow);
        actionDashLine->setObjectName(QStringLiteral("actionDashLine"));
        actionDotLine = new QAction(MainWindow);
        actionDotLine->setObjectName(QStringLiteral("actionDotLine"));
        actionDashDotLine = new QAction(MainWindow);
        actionDashDotLine->setObjectName(QStringLiteral("actionDashDotLine"));
        actionDashDotDotLine = new QAction(MainWindow);
        actionDashDotDotLine->setObjectName(QStringLiteral("actionDashDotDotLine"));
        actionCustomDashLine = new QAction(MainWindow);
        actionCustomDashLine->setObjectName(QStringLiteral("actionCustomDashLine"));
        actionUpload = new QAction(MainWindow);
        actionUpload->setObjectName(QStringLiteral("actionUpload"));
        actionDataBase_Configure = new QAction(MainWindow);
        actionDataBase_Configure->setObjectName(QStringLiteral("actionDataBase_Configure"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_8 = new QHBoxLayout(centralWidget);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(198, 16777215));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        System_Parameters = new QGroupBox(groupBox);
        System_Parameters->setObjectName(QStringLiteral("System_Parameters"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(System_Parameters->sizePolicy().hasHeightForWidth());
        System_Parameters->setSizePolicy(sizePolicy);
        System_Parameters->setMaximumSize(QSize(175, 16777215));
        verticalLayout = new QVBoxLayout(System_Parameters);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, 11, -1);
        autozerocheckBox = new QCheckBox(System_Parameters);
        autozerocheckBox->setObjectName(QStringLiteral("autozerocheckBox"));

        verticalLayout->addWidget(autozerocheckBox);

        negativecurrentcheckBox = new QCheckBox(System_Parameters);
        negativecurrentcheckBox->setObjectName(QStringLiteral("negativecurrentcheckBox"));
        negativecurrentcheckBox->setChecked(false);

        verticalLayout->addWidget(negativecurrentcheckBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        zeroerrorlabel = new QLabel(System_Parameters);
        zeroerrorlabel->setObjectName(QStringLiteral("zeroerrorlabel"));

        horizontalLayout->addWidget(zeroerrorlabel);

        zeroerrorlineEdit = new QLineEdit(System_Parameters);
        zeroerrorlineEdit->setObjectName(QStringLiteral("zeroerrorlineEdit"));

        horizontalLayout->addWidget(zeroerrorlineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        zerodriftlabel = new QLabel(System_Parameters);
        zerodriftlabel->setObjectName(QStringLiteral("zerodriftlabel"));

        horizontalLayout_2->addWidget(zerodriftlabel);

        zerodriftlineEdit = new QLineEdit(System_Parameters);
        zerodriftlineEdit->setObjectName(QStringLiteral("zerodriftlineEdit"));

        horizontalLayout_2->addWidget(zerodriftlineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        showsystemButton = new QPushButton(System_Parameters);
        showsystemButton->setObjectName(QStringLiteral("showsystemButton"));

        horizontalLayout_3->addWidget(showsystemButton);

        setsystemButton = new QPushButton(System_Parameters);
        setsystemButton->setObjectName(QStringLiteral("setsystemButton"));

        horizontalLayout_3->addWidget(setsystemButton);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_4->addWidget(System_Parameters);

        Work_Mode = new QGroupBox(groupBox);
        Work_Mode->setObjectName(QStringLiteral("Work_Mode"));
        Work_Mode->setEnabled(true);
        Work_Mode->setMaximumSize(QSize(16777215, 16777213));
        verticalLayout_2 = new QVBoxLayout(Work_Mode);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, 12, -1);
        Mode1checkBox = new QCheckBox(Work_Mode);
        Mode1checkBox->setObjectName(QStringLiteral("Mode1checkBox"));
        Mode1checkBox->setMinimumSize(QSize(119, 20));
        Mode1checkBox->setMaximumSize(QSize(119, 20));
        Mode1checkBox->setChecked(true);

        verticalLayout_2->addWidget(Mode1checkBox);

        Mode2checkBox = new QCheckBox(Work_Mode);
        Mode2checkBox->setObjectName(QStringLiteral("Mode2checkBox"));
        Mode2checkBox->setMinimumSize(QSize(119, 20));
        Mode2checkBox->setMaximumSize(QSize(119, 20));

        verticalLayout_2->addWidget(Mode2checkBox);

        Mode3checkBox = new QCheckBox(Work_Mode);
        Mode3checkBox->setObjectName(QStringLiteral("Mode3checkBox"));
        Mode3checkBox->setMinimumSize(QSize(119, 20));
        Mode3checkBox->setMaximumSize(QSize(119, 20));

        verticalLayout_2->addWidget(Mode3checkBox);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(Work_Mode);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        svaluelineEdit = new QLineEdit(Work_Mode);
        svaluelineEdit->setObjectName(QStringLiteral("svaluelineEdit"));
        svaluelineEdit->setMinimumSize(QSize(61, 21));
        svaluelineEdit->setMaximumSize(QSize(61, 21));

        horizontalLayout_4->addWidget(svaluelineEdit);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(Work_Mode);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        cvaluelineEdit = new QLineEdit(Work_Mode);
        cvaluelineEdit->setObjectName(QStringLiteral("cvaluelineEdit"));
        cvaluelineEdit->setMinimumSize(QSize(61, 20));
        cvaluelineEdit->setMaximumSize(QSize(61, 20));

        horizontalLayout_5->addWidget(cvaluelineEdit);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(Work_Mode);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3);

        tvaluelineEdit = new QLineEdit(Work_Mode);
        tvaluelineEdit->setObjectName(QStringLiteral("tvaluelineEdit"));
        tvaluelineEdit->setMinimumSize(QSize(61, 21));
        tvaluelineEdit->setMaximumSize(QSize(61, 21));

        horizontalLayout_6->addWidget(tvaluelineEdit);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_4->addWidget(Work_Mode);

        splitter->addWidget(groupBox);
        Data_Receive_Area = new QGroupBox(splitter);
        Data_Receive_Area->setObjectName(QStringLiteral("Data_Receive_Area"));
        Data_Receive_Area->setMaximumSize(QSize(190, 16777215));
        verticalLayout_3 = new QVBoxLayout(Data_Receive_Area);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        receivetextEdit = new QTextEdit(Data_Receive_Area);
        receivetextEdit->setObjectName(QStringLiteral("receivetextEdit"));

        verticalLayout_3->addWidget(receivetextEdit);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        recover = new QPushButton(Data_Receive_Area);
        recover->setObjectName(QStringLiteral("recover"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(9);
        font.setBold(false);
        font.setWeight(50);
        recover->setFont(font);

        horizontalLayout_7->addWidget(recover);

        startButton = new QPushButton(Data_Receive_Area);
        startButton->setObjectName(QStringLiteral("startButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setBold(false);
        font1.setWeight(50);
        startButton->setFont(font1);
        startButton->setStyleSheet(QStringLiteral(""));

        horizontalLayout_7->addWidget(startButton);

        clearButton = new QPushButton(Data_Receive_Area);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        horizontalLayout_7->addWidget(clearButton);


        verticalLayout_3->addLayout(horizontalLayout_7);

        splitter->addWidget(Data_Receive_Area);
        chartWidget = new QWidget(splitter);
        chartWidget->setObjectName(QStringLiteral("chartWidget"));
        chartLayout = new QHBoxLayout(chartWidget);
        chartLayout->setSpacing(6);
        chartLayout->setContentsMargins(11, 11, 11, 11);
        chartLayout->setObjectName(QStringLiteral("chartLayout"));
        splitter->addWidget(chartWidget);

        horizontalLayout_8->addWidget(splitter);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1129, 21));
        menuCalls = new QMenu(menuBar);
        menuCalls->setObjectName(QStringLiteral("menuCalls"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuChartTheme = new QMenu(menuTools);
        menuChartTheme->setObjectName(QStringLiteral("menuChartTheme"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuFiles = new QMenu(menuBar);
        menuFiles->setObjectName(QStringLiteral("menuFiles"));
        menuDate = new QMenu(menuBar);
        menuDate->setObjectName(QStringLiteral("menuDate"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFiles->menuAction());
        menuBar->addAction(menuCalls->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuDate->menuAction());
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
        menuDate->addAction(actionUpload);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionConnect->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        actionDisconnect->setText(QApplication::translate("MainWindow", "Disconnect", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
        actionConfigure->setText(QApplication::translate("MainWindow", "Configure", Q_NULLPTR));
        actionClear->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About System", Q_NULLPTR));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", Q_NULLPTR));
        actionSave_Data->setText(QApplication::translate("MainWindow", "Save Datas", Q_NULLPTR));
        actionSave_Chart->setText(QApplication::translate("MainWindow", "Save Chart", Q_NULLPTR));
        actionQuit_2->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
        actionOpen_file->setText(QApplication::translate("MainWindow", "Open file", Q_NULLPTR));
        actionChartThemeLight->setText(QApplication::translate("MainWindow", "ChartThemeLight", Q_NULLPTR));
        actionChartThemeBlueCerulean->setText(QApplication::translate("MainWindow", "ChartThemeBlueCerulean", Q_NULLPTR));
        actionChartThemeDark->setText(QApplication::translate("MainWindow", "ChartThemeDark", Q_NULLPTR));
        actionChartThemeBrownSand->setText(QApplication::translate("MainWindow", "ChartThemeBrownSand", Q_NULLPTR));
        actionChartThemeBlueNcs->setText(QApplication::translate("MainWindow", "ChartThemeBlueNcs", Q_NULLPTR));
        actionChartThemeHighContrast->setText(QApplication::translate("MainWindow", "ChartThemeHighContrast", Q_NULLPTR));
        actionChartThemeBlueIcy->setText(QApplication::translate("MainWindow", "ChartThemeBlueIcy", Q_NULLPTR));
        actionChartThemeQt->setText(QApplication::translate("MainWindow", "ChartThemeQt", Q_NULLPTR));
        actionfilter->setText(QApplication::translate("MainWindow", "filter", Q_NULLPTR));
        actionFilter->setText(QApplication::translate("MainWindow", "Filter", Q_NULLPTR));
        actionSetLegend->setText(QApplication::translate("MainWindow", "SetLegend", Q_NULLPTR));
        actionCancel_Filter->setText(QApplication::translate("MainWindow", "Cancel Filter", Q_NULLPTR));
        actionChartThemeCustom->setText(QApplication::translate("MainWindow", "ChartThemeCustom", Q_NULLPTR));
        actionSolidLine->setText(QApplication::translate("MainWindow", "SolidLine", Q_NULLPTR));
        actionDashLine->setText(QApplication::translate("MainWindow", "DashLine", Q_NULLPTR));
        actionDotLine->setText(QApplication::translate("MainWindow", "DotLine", Q_NULLPTR));
        actionDashDotLine->setText(QApplication::translate("MainWindow", "DashDotLine", Q_NULLPTR));
        actionDashDotDotLine->setText(QApplication::translate("MainWindow", "DashDotDotLine", Q_NULLPTR));
        actionCustomDashLine->setText(QApplication::translate("MainWindow", "CustomDashLine", Q_NULLPTR));
        actionUpload->setText(QApplication::translate("MainWindow", "Upload", Q_NULLPTR));
        actionDataBase_Configure->setText(QApplication::translate("MainWindow", "DataBase Configure", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "FAIMS Configure", Q_NULLPTR));
        System_Parameters->setTitle(QApplication::translate("MainWindow", "System Parameters", Q_NULLPTR));
        autozerocheckBox->setText(QApplication::translate("MainWindow", "Auto Zero", Q_NULLPTR));
        negativecurrentcheckBox->setText(QApplication::translate("MainWindow", "Negative Current", Q_NULLPTR));
        zeroerrorlabel->setText(QApplication::translate("MainWindow", "Zero Error:", Q_NULLPTR));
        zeroerrorlineEdit->setText(QApplication::translate("MainWindow", "0.5", Q_NULLPTR));
        zerodriftlabel->setText(QApplication::translate("MainWindow", "Zero Drift:", Q_NULLPTR));
        zerodriftlineEdit->setText(QApplication::translate("MainWindow", "50", Q_NULLPTR));
        showsystemButton->setText(QApplication::translate("MainWindow", "Show", Q_NULLPTR));
        setsystemButton->setText(QApplication::translate("MainWindow", "Set", Q_NULLPTR));
        Work_Mode->setTitle(QApplication::translate("MainWindow", "Work Mode", Q_NULLPTR));
        Mode1checkBox->setText(QApplication::translate("MainWindow", "RealTime Mode", Q_NULLPTR));
        Mode2checkBox->setText(QApplication::translate("MainWindow", "Data Processing", Q_NULLPTR));
        Mode3checkBox->setText(QApplication::translate("MainWindow", "Keithley Mode", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "CV Span:", Q_NULLPTR));
        svaluelineEdit->setText(QApplication::translate("MainWindow", "13", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Density:", Q_NULLPTR));
        cvaluelineEdit->setText(QApplication::translate("MainWindow", "1000", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Step Size:", Q_NULLPTR));
        tvaluelineEdit->setText(QApplication::translate("MainWindow", "10", Q_NULLPTR));
        Data_Receive_Area->setTitle(QApplication::translate("MainWindow", "Data Receive Area", Q_NULLPTR));
        recover->setText(QApplication::translate("MainWindow", "Reset", Q_NULLPTR));
        startButton->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        clearButton->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        menuCalls->setTitle(QApplication::translate("MainWindow", "Calls", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
        menuChartTheme->setTitle(QApplication::translate("MainWindow", "ChartTheme", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        menuFiles->setTitle(QApplication::translate("MainWindow", "Files", Q_NULLPTR));
        menuDate->setTitle(QApplication::translate("MainWindow", "Database", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
