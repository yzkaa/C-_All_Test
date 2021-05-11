#include "serverdialog.h"
#include "ui_serverdialog.h"

ServerDialog::ServerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServerDialog)
{
    ui->setupUi(this);

    //初始化
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    setWindowTitle("Clound Server");
    server = new QTcpServer(this);
    socket = new QTcpSocket(this);
    //监听
    server->listen(QHostAddress::Any, 6000);

    //按钮状态变换
    connect(socket, &QTcpSocket::connected, [=](){
        Utils::tipMessageBox("connect success");
        isConnect = !isConnect;
    });
    connect(socket, &QTcpSocket::disconnected, [=](){
        isConnect = !isConnect;
    });

    //测试使用
    ui->lineEdit_ip->setText("");
}

ServerDialog::~ServerDialog()
{
    delete ui;
}

void ServerDialog::on_pushButton_connect_clicked()
{
    if (!isConnect)
    {
        QString ip = ui->lineEdit_ip->text();
        qint16 port = ui->lineEdit_port->text().toInt();

        if (ip.isEmpty() || port == 0)
        {
            Utils::tipMessageBox("Please enter the complete information");
        }
        else
        {
            socket->connectToHost(QHostAddress(ip), port);
        }
    }
    else
    {
        socket->disconnectFromHost();
    }


    //文字变换
    ui->pushButton_connect->setText(tr(isConnect == true ? "disConnect":"connect"));
}
