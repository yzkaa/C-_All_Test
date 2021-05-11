#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingdialog.h"
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

#include <QDebug>
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
//    setWindowFlags(Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint);

    chartInit();

    connect(m_ui->svaluelineEdit, &QLineEdit::editingFinished,this, &MainWindow::updateSvalue);

    initWidget();
    initActionsConnect();
    initNetworkServer();

    connect(m_serial,SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(handleError(QSerialPort::SerialPortError)));
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

    //生成配置文件
    Utils::systemSettingsInit();

    //数据库
    initDatabase();

    //新数据绘图连接
    connect(this, &MainWindow::receiveNewData, this, &MainWindow::newLine);

}

MainWindow::~MainWindow()
{
    on_clearButton_clicked();

    delete m_ui;
    delete m_settings;
    delete filedialog;

    if (Legend_dialog != nullptr)
    {
        delete Legend_dialog;
    }

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
    m_ui->actionDrawSpectrogram->setIcon(QIcon(":/images/drawSpectrogram.png"));
    m_ui->actionDrawSpectrogram->setToolTip("According to the prepared data, we can also open the data drawing interface");
    m_ui->actiondatabase->setIcon(QIcon(":/images/database.png"));
    m_ui->actiondatabase->setToolTip("DataBase");
//    m_ui->actionyunServer->setIcon(QIcon(":/images/yun.jpg"));
    m_ui->actionyunServer->setToolTip("Cloud services");

    m_ui->mainToolBar->addAction(m_ui->actionOpen_file);
    m_ui->mainToolBar->addAction(m_ui->actionSave_Data);
    m_ui->mainToolBar->addAction(m_ui->actionSave_Chart);
    m_ui->mainToolBar->addAction(m_ui->actionConnect);
    m_ui->mainToolBar->addAction(m_ui->actionDisconnect);
    m_ui->mainToolBar->addAction(m_ui->actionConfigure);
    m_ui->mainToolBar->addAction(m_ui->actionDrawSpectrogram);
    m_ui->mainToolBar->addAction(m_ui->actiondatabase);
//    m_ui->mainToolBar->addAction(m_ui->actionyunServer);
    m_ui->mainToolBar->addAction(m_ui->actionQuit_2);



    m_ui->actionConnect->setEnabled(true);
    m_ui->actionDisconnect->setEnabled(false);
    m_ui->actionQuit->setEnabled(true);
    m_ui->actionConfigure->setEnabled(true);
    m_ui->actionDrawSpectrogram->setEnabled(true);
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

    //峰参数显示label
    peakParametersShow = new QLabel(this);
    peakParametersShow->setStyleSheet(QString("QLabel{color:#000000; font-family:\"Microsoft Yahei\"; font-size:18px; font-weight:bold;"
                                        " background-color:rgba(21, 100, 255, 51); border-radius:2px; text-align:center;}"));
    peakParametersShow->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//21 100 255 51#1564FF
    QRect r2(200,70,200,90);
    peakParametersShow->setGeometry(r2);
    peakParametersShow->hide();


    m_chart = new QChart;
    m_chartview = new QChartView(m_chart);
    m_chartview->setRenderHint(QPainter::Antialiasing);
    m_chart->setTheme(QChart::ChartThemeHighContrast);
//    m_series = new QLineSeries;
    filterSeries = new QLineSeries;
    m_scatter = new QScatterSeries;
    m_scatter1 = new QScatterSeries;

    //m_chart->addSeries(m_series);
    m_chart->addSeries(filterSeries);
    filterSeries->hide();

    axisX = new QValueAxis;
    axisX->setRange(-14, 14);
    axisX->setLabelFormat("%g");
    axisX->setMinorTickCount(6);
    axisX->setTitleText(QStringLiteral("Voltage(V)"));
    axisX->linePenColor();

    axisY = new QValueAxis;
    axisY->setRange(-2, 2);
    axisY->setLabelFormat("%g");
    axisY->setMinorTickCount(6);
    axisY->setTitleText(QStringLiteral("Current(pA)"));
    axisY->linePenColor();

    m_chart->setAxisX(axisX, filterSeries);
    m_chart->setAxisY(axisY, filterSeries);
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

void MainWindow::initFingerprintSpectrum()
{
    if (spectrogramDialog == nullptr)
    {
        spectrogramDialog = new SpectrogramDialog(this);
    }
    spectrogramDialog->getSpectrogramParameter(currentAllDate, axisY->min(), axisY->max(), axisX->min(), axisX->max());
    spectrogramDialog->showMaximized();
    spectrogramDialog->exec();
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
    static QString string;
    static QList<QPointF> points;
    string += m_serial->readAll();

    while (string.endsWith("\r\n")) {
        int pos = string.indexOf("\r\n");   //找到"\r\n"的位置
        QString temp_string = string.left(pos + 2);   //根据得到的位置取出首个数据包

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
            points << point;
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
        string.remove(temp_string);   //继续处理下一个"\r\n"结尾的字符串
    }

    //画图
    emit receiveNewData(points);

    points.clear();                //清除容器内已存在的点
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
    connect(m_ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
    connect(m_ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
    connect(m_ui->actionQuit_2, &QAction::triggered, this, &MainWindow::close);
//    connect(m_ui->actionConfigure, &QAction::triggered, m_settings, &SettingDialog::show);
    connect(m_ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    connect(m_ui->actionAbout_Qt, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(m_ui->actionOpen_file, &QAction::triggered, this, &MainWindow::opendatafileSelected);
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
    connect(m_ui->actionSetLegend, &QAction::triggered, this, &MainWindow::Set_Legend);

    //谱图界面
    connect(m_ui->actionDrawSpectrogram, &QAction::triggered, this, &MainWindow::initFingerprintSpectrum);
    //
    connect(m_ui->actiondatabase, &QAction::triggered, this, &MainWindow::actionDatabaseTrigger);

    //参数配置界面
    connect(m_ui->actionConfigure, &QAction::triggered, this, &MainWindow::SettingsTrigger);

}

void MainWindow::initNetworkServer()
{
    //udp初始化
    networkServer = new NetworkServer(this);
    connect(this, &MainWindow::peakParamsCalculation, networkServer, &NetworkServer::getCalculationData);
}

void MainWindow::initDatabase()
{
    //数据库初始化
    dbServer = new DatabaseServer(this);

    connect(this, &MainWindow::inSertToDatabase, dbServer, &DatabaseServer::insertToDatabase);
    connect(dbServer, &DatabaseServer::inputSucess, [=](){
        Utils::tipMessageBox("数据入库成功");
    });
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
   axisX->setRange((x - 2*x) - 0.5, x + 0.5);

   double y = (-2046/13.0*x) + 2046;
   quint16 y_ = quint16(y);
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
    //曲线相关的释放
    seriesListClear();

    //缓存数据清除
    currentAllDate.clear();

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

    //面积模式的退出与清除操作
    peakParametersShow->hide();
    isPPCalculation = false;
}

//void MainWindow::opendatafile(void)
//{
//    if(filedialog == nullptr)
//    {
//        filedialog = new QFileDialog(this);
//        filedialog->setWindowTitle("Open Data File");
//        filedialog->setAcceptMode(QFileDialog::AcceptOpen);
//        QStringList filters;
//        filters<<"Text File(*.txt *.xls)";
//        filedialog->setNameFilters(filters);
//    }
//    connect(filedialog, SIGNAL(accepted()), this, SLOT(opendatafileSelected()));
//    filedialog->show();

//}

void MainWindow::opendatafileSelected(void)
{  
    flag=false;
    estimate(flag);
    m_points.clear();

    //"Data file(*.xls;*.xlsx;*.txt)"
    QString filePath = QFileDialog::getOpenFileName(this,"Open file",
                                                     QStandardPaths::writableLocation(QStandardPaths::DesktopLocation)
                                                     );
    //qDebug() << "filename1:" << filename;
    if (filePath.isEmpty())
    {
        Utils::tipMessageBox("打开失败");
        return;
    }
    
    //获取文件名
    QString filename;
    QFileInfo fi;
    int index;
    fi=QFileInfo(filePath);
    filename = fi.fileName();//获取文件名
    index = filePath.lastIndexOf(".");
    filename.truncate(index);      //去掉后缀,上一句是找到名称长度
//    m_series->setName(file_name);
    seriesName = filename;

    if (!filename.isEmpty()) {
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, tr("Open Datas File"), tr("Can not open file:\n%1").arg(filename));
            return;
        }
        m_chart->legend()->setVisible(true);
        QTextStream in(&file);
        QPointF point;
        QString str;
        m_points.clear();
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

//        if(point.y() > currentymax){
//            currentymax = point.y();
//        }
        for (int i=0;i<m_points.size();i++) {
            if(m_points[i].y()==currentymax){
//                m_points[i].y() = currentymax;
                maxOriginData= m_points[i];
            }
        }
        maxDataListO<<maxOriginData;
        file.close();

        //新曲线绘制
        emit receiveNewData(m_points);
//        QMessageBox::information(this, tr("Open Datas File"), tr("The data file was opened successfully."));
    }


//    QVector<double> pointRF;
//    currentymax=0;
//    for(int i=0;i<m_points.size();i++)
//        pointRF+=m_points.at(i).y();
//    currentymaxIndex = pointRF.indexOf(currentymax);

    qDebug()<<"file is open";
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
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::warning(this, tr("Save Datas File"), tr("Can not open file:\n%1").arg(filename));
            return;
        }
        QTextStream out(&file);
        out << m_ui->receivetextEdit->toPlainText();
        file.close();
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

void MainWindow::seriesListClear()
{
    //曲线清除
    for (int i = 0; i < seriesList.size(); i++)
    {
        seriesList.at(i)->clear();
    }

    foreach(QLineSeries *w, seriesList)
    {
        if(w)
        {
            seriesList.removeOne(w);
            delete w;
            w = nullptr;
        }
    }

    //轴线
    axisY->setMin(-2);
    axisY->setMax(2);
    axisY->setMin(-12);
    axisY->setMax(12);

}

void MainWindow::setPenFormat(){
    pen.setColor(QColor(qrand()%256,qrand()%256,qrand()%256));
    pen.setWidth(2);

//    switch(count%6){
//    case 1:pen.setStyle(Qt::SolidLine);break;
//    case 2:pen.setStyle(Qt::DashLine);break;
//    case 3:pen.setStyle(Qt::DotLine);break;
//    case 4:pen.setStyle(Qt::DashDotLine);break;
//    case 5:pen.setStyle(Qt::DashDotDotLine);break;
//    case 0:pen.setStyle(Qt::DashLine);break;

//    }
}

void MainWindow::newLine(const QList<QPointF> &data)
{
    //缓存数据
    currentAllDate.append(data);

    //绘图相关
    //新建曲线添加数据
    m_ui->actionFilter->setEnabled(true);
    seriesList.append(new QLineSeries);
    seriesList.last()->append(data);
    seriesList.last()->setName(seriesName);
    m_chart->addSeries(seriesList.last());
    //轴线更新
    //X轴
    double x = seriesList.last()->at(0).x();
    if (axisX->min() > x - 1)
    {
        axisX->setMin(x - 1);
    }
    if (axisX->max() < (x - 2*x) + 1)
    {
        axisX->setMax((x - 2*x) + 1);
    }
    //Y轴
    getExtreMum(currentAllDate.last());

    m_chart->setAxisX(axisX, seriesList.last());
    m_chart->setAxisY(axisY, seriesList.last());
    setPenFormat();
    seriesList.last()->setPen(pen);
    connect(seriesList.last(), &QLineSeries::hovered, this, &MainWindow::pointHoverd);

    qDebug()<<"enter newLine";
}

void MainWindow::getExtreMum(QList<QPointF> &data)
{
    QList<QPointF>::const_iterator i;
    for (i = data.begin(); i != data.end(); i++)
    {
        if (axisY->min() > (*i).y())
        {
            axisY->setMin((*i).y() - 10);
        }
        if (axisY->max() < (*i).y())
        {
            axisY->setMax((*i).y() + 20);
        }
    }
}


void MainWindow::filter(){
    filterFlag = true;

    //filter 封装在工具类
    Utils::Filter(m_points);

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
    filterSeries->clear();
    filter();
    QPen fPen(Qt::blue,2);
    filterSeries->setPen(fPen);
    filterSeries->append(m_points);
    filterSeries->setName("Flitered");
    filterSeries->show();
    QMessageBox::information(this,"filter","The data was filtered successfully");
    flag=true;
    estimate(flag);
    filteredLineNum++;

}
void MainWindow::on_actionCancel_Filter_triggered(){
    filterFlag = false;
    filterSeries->clear();
    filterSeries->hide();
    m_scatter1->clear();
    m_scatter1->hide();
    flag = false;
    estimate(flag);

}

void MainWindow::contextMenuEvent(QContextMenuEvent *){     //右键菜单事件
    QMenu *menu = new QMenu(this);
    QAction *action = new QAction("show extreme value",this);
    QAction *action1 = new QAction("Save Chart",this);
    QAction *action2 = new QAction("Save datas",this);
    QAction *action3 = new QAction("Chart Legend setting",this);
    QAction *action4 = new QAction("Next LineSeries Peak parameter Calculation",this);
    QAction *inSertToDB = new QAction("insert current data to database", this);
    QAction *dataToCloudServer = new QAction("Current Data to CLoud Server", this);
    if(maxClickedFlag%2){
        action->setText("Cancel show extreme value");

    }
    if(m_points.empty()){
        action->setEnabled(false);
        action1->setEnabled(false);
        action2->setEnabled(false);
        action3->setEnabled(false);
    }

    if(isPPCalculation)
    {
        action4->setEnabled(true);
    }
    else
    {
        action4->setEnabled(false);
    }

    connect(action, &QAction::triggered, this, &MainWindow::showextremeValue);
    connect(action1, &QAction::triggered, this, &MainWindow::savewaveform);
    connect(action2, &QAction::triggered, this, &MainWindow::savedatas);
    connect(action3, &QAction::triggered, this, &MainWindow::Set_Legend);
    connect(action4, &QAction::triggered, this, &MainWindow::multipleCurvesCalculation);
    connect(inSertToDB, &QAction::triggered, this, &MainWindow::showInSertDBDialog);
    connect(dataToCloudServer, &QAction::triggered, this, &MainWindow::currentDataToCloudServer);

    menu->addAction(action);
    menu->addAction(action1);
    menu->addAction(action2);
    menu->addAction(action3);
    menu->addAction(action4);
    menu->addAction(inSertToDB);
    menu->addAction(dataToCloudServer);
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
        m_scatter = new QScatterSeries;
        m_scatter->setName("Max point(Original)");
        m_scatter->setMarkerShape(QScatterSeries::MarkerShapeCircle);  //圆形的点
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
            m_scatter1 = new QScatterSeries;
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
        //![2]
        legend->detachFromChart();
        m_chart->legend()->setBackgroundVisible(true);
        m_chart->legend()->setBrush(QBrush(QColor(128, 128, 128, 128)));
        m_chart->legend()->setPen(QPen(QColor(192, 192, 192, 192)));
        //![2]
        showLegendSpinbox();
        updateLegendLayout();
    } else {
        //![3]
        legend->attachToChart();
        legend->setBackgroundVisible(false);
        //![3]
        hideLegendSpinbox();
    }
    update();
}

void MainWindow::Set_Legend()
{
    Legend_dialog = new QDialog;
    Legend_dialog->setWindowTitle(QStringLiteral("Legend Setting"));
    // Create buttons for ui
    m_buttonLayout = new QGridLayout();
    QPushButton *detachLegendButton = new QPushButton("Toggle attached");
    detachLegendButton->setFixedSize(200,50);
    connect(detachLegendButton, SIGNAL(clicked()), this, SLOT(toggleAttached()));
    m_buttonLayout->addWidget(detachLegendButton, 0, 0);

    QPushButton *alignButton = new QPushButton("Align (Bottom)");
    alignButton->setFixedSize(200,50);
    connect(alignButton, SIGNAL(clicked()), this, SLOT(setLegendAlignment()));
    m_buttonLayout->addWidget(alignButton, 2, 0);

    QPushButton *boldButton = new QPushButton("Toggle bold");
    boldButton->setFixedSize(200,50);
    connect(boldButton, SIGNAL(clicked()), this, SLOT(toggleBold()));
    m_buttonLayout->addWidget(boldButton, 4, 0);

    QPushButton *italicButton = new QPushButton("Toggle italic");
    italicButton->setFixedSize(200,50);
    connect(italicButton, SIGNAL(clicked()), this, SLOT(toggleItalic()));
    m_buttonLayout->addWidget(italicButton, 6, 0);

    m_legendPosX = new QDoubleSpinBox();
    m_legendPosY = new QDoubleSpinBox();
    m_legendWidth = new QDoubleSpinBox();
    m_legendHeight = new QDoubleSpinBox();

    connect(m_legendPosX, SIGNAL(valueChanged(double)), this, SLOT(updateLegendLayout()));
    connect(m_legendPosY, SIGNAL(valueChanged(double)), this, SLOT(updateLegendLayout()));
    connect(m_legendWidth, SIGNAL(valueChanged(double)), this, SLOT(updateLegendLayout()));
    connect(m_legendHeight, SIGNAL(valueChanged(double)), this, SLOT(updateLegendLayout()));

    QFormLayout *legendLayout = new QFormLayout();
    legendLayout->addRow("HPos", m_legendPosX);
    legendLayout->addRow("VPos", m_legendPosY);
    legendLayout->addRow("Width", m_legendWidth);
    legendLayout->addRow("Height", m_legendHeight);
    m_legendSettings = new QGroupBox("Detached legend");
    m_legendSettings->setLayout(legendLayout);
    m_buttonLayout->addWidget(m_legendSettings);
    m_legendSettings->setVisible(false);

    m_fontSize = new QDoubleSpinBox();
    m_fontSize->setValue(m_chart->legend()->font().pointSizeF());
    connect(m_fontSize, SIGNAL(valueChanged(double)), this, SLOT(fontSizeChanged()));

    QFormLayout *fontLayout = new QFormLayout();
    fontLayout->addRow("Legend font size", m_fontSize);

    // Create layout for grid and detached legend
    m_mainLayout = new QGridLayout();
    m_mainLayout->addLayout(m_buttonLayout, 0, 0);
    m_mainLayout->addLayout(fontLayout, 1, 0);
    //m_mainLayout->addWidget(m_chartview, 0, 1, 3, 1);

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
    //![4]
        m_chart->legend()->setGeometry(QRectF(m_legendPosX->value(),
                                              m_legendPosY->value(),
                                              m_legendWidth->value(),
                                              m_legendHeight->value()));
        m_chart->legend()->update();
    //![4]
}

void MainWindow::pointClickedO(const QPointF &point){
    double minusDataY=100 ;
    //double minusDataX=100;
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
    //double minusDataX=100;
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
        if(curPos != point){
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



//峰参数计算显示
void MainWindow::currentDataToCloudServer()
{
//    int rowCount = seriesList.size();
//    double FWHM, Area;

//    //曲线ID初始化
//    Index = 0;
//    //没有曲线
//    if(rowCount == 0)
//    {
//        Utils::tipMessageBox("No curves have been drawn yet");
//        return;
//    }
//    //单条
//    if(rowCount == 1)
//    {
//        QList<QPointF> data = seriesList.last()->points();
//        emit peakParamsCalculation(data);
////        Utils::Filter(point);
////        Utils::peakParameterCalculation(point,FWHM,Area);
////        peakParametersInforShow(FWHM,Area);
//    }
//    //多条
//    else
//    {
//        multipleCurvesCalculation();
//    }

    emit peakParamsCalculation(currentAllDate.last());
    qDebug()<<time++;
    qDebug()<<"series size = "<<seriesList.last()->points().size();
    qDebug()<<"currenDataSize = "<<currentAllDate.last().size();
}

void MainWindow::peakParametersInforShow(double FWHM, double Area)
{
    //绘制标志
    isPPCalculation = true;
    //小数位数保留设置
    QString sFWHM = QString::number(FWHM,'f',2);
    QString sArea = QString::number(Area,'f',2);
    peakParametersShow->setText(QString("FWHM:%1 \n PeakArea:%2").arg(sFWHM).arg(sArea));
    qDebug()<< "FWHM = "<< FWHM;
    qDebug()<< "Area = "<< Area;
    //出现位置
    int gap = m_ui->chartLayout->margin();
    int width = m_ui->chartWidget->width();
    QPoint pos = m_ui->chartWidget->pos();
    peakParametersShow->move(pos.x()+width-peakParametersShow->width(),pos.y()+gap+peakParametersShow->height());
    peakParametersShow->show();
}

void MainWindow::multipleCurvesCalculation()
{
    qDebug()<< "triger is enter";
    double FWHM,Area;
    QList<QPointF> point;


    //复原
    for (int i = 0; i < seriesList.size(); i++)
    {
        QPen tempPen = seriesList.at(i)->pen();
        tempPen.setWidth(2);
        seriesList.at(i)->setPen(tempPen);
    }

    if (Index == seriesList.size())
    {
        Index = 0;
    }

    //计算
    point.append(seriesList.at(Index)->points());
    Utils::Filter(point);
    Utils::peakParameterCalculation(point, FWHM, Area);

    //颜色不变，加粗显示
    peakParametersInforShow(FWHM, Area);
    QPen newPen = seriesList.at(Index)->pen();
    newPen.setWidthF(5);
    seriesList.at(Index)->setPen(newPen);
    //移位
    Index++;
}

void MainWindow::actionDatabaseTrigger()
{

    if (dbDialog == nullptr)
    {
        dbDialog = new DataBaseDialog(this);

        //数据导出
        connect(dbDialog, &DataBaseDialog::isReadyToDraw, this, &MainWindow::exportDataToDraw);

        connect(dbServer, &DatabaseServer::inputSucess, dbDialog, &DataBaseDialog::updateShow);
    }

    dbDialog->exec();
}

void MainWindow::showInSertDBDialog()
{
    if (dbInsertDialog == nullptr)
    {
        dbInsertDialog = new DatabaseInsertDialog(this);

        //将信息与数据组装传递
        connect(dbInsertDialog, &DatabaseInsertDialog::inSertToDatabase, this, &MainWindow::currentDataInputToDatabase);
    }

    dbInsertDialog->exec();
}

void MainWindow::currentDataInputToDatabase(DBValues data)
{
    if (currentAllDate.isEmpty())
    {
        Utils::tipMessageBox("当前数据为空或已存在，或录入错误，请检查");
    }
    else
    {
        data.pointfList.append(currentAllDate);
        data.dataLength = currentAllDate.first().size();
        data.curvesNum = currentAllDate.size();
        emit inSertToDatabase(data);
        qDebug()<<"到达信号发送位置";
    }
}

void MainWindow::exportDataToDraw(QVector<QList<QPointF>> &data)
{
    //数据导出
    //清空
    seriesListClear();
    qDebug()<<"is reach data size is :"<<data.size();
    //新建曲线
    for (int i = 0; i < data.size(); i++)
    {
        emit receiveNewData(data.at(i));
    }
    Utils::tipMessageBox("数据导出成功");
}


void MainWindow::SettingsTrigger()
{
    if (allSettingsDialog == nullptr)
    {
        allSettingsDialog = new AllSettingsDialog(this);

        //设置后数据库重连
        connect(allSettingsDialog, &AllSettingsDialog::reConnect, dbServer, &DatabaseServer::readSettingsAndConnect);
        //udp参数重设
        connect(allSettingsDialog, &AllSettingsDialog::reSetUdpParams, networkServer, &NetworkServer::readSettingsAndBind);
        //数据入库参数重设
        connect(allSettingsDialog, &AllSettingsDialog::dbInsertSettingsUpdata, dbServer, &DatabaseServer::dbInsertSettingsUpdata);
    }

    allSettingsDialog->exec();
}
