#include "spectrogramfilterdialog.h"
#include "ui_spectrogramfilterdialog.h"

SpectrogramFilterDialog::SpectrogramFilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpectrogramFilterDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);

    ui->timeStart->setCalendarPopup(true);
    ui->timeEnd->setCalendarPopup(true);

    QDateTime dataTime = QDateTime::currentDateTime();
    ui->timeStart->setDateTime(dataTime);
    ui->timeEnd->setDateTime(dataTime);
}

SpectrogramFilterDialog::~SpectrogramFilterDialog()
{
    delete ui;
}

void SpectrogramFilterDialog::on_btn_sure_clicked()
{
    QString filter;
    QString tableName;
    QString gasType;
}
