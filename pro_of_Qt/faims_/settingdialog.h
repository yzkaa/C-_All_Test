#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QIntValidator>
#include <QTimer>

QT_BEGIN_NAMESPACE

namespace Ui {
class SettingDialog;
}

class QIntValidator;

QT_END_NAMESPACE

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    struct Settings {
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
        bool localEchoEnabled;
    };
    Ui::SettingDialog *m_ui = nullptr;

    bool conncetOK=false;
    explicit SettingDialog(QWidget *parent = 0);
    ~SettingDialog();

    Settings settings() const;
    QTimer *m_timer;

signals:
    void ready();
    void connectIsOK();

private slots:
    void showPortInfo(int idx);
    void apply(void);
    void checkCustomBaudRatePolicy(int idx);
    void checkCustomDevicePathPolicy(int idx);

    void Timer_Init();


    void on_searchButton_clicked();

private:
    void fillPortsParameters(void);
    void fillPortsInfo(void);
    void updateSettings(void);

private:

    Settings m_currentSettings;
    QIntValidator *m_intValidator = nullptr;

};

#endif // SETTINGDIALOG_H
