#include "networksettingsdialog.h"
#include "ui_networksettingsdialog.h"

NetworkSettingsDialog::NetworkSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NetworkSettingsDialog)
{
    ui->setupUi(this);

    readSettingsAndShow();
}

NetworkSettingsDialog::~NetworkSettingsDialog()
{
    delete ui;
}

void NetworkSettingsDialog::readSettingsAndShow()
{
    UdpParams data;
    Utils::readSettings(&data);

    ui->lineEdit_currentIP->setText(data.valueList.at(UDPPARAMSID_CURRENTIP).toString());
    ui->lineEdit_currentPort->setText(data.valueList.at(UDPPARAMSID_CURRENTPORT).toString());
    ui->lineEdit_targetIP->setText(data.valueList.at(UDPPARAMSID_CURRENTIP).toString());
    ui->lineEdit_targetPort->setText(data.valueList.at(UDPPARAMSID_TARGETPORT).toString());
}

void NetworkSettingsDialog::on_pushButto_connect_clicked()
{
    UdpParams data;

    data.valueList[UDPPARAMSID_CURRENTIP] = ui->lineEdit_currentIP->text();
    data.valueList[UDPPARAMSID_CURRENTPORT] = ui->lineEdit_currentPort->text();
    data.valueList[UDPPARAMSID_TARGETIP] = ui->lineEdit_targetIP->text();
    data.valueList[UDPPARAMSID_TARGETPORT] = ui->lineEdit_targetPort->text();

    Utils::writeSettings(&data);

    emit reSetUdpParams();
}
