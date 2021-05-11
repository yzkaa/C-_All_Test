#ifndef ALLSETTINGSDIALOG_H
#define ALLSETTINGSDIALOG_H

#include <QDialog>

#include "settingdialog.h"
#include "DataBase/databaseconnectdialog.h"
#include "networksettingsdialog.h"
#include "DataBase/databaseinsertdialog.h"
namespace Ui {
class AllSettingsDialog;
}

class AllSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AllSettingsDialog(QWidget *parent = 0);
    ~AllSettingsDialog();
signals:
    void reConnect();
    void reSetUdpParams();
    void dbInsertSettingsUpdata();
private:
    Ui::AllSettingsDialog *ui;

    SettingDialog *serialPort = nullptr;
    DatabaseConnectDialog *dbConnect = nullptr;
    NetworkSettingsDialog *networkConnectSettings = nullptr;
    DatabaseInsertDialog *databaseInsertDialog = nullptr;
};

#endif // ALLSETTINGSDIALOG_H
