#ifndef DATABASEINSERTDIALOG_H
#define DATABASEINSERTDIALOG_H

#include <QDialog>
#include "utils.h"

namespace Ui {
class DatabaseInsertDialog;
}

class DatabaseInsertDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DatabaseInsertDialog(QWidget *parent = 0);
    ~DatabaseInsertDialog();

signals:
    void inSertToDatabase(DBValues &data);
    void dbInsertSettingsUpdata();
private slots:
    void on_pushButton_sure_clicked();
    void readSettingsAndShow();
private:
    Ui::DatabaseInsertDialog *ui;
};

#endif // DATABASEINSERTDIALOG_H
