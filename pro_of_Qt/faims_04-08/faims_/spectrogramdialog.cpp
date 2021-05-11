#include "spectrogramdialog.h"
#include "ui_spectrogramdialog.h"
SpectrogramDialog::SpectrogramDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpectrogramDialog)
{
    ui->setupUi(this);

    Initialization();
    CoustemConnects();

}

SpectrogramDialog::~SpectrogramDialog()
{
    delete ui;
    delete myPlot;
}

void SpectrogramDialog::Initialization()
{
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    setAttribute(Qt::WA_QuitOnClose,false); //主窗口关闭时释放内存，当子窗口显示时，关闭主窗口，并不进行析构，而是进行窗口关闭，只有所有窗口都关闭后才析构，而子窗口不显示时，关闭主窗口，则直接析构，具体见博文https://blog.csdn.net/qq_40754866/article/details/109217799
//    setAttribute(Qt::WA_DeleteOnClose,true);
    //设置点击获取焦点
    setFocusPolicy(Qt::ClickFocus);
//    setFocusPolicy(Qt::NoFocus);
    //谱图相关
    myPlot=new QwtPlot;                   //先实例化，避免重复
    mySpectrogram=new QwtPlotSpectrogram;
    mydata=new QwtMatrixRasterData;
    colormap=new LinearColorMapRGB;
    colorbar=new LinearColorMapRGB;
    //设置颜色映射
    mySpectrogram->setColorMap(colormap);  //在添加了颜色映射之后（相当于加入了子表），如果再手动释放colormap就会双重释放报错
    mydata->setResampleMode( QwtMatrixRasterData::BilinearInterpolation);//设置插值模式，根据矩阵中4个周围值的距离和值进行插值
    mySpectrogram->setData(mydata);
    mySpectrogram->attach(myPlot);

    mySpectrogram->setRenderHint(QwtPlotItem::RenderAntialiased,true);
    mySpectrogram->setDisplayMode(QwtPlotSpectrogram::ImageMode,true);  //设置显示模式
    mySpectrogram->setDisplayMode(QwtPlotSpectrogram::ContourMode,false);

    rightAxis=myPlot->axisWidget(QwtPlot::yRight); //指向颜色栏坐标
    rightAxis->setColorBarEnabled(true);
    myPlot->enableAxis(QwtPlot::yRight);

    myPlot->setAxisTitle(QwtPlot::xBottom,"补偿电压");
    myPlot->setAxisTitle(QwtPlot::yLeft,"射频电压");
    myPlot->setAxisMaxMinor(QwtPlot::yRight,0);   //去掉小刻度
    myPlot->setAxisMaxMinor(QwtPlot::yLeft,0);

//    myPlot->setAxisLabelRotation(QwtPlot::yRight,90);  //改变刻度标签的角度
    myMainlayout=new QVBoxLayout;  //因为qwt在ui界面难以操作，所以使用代码定义与布局
    myMainlayout->addWidget(myPlot);

    ui->widget_drawArea->setLayout(myMainlayout);




    //限制设置
    QIntValidator *Xvalidator = new QIntValidator(-100, 100, this);
    QIntValidator *Yvalidator = new QIntValidator(0, 1000, this);
    ui->lineEdit_xEnd->setValidator(Xvalidator);
    ui->lineEdit_xStart->setValidator(Xvalidator);
    ui->lineEdit_yEnd->setValidator(Yvalidator);
    ui->lineEdit_yStart->setValidator(Yvalidator);
    //不可输入
    ui->comboBox_BackgroundColorSelect->setEditable(false);


    //comboBox相应设置
    //背景下拉项生成
    ui->comboBox_BackgroundColorSelect->addItem(tr("Black"),QColor(Qt::black));
    ui->comboBox_BackgroundColorSelect->addItem(tr("White"),QColor(Qt::white));
    ui->comboBox_BackgroundColorSelect->addItem(tr("blue"),QColor(Qt::blue));
    ui->comboBox_BackgroundColorSelect->setCurrentText(tr("blue"));
    //enhance
    ui->comboBox_Enhance->addItem(tr("0.5"),1.5);
    ui->comboBox_Enhance->addItem(tr("0.75"),1.25);
    ui->comboBox_Enhance->addItem(tr("1"),1);
    ui->comboBox_Enhance->addItem(tr("1.25"),0.75);
    ui->comboBox_Enhance->addItem(tr("1.5"),0.5);
    ui->comboBox_Enhance->addItem(tr("1.75"),0.25);
    ui->comboBox_Enhance->setCurrentIndex(2);
    //ClearMode
    ui->comboBox_DataClearMode->addItem(tr("Mode 1"),1);
    ui->comboBox_DataClearMode->addItem(tr("Manual"),2);
    ui->comboBox_DataClearMode->setCurrentText("Mode 1");

    //初始化控件可编辑状态设置
    on_ControlStateChange(0);

    //doubleSpinBox 步长
    ui->doubleSpinBox->setSingleStep(0.3);

    //布局
    ui->Layout_mainWidget->setStretch(1,3);


    //lineEdit批量处理录入
    LineEditList.append(ui->lineEdit_xStart);
    LineEditList.append(ui->lineEdit_xEnd);
    LineEditList.append(ui->lineEdit_yStart);
    LineEditList.append(ui->lineEdit_yEnd);

    for(int i = 0; i < LineEditList.size(); i++)
    {
        //设置点击才获取焦点，避免软件盘直接弹出影响体感
        LineEditList.at(i)->setFocusPolicy(Qt::ClickFocus);
    }
}

