#include "databaseconnectdialog.h"
#include "ui_databaseconnectdialog.h"

DatabaseConnectDialog::DatabaseConnectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatabaseConnectDialog)
{
    ui->setupUi(this);

    //
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    ui->pushButto_connect->setFocus();

    setAttribute(Qt::WA_DeleteOnClose);

    //读取显示
    DBParams data;
    Utils::readSettings(&data);
    if (data.isSucess)
    {
        ui->lineEdit_userName->setText(data.valueList.at(DBSETTINGSID_USERNAME).toString());
        ui->lineEdit_passWord->setText(data.valueList.at(DBSETTINGSID_PASSWORD).toString());
        ui->lineEdit_ip->setText(data.valueList.at(DBSETTINGSID_HOSTNAME).toString());
        ui->lineEdit_port->setText(data.valueList.at(DBSETTINGSID_PORT).toString());
    }
    else
    {
        Utils::tipMessageBox("配置文件读取错误");
    }
}

DatabaseConnectDialog::~DatabaseConnectDialog()
{
    delete ui;
}

void DatabaseConnectDialog::connectSucess()
{
    this->close();
}

void DatabaseConnectDialog::on_pushButto_connect_clicked()
{
    QList<QVariant> value;
    DBParams data;
    Utils::readSettings(&data);
    value.append(data.valueList);

    data.valueList[DBSETTINGSID_USERNAME] = ui->lineEdit_userName->text();
    data.valueList[DBSETTINGSID_PASSWORD] = ui->lineEdit_passWord->text();
    data.valueList[DBSETTINGSID_HOSTNAME] = ui->lineEdit_ip->text();
    data.valueList[DBSETTINGSID_PORT] = ui->lineEdit_port->text();

    for (int i = 0; i < data.nameList.size(); i ++)
    {
        if ( i == DBSETTINGSID_USERNAME || i == DBSETTINGSID_PASSWORD || i == DBSETTINGSID_HOSTNAME || i == DBSETTINGSID_PORT )
        {
            if (data.valueList.at(i) == "")
            {
                data.valueList[i] = value.at(i);
            }
        }
    }

    Utils::writeSettings(&data);

    emit reConnect();
}
