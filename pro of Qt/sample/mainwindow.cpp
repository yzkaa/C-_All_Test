#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts>
#include <QPushButton>
#include <QFileDialog>
QT_CHARTS_USE_NAMESPACE
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      m_settings(new SerialPortSetting),
      m_serial(new QSerialPort(this))
{
    ui->setupUi(this);
    showMaximized();
    filedialog = new QFileDialog(this);
    chart_Init();
    connect(ui->select, &QAction::triggered,this,&MainWindow::file_Open);
    connect(ui->clear,&QAction::triggered,this,&MainWindow::clear);
    connect(ui->clearButton,&QPushButton::clicked,this,&MainWindow::clear);
    connect(ui->startButton,&QPushButton::clicked,this,&MainWindow::start);
    connect(ui->actionConnect, &QAction::triggered, this, &MainWindow::serial_Port_open);
    connect(ui->actionDisconnect, &QAction::triggered, this, &MainWindow::serial_Port_close);
    connect(ui->actionConfigure, &QAction::triggered, m_settings, &SerialPortSetting::show);
    connect(m_serial,SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(handle_Error_Info(QSerialPort::SerialPortError)));
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::data_Read);

    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);



}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_settings;
    ui->portNameLabel->clear();
    ui->BaudRateLabel->clear();
    ui->dataBitsLabel->clear();
    ui->parityLabel->clear();
    ui->stopBitsLabel->clear();
}

void MainWindow::chart_Init(){
    m_chart = new QChart;
    m_chartview = new QChartView(m_chart);
    m_chartview->setRenderHint(QPainter::Antialiasing);
    m_chart->setTheme(QChart::ChartThemeHighContrast);
    m_series = new QLineSeries;

    axisX = new QValueAxis;
    axisX->setRange(-14, 14);
    axisX->setLabelFormat("%g");
    axisX->setMinorTickCount(6);
    axisX->setTitleText(QStringLiteral("X"));
    axisX->linePenColor();

    axisY = new QValueAxis;
    axisY->setRange(-2, 2);
    axisY->setLabelFormat("%g");
    axisY->setMinorTickCount(6);
    axisY->setTitleText(QStringLiteral("Y"));
    axisY->linePenColor();

    m_chart->setAxisX(axisX, m_series);
    m_chart->setAxisY(axisY, m_series);
    m_chart->legend()->hide();

    QFont font;
    font.setPixelSize(20);
    font.setBold(true);
    m_chart->setTitleFont(font);
    ui->chartLayout->addWidget(m_chartview);

}


void MainWindow::set_Pen_Format(){
    pen.setColor(QColor(qrand()%256,qrand()%256,qrand()%256));
    pen.setWidth(3);
}


void MainWindow::line_New(){
    m_series = new QLineSeries;
    m_chart->addSeries(m_series);
    m_chart->setAxisX(axisX, m_series);
    m_chart->setAxisY(axisY, m_series);
    set_Pen_Format();
    m_series->setPen(pen);

}


void MainWindow::file_Open(){
    //delete filedialog;
    filedialog = new QFileDialog(this);
    filedialog->setWindowTitle("Open Data File");
    filedialog->setAcceptMode(QFileDialog::AcceptOpen);
    QStringList filters;
    filters<<"Text File(*.txt)";

    filedialog->setNameFilters(filters);
    connect(filedialog, SIGNAL(accepted()), this, SLOT(openFileSelected()));
    filedialog->show();
}
void MainWindow::open_File_Selected(void)
{
    m_points.clear();
    m_pointsX.clear();
    m_pointsY.clear();
    line_New();

    QString filename = filedialog->selectedFiles()[0];
    QString file_name;
    QFileInfo fi;
    int index;
    fi=QFileInfo(filename);
    file_name = fi.fileName();//获取文件名
    index = file_name.lastIndexOf(".");//去掉后缀
    file_name.truncate(index);
    m_series->setName(file_name);

    if (!filename.isEmpty()) {
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, tr("Open Datas File"), tr("Can not open file:\n%1").arg(filename));
            return;
        }
        QTextStream in(&file);
        QPointF point;
        QString str;
        m_points.clear();
        while (!in.atEnd()) {
            str = in.readLine();
            if (!str.endsWith("\r\n")) {
                str.append(QStringLiteral("\r\n"));
            }
            if(contain_Num(str)){
                str_To_Num(str, point);
                if (point.y() > currentymax) {
                    currentymax = point.y();
                    if ((point.y() - currentymax) < 5) {
                        axisY->setMax(currentymax + 10);
                    }
                }
                if (point.y() < currentymin) {
                    currentymin = point.y();
                    if ((currentymin - axisY->min()) < 5) {
                        axisY->setMin(currentymin - 10);
                    }
                }
                m_pointsX<<point.x();
                m_pointsY<<point.y();


                m_points<<point;


            }
            str.clear();
        }
        m_series->append(m_points);

        file.close();
        double x = m_series->at(1).x();
        axisX->setRange(x-1,i+1);
        i=0;
        QMessageBox::information(this, tr("Open Datas File"), tr("The data file was opened successfully."));
    }

}

