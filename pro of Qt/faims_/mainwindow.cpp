#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingdialog.h"
#include "frminput.h"
#include "ui_settingdialog.h"
#include <QMessageBox>
#include <QDebug>
#include <QScrollBar>
#include <QtGui>
#include <QtWidgets>
#include <QChartView>
#include <QChart>
#include <QtCharts/QChartView>
#include <QRubberBand>
#include <QtCharts/QLegend>
#include <QtCharts/QLegendMarker>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtWidgets/QFormLayout>
#include <QPushButton>
#include <QScatterSeries>
//#include <QLinearGradient>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_status(new QLabel),
    m_settings(new SettingDialog),
    m_serial(new QSerialPort(this))
{
    m_ui->setupUi(this);
    filedialog = new QFileDialog(this);

    setWindowTitle(tr("FAIMS SerialPort"));
    setWindowIcon(QIcon(":/images/mainwindow.png"));

    showMaximized();
    setWindowFlags(Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint);

    chartInit();

    connect(m_ui->svaluelineEdit, &QLineEdit::editingFinished,this, &MainWindow::updateSvalue);

    initWidget();
    initActionsConnect();


    //connect(m_serial, &QSerialPort::errorOccurred, this, &MainWindow::handleError);
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);

    currentymax = axisY->max();   //获取当前y轴的初始最大值
    currentymin = axisY->min();   //获取当前y轴的初始最小值
    m_ui->receivetextEdit->setProperty("noinput", true);

    //检测输入的数值是否有效
    connect(m_ui->zeroerrorlineEdit, &QLineEdit::editingFinished, this, &MainWindow::zeroerrorvalue);
    connect(m_ui->zerodriftlineEdit, &QLineEdit::editingFinished, this, &MainWindow::zerodriftvalue);
    connect(m_ui->svaluelineEdit, &QLineEdit::editingFinished, this, &MainWindow::svalue);
    connect(m_ui->cvaluelineEdit, &QLineEdit::editingFinished, this, &MainWindow::cvalue);
    connect(m_ui->tvaluelineEdit, &QLineEdit::editingFinished, this, &MainWindow::tvalue);

}

MainWindow::~MainWindow()
{

    delete m_ui;
//    delete m_settings;
//    delete filedialog;
//    delete Legend_dialog;
}

void MainWindow::initWidget(void)
{

    m_ui->actionConnect->setIcon(QIcon(":/images/connect.png"));
    m_ui->actionConnect->setStatusTip(tr("Connect to the serial port of the Faims system MCU."));
    m_ui->actionDisconnect->setIcon(QIcon(":/images/disconnect.png"));
    m_ui->actionDisconnect->setStatusTip(tr("Disconnect to the serial port of the Faims system MCU."));
    m_ui->actionConfigure->setIcon(QIcon(":/images/settings.png"));
    m_ui->actionConfigure->setStatusTip(tr("Faims system serial port configuration."));
    m_ui->actionQuit_2->setIcon(QIcon(":/images/application-exit.png"));
    m_ui->actionQuit_2->setStatusTip(tr("Exit the program."));
    m_ui->actionClear->setIcon(QIcon(":/images/clear.png"));
    m_ui->actionClear->setStatusTip(tr("Clear data and waveform."));
    m_ui->actionOpen_file->setIcon(QIcon(":/images/fileopen.png"));
    m_ui->actionOpen_file->setStatusTip(tr("Open a data file."));
    m_ui->actionSave_Data->setIcon(QIcon(":/images/filesave.png"));
    m_ui->actionSave_Data->setStatusTip(tr("Save the collected data to a file."));
    m_ui->actionSave_Chart->setIcon(QIcon(":/images/savechart.ico"));
    m_ui->actionSave_Chart->setStatusTip(tr("Save the image file of the displayed waveform."));
    m_ui->actionUpload->setIcon(QIcon(":/images/upload.png"));
    m_ui->actionUpload->setStatusTip(tr("Upload the collected data to database."));


    m_ui->mainToolBar->addAction(m_ui->actionOpen_file);
    m_ui->mainToolBar->addAction(m_ui->actionSave_Data);
    m_ui->mainToolBar->addAction(m_ui->actionSave_Chart);
    m_ui->mainToolBar->addAction(m_ui->actionConnect);
    m_ui->mainToolBar->addAction(m_ui->actionDisconnect);
    m_ui->mainToolBar->addAction(m_ui->actionConfigure);
    m_ui->mainToolBar->addAction(m_ui->actionUpload);
    m_ui->mainToolBar->addAction(m_ui->actionQuit_2);

    m_ui->actionConnect->setEnabled(true);
    m_ui->actionDisconnect->setEnabled(false);
    m_ui->actionQuit->setEnabled(true);
    m_ui->actionConfigure->setEnabled(true);
    m_ui->actionFilter->setEnabled(false);

    m_ui->statusBar->addWidget(m_status);
    m_ui->actionCancel_Filter->setEnabled(false);

    m_points.clear();
}
void MainWindow::chartInit(){
    //chart_begin
    m_valueLabel = new QLabel(this);
    m_valueLabel->setStyleSheet(QString("QLabel{color:#000000; font-family:\"Microsoft Yahei\"; font-size:18px; font-weight:bold;"
                                        " background-color:rgba(21, 100, 255, 51); border-radius:2px; text-align:center;}"));
    m_valueLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//21 100 255 51#1564FF
    QRect r(200,70,200,70);
    m_valueLabel->setGeometry(r);
    m_valueLabel->hide();

    m_maxLabel = new QLabel(this);
    m_maxLabel->hide();

    m_chart = new QChart();
    m_chartview = new QChartView(m_chart);
    m_chartview->setRenderHint(QPainter::Antialiasing);
    m_chart->setTheme(QChart::ChartThemeHighContrast);
    m_series = new QLineSeries;
    m_scatter = new QScatterSeries;
    m_scatter1 = new QScatterSeries;

    axisX = new QValueAxis(this);
    axisX->setRange(-14, 14);
    axisX->setLabelFormat("%g");
    axisX->setMinorTickCount(6);
    axisX->setTitleText(QStringLiteral("Voltage(V)"));
    axisX->linePenColor();

    axisY = new QValueAxis(this);
    axisY->setRange(-2, 2);
    axisY->setLabelFormat("%g");
    axisY->setMinorTickCount(6);
    axisY->setTitleText(QStringLiteral("Current(pA)"));
    axisY->linePenColor();

    m_chart->setAxisX(axisX, m_series);
    m_chart->setAxisY(axisY, m_series);
    m_chart->legend()->hide();

    m_chart->setTitle(QStringLiteral("FAIMS Spectrum"));
    QFont font;
    font.setPixelSize(20);
    font.setBold(true);
    m_chart->setTitleFont(font);
    m_ui->chartLayout->addWidget(m_chartview);
    //chart_end
}

