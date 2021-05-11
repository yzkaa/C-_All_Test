#ifndef SPECTROGRAMFILTERDIALOG_H
#define SPECTROGRAMFILTERDIALOG_H

#include <QDialog>

namespace Ui {
class SpectrogramFilterDialog;
}

class SpectrogramFilterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SpectrogramFilterDialog(QWidget *parent = 0);
    ~SpectrogramFilterDialog();

private slots:
    void on_btn_sure_clicked();

private:
    Ui::SpectrogramFilterDialog *ui;
};

#endif // SPECTROGRAMFILTERDIALOG_H
