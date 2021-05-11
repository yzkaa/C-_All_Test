#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QLabel>

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLineSeries>
#include <QFileDialog>
#include <QDialog>
#include <QtCharts/QChartGlobal>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGraphicsGridLayout>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QScatterSeries>
#include <QTimer>

#include "settingdialog.h"
#include "spectrogramdialog.h"
#include "utils.h"
#include "DataBase/databasedialog.h"
#include "DataBase/databaseinsertdialog.h"
#include "DataBase/databaseconnectdialog.h"
#include "DataBase/databaseserver.h"
#include "serverdialog.h"
#include "allsettingsdialog.h"
#include "UDP/networkserver.h"

QT_BEGIN_NAMESPACE

class QLabel;


namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

using namespace QtCharts;

class SettingsDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void inSertToDatabase(DBValues data);
    void peakParamsCalculation(QList<QPointF> &data);
    void receiveNewData(const QList<QPointF> &data);
private slots:
    void openSerialPort(void);
    void closeSerialPort(void);
    void about(void);
    void writeData(const QByteArray &data);
    void readData(void);
    void handleError(QSerialPort::SerialPortError error);
    void on_startButton_clicked();
    void updateSvalue(void);
    void on_clearButton_clicked();
    void on_recoverButton_clicked();

    void seriesListClear();

//    void opendatafile(void);
    void opendatafileSelected(void);
    void savedatas(void);
    void savedatasfileSelected();
    void savewaveform(void);
    void savewaveformfileSelected();

    void on_showsystemButton_clicked();
    void on_setsystemButton_clicked();
    void zeroerrorvalue(void);
    void zerodriftvalue(void);
    void svalue(void);
    void cvalue(void);
    void tvalue(void);
    void on_actionFilter_triggered();
    void on_actionCancel_Filter_triggered();
    void estimate(bool flag);

    void pointHoverd(const QPointF &point, bool state);
    void setPenFormat();
    void newLine(const QList<QPointF> &data);
    void getExtreMum(QList<QPointF> &data);

    void contextMenuEvent(QContextMenuEvent *); //右键菜单
    void mousePressEvent(QMouseEvent *event);
    void showextremeValue();
    void pointClickedO(const QPointF &point);
    void pointClickedF(const QPointF &point);
    void maxPointHoverd(const QPointF &point, bool state);

    //Legend setting
    void toggleAttached();
    void Set_Legend();
    void setLegendAlignment();
    void toggleBold();
    void toggleItalic();
    void fontSizeChanged();
    void updateLegendLayout();



    void chart_Theme_0();
    void chart_Theme_1();
    void chart_Theme_2();
    void chart_Theme_3();
    void chart_Theme_4();
    void chart_Theme_5();
    void chart_Theme_6();
    void chart_Theme_7();


    //指纹图谱
    void initFingerprintSpectrum();
    //数据上传处理
    void currentDataToCloudServer();
    //峰参数显示相关
    void peakParametersInforShow(double FWHM, double Area);
    //多条曲线峰参数计算
    void multipleCurvesCalculation();

    //数据库
    void actionDatabaseTrigger();
    void showInSertDBDialog();
    void currentDataInputToDatabase(DBValues data);
    void exportDataToDraw(QVector<QList<QPointF>> &data);

    void SettingsTrigger();

private:
    void initWidget(void);
    void initActionsConnect(void);
    void initNetworkServer();   //初始UDP
    void initDatabase();       //初始化数据库
    void chartInit();
    void showStatusMessage(const QString &message);
    void smartInserText(const QString &str);
    void strtovoltageandcurrent(const QString &str, QPointF &point);
    void yvalueback(void);
    void filter();
    void showLegendSpinbox();
    void hideLegendSpinbox();



private:
    Ui::MainWindow *m_ui = nullptr;


    QLabel *m_status = nullptr;
    SettingDialog *m_settings = nullptr;
    QSerialPort *m_serial = nullptr;

    //参数配置界面
    AllSettingsDialog *allSettingsDialog = nullptr;
    //指纹谱图
    SpectrogramDialog *spectrogramDialog = nullptr;

    //峰参数相关
    //显示面积，半峰宽用
    int currentymaxIndex;
    //面积参数
    double TriangleArea=0;
    double PeakArea=0;
    //峰参数显示
    QLabel *peakParametersShow = nullptr;
    int Index;

    //chart
    QLineSeries *m_series;
    QLineSeries *filterSeries;
    QScatterSeries *m_scatter;
    QScatterSeries *m_scatter1;
    QChart *m_chart;
    QChartView *m_chartview;
    QValueAxis *axisX;
    QValueAxis *axisY;
    QLabel *m_valueLabel;
    QPen pen;
    QLabel *m_maxLabel;

    //多条QLineSeries时的保存，与访问
    QList<QLineSeries *> seriesList;
    //filter 曲线也要保存


    //实时保存接收数据的最大和最小值
    float currentymax;
    float currentymin;
    QVector<QList<QPointF>> currentAllDate;  //跟踪保存当前数据
    QString seriesName;

    //用于文件操作
    QFileDialog *filedialog = nullptr;
    QList<QPointF> m_points;
    QList<QPointF> maxDataListO;
    QList<QPointF> maxDataListF;
    QPointF maxFilteredData;
    QPointF maxOriginData;
    QPointF currentMaxData;




    QDialog *Legend_dialog = nullptr;

    QGridLayout *m_mainLayout;
    QGridLayout *m_buttonLayout;
    QGridLayout *m_fontLayout;

    QDoubleSpinBox *m_fontSize;

    // For detached layout
    QGroupBox *m_legendSettings;
    QDoubleSpinBox *m_legendPosX;
    QDoubleSpinBox *m_legendPosY;
    QDoubleSpinBox *m_legendWidth;
    QDoubleSpinBox *m_legendHeight;


    //数据库
    DataBaseDialog *dbDialog = nullptr;
    DatabaseInsertDialog *dbInsertDialog = nullptr;
    DatabaseServer *dbServer = nullptr;
    int curvesNum = 0;
    //UDP相关
    NetworkServer *networkServer = nullptr;

    //Flags
    int clicked=0;
    int filteredLineNum=0;
    int lineNum=0;
    int i=0;
    bool flag=false;
    bool filterFlag=false;
    int maxClickedFlag=0;

    bool isPPCalculation = false;

    //test
    int time = 0;

};

#endif // MAINWINDOW_H
