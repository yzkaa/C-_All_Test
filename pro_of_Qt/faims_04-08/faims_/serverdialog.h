#ifndef SERVERDIALOG_H
#define SERVERDIALOG_H

#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>
#include "utils.h"
namespace Ui {
class ServerDialog;
}

class ServerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ServerDialog(QWidget *parent = 0);
    ~ServerDialog();

private slots:
    void on_pushButton_connect_clicked();

private:
    Ui::ServerDialog *ui;
    QTcpServer *server = nullptr;
    QTcpSocket *socket = nullptr;

    QString IP;
    qint16 Port = 22;


    //
    bool isConnect = false;
};

#endif // SERVERDIALOG_H