void MainWindow::chart_Theme_0()
{
    m_chart->setTheme(QChart::ChartThemeLight);
}

void MainWindow::chart_Theme_1()
{
    m_chart->setTheme(QChart::ChartThemeBlueCerulean);
}

void MainWindow::chart_Theme_2()
{
    m_chart->setTheme(QChart::ChartThemeDark);
}

void MainWindow::chart_Theme_3()
{
    m_chart->setTheme(QChart::ChartThemeBrownSand);
}

void MainWindow::chart_Theme_4()
{
    m_chart->setTheme(QChart::ChartThemeBlueNcs);
}

void MainWindow::chart_Theme_5()
{
    m_chart->setTheme(QChart::ChartThemeHighContrast);
}

void MainWindow::chart_Theme_6()
{
    m_chart->setTheme(QChart::ChartThemeBlueIcy);
}

void MainWindow::chart_Theme_7()
{
    m_chart->setTheme(QChart::ChartThemeQt);
}

void MainWindow::chart_Theme_8()
{
    // Customize chart background
    QLinearGradient backgroundGradient;
    backgroundGradient.setStart(QPointF(0, 0));
    backgroundGradient.setFinalStop(QPointF(0, 1));
    backgroundGradient.setColorAt(0.0, QRgb(0xd2d0d1));
    backgroundGradient.setColorAt(1.0, QRgb(0xd2d0d1));
    backgroundGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    m_chart->setBackgroundBrush(backgroundGradient);

    // Customize plot area background
    QLinearGradient plotAreaGradient;
    plotAreaGradient.setStart(QPointF(0, 1));
    plotAreaGradient.setFinalStop(QPointF(1, 0));
    plotAreaGradient.setColorAt(0.0, QRgb(0xC6E2FF));
    plotAreaGradient.setColorAt(1.0, QRgb(0xE0EEEE));
    plotAreaGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    m_chart->setPlotAreaBackgroundBrush(plotAreaGradient);
    m_chart->setPlotAreaBackgroundVisible(true);
}

void MainWindow::openSerialPort(void)
{
    const SettingDialog::Settings p = m_settings->settings();
    m_serial->setPortName(p.name);
    m_serial->setBaudRate(p.baudRate);
    m_serial->setDataBits(p.dataBits);
    m_serial->setParity(p.parity);
    m_serial->setStopBits(p.stopBits);
    m_serial->setFlowControl(p.flowControl);

    if (m_serial->open(QIODevice::ReadWrite)) {
        m_ui->actionConnect->setEnabled(false);
        m_ui->actionDisconnect->setEnabled(true);
        m_ui->actionConfigure->setEnabled(false);

        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));

    } else {
        QMessageBox::critical(this, tr("Error"), m_serial->errorString());
        showStatusMessage(tr("Open error."));
    }

}

void MainWindow::closeSerialPort()
{

    if (m_serial->isOpen()) {
        m_serial->close();
    }
    m_ui->actionConnect->setEnabled(true);
    m_ui->actionDisconnect->setEnabled(false);
    m_ui->actionConfigure->setEnabled(true);
    showStatusMessage(tr("Disconnected"));

}

void MainWindow::about(void)
{
    QMessageBox::about(this, tr("About FAIMS SerialPort"),
                             tr("FAIMS SerialPort is a QT application "
                                "that communicates with the FAIMS lower "
                                "computer control center through the serial port."
                                "After the serial port is successfully connected,"
                                "Click the Show button to display the current parameters."
                                "Click the Set button to change the parameters."
                                "Auto Zero selects the auto zero function after selection."
                                "Negative Current supports negative current acquisition after selection."
                                "Zero Error is the range of auto-zero error.It can be set to 0.01~2pA."
                                "Zero Drift is the range of zero drift.It can be set to 0~50pA."
                                "FAIMS SerialPort can be configured with FAIMS lower position machine."
                                "Three working modes,in which CV Span is the compensation "
                                "voltage range of FAIMS system,the value can be in "
                                "the range of 0~13.5V,Density is the sampling point "
                                "of FAIMS system,the value can be in the range of 1~4096,"
                                "Step Size is the step size of sampling,the value is The range "
                                "is from 1 to 1000,corresponding to 10~1010ms."));
}

void MainWindow::writeData(const QByteArray &data)
{
    m_serial->write(data);
}