void SpectrogramDialog::CoustemConnects()
{
    //自定义信号和槽的连接
    connect(this, &SpectrogramDialog::DrawSpectrogram, this, &SpectrogramDialog::toDrawSpectrogram);
    connect(ui->comboBox_BackgroundColorSelect,QOverload<int>::of(&QComboBox::currentIndexChanged),this,&SpectrogramDialog::on_BackgroundColorChange);
    //状态切换
    connect(this,&SpectrogramDialog::ControlStateChange,this,&SpectrogramDialog::on_ControlStateChange);
    connect(ui->comboBox_DataClearMode,QOverload<int>::of(&QComboBox::currentIndexChanged),[=](){emit ControlStateChange(ui->comboBox_DataClearMode->currentData().toInt());});
    //显示增强切换
    connect(ui->comboBox_Enhance,QOverload<int>::of(&QComboBox::currentIndexChanged),this,&SpectrogramDialog::showEnhance);

}

void SpectrogramDialog::Int_To26_QString(int mydata, QString &res)
{
    ch=mydata+0x40;  //A 为0x40
    m_str=QString(ch);//浅拷贝，用的是QString的构造函数实现char转QString
    res+=m_str;
}

QString SpectrogramDialog::Columns_identifier(int columns)
{
    Q_ASSERT(columns>0&&columns<65535); //错误提示，参数为falsse时会打印警告信息
    QString str2;
    int merchant,remainder;
    while(columns>0)
    {
        merchant = columns / 26;
        remainder = columns % 26;
        if(merchant>0 && merchant<27)  //如果为2，说明到了BX ,<27到ZZ  最多两位到zz  26*26=676+26=702列
        {
            Int_To26_QString(merchant,str2);
            Int_To26_QString(remainder,str2);
            return str2;
        }

        else
        {
            Int_To26_QString(remainder,str2);
            return str2;
        }
    }

    return str2;
}

void SpectrogramDialog::toDrawSpectrogram(QVector<double> &SpectrogramData)
{
    mydata->setValueMatrix(SpectrogramData, matrixColumn);   //转化成数据栅格矩阵
    mydata->setInterval(Qt::XAxis,QwtInterval(xMin, xMax));     //x,y数据的默认刻度
    mydata->setInterval(Qt::YAxis,QwtInterval(yMin, yMax));
    mydata->setInterval(Qt::ZAxis,QwtInterval(mindata, maxdata));

    myPlot->setAxisScale(QwtPlot::yRight, mindata, maxdata);

    const QwtInterval zInterval=mydata->interval(Qt::ZAxis);//注意m_spetrogram->setData(m_data);要写在前面，不然会读取错误，先设好才能读取到
    rightAxis->setColorMap(zInterval,colorbar); //给同一个参数,关闭时程序异常结束！！！！！！！！这句 ，双重释放；现在这种方式不会

    myPlot->setAxisScale(QwtPlot::xBottom,xMin,xMax);
    myPlot->setAxisScale(QwtPlot::yLeft, yMin, yMax, step);  //数据和QwtPlot都有坐标轴，两者要对应，其中，QwtPlot可以设置步长

    myPlot->replot();


    //改变控件状态
    //已成功绘图状态
    CurrentState = 1;
}

