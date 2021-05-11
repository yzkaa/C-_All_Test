#include "databaseinsertdialog.h"
#include "ui_databaseinsertdialog.h"

DatabaseInsertDialog::DatabaseInsertDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatabaseInsertDialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);

    ui->pushButton_sure->setFocus();


    readSettingsAndShow();
}

DatabaseInsertDialog::~DatabaseInsertDialog()
{
    delete ui;
}

void DatabaseInsertDialog::on_pushButton_sure_clicked()
{
    DBValues data;

    data.gasType = ui->lineEdit_gasType->text();
    data.gasVolume = ui->lineEdit_gasVolume->text();

    data.reMarks = ui->textEdit->toPlainText();

    if (data.gasType.isEmpty())
    {
        data.gasType = "null";
    }
    if (data.gasVolume.isEmpty())
    {
        data.gasVolume = "null";
    }
    if (data.reMarks.isEmpty())
    {
        data.reMarks = "null";
    }

    emit inSertToDatabase(data);

    this->accept();

    //配置文件写入
//    DBInsertParams data;
//    Utils::readSettings(&data);

//    QString gasType = ui->lineEdit_gasType->text();
//    QString gasVolume = ui->lineEdit_gasVolume->text();
//    QString startRF = ui->lineEdit_startRF->text();
//    QString remarks = ui->textEdit->toPlainText();

//    if (!gasType.isEmpty())
//    {
//        data.valueList[DBINSERTPARAMSID_GASTYPE] = gasType;
//    }
//    if (!gasVolume.isEmpty())
//    {
//        data.valueList[DBINSERTPARAMSID_GASVOLUME] = gasVolume;
//    }
//    if (!startRF.isEmpty())
//    {
//        data.valueList[DBINSERTPARAMSID_STARTRF] = startRF;
//    }
//    if (!remarks.isEmpty())
//    {
//        data.valueList[DBINSERTPARAMSID_REMARKS] = remarks;
//    }

//    //数据插入的地方读取跟新的配置
//    emit dbInsertSettingsUpdata();
}

void DatabaseInsertDialog::readSettingsAndShow()
{
    DBInsertParams params;
    Utils::readSettings(&params);

    ui->lineEdit_gasType->setText(params.valueList.at(DBINSERTPARAMSID_GASTYPE).toString());
    ui->lineEdit_gasVolume->setText(params.valueList.at(DBINSERTPARAMSID_GASVOLUME).toString());
    ui->lineEdit_startRF->setText(params.valueList.at(DBINSERTPARAMSID_STARTRF).toString());
    ui->textEdit->setText(params.valueList.at(DBINSERTPARAMSID_REMARKS).toString());
}