void MainWindow::readData()
{
    COMData += m_serial->readAll();
    while (COMData.endsWith("\r\n")) {
        int pos = COMData.indexOf("\r\n");   //找到"\r\n"的位置
        QString temp_string = COMData.left(pos + 2);   //根据得到的位置取出首个数据包

        //判断是否是补偿电压与电流的数据包，是的话，提取有效值并且将点存入points容器中
        if (temp_string.contains("V") &&
            temp_string.contains("C") &&
            temp_string.contains("  ")) {
            QPointF point;
            strtovoltageandcurrent(temp_string, point); //将数据点进行输出
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

            COMPoint << point;
        } else if (temp_string.contains("Input_Sys_config")) {
            //设置调零参数
            QString command;
            if (m_ui->autozerocheckBox->isChecked()) {
                command.append("A0001");   //自动调零开
            } else {
                command.append("A0000");   //自动调零关
            }
            if (m_ui->negativecurrentcheckBox->isChecked()) {
                command.append("N0001");    //负电流采集开
            } else {
                command.append("N0000");    //负电流采集关
            }
            qreal z_e = m_ui->zeroerrorlineEdit->text().toDouble();  //获取调零误差
            z_e = z_e * 100;  //放大100倍，单位为pA
            QString str_ZE = QString::number(z_e);
            while (str_ZE.size() < 4) {
                str_ZE.insert(0, "0");
            }
            command.append("O").append(str_ZE);
            QString str_ZD = m_ui->zerodriftlineEdit->text();   //获取零点漂移
            while (str_ZD.size() < 4) {
                str_ZD.insert(0, "0");
            }
            command.append("Z").append(str_ZD);
            writeData(&command.toStdString()[0]);  //将设置命令发送到串口
        }

        smartInserText(temp_string);
        COMData.remove(temp_string);   //继续处理下一个"\r\n"结尾的字符串
    }
    m_series->append(COMPoint);//画图
    COMPoint.clear();                //清除容器内已存在的点

    /*TODELETE*/

}

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), m_serial->errorString());
        closeSerialPort();
    }
}


