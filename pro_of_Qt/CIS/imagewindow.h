#ifndef IMAGEWINDOW_H
#define IMAGEWINDOW_H

#include "counterthread.h"

#include <QMainWindow>

namespace Ui {
class ImageWindow;
}

class ImageWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImageWindow(QWidget *parent = nullptr);
    ~ImageWindow();
    QString fileName;
    void showImage();

private:
    Ui::ImageWindow *ui;
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);

    void init();
    void saveImage();
    void startCounter();

private:
    QPixmap image;
    QPointF startPos;
    QPointF endPos;
    CounterThread *ct;
};

#endif // IMAGEWINDOW_H
