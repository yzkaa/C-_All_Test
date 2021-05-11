#include "networkserver.h"

NetworkServer::NetworkServer(QObject *parent) : QObject(parent)
{
    receiveSocket = new QUdpSocket(this);
    udpThread = new UdpThread(this);

    connect(this, &NetworkServer::getCalculationData, udpThread, &UdpThread::getCalculationData);
    connect(receiveSocket, &QUdpSocket::readyRead, this, &NetworkServer::receiveResults);
    readSettingsAndBind();
}

void NetworkServer::readSettingsAndBind()
{
    UdpParams params;
    Utils::readSettings(&params);

    if (!params.isSucess)
    {
        Utils::tipMessageBox("配置文件读取错误，请检查");
        return;
    }

    currentIp = params.valueList.at(UDPPARAMSID_CURRENTIP).toString();
    targetIp = params.valueList.at(UDPPARAMSID_TARGETIP).toString();
    currentPort = params.valueList.at(UDPPARAMSID_CURRENTPORT).toInt();
    targetPort = params.valueList.at(UDPPARAMSID_TARGETPORT).toInt();

    if(!receiveSocket->bind(QHostAddress(currentIp), currentPort))
    {
        QString errorInfo = receiveSocket->errorString();
        Utils::tipMessageBox(QString("UDP绑定错误：%1").arg(errorInfo));
        isBind = false;
        return;
    }

    qDebug()<<"端口绑定成功";
    //发报线程获取目标参数
    udpThread->getNetwordParams(targetIp, targetPort);
    isBind = true;
}

void NetworkServer::receiveResults()
{
    QHostAddress add;
    quint16 port;
    QByteArray temp;
    temp.resize(receiveSocket->pendingDatagramSize());
    receiveSocket->readDatagram(temp.data(), temp.size(), &add, &port);
    qDebug()<<QString("接收到报文，IP = %1, port = %2").arg(add.toString()).arg(port);

    qDebug()<<"峰参数计算完成";
}