void MainWindow::initActionsConnect()
{
    connect(m_serial,SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(handleError(QSerialPort::SerialPortError)));
    connect(m_ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
    connect(m_ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
    connect(m_ui->actionQuit_2, &QAction::triggered, this, &MainWindow::close);
    connect(m_ui->actionConfigure, &QAction::triggered, m_settings, &SettingDialog::show);
    connect(m_ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    connect(m_ui->actionAbout_Qt, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(m_ui->actionOpen_file, &QAction::triggered, this, &MainWindow::opendatafile);
    connect(m_ui->actionSave_Data, &QAction::triggered, this, &MainWindow::savedatas);
    connect(m_ui->actionSave_Chart, &QAction::triggered, this, &MainWindow::savewaveform);
    connect(m_ui->actionClear, &QAction::triggered, this, &MainWindow::on_clearButton_clicked);
    connect(m_ui->recover,&QPushButton::clicked,this,&MainWindow::on_recoverButton_clicked);
    connect(m_ui->actionChartThemeLight, &QAction::triggered, this, &MainWindow::chart_Theme_0);
    connect(m_ui->actionChartThemeBlueCerulean, &QAction::triggered, this, &MainWindow::chart_Theme_1);
    connect(m_ui->actionChartThemeDark, &QAction::triggered, this, &MainWindow::chart_Theme_2);
    connect(m_ui->actionChartThemeBrownSand, &QAction::triggered, this, &MainWindow::chart_Theme_3);
    connect(m_ui->actionChartThemeBlueNcs, &QAction::triggered, this, &MainWindow::chart_Theme_4);
    connect(m_ui->actionChartThemeHighContrast, &QAction::triggered, this, &MainWindow::chart_Theme_5);
    connect(m_ui->actionChartThemeBlueIcy, &QAction::triggered, this, &MainWindow::chart_Theme_6);
    connect(m_ui->actionChartThemeQt, &QAction::triggered, this, &MainWindow::chart_Theme_7);
    connect(m_ui->actionChartThemeCustom, &QAction::triggered, this, &MainWindow::chart_Theme_8);
    connect(m_ui->actionSetLegend, &QAction::triggered, this, &MainWindow::Set_Legend);
    connect(m_settings,&SettingDialog::ready,this,&MainWindow::autoOpenSerialPort);
    connect(this,&MainWindow::connectIsOK,this,&MainWindow::closeConfigure);

}

void MainWindow::showStatusMessage(const QString &message)
{
    m_status->setText(message);
}

void MainWindow::smartInserText(const QString &str)
{
    QTextCursor preCursor(m_ui->receivetextEdit->textCursor());

    bool scrollbar;
    QScrollBar *bar = m_ui->receivetextEdit->verticalScrollBar();
    int barValue = bar->value();
    if (barValue == bar->maximum()) {
        scrollbar = true;
    } else {
        scrollbar = false;
    }

    int size(m_ui->receivetextEdit->toPlainText().size() + str.size());
    if (size > 1000) {
        QTextCursor cursor(m_ui->receivetextEdit->textCursor());

        cursor.movePosition(QTextCursor::Start);
        cursor.setPosition(size - 1000, QTextCursor::KeepAnchor);
        //cursor.removeSelectedText();
    }
    m_ui->receivetextEdit->moveCursor(QTextCursor::End);
    m_ui->receivetextEdit->insertPlainText(str);
    m_ui->receivetextEdit->setTextCursor(preCursor);

    if (scrollbar) {
        bar->setValue(bar->maximum());
    } else {
        bar->setValue(barValue);
    }
}

void MainWindow::on_startButton_clicked()
{
   QString command;
   flag=false;
   estimate(flag);
   m_points.clear();
   newLine();
   currentymax=0;
   if (m_ui->Mode1checkBox->isChecked()) {
       command.append("A");
   } else if (m_ui->Mode2checkBox->isChecked()) {
       command.append("D");
   } else if (m_ui->Mode3checkBox->isChecked()) {
       command.append("K");
   } else {
       command.append("S0000C0000T0000");
       writeData(&command.toStdString()[0]);
       return;
   }
   QString S,S_Value,C,T;
   S_Value = m_ui->svaluelineEdit->text();
   double x = S_Value.toDouble();
   qDebug()<<x;
   axisX->setRange((x - 2*x) - 0.5, x + 0.5);

   double y = (-2046/13.0*x) + 2046;
   qDebug()<<y;
   quint16 y_ = quint16(y);
   qDebug()<<y_;
   S = QString::number(y_);
   while (S.size() < 4) {
       S.insert(0, "0");
   }
   C = m_ui->cvaluelineEdit->text();
   while (C.size() < 4) {
       C.insert(0, "0");
   }
   T = m_ui->tvaluelineEdit->text();
   while (T.size() < 4) {
       T.insert(0, "0");
   }
   command.append("S").append(S);
   command.append("C").append(C);
   command.append("T").append(T);
   qDebug()<<command;
   writeData(&command.toStdString()[0]);

   m_ui->receivetextEdit->clear();

}

void MainWindow::strtovoltageandcurrent(const QString &str, QPointF &point)
{
    QString temp_str = str;
    quint8 str_size = temp_str.size();
    temp_str.remove((str_size - 2), 2); //将数据包的"\r\n"移除
    quint8 space_pos = temp_str.indexOf("  "); //获取"  "的位置
    QString data_str;
    data_str = temp_str.left(space_pos);
    data_str.remove(0, 1);  //移除"V"
    point.setX(data_str.toFloat()); //获得补偿电压的数值
    data_str.clear();
    data_str = temp_str.mid(space_pos + 2);
    data_str.remove(0, 1);  //移除"C"
    point.setY(data_str.toFloat());  //获得微弱电流的数据
}


void MainWindow::updateSvalue(void)
{
    bool ok;
    qreal value;
    value = m_ui->svaluelineEdit->text().toDouble(&ok);
    if (ok) {
        static_cast<QValueAxis*>(m_chart->axisX())->setMax(value + 0.5);
        static_cast<QValueAxis*>(m_chart->axisX())->setMin((value - 2*value) - 0.5);
    } else {
        QMessageBox::critical(this, tr("Critical Error"), tr("Invalid Value!"));
    }
}

void MainWindow::on_clearButton_clicked()
{
    maxDataListF.clear();
    maxDataListO.clear();
    flag=false;
    m_points.clear();
    clicked=0;
    maxClickedFlag=0;
    m_ui->actionFilter->setText("Filter");
    m_chart->removeAllSeries();
    m_ui->receivetextEdit->clear();
    estimate(flag);
    yvalueback();
    if (m_serial->isOpen()) {
        smartInserText("InputConfig:\r\n");
    }
    series.clear();

}

void MainWindow::opendatafile()
{
    delete filedialog;
    filedialog = new QFileDialog(this);
    filedialog->setWindowTitle("Open Data File");
    filedialog->setFileMode(QFileDialog::ExistingFile);
    filedialog->setAcceptMode(QFileDialog::AcceptOpen);
    QStringList filters;
    filters<<"Text File(*.txt *.xls)";

    filedialog->setNameFilters(filters);

    connect(filedialog, &QFileDialog::accepted, this, &MainWindow::opendatafileSelected);
    filedialog->show();
}

void MainWindow::opendatafileSelected()
{
    flag=false;
    estimate(flag);
    if(!m_points.empty()){
        m_points.clear();
    }
    newLine();
    currentymax=0;

    QString filename = filedialog->selectedFiles()[0];

    //获取文件名

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
        m_chart->legend()->setVisible(true);
        QTextStream in(&file);
        QPointF point;
        QString str;
        while (!in.atEnd()) {
            str = in.readLine();
            if (!str.endsWith("\r\n")) {
                str.append(QStringLiteral("\r\n"));
            }
            smartInserText(str);
            if ((str.contains("V")) && (str.contains("C"))) {
                strtovoltageandcurrent(str, point);
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
                m_points<<point;

            }

            str.clear();
        }
        for (int i=0;i<m_points.size();i++) {
            if(m_points[i].y()==currentymax){
                maxOriginData= m_points[i];
            }
        }
        maxDataListO<<maxOriginData;
        m_series->append(m_points);
        file.close();
        double x = m_series->at(1).x();
        axisX->setRange(x - 1, (x - 2*x) + 1);
        QMessageBox::information(this, tr("Open Datas File"), tr("The data file was opened successfully."));
    }

}

void MainWindow::savedatas(void)
{
    delete filedialog;
    filedialog = new QFileDialog(this);
    filedialog->setWindowTitle("Save Data File");
    filedialog->setAcceptMode(QFileDialog::AcceptSave);
    QString str("Text File(*.txt *.xls)");
    filedialog->setNameFilter(str);
    connect(filedialog, SIGNAL(accepted()), this, SLOT(savedatasfileSelected()));
    filedialog->show();
}

void MainWindow::savedatasfileSelected()
{
    QString filename = filedialog->selectedFiles()[0];
    qDebug() << "filename2:" << filename;
    if (!filename.isEmpty()) {
        QFile file(filename+".txt");
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::warning(this, tr("Save Datas File"), tr("Can not open file:\n%1").arg(filename));
            return;
        }
        QTextStream out(&file);
        out << m_ui->receivetextEdit->toPlainText();
        QFile file1(filename+".xlsx");
        if (!file1.open(QIODevice::WriteOnly)) {
            QMessageBox::warning(this, tr("Save Datas File"), tr("Can not open file:\n%1").arg(filename));
            return;
        }
        QTextStream out1(&file1);
        out1 << m_ui->receivetextEdit->toPlainText();
        file.close();
        file1.close();
        QMessageBox::information(this, tr("Save Datas File"), tr("The data file was saved successfully."));
    }
}

void MainWindow::savewaveform(void)
{
    delete filedialog;
    filedialog = new QFileDialog(this);
    filedialog->setWindowTitle("Save Image File");
    filedialog->setAcceptMode(QFileDialog::AcceptSave);
    QString str("Image File(*.png)");
    filedialog->setNameFilter(str);
    connect(filedialog, SIGNAL(accepted()), this, SLOT(savewaveformfileSelected()));
    filedialog->show();
}

void MainWindow::savewaveformfileSelected()
{
    QString filename = filedialog->selectedFiles()[0];
    qDebug() << "filename3:" << filename;
    if (!filename.isEmpty()) {
        QScreen *screen = QGuiApplication::primaryScreen();
        if (screen) {
            screen->grabWindow(m_ui->chartWidget->winId()).save(filename);
        }
        QMessageBox::information(this, tr("Save Chart"), tr("The image file was saved successfully."));
    }
}

void MainWindow::yvalueback(void)
{
    axisY->setRange(-2, 2);
    currentymax = axisY->max();
    currentymin = axisY->min();
}

void MainWindow::on_showsystemButton_clicked()
{
    QByteArray str = "P";
    writeData(str);
}

void MainWindow::on_setsystemButton_clicked()
{
    QByteArray str = "F";
    writeData(str);
}

void MainWindow::zeroerrorvalue(void)
{
   bool ok;
   qreal value = m_ui->zeroerrorlineEdit->text().toDouble(&ok);
   if (ok) {
        if ((value < 0.01) || (value > 2.0)) {
            QMessageBox::warning(this, tr("Critical Error"), tr("Invalid Value!\n"
                                                            "The range you enter should be 0.01~2pA,"
                                                            "please re-enter."));
       }
   }
}

void MainWindow::zerodriftvalue(void)
{
    bool ok;
    qreal value = m_ui->zerodriftlineEdit->text().toDouble(&ok);
    if (ok) {
        if ((value < 0) || (value > 50)) {
            QMessageBox::warning(this, tr("Critical Error"), tr("Invalid Value!\n"
                                                                "The range you enter should be 0~50pA,"
                                                                "please re-enter."));
        }
    }
}

void MainWindow::svalue(void)
{
    bool ok;
    qreal value = m_ui->svaluelineEdit->text().toDouble(&ok);
    if (ok) {
        if ((value < 0) || (value) > 14) {
            QMessageBox::warning(this, tr("Critical Error"), tr("Invalid Value!\n"
                                                                "The range you enter should be 0~13.5V,"
                                                                "please re-enter."));
        }
    }
}

void MainWindow::cvalue(void)
{
    bool ok;
    int value = m_ui->cvaluelineEdit->text().toInt(&ok);
    if (ok) {
        if ((value < 1) || (value) > 4096) {
            QMessageBox::warning(this, tr("Critical Error"), tr("Invalid Value!\n"
                                                                "The range you enter should be 1~4096 point,"
                                                                "please re-enter."));
        }
    }
}

void MainWindow::tvalue(void)
{
    bool ok;
    int value = m_ui->tvaluelineEdit->text().toInt(&ok);
    if (ok) {
        if ((value < 1) || (value > 1000)) {
            QMessageBox::warning(this, tr("Critical Error"), tr("Invalid Value!\n"
                                                                "The range you enter should be 1~1000,"
                                                                "please re-enter."));
        }
    }
}

void MainWindow::pointHoverd(const QPointF &point, bool state){

    if (state) {
        m_valueLabel->setText(QString::asprintf("%2.2f(V),%2.2f(pA)", point.x(),point.y()));

        QPoint curPos = mapFromGlobal(QCursor::pos());
        m_valueLabel->move(curPos.x() - m_valueLabel->width() / 1.5, curPos.y() - m_valueLabel->height() * 2);//移动数值
        m_valueLabel->show();
    }
    else{
        m_valueLabel->hide();
    }
}

void MainWindow::on_recoverButton_clicked(){
    m_chart->zoomReset();
}

void MainWindow::setPenFormat(){
    pen.setColor(QColor(qrand()%256,qrand()%256,qrand()%256));
    pen.setWidth(3);
}

void MainWindow::newLine(){
    m_ui->actionFilter->setEnabled(true);
    m_series = new QLineSeries(this);
    m_chart->addSeries(m_series);
    m_chart->setAxisX(axisX, m_series);
    m_chart->setAxisY(axisY, m_series);
    setPenFormat();
    m_series->setPen(pen);
    connect(m_series,&QLineSeries::hovered,this,&MainWindow::pointHoverd);
    series<<m_series;
    connectMarkers();
}


bool sortByY(const QPointF &p1, const QPointF &p2)

{

    return p1.y() < p2.y();//升序排列

}
void MainWindow::filter(){
    filterFlag = true;
    QList<QPointF> fittedResult;
    QList<QPointF> fittedAndSmoothResult;
    fittedResult.clear();
    //线性五点拟合去差值
    double tmpY;
    double flag=0;
    if(m_points.size()>=5){
        int N_1 = m_points.size();
        std::vector<QPointF> tmpData(5);
        for(int i=0;i<N_1-5;i++){
            tmpData.clear();
            for(int j=i;j<i+5;j++){
                tmpData.push_back(m_points[j]);
            }
            std::sort(tmpData.begin(),tmpData.end(),sortByY);
            tmpY = (tmpData[1].y()+tmpData[2].y()+tmpData[3].y())/3;
            fittedResult.push_back(QPointF(m_points[i].x(),tmpY));
        }
        fittedResult[fittedResult.size()-1].setX(m_points[m_points.size()-1].x());
    }
    //线性五点平滑
    int N_2 = fittedResult.size();
    tmpY = (3.0*fittedResult[0].y()+2.0*fittedResult[1].y()+fittedResult[2].y()-fittedResult[4].y()) / 5.0;
    if(tmpY<=0){
        tmpY = 0;
    }
    fittedAndSmoothResult.push_back(QPointF(fittedResult[0].x(), tmpY));
    tmpY = (4.0 * fittedResult[0].y() + 3.0 * fittedResult[1].y() + 2 * fittedResult[2].y() + fittedResult[3].y()) / 10.0;
    fittedAndSmoothResult.push_back(QPointF(fittedResult[1].x(), tmpY));
    for(int i=2;i<N_2 - 3;i++){
        tmpY = (fittedResult[i - 2].y() + fittedResult[i - 1].y() + fittedResult[i].y() + fittedResult[i + 1].y() + fittedResult[i + 2].y()) / 5.0;
        fittedAndSmoothResult.push_back(QPointF(fittedResult[i].x(), tmpY));
    }
    tmpY = (4.0 * fittedResult[N_2 - 1].y() + 3.0 * fittedResult[N_2 - 2].y() + 2 * fittedResult[N_2 - 3].y() + fittedResult[N_2 - 4].y()) / 10.0;
    fittedAndSmoothResult.push_back(QPointF(fittedResult[N_2 - 2].x(), tmpY));
    tmpY  = (3.0 * fittedResult[N_2 - 1].y() + 2.0 * fittedResult[N_2 - 2].y() + fittedResult[N_2 - 3].y() - fittedResult[N_2 - 5].y()) / 5.0;
    fittedAndSmoothResult.push_back(QPointF(fittedResult[N_2 - 1].x(), tmpY));
    m_points.clear();
    m_points=fittedAndSmoothResult;

    for(int i =0;i<m_points.size();i++){
        if(flag<m_points[i].y()){
            flag=m_points[i].y();
            maxFilteredData= m_points[i];
        }
    }
    maxDataListF<<maxFilteredData;

}

void MainWindow::showLegendSpinbox()
{
    m_legendSettings->setVisible(true);
    QRectF chartViewRect = m_chartview->rect();

    m_legendPosX->setMinimum(0);
    m_legendPosX->setMaximum(chartViewRect.width());
    m_legendPosX->setValue(150);

    m_legendPosY->setMinimum(0);
    m_legendPosY->setMaximum(chartViewRect.height());
    m_legendPosY->setValue(150);

    m_legendWidth->setMinimum(0);
    m_legendWidth->setMaximum(chartViewRect.width());
    m_legendWidth->setValue(150);

    m_legendHeight->setMinimum(0);
    m_legendHeight->setMaximum(chartViewRect.height());
    m_legendHeight->setValue(75);
}

void MainWindow::hideLegendSpinbox()
{
    m_legendSettings->setVisible(false);
}

void MainWindow::on_actionFilter_triggered(){
     newLine();
     QPen fPen(Qt::blue,2);
     m_series->setPen(fPen);
     filter();
     m_series->append(m_points);
     m_series->setName("Filtered");
     QMessageBox::information(this,"filter","The data was filtered successfully");
     flag=true;
     estimate(flag);
     filteredLineNum++;
}
void MainWindow::on_actionCancel_Filter_triggered(){
    filterFlag = false;
    m_series->clear();
    m_series->hide();
    m_scatter1->clear();
    m_scatter1->hide();
    flag = false;
    estimate(flag);

}

void MainWindow::contextMenuEvent(QContextMenuEvent *){
    QMenu *menu = new QMenu(this);
    QAction *action = new QAction("show extreme value",this);
    QAction *action1 = new QAction("Save Chart",this);
    QAction *action2 = new QAction("Save datas",this);
    QAction *action3 = new QAction("Chart Legend setting",this);
    QMenu *menu1 = new QMenu("Delete series ...",this);
    if(maxClickedFlag%2){
        action->setText("Cancel show extreme value");

    }
    if(m_ui->receivetextEdit->document()->isEmpty()){
        action->setEnabled(false);
        action1->setEnabled(false);
        action2->setEnabled(false);
    }
    if(series.empty()){
        menu1->setEnabled(false);

    }else{
        for(int i=1;i<=series.size();++i){
            QAction *ac = new QAction(QString("Delete series %1").arg(i),this);
            connect(ac,&QAction::triggered,[=](){
                removeSpecifiedSeries(i-1);
            });
            menu1->addAction(ac);
        }

    }
    connect(action, &QAction::triggered, this, &MainWindow::showextremeValue);
    connect(action1, &QAction::triggered, this, &MainWindow::savewaveform);
    connect(action2, &QAction::triggered, this, &MainWindow::savedatas);
    connect(action3, &QAction::triggered, this, &MainWindow::Set_Legend);

    menu->addAction(action);
    menu->addAction(action1);
    menu->addAction(action2);
    menu->addAction(action3);
    menu->addMenu(menu1);
    menu->move(cursor().pos());
    menu->show();

}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        m_chartview->setRubberBand(QChartView::RectangleRubberBand);
    }
    else{
        m_chartview->setRubberBand(QChartView::NoRubberBand);
    }
}

