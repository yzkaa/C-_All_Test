#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    s_ui(new Ui::SecondWindow)
{
    s_ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete s_ui;
}

void SecondWindow::showPicture(){
    pm = new QPixmap(fileName);
    s_ui->picture->setPixmap(*pm);
    this->show();
}


