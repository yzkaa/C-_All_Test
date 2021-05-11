#include "allsettingsdialog.h"
#include "ui_allsettingsdialog.h"

AllSettingsDialog::AllSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AllSettingsDialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);

    setWindowTitle("Settings");

    //串口设置界面
    serialPort = new SettingDialog(this);
    //数据库连接设置界面
    dbConnect = new DatabaseConnectDialog(this);
    //Udp连接参数配置界面
    networkConnectSettings = new NetworkSettingsDialog(this);
    //数据插入配置界面
    databaseInsertDialog = new DatabaseInsertDialog(this);

    //添加到tabWidget
    ui->tabWidget->removeTab(0);
    ui->tabWidget->removeTab(0);
    ui->tabWidget->addTab(serialPort, "Serial port");
    ui->tabWidget->addTab(dbConnect, "Database");
    ui->tabWidget->addTab(networkConnectSettings, "Network");
    ui->tabWidget->addTab(databaseInsertDialog, "Database Insert");

    //信号转发
    connect(dbConnect, &DatabaseConnectDialog::reConnect, this, &AllSettingsDialog::reConnect);
    connect(networkConnectSettings, &NetworkSettingsDialog::reSetUdpParams, this, &AllSettingsDialog::reSetUdpParams);
    connect(databaseInsertDialog, &DatabaseInsertDialog::dbInsertSettingsUpdata, this, &AllSettingsDialog::dbInsertSettingsUpdata);
}

AllSettingsDialog::~AllSettingsDialog()
{
    delete ui;
}