void MainWindow::showextremeValue(){

    maxClickedFlag++;
    if(maxClickedFlag%2){

        //m_scatter->hide();
        m_scatter = new QScatterSeries(this);
        scatter_O <<m_scatter;
        m_scatter->setName("Max point(Original)");
        m_scatter->setMarkerShape(QScatterSeries::MarkerShapeCircle);
        m_scatter->setMarkerSize(9);
        m_scatter->setBrush(Qt::red);
        m_scatter->setPointsVisible(true);
        m_scatter->append(maxDataListO);
        m_chart->addSeries(m_scatter);
        m_chart->setAxisX(axisX, m_scatter);
        m_chart->setAxisY(axisY, m_scatter);
        connect(m_scatter,&QScatterSeries::hovered,this,&MainWindow::maxPointHoverd);

        if(filterFlag){
                //m_scatter1->hide();
                m_scatter1 = new QScatterSeries(this);
                scatter_F << m_scatter1;
                m_scatter1->setName("Max point(Filtered)");
                m_scatter->setMarkerShape(QScatterSeries::MarkerShapeCircle);
                m_scatter1->setMarkerSize(9.0);
                m_scatter1->setBrush(Qt::green);
                m_scatter1->setPointsVisible(true);
                m_scatter1->append(maxDataListF);
                m_chart->addSeries(m_scatter1);
                m_chart->setAxisX(axisX, m_scatter1);
                m_chart->setAxisY(axisY, m_scatter1);
                connect(m_scatter1,&QScatterSeries::hovered,this,&MainWindow::maxPointHoverd);
            }
    }else{
       m_scatter->clear();
       m_scatter->hide();
       m_scatter1->clear();
       m_scatter1->hide();
    }
}

