#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();
public:
    void showPicture();
public:
    QString fileName;
private:
    Ui::SecondWindow *s_ui;


private:
    QPixmap *pm;
};

#endif // SECONDWINDOW_H
