#ifndef UDPTHREAD_H
#define UDPTHREAD_H

#include <QObject>
#include <QThread>
#include <QUdpSocket>
#include <QPointF>
#include <QHostAddress>

class UdpThread : public QThread
{
    Q_OBJECT
public:
    explicit UdpThread(QObject *parent = nullptr);
    enum OPERATION
    {
        FILTER,           //滤波
        PEAKCALCULATION   //峰参数计算
    };

    enum STOP_BIT
    {
        END,
        ONGOING
    };
signals:

public slots:
    void getCalculationData(QList<QPointF> &data);
    void getNetwordParams(QString targetIp, qint16 port);
private:
    void run();
    QByteArray doubleToByteArray(double xory);

    QString targetIp;
    qint16 port;
    QUdpSocket *sendSocket = nullptr;
    QList<QPointF> cacheData;

    int operation = 1;
};

#endif // UDPTHREAD_H