void MainWindow::toggleAttached()
{
    QLegend *legend = m_chart->legend();
    if (legend->isAttachedToChart()) {
        legend->detachFromChart();
        m_chart->legend()->setBackgroundVisible(true);
        m_chart->legend()->setBrush(QBrush(QColor(128, 128, 128, 128)));
        m_chart->legend()->setPen(QPen(QColor(192, 192, 192, 192)));
        showLegendSpinbox();
        updateLegendLayout();
    } else {
        legend->attachToChart();
        legend->setBackgroundVisible(false);
        hideLegendSpinbox();
    }
    update();
}

void MainWindow::Set_Legend()
{
    Legend_dialog = new QDialog(this);
    Legend_dialog->setWindowTitle(QStringLiteral("Legend Setting"));
    // Create buttons for ui
    m_buttonLayout = new QGridLayout(this);
    QPushButton *detachLegendButton = new QPushButton("Toggle attached");
    detachLegendButton->setFixedSize(200,50);
    connect(detachLegendButton, SIGNAL(clicked()), this, SLOT(toggleAttached()));
    m_buttonLayout->addWidget(detachLegendButton, 0, 0);

    QPushButton *alignButton = new QPushButton("Align (Bottom)",this);
    alignButton->setFixedSize(200,50);
    connect(alignButton, SIGNAL(clicked()), this, SLOT(setLegendAlignment()));
    m_buttonLayout->addWidget(alignButton, 2, 0);

    QPushButton *boldButton = new QPushButton("Toggle bold",this);
    boldButton->setFixedSize(200,50);
    connect(boldButton, SIGNAL(clicked()), this, SLOT(toggleBold()));
    m_buttonLayout->addWidget(boldButton, 4, 0);

    QPushButton *italicButton = new QPushButton("Toggle italic",this);
    italicButton->setFixedSize(200,50);
    connect(italicButton, SIGNAL(clicked()), this, SLOT(toggleItalic()));
    m_buttonLayout->addWidget(italicButton, 6, 0);

    m_legendPosX = new QDoubleSpinBox(this);
    m_legendPosY = new QDoubleSpinBox(this);
    m_legendWidth = new QDoubleSpinBox(this);
    m_legendHeight = new QDoubleSpinBox(this);

    connect(m_legendPosX, SIGNAL(valueChanged(double)), this, SLOT(updateLegendLayout()));
    connect(m_legendPosY, SIGNAL(valueChanged(double)), this, SLOT(updateLegendLayout()));
    connect(m_legendWidth, SIGNAL(valueChanged(double)), this, SLOT(updateLegendLayout()));
    connect(m_legendHeight, SIGNAL(valueChanged(double)), this, SLOT(updateLegendLayout()));

    QFormLayout *legendLayout = new QFormLayout(this);
    legendLayout->addRow("HPos", m_legendPosX);
    legendLayout->addRow("VPos", m_legendPosY);
    legendLayout->addRow("Width", m_legendWidth);
    legendLayout->addRow("Height", m_legendHeight);
    m_legendSettings = new QGroupBox("Detached legend",this);
    m_legendSettings->setLayout(legendLayout);
    m_buttonLayout->addWidget(m_legendSettings);
    m_legendSettings->setVisible(false);

    m_fontSize = new QDoubleSpinBox(this);
    m_fontSize->setValue(m_chart->legend()->font().pointSizeF());
    connect(m_fontSize, SIGNAL(valueChanged(double)), this, SLOT(fontSizeChanged()));

    QFormLayout *fontLayout = new QFormLayout(this);
    fontLayout->addRow("Legend font size", m_fontSize);

    // Create layout for grid and detached legend
    m_mainLayout = new QGridLayout(this);
    m_mainLayout->addLayout(m_buttonLayout, 0, 0);
    m_mainLayout->addLayout(fontLayout, 1, 0);

    Legend_dialog->setLayout(m_mainLayout);
    Legend_dialog->setFixedSize(600,600);
    Legend_dialog->show();
}

