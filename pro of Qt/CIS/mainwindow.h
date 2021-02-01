#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "secondwindow.h"

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void readOk();

private:
    Ui::MainWindow *ui;

    //各种初始化
    void windowsInit();
    //连接列表
    void connectList();
    //更改按钮
    void setPushButton(QPushButton *btn,const char tips[50],QString iconPath,int width,int height);
    //选择图片
    void pictureSelect();
    //事件重写
    void closeEvent(QCloseEvent *e);


private:
    SecondWindow sw;
};
#endif // MAINWINDOW_H
