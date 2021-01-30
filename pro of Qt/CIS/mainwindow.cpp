#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    //button
    setPushButton(ui->select_picture,"选择图片",":/images/photo.png",ui->select_picture->width(),ui->select_picture->height());
    setPushButton(ui->exit,"退出",":/images/exit.png",ui->exit->width()+15,ui->exit->height()+15);
}


void MainWindow::connectList(){

}



/***********************轮子******************************/
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
