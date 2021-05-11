#ifndef SERIALPORTSETTING_H
#define SERIALPORTSETTING_H


#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QIntValidator>

#include <QDialog>

namespace Ui {
class SerialPortSetting;
}

class QIntValidator;

class SerialPortSetting : public QDialog
{
    Q_OBJECT

public:
    explicit SerialPortSetting(QWidget *parent = nullptr);
    ~SerialPortSetting();
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
    Settings settings() const;

private slots:
    void showPortInfo(int idx);
    void apply(void);
    void checkCustomBaudRatePolicy(int idx);
    void checkCustomDevicePathPolicy(int idx);


    void on_searchButton_clicked();

private:
    void fillPortsParameters(void);
    void fillPortsInfo(void);
    void updateSettings(void);

private:
    Ui::SerialPortSetting *m_ui = nullptr;
    Settings m_currentSettings;
    QIntValidator *m_intValidator = nullptr;
};

#endif // SERIALPORTSETTING_H
