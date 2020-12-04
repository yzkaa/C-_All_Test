#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QLabel>
#include "settingdialog.h"
#include "frminput.h"
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
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
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
    void connectIsOK();


private slots:
    void about(void);

    void openSerialPort(void);
    void closeSerialPort(void);
    void writeData(const QByteArray &data);
    void readData(void);
    void handleError(QSerialPort::SerialPortError error);
    void updateSvalue(void);
    void autoOpenSerialPort();

    void on_clearButton_clicked();
    void on_startButton_clicked();
    void on_recoverButton_clicked();
    void opendatafile(void);
    void opendatafileSelected(void);
    void savedatas(void);
    void savedatasfileSelected();
    void savewaveform(void);
    void savewaveformfileSelected();
    void closeConfigure();

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

    void removeSeries();
    void handleMarkerClicked();
    void connectMarkers();
    void disconnectMarkers();

    void pointHoverd(const QPointF &point, bool state);
    void setPenFormat();
    void newLine();
    void contextMenuEvent(QContextMenuEvent *);
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
    void chart_Theme_8();

private:
    void initWidget(void);
    void initActionsConnect(void);
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
    QString COMData;
    QList<QPointF> COMPoint;

    //chart
    QList<QLineSeries *> series;
    QLineSeries* m_series;
    QScatterSeries *m_scatter;
    QScatterSeries *m_scatter1;
    QChart *m_chart;
    QChartView *m_chartview;
    QValueAxis *axisX;
    QValueAxis *axisY;
    QLabel *m_valueLabel;
    QPen pen;
    QLabel *m_maxLabel;
    QList<QString> seriesName;

    //实时保存接收数据的最大和最小值
    float currentymax;
    float currentymin;

    //用于文件操作
    QFileDialog *filedialog;
    QList<QPointF> m_points;
    QList<QPointF> maxDataListO;
    QList<QPointF> maxDataListF;
    QPointF maxFilteredData;
    QPointF maxOriginData;
    QPointF currentMaxData;
    QString file_name;

    QDialog *Legend_dialog;

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



    //Flags
    int clicked=0;
    int filteredLineNum=0;
    int lineNum=0;
    int i=0;
    int x=0;
    bool flag=false;
    bool filterFlag=false;
    int maxClickedFlag=0;
    bool COMFlag=false;
};

#endif // MAINWINDOW_H