void SpectrogramDialog::getSpectrogramParameter(QVector<QList<QPointF>> &data, double yMin, double yMax, double xMin, double xMax)
{
    if (data.isEmpty())
    {
        Utils::tipMessageBox("数据为空");
        return;
    }

    getDataMode = LOWER_MACHINE;

    //轴线范围
    maxdata = yMax; //这是z轴的映射范围
    mindata = yMin;
    this->xMin = xMin;
    this->xMax = xMax;
    matrixColumn = data.first().size();
    this->yMax = this->yMin + data.size()*step;

    //取数据
    InitData.clear();
    QVector<double> temp;
    QList<QPointF>::const_iterator it;
    for (int i = 0; i < data.size(); i++)
    {
        for (it = data.at(i).begin(); it != data.at(i).end(); it++)
        {
            temp.append((*it).y());
        }

        InitData.append(temp);
        temp.clear();
    }

//    toDrawSpectrogram(cacheData);

//    qDebug()<<"逐条数据";
//    qDebug()<<"myrows = "<<matrixColumn;

    //预处理
    Pre_processing();
}


void SpectrogramDialog::Pre_processing()
{
    //过滤掉偏大的数据(条)，使显示变得正常
    //找到第一大和第二大的曲线峰值
    double max1 = 0;
    double max2 =0;
    int max1CurveID;
    QVector<double>::const_iterator it;
    for (int i = 0;  i < InitData.size(); i++)
    {
        for (it = InitData.at(i).begin(); it != InitData.at(i).end(); it++)
        {
            if (max1 < *it)
            {
                max2 = max1;
                max1 = *it;

                max1CurveID = i;
            }
        }
    }

    //峰值最大的曲线，远大于之后的曲线，去除
    if(max1 / max2 > 1.5)
    {
        InitData.removeAt(max1CurveID);
    }
    //转换
    QVector<double> Data;
    for (int i = 0; i < InitData.size(); i++)
    {
        Data.append(InitData.at(i));
    }

    //取颜色映射(Z轴)范围，如果是文件打开的模式
    if (getDataMode == FILE_OPEN)
    {
        //找到最大最小值映射值，找到Z轴最小值;
        maxdata = 0;
        mindata = 0;
        for (it = Data.begin(); it != Data.end(); it++)
        {
            if (maxdata < *it)
            {
                maxdata = *it;
            }
            if (mindata > *it)
            {
                mindata = *it;
            }
        }

        yMax=step*(mycolumns-1)+yMin;
    }

    //doubleSpinbox设置
    ui->doubleSpinBox->setMinimum(mindata);
    ui->doubleSpinBox->setValue(mindata);

    emit DrawSpectrogram(Data);
}