void MainWindow::setLegendAlignment()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());

    switch (m_chart->legend()->alignment()) {
    case Qt::AlignTop:
        m_chart->legend()->setAlignment(Qt::AlignLeft);
        if (button)
            button->setText("Align (Left)");
        break;
    case Qt::AlignLeft:
        m_chart->legend()->setAlignment(Qt::AlignBottom);
        if (button)
            button->setText("Align (Bottom)");
        break;
    case Qt::AlignBottom:
        m_chart->legend()->setAlignment(Qt::AlignRight);
        if (button)
            button->setText("Align (Right)");
        break;
    default:
        if (button)
            button->setText("Align (Top)");
        m_chart->legend()->setAlignment(Qt::AlignTop);
        break;
    }
}

void MainWindow::toggleBold()
{
    QFont font = m_chart->legend()->font();
    font.setBold(!font.bold());
    m_chart->legend()->setFont(font);
}

void MainWindow::toggleItalic()
{
    QFont font = m_chart->legend()->font();
    font.setItalic(!font.italic());
    m_chart->legend()->setFont(font);
}

void MainWindow::fontSizeChanged()
{
    QFont font = m_chart->legend()->font();
    font.setPointSizeF(m_fontSize->value());
    m_chart->legend()->setFont(font);
}

void MainWindow::updateLegendLayout()
{
        m_chart->legend()->setGeometry(QRectF(m_legendPosX->value(),
                                              m_legendPosY->value(),
                                              m_legendWidth->value(),
                                              m_legendHeight->value()));
        m_chart->legend()->update();
}

