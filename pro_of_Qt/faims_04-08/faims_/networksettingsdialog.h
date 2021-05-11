#ifndef NETWORKSETTINGSDIALOG_H
#define NETWORKSETTINGSDIALOG_H

#include <QDialog>

#include "params.h"
#include "utils.h"
namespace Ui {
class NetworkSettingsDialog;
}

class NetworkSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NetworkSettingsDialog(QWidget *parent = 0);
    ~NetworkSettingsDialog();
signals:
    void reSetUdpParams();
public slots:
    void readSettingsAndShow();
private slots:
    void on_pushButto_connect_clicked();

private:
    Ui::NetworkSettingsDialog *ui;
};

#endif // NETWORKSETTINGSDIALOG_H