//槽函数
void SpectrogramDialog::on_pushButton_OpenFile_clicked()
{
//    //QAxObject的方法，其他系统不知到是否可用
//    QList<QVector<double>> clear;
//    QVector<double> clear1;
//    Data.swap(clear1);    //清空上次的的数据
//    InitData.swap(clear);
//    dataYAxis=Y_Value1;

//    QAxObject *excel=new QAxObject(this);
//    excel->setControl("Excel.Application");  //连接Excel控件
//    excel->setProperty("Visible", false);//显示窗体看效果,选择ture将会看到excel表格被打开
//    excel->setProperty("DisplayAlerts", true);//显示警告看效果
//    QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿(excel文件)集合
//    QString str =QFileDialog::getOpenFileName(this,"Open file",QStandardPaths::writableLocation(QStandardPaths::DesktopLocation),"Excel 文件(*.xls *.xlsx)");

//    if(str.isEmpty())
//    {
//        QMessageBox::critical(this,"error","open false");
//        return;
//    }

//    workbooks->dynamicCall("Open(const QString&)", str);//打开刚才选定的excel
//    QAxObject *workbook = excel->querySubObject("ActiveWorkBook");
//    QAxObject *worksheet = workbook->querySubObject("WorkSheets(int)",1);
//    QAxObject *usedRange = worksheet->querySubObject("UsedRange");//获取表格中的数据范围
//    QAxObject *rows=usedRange->querySubObject("Rows");  //行
//    QAxObject *columns=usedRange->querySubObject("columns");  //列
//    int introws=rows->property("Count").toInt();
//    int intcolumns=columns->property("Count").toInt();

//    myrows=introws;
//    mycolumns=intcolumns;

//    //范围读取，提高读取速度
//    QString Range="A1:"+Columns_identifier(intcolumns)+QString::number(introws);
//    QAxObject *allEnvData=worksheet->querySubObject("Range(QString)",Range);
//    QVariant  allEnvDataQVariant=allEnvData->dynamicCall("Value");
//    QVariantList allEnvDataList = allEnvDataQVariant.toList();
//    QList<QList<QVariant>> excel_list;//用于将QVariant转换为Qlist的二维数组
//    if(allEnvDataList.isEmpty())
//    {
//       return;
//    }
//    const int row_count = allEnvDataList.size();
//    QVariantList rowData;
//    for(int i=0;i<row_count;++i)
//    {
//       rowData =  allEnvDataList[i].toList();
//       excel_list.push_back(rowData);
//    }//转换完毕
//    workbooks->dynamicCall("Close()");  //关闭excel

//    //数据传入指定容器
//    QVector<double> data;
//    for(int i=0;i<excel_list.at(0).length();i++){ //列长度
//        data.clear();
//        for(int j=0;j<excel_list.length();j++)  //行长度
//            data+=excel_list.at(j).at(i).toDouble();//按列读取到QVector容器
//        InitData.push_back(data);
//    }

    //QXlsx文件读取，可跨平台
    /*
    QString filePath =QFileDialog::getOpenFileName(this,"Open file",
                                              QStandardPaths::writableLocation(QStandardPaths::DesktopLocation),
                                              "Excel 文件(*.xls *.xlsx)");
    QXlsx::Document xlsx(filePath);

    QXlsx::Workbook *workBook = xlsx.workbook();
    QXlsx::Worksheet *workSheet = static_cast<QXlsx::Worksheet*>(workBook->sheet(0));

    matrixColumn = workSheet->dimension().rowCount();
    mycolumns = workSheet->dimension().columnCount();
    QVector<double> data;
    //行列从1开始,竖着读取
    //注意是从1，开始，录入时得 《=  否则会少录入一个，导致画图的时候读取QList崩溃
    for(int colmun = 1; colmun <= mycolumns; colmun++)
    {
        for(int row = 1; row <= matrixColumn; row++)
        {
            QXlsx::Cell *cell = workSheet->cellAt(row,colmun);
            data += cell->value().toDouble();
        }
        InitData.append(data);
        data.clear();
    }

    getDataMode = FILE_OPEN;

    qDebug()<<"文件打开";
    qDebug()<<"myrows = "<<matrixColumn;
    qDebug()<<"InitData = "<<InitData.size();

   Pre_processing();  //预先处理
   */
}

void SpectrogramDialog::on_BackgroundColorChange()
{
    QColor Color=ui->comboBox_BackgroundColorSelect->itemData(ui->comboBox_BackgroundColorSelect->currentIndex()).value<QColor>();
    colormap->setColorInterval(Color,QColor(Qt::red));
    colormap->addColorStop(0.125,QColor(0,0,255));
    colormap->addColorStop(0.375,QColor(0,255,255));
    colormap->addColorStop(0.625,QColor(255,255,0));
    colormap->addColorStop(0.875,QColor(255,0,0));

    colorbar->setColorInterval(Color,QColor(Qt::red));
    colorbar->addColorStop(0.125,QColor(0,0,255));
    colorbar->addColorStop(0.375,QColor(0,255,255));
    colorbar->addColorStop(0.625,QColor(255,255,0));
    colorbar->addColorStop(0.875,QColor(255,0,0));

    myPlot->replot();
}

