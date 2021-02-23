#include "imagewindow.h"
#include "ui_imagewindow.h"

#include <QCloseEvent>
#include <QFileDialog>
#include <QMainWindow>
#include <QPainter>
#include <QDebug>
#include <QMessageBox>

ImageWindow::ImageWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImageWindow)
{
    ui->setupUi(this);
    init();
}

ImageWindow::~ImageWindow()
{
    delete ui;
}

void ImageWindow::init(){

    connect(ui->saveLabel,&QPushButton::clicked,this,&ImageWindow::saveImage);
}

void ImageWindow::showImage(){
    image =  QPixmap(fileName);
    ui->label->setPixmap(image);
    ui->label->setAlignment(Qt::AlignCenter);
    startPos = endPos = {0,0};
    this->show();
}

void ImageWindow::mousePressEvent(QMouseEvent *e){
    startPos = ui->label->mapFromGlobal(e->globalPos());
    endPos = startPos;
}

void ImageWindow::mouseMoveEvent(QMouseEvent *e){

    if (e->type() == QEvent::MouseMove && (e->buttons() & Qt::LeftButton ))
    {
        endPos = ui->label->mapFromGlobal(e->globalPos());
        this->repaint();
        //ui->label->setPixmap(image);
    }


}

void ImageWindow::mouseReleaseEvent(QMouseEvent *e){
    this->repaint();
    qDebug()<<startPos<<" "<<endPos;
    ui->label->clear();
    ui->label->setPixmap(image);
}

void ImageWindow::paintEvent(QPaintEvent *e){
    QPixmap tmp = image.copy();
    QPen pen(qRgb(255,0,0));
    QPainter painter(&tmp);

    painter.setPen(pen);
    painter.setBrush(QBrush(qRgb(255,0,0),Qt::SolidPattern));
    painter.drawEllipse(QRectF(startPos,endPos));
    ui->label->setPixmap(tmp);
    if(ui->saveLabel->isDown()){
        image = tmp;
    }
}

void ImageWindow::saveImage(){

    QString filename = QFileDialog::getSaveFileName(this,
        tr("Save Image"),
        ("/home/yzk"),
        tr("")); //选择路径

    if (filename.isEmpty())
    {
        return;
    }
    else
    {
        if (!(image.save(filename+"-副本.tif"))) //保存图像
        {

            QMessageBox::information(this,
                tr("Failed to save the image"),
                tr("Failed to save the image!"));
            return;
        }
         QMessageBox::information(this,tr("图片保存成功"),tr("图片保存成功"));
    }


}
