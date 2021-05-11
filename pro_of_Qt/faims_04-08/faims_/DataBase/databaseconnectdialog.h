#ifndef DATABASECONNECTDIALOG_H
#define DATABASECONNECTDIALOG_H

#include <QDialog>
#include "utils.h"
namespace Ui {
class DatabaseConnectDialog;
}

class DatabaseConnectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DatabaseConnectDialog(QWidget *parent = 0);
    ~DatabaseConnectDialog();
signals:
    void reConnect();
public slots:
    void connectSucess();
private slots:
    void on_pushButto_connect_clicked();
private:
    Ui::DatabaseConnectDialog *ui;
};

#endif // DATABASECONNECTDIALOG_H
