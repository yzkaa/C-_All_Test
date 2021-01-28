#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init(){
    //title
    this->setWindowTitle("菌落自动计数系统V1.0");
    QPalette pal = ui->select_picture->palette();
    pal.setColor(QPalette::Button,qRgb(255,0,105));
    ui->select_picture->setIcon(QIcon(":/images/photo.png"));
    ui->select_picture->setIconSize(QSize(ui->select_picture->width(),ui->select_picture->height()));
    ui->select_picture->setPalette(pal);
    ui->select_picture->setAutoFillBackground(true);
    ui->select_picture->setFlat(true);


}
