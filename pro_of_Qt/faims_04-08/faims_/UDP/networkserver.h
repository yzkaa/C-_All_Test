#ifndef NETWORKSERVER_H
#define NETWORKSERVER_H

#include <QObject>
#include <QUdpSocket>

#include "utils.h"
#include "UDP/udpthread.h"
#include "params.h"
class NetworkServer : public QObject
{
    Q_OBJECT
public:
    explicit NetworkServer(QObject *parent = nullptr);

signals:
    void getCalculationData(QList<QPointF> &data);
public slots:
    void readSettingsAndBind();
    void receiveResults();
private:
    QUdpSocket *receiveSocket = nullptr;
    UdpThread *udpThread = nullptr;

    QString currentIp;
    QString targetIp;
    quint16 currentPort;
    quint16 targetPort;

    bool isBind = false;
};

#endif // NETWORKSERVER_H