void MainWindow::pointClickedO(const QPointF &point){
    double minusDataY=100 ;
    for(int i=0;i<maxDataListO.size();i++){
        if(minusDataY > fabs(maxDataListO[i].y()-point.y())){
            minusDataY = fabs(maxDataListO[i].y()-point.y());
            currentMaxData = maxDataListO[i];
       }
    }

    m_maxLabel->setStyleSheet(QString("QLabel{color:#000000; font-family:\"Microsoft Yahei\"; font-size:16px; font-weight:bold;"
                                        " background-color:rgba(21, 100, 255, 51); border-radius:2px; text-align:center;}"));
    m_maxLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//21 100 255 51#1564FF
    QRect r(200,70,200,70);
    m_maxLabel->setGeometry(r);
    m_maxLabel->setText(QString::asprintf("MaxO:%2.2f(V),%2.2f(pA)",currentMaxData.x(),currentMaxData.y()));
    QPoint curPos = mapFromGlobal(QCursor::pos());
    m_maxLabel->move(curPos.x(), curPos.y());//移动数值
    m_maxLabel->show();
}

void MainWindow::pointClickedF(const QPointF &point){
    double minusDataY=100 ;
    for(int i=0;i<maxDataListF.size();i++){
        if(minusDataY > fabs(maxDataListF[i].y()-point.y())){
            minusDataY = fabs(maxDataListF[i].y()-point.y());
            currentMaxData = maxDataListF[i];
       }
    }

    m_maxLabel->setStyleSheet(QString("QLabel{color:#000000; font-family:\"Microsoft Yahei\"; font-size:16px; font-weight:bold;"
                                        " background-color:rgba(21, 100, 255, 51); border-radius:2px; text-align:center;}"));
    m_maxLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//21 100 255 51#1564FF
    QRect r(200,70,200,70);
    m_maxLabel->setGeometry(r);
    m_maxLabel->setText(QString::asprintf("MaxF:%2.2f(V),%2.2f(pA)",currentMaxData.x(),currentMaxData.y()));
    QPoint curPos = mapFromGlobal(QCursor::pos());
    m_maxLabel->move(curPos.x(), curPos.y());//移动数值
    m_maxLabel->show();
}

void MainWindow::maxPointHoverd(const QPointF &point, bool state){
    if(state){
        connect(m_scatter,&QScatterSeries::clicked,this,&MainWindow::pointClickedO);
        connect(m_scatter1,&QScatterSeries::clicked,this,&MainWindow::pointClickedF);

    }else{
        QPoint curPos = mapFromGlobal(QCursor::pos());
        if(curPos!=point){
            m_maxLabel->hide();
        }
    }
}

void MainWindow::estimate(bool flag){
    if(flag){
        if(!m_points.empty()){
            m_ui->actionFilter->setEnabled(false);
            m_ui->actionCancel_Filter->setEnabled(true);
        }
        else{
            m_ui->actionFilter->setEnabled(false);
            m_ui->actionCancel_Filter->setEnabled(false);
        }
    }else{
        if(!m_points.empty()){
            m_ui->actionFilter->setEnabled(true);
            m_ui->actionCancel_Filter->setEnabled(false);

        }
        else{
            m_ui->actionFilter->setEnabled(false);
            m_ui->actionCancel_Filter->setEnabled(false);
        }

    }

}

void MainWindow::autoOpenSerialPort(){
    const SettingDialog::Settings p = m_settings->settings();
    m_serial->setPortName(p.name);
    m_serial->setBaudRate(p.baudRate);
    m_serial->setDataBits(p.dataBits);
    m_serial->setParity(p.parity);
    m_serial->setStopBits(p.stopBits);
    m_serial->setFlowControl(p.flowControl);

    if (m_serial->open(QIODevice::ReadWrite)) {
        m_ui->actionConnect->setEnabled(false);
        m_ui->actionDisconnect->setEnabled(true);
        m_ui->actionConfigure->setEnabled(false);

        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));

    }
    emit connectIsOK();
}

void MainWindow::closeConfigure(){
    m_settings->m_timer->stop();
    m_settings->m_ui->autoCheckBox->setChecked(false);
}


void MainWindow::removeSpecifiedSeries(int index){
    series.move(index,series.count()-1);
    if (series.count() > 0) {
        QLineSeries *series1 = series.last();
        m_chart->removeSeries(series1);
        series.removeLast();
        delete series1;
    }
}
void MainWindow::handleMarkerClicked(){
    QLegendMarker* marker = qobject_cast<QLegendMarker*> (sender());
    Q_ASSERT(marker);



    switch (marker->type())

    {
        case QLegendMarker::LegendMarkerTypeXY:
        {
        // Toggle visibility of series
        marker->series()->setVisible(!marker->series()->isVisible());

        // Turn legend marker back to visible, since hiding series also hides the marker
        // and we don't want it to happen now.
        marker->setVisible(true);
        // Dim the marker, if series is not visible
        qreal alpha = 1.0;

        if (!marker->series()->isVisible())
            alpha = 0.5;

        QColor color;
        QBrush brush = marker->labelBrush();
        color = brush.color();
        color.setAlphaF(alpha);
        brush.setColor(color);
        marker->setLabelBrush(brush);

        brush = marker->brush();
        color = brush.color();
        color.setAlphaF(alpha);
        brush.setColor(color);
        marker->setBrush(brush);

        QPen pen = marker->pen();
        color = pen.color();
        color.setAlphaF(alpha);
        pen.setColor(color);
        marker->setPen(pen);
        break;
        }
    default:
        {
        qDebug() << "Unknown marker type";
        break;
        }
    }
}

void MainWindow::connectMarkers()
{
    // Connect all markers to handler
    const auto markers = m_chart->legend()->markers();
    for (QLegendMarker *marker : markers) {
        // Disconnect possible existing connection to avoid multiple connections
        disconnect(marker, &QLegendMarker::clicked,
                   this, &MainWindow::handleMarkerClicked);
        connect(marker, &QLegendMarker::clicked, this, &MainWindow::handleMarkerClicked);
    }

}

void MainWindow::disconnectMarkers()
{

    const auto markers = m_chart->legend()->markers();
    for (QLegendMarker *marker : markers) {
        disconnect(marker, &QLegendMarker::clicked,
                   this, &MainWindow::handleMarkerClicked);
    }

}
