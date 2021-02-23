#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imagewindow.h"

#include <QFileDialog>
#include <QDebug>
#include <QApplication>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDesktopWidget>
#include <QMainWindow>
#include <QScrollArea>
#include <QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    windowsInit();
    connectList();

}

MainWindow::~MainWindow()
{
    delete ui;
}
/************************界面*****************************/
void MainWindow::windowsInit(){
    //main window
    this->setWindowTitle("菌落自动计数系统V1.0");
    QPalette windowPal = this->palette();
    windowPal.setColor(QPalette::Window,qRgb(38,0,92));
    this->setPalette(windowPal);
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // 禁止最大化按钮
    setFixedSize(this->width(),this->height());                     // 禁止拖动窗口大小
    QDesktopWidget *desktop = QApplication::desktop();
    move((desktop->width()-this->width())/2,(desktop->height()-this->height())/2);//居中显示
    //button
    setPushButton(ui->select_picture,"选择图片",":/images/photo.png",ui->select_picture->width(),ui->select_picture->height());
    setPushButton(ui->exit,"退出",":/images/exit.png",ui->exit->width()+15,ui->exit->height()+15);

}


void MainWindow::connectList(){
    connect(ui->select_picture,&QPushButton::clicked,this,&MainWindow::pictureSelect);
    connect(ui->exit,&QPushButton::clicked,this,&MainWindow::close);
    connect(this,&MainWindow::readOk,&iw,&ImageWindow::showImage);
}

void MainWindow::pictureSelect(){
    iw.fileName = "";
    //定义文件对话框类
    QFileDialog *fileDialog = new QFileDialog(this);
    //定义文件对话框标题
    fileDialog->setWindowTitle(QStringLiteral("选择图片"));
    //设置默认文件路径
    fileDialog->setDirectory("/home/yzk/PYTHON");
    //设置文件过滤器
    fileDialog->setNameFilter(tr("File(*.png *.jpg *.jpeg *.tif *.bmp)"));
    //设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    //设置视图模式
    fileDialog->setViewMode(QFileDialog::Detail);

    if((iw.fileName = fileDialog->getOpenFileName()) ==NULL){
        return ;
    }
    emit readOk();
}

void MainWindow::closeEvent(QCloseEvent *event){
    QMessageBox::StandardButton result=QMessageBox::question(this, "确认", "确定要退出本系统吗？",
                         QMessageBox::Yes|QMessageBox::No |QMessageBox::Cancel,
                         QMessageBox::No);

       if (result==QMessageBox::Yes)
           event->accept();
       else
           event->ignore();
}


//size: icon size(width,height)
void MainWindow::setPushButton(QPushButton *btn,const char tips[50], QString iconPath, int width,int height){
    btn->setIcon(QIcon(iconPath));
    btn->setIconSize(QSize(width,height));
    btn->setAutoFillBackground(true);
    btn->setFlat(true);
    btn->setStyleSheet("QPushButton{border-radius:10px;padding:10px 10px;background-color: rgb(255,62,150);}"
                       "QPushButton::hover{border-radius:10px;padding:10px 10px;background-color: rgb(238,58,140);}"
                       "QPushButton::pressed{border-radius:10px;padding:10px 10px;background-color: rgb(205,50,120);}");
    btn->setToolTip(QString::fromLocal8Bit(tips));

}

//void MainWindow::mousePressEvent(QMouseEvent *e){
//    startPos = e->pos();

//}

//void MainWindow::mouseMoveEvent(QMouseEvent *e){

//    if (e->type() == QEvent::MouseMove && (e->buttons() & Qt::LeftButton ))
//    {
//        endPos = e->pos();
//        this->repaint();
//    }


//}

//void MainWindow::mouseReleaseEvent(QMouseEvent *e){

//    qDebug()<<startPos<<" "<<endPos;
//    this->repaint();
//}

//void MainWindow::paintEvent(QPaintEvent *e){
//    QPen pen(Qt::red);
//    QPainter painter(this);
//    painter.setPen(pen);
//    painter.drawEllipse(QRectF(startPos,endPos));
//}