void SpectrogramDialog::on_ControlStateChange(int State)
{
    //0是初始状态
    if(State == 0)
    {
        ui->comboBox_Enhance->setEditable(false);   //注意区分editable和endable
        ui->comboBox_Enhance->setEnabled(false);
        ui->comboBox_BackgroundColorSelect->setEnabled(false);
        ui->comboBox_DataClearMode->setEnabled(false);
        ui->pushButton_Change->setEnabled(false);
        ui->pushButton_Remove->setEnabled(false);
        ui->pushButton_Back->setEnabled(false);
        ui->doubleSpinBox->setEnabled(false);
        ui->pushButton_SaveSpectrogram->setEnabled(false);
    }

    else if(State == 1)
    {
        ui->comboBox_Enhance->setEnabled(true);
        ui->comboBox_BackgroundColorSelect->setEnabled(true);
        ui->pushButton_Change->setEnabled(true);
        ui->pushButton_Remove->setEnabled(true);
        ui->pushButton_Back->setEnabled(true);
        ui->comboBox_DataClearMode->setEnabled(true);
        ui->pushButton_SaveSpectrogram->setEnabled(true);
        ui->doubleSpinBox->setEnabled(false);       
    }

    else if(State == 2)
    {
        ui->doubleSpinBox->setEnabled(true);
    }
}


bool SpectrogramDialog::event(QEvent *event)
{
    if(ControlState !=  CurrentState)
    {
        ControlState = CurrentState;
        emit ControlStateChange(ControlState);
    }

    return QDialog::event(event);
}


void SpectrogramDialog::showEnhance()
{
    float upLimit = ui->comboBox_Enhance->currentData().toFloat();
    upLimit = maxdata * upLimit;
    mydata->setInterval(Qt::ZAxis,QwtInterval(mindata,upLimit));
    myPlot->replot();
}



//去除,低于一水平的数据   !!不能删除数据，最好将其变成最小值或0
void SpectrogramDialog::on_pushButton_Remove_clicked()
{
    QString Mode = ui->comboBox_DataClearMode->currentText();
    if(Mode == "Manual")
    {
        QVector<double> tempData;
        float level = ui->doubleSpinBox->value();
        for(int i = 0; i < InitData.size(); i ++)
        {
            tempData.append(InitData.at(i));
        }

        for(int i = 0; i < tempData.size(); i++)
        {
            if(tempData.at(i) < level)
            {
                tempData[i] = 0;
            }
        }
        Data.swap(tempData);
        emit DrawSpectrogram(Data);
    }
}

void SpectrogramDialog::on_pushButton_Back_clicked()
{
    QVector<double> tempData;
    for(int i = 0; i < InitData.size(); i++)
    {
        tempData.append(InitData.at(i));
    }

    Pre_processing();
    emit DrawSpectrogram(tempData);
}

void SpectrogramDialog::on_pushButton_Change_clicked()
{
    QString str1(ui->lineEdit_xStart->text());
    QString str2(ui->lineEdit_xEnd->text());
    QString str3(ui->lineEdit_yStart->text());
    QString str4(ui->lineEdit_yEnd->text());

    if(str1 != NULL&& str2 != NULL){
        xMin=str1.toInt();
        xMax=str2.toInt();
    }
    else if(str1 != NULL){
        xMin=str1.toInt();
    }
    else if(str2 != NULL){
        xMax=str2.toInt();
    }

    if(str3 != NULL&& str4 != NULL){
        yMin=str3.toInt();
        yMax=str4.toInt();
    }
    else if(str3 != NULL){
        yMin=str3.toInt();
    }
    else if(str4!=NULL){
        yMax=str4.toInt();
    }
    mydata->setInterval(Qt::XAxis,QwtInterval(xMin,xMax));     //x,y数据的默认刻度
    mydata->setInterval(Qt::YAxis,QwtInterval(yMin,yMax));
    myPlot->setAxisScale(QwtPlot::xBottom,xMin,xMax);
    myPlot->setAxisScale(QwtPlot::yLeft,yMin,yMax,step);
    myPlot->replot();
}

void SpectrogramDialog::on_pushButton_SaveSpectrogram_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this,"Save Spectrogram",QStandardPaths::writableLocation(QStandardPaths::DesktopLocation),"Image file(*.png)");
    qDebug()<<filename;
    if(! filename.isEmpty())
    {
        QScreen *screen = QGuiApplication::primaryScreen();
        if (screen) {
            screen->grabWindow(myPlot->winId()).save(filename);
        }
        QMessageBox::information(this, tr("Save Spectrogram"), tr("The image file was saved successfully."));
    }

}
