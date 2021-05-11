#include "udpthread.h"

UdpThread::UdpThread(QObject *parent) : QThread(parent)
{
    sendSocket = new QUdpSocket(this);
}

void UdpThread::getNetwordParams(QString targetIp, qint16 port)
{
    this->targetIp = targetIp;
    this->port = port;

    qDebug()<<"targetIp = "<<targetIp;
    qDebug()<<"port = "<<port;
}

void UdpThread::getCalculationData(QList<QPointF> &data)
{
    //获取数据启动线程
    cacheData.append(data);
    if (!isRunning())
    {
        start();
    }
}

void UdpThread::run()
{
    QList<QPointF> tempData;
    tempData.swap(cacheData);

    QByteArray sendDataGram;
    QList<QPointF>::const_iterator i;
    int count = 1;
    for (i = tempData.begin(); i != tempData.end(); i++)
    {
        QByteArray x = doubleToByteArray((*i).x());
        QByteArray y = doubleToByteArray((*i).y());
        sendDataGram.append(x);
        sendDataGram.append(y);
        if (sendDataGram.size() >= 20*8) //一包20个点，一个点长度8 字节
        {
            //添加报头2字节，第一字节为操作码，第二字节为停止位
            sendDataGram.push_front(char(ONGOING));
            sendDataGram.push_front(char(operation));
            sendSocket->writeDatagram(sendDataGram, QHostAddress(targetIp), port);

            qDebug()<< "发包数:" << count++;
            sendDataGram.clear();
        }
    }

    //不足20个的尾部信息,补足长度
    if (!sendDataGram.isEmpty())
    {
        sendDataGram.push_front(char(ONGOING));
        sendDataGram.push_front(char(operation));
        sendSocket->writeDatagram(sendDataGram, QHostAddress(targetIp), port);
    }

    //发送结束信息,延时1ms
    msleep(1);
    sendDataGram.append(char(END));
    sendDataGram.push_front(char(operation));
    sendSocket->writeDatagram(sendDataGram, QHostAddress(targetIp), port);
    qDebug()<<"报文发送结束";
}

QByteArray UdpThread::doubleToByteArray(double xory)
{
    // 先转int ,后转4个字节
    int temp = int (xory * 1000); //保留3位小数
    QByteArray byte;
    byte.resize(4);

    byte[0] = (uchar)(0x000000ff & temp);
    byte[1] = (uchar)((0x0000ff00&temp)>>8);
    byte[2] = (uchar)((0x00ff0000&temp)>>16);
    byte[3] = (uchar)((0xff000000&temp)>>24);
    return byte;
}
