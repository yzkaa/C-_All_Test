#include "imagewindow.h"
#include "ui_imagewindow.h"

#include <QCloseEvent>
#include <QMainWindow>
#include <QPainter>
#include <QDebug>

ImageWindow::ImageWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImageWindow)
{
    ui->setupUi(this);

}

ImageWindow::~ImageWindow()
{
    delete ui;
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
}

void ImageWindow::mouseMoveEvent(QMouseEvent *e){

    if (e->type() == QEvent::MouseMove && (e->buttons() & Qt::LeftButton ))
    {
        endPos = ui->label->mapFromGlobal(e->globalPos());
        this->repaint();
        ui->label->setPixmap(image);
    }


}

void ImageWindow::mouseReleaseEvent(QMouseEvent *e){
    this->repaint();
    qDebug()<<startPos<<" "<<endPos;
    ui->label->clear();
    ui->label->setPixmap(image);
}

void ImageWindow::paintEvent(QPaintEvent *e){
    QPen pen(qRgb(255,0,0));
    QPainter painter(&image);
    painter.setPen(pen);
    painter.drawEllipse(QRectF(startPos,endPos));

}
