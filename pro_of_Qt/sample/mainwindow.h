#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "serialportsetting.h"
#include <QMainWindow>
#include <QtCharts>
#include <QDialog>
#include <QFileDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

/*ui*/
private:
    Ui::MainWindow *ui;
    void data_Show();
    QString str_dataShow;

/*serial port*/
private:
    void serial_Port_open();
    void serial_Port_close();
    void data_Read();
    void data_write(const QByteArray &data);
    void start();


    SerialPortSetting *m_settings = nullptr;
    QSerialPort *m_serial = nullptr;

/*chart*/
private:
    void chart_Init();
    void set_Pen_Format();
    void line_New();
    void clear();

    QPen pen;
    QChartView *m_chartview;
    QChart *m_chart;
    QValueAxis *axisX;
    QValueAxis *axisY;
    QLineSeries *m_series;

/*file and data*/
private:
    void open_File_Selected();
    void file_Open();
    void str_To_Num(const QString &str, QPointF &point);
    bool contain_Num(QString str);

    float currentymax;
    float currentymin;
    int i =0;

    QList<QPointF> m_points;
    QFileDialog *filedialog;
    QVector<double> m_pointsX;
    QVector<double> m_pointsY;
    


};
#endif // MAINWINDOW_H