void MainWindow::str_To_Num(const QString &str, QPointF &point)
{

    QString temp_str = str;
    quint8 str_size = temp_str.size();
    temp_str.remove((str_size - 2), 2); //将数据包的"\r\n"移除
    str_dataShow=temp_str;
    bool ok=true;
    int y=temp_str.toUInt(&ok,16);
    data_Show();
    point.setY(y); //获得数值
    temp_str.clear();
    point.setX(++i);
}

void MainWindow::clear()
{
    m_chart->removeAllSeries();
    m_points.clear();
    ui->portNameLabel->clear();
    ui->BaudRateLabel->clear();
    ui->dataBitsLabel->clear();
    ui->parityLabel->clear();
    ui->stopBitsLabel->clear();


}


bool MainWindow::contain_Num(QString str){
    QByteArray ba = str.toLatin1();//QString 转换为 char*
    const char *s = ba.data();
    while(*s++){
        if ('0'<=*s||'9'>*s)
                return true ;
        }
         return false;
}

void MainWindow::serial_Port_open()
{
    const SerialPortSetting::Settings p = m_settings->settings();
    m_serial->setPortName(p.name);
    m_serial->setBaudRate(p.baudRate);
    m_serial->setDataBits(p.dataBits);
    m_serial->setParity(p.parity);
    m_serial->setStopBits(p.stopBits);
    m_serial->setFlowControl(p.flowControl);

    if (m_serial->open(QIODevice::ReadWrite)) {
        QMessageBox::critical(this,tr("Serial Port"),tr("The connection was successful."));
        {
            ui->portNameLabel->setText(p.name);
            ui->BaudRateLabel->setText(p.stringBaudRate);
            ui->dataBitsLabel->setText(p.stringDataBits);
            ui->parityLabel->setText(p.stringParity);
            ui->stopBitsLabel->setText(p.stringStopBits);
        }
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionConfigure->setEnabled(false);

    } else {
        QMessageBox::critical(this, tr("Error"), m_serial->errorString());
    }

}

void MainWindow::serial_Port_close()
{
    if (m_serial->isOpen()) {
        m_serial->close();
    }
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
}

void MainWindow::data_write(const QByteArray &data)
{
    m_serial->write(data);
}

void MainWindow::data_Read()
{
    static QString string;
    static QList<QPointF> points;
    string += m_serial->readAll();
    while (string.endsWith("\r\n")) {
        int pos = string.indexOf("\r\n");   //找到"\r\n"的位置
        QString temp_string = string.left(pos+2);   //根据得到的位置取出首个数据包

            QPointF point;

            str_To_Num(temp_string, point); //将数据点进行输出
            if (point.y() > currentymax) {
                currentymax = point.y();
                if ((axisY->max() - currentymax) < 5) {
                    axisY->setMax(currentymax + 10);
                }
            }
            if (point.y() < currentymin) {
                currentymin = point.y();
                if ((currentymin - axisY->min()) < 5) {
                    axisY->setMin(currentymin - 10);
                }
            }
            points << point;
            m_pointsX<<point.x();
            m_pointsY<<point.y();
        string.remove(temp_string);//继续处理下一个"\r\n"结尾的字符串
    }

    m_series->append(points);//画图
    points.clear();                //清除容器内已存在的点
}



//TODO: communication protocol

void MainWindow::start()
{
//   QString command;
   m_points.clear();
   line_New();
//   currentymax=0;
//   QString S,C,T;
//   double x = 13;
//   //axisX->setRange((x - 2*x) - 0.5, x + 0.5);
//   double y = (-2046/13.0*x) + 2046;
//   quint16 y_ = quint16(y);
//   S = QString::number(y_);
//   while (S.size() < 4) {
//       S.insert(0, "0");
//   }
//   C = "1000";
//   while (C.size() < 4) {
//       C.insert(0, "0");
//   }
//   T = "10";
//   while (T.size() < 4) {
//       T.insert(0, "0");
//   }
//   command.append("S").append(S);
//   command.append("C").append(C);
//   command.append("T").append(T);
//   data_write(&command.toStdString()[0]);


}

void MainWindow::data_Show(){
    if(!m_points.isEmpty()){
        ui->dataShow->appendPlainText(str_dataShow);
    }
    else{
        return;
    }
}
