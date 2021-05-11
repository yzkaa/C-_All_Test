#ifndef SPECTROGRAMDIALOG_H
#define SPECTROGRAMDIALOG_H

#include <QDialog>
#include <QScreen>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>
#include <QLineEdit>
#include <QScreen>
#include <QPointF>
#include <QList>

//#include "xlsxdocument.h"
//#include "xlsxworkbook.h"
#include "utils.h"

#include <qwt_plot.h>
#include <qwt_color_map.h>
#include <qwt_scale_widget.h>
#include <qwt_scale_draw.h>
#include <qwt_plot_spectrogram.h>
#include <qwt_matrix_raster_data.h>
namespace Ui {
class SpectrogramDialog;
}

class LinearColorMapRGB : public QwtLinearColorMap
{
public:
    LinearColorMapRGB() :
        QwtLinearColorMap(Qt::blue, Qt::red, QwtColorMap::RGB)
    {
//        addColorStop(0,QColor(0,0,0));  //QColor(r,g,b);   颜色拐点参照colormap jet
        addColorStop(0.125,QColor(0,0,255));
        addColorStop(0.375,QColor(0,255,255));
        addColorStop(0.625,QColor(255,255,0));
        addColorStop(0.875,QColor(255,0,0));
//        addColorStop(1,QColor(128,0,0));
    }
};

class SpectrogramDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SpectrogramDialog(QWidget *parent = 0);
    ~SpectrogramDialog();

    enum GET_DATA_MODES
    {
        FILE_OPEN,
        LOWER_MACHINE
    };

    void Initialization();
    void CoustemConnects();

    //用于Excel汇总形式的数据读取
    void Int_To26_QString(int mydata,QString &res);
    QString Columns_identifier(int columns);

signals:
    void DrawSpectrogram(QVector<double> &SpectrogramData); //信号
    void ControlStateChange(int State);
public slots:
    void toDrawSpectrogram(QVector<double> &SpectrogramData);//引用在实参处就可以直接写，指针得在实参处加&

    //外部数据传输
    void getSpectrogramParameter(QVector<QList<QPointF> > &data, double yMin, double yMax, double xMin, double xMax);
private slots:
    void on_pushButton_OpenFile_clicked();


    void on_BackgroundColorChange();
    void on_ControlStateChange(int State);

    //监听状态变化
    bool event(QEvent *event);

    void showEnhance();
    //预处理
    void Pre_processing();
    void on_pushButton_Remove_clicked();

    void on_pushButton_Back_clicked();

    void on_pushButton_Change_clicked();

    void on_pushButton_SaveSpectrogram_clicked();
private:
    Ui::SpectrogramDialog *ui;

    //批量处理相关
    QList<QLineEdit *> LineEditList;

    //谱图相关类
    QwtPlot *myPlot;
    QwtPlotSpectrogram *mySpectrogram;
    QwtMatrixRasterData *mydata;
    QwtLinearColorMap *myColorMap;
    QwtScaleWidget *rightAxis;
    LinearColorMapRGB *colormap;
    LinearColorMapRGB *colorbar;
    //谱图显示布局
    QVBoxLayout *myMainlayout;

    //数据
    QVector<QVector<double>> InitData;  //原始数据
    QVector<double> Data;  //数据
    int xMin = -10;
    int xMax = 10;
    int yMin = 100;
    int yMax;
    int step = 10;
    int dataYAxis = yMin;
    int matrixColumn = 0;  //射频电压数数据长度（行数），用做栅格数值矩阵的列数
    int mycolumns = 0; //列数
    double maxdata = 10;  //全部数据的最大最小值
    double mindata = 0;

    //Excle数据读取相关
    QString m_str;
    QChar ch;

    //flag
    int ControlState = -1;
    int CurrentState = -1;
    int getDataMode;
};

#endif // SPECTROGRAMDIALOG_H
