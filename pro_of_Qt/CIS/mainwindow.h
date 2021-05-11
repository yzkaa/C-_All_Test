#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "imagewindow.h"

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

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
//    void mousePressEvent(QMouseEvent *e);
//    void mouseReleaseEvent(QMouseEvent *e);
//    void mouseMoveEvent(QMouseEvent *e);
//    void paintEvent(QPaintEvent *e);

private:
    QMainWindow *window;
    Ui::MainWindow *ui;
    QPixmap *pm;
    QLabel *imgBox;
    QPointF startPos;
    QPointF endPos;
    ImageWindow iw;

};
#endif // MAINWINDOW_H
