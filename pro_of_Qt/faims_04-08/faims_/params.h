#ifndef PARAMS_H
#define PARAMS_H

#include <QString>
#include <QVariant>

enum UDPPARAMSID
{
    UDPPARAMSID_CURRENTIP,
    UDPPARAMSID_TARGETIP,
    UDPPARAMSID_CURRENTPORT,
    UDPPARAMSID_TARGETPORT
};

enum DBSETTINGSID
{
    DBSETTINGSID_DBTYPE,
    DBSETTINGSID_HOSTNAME,
    DBSETTINGSID_DBNAME,
    DBSETTINGSID_PORT,
    DBSETTINGSID_USERNAME,
    DBSETTINGSID_PASSWORD
};

enum DBINSERTPARAMSID
{
    DBINSERTPARAMSID_GASTYPE,
    DBINSERTPARAMSID_GASVOLUME,
    DBINSERTPARAMSID_STARTRF,
    DBINSERTPARAMSID_REMARKS
};

struct Params
{
    QString groupName;
    QStringList nameList;
    QList<QVariant> valueList;

    bool isSucess;
};

struct UdpParams : public Params
{
    UdpParams()
    {
        groupName = "UDP";

        nameList.append("currentIp");
        nameList.append("targetIp");
        nameList.append("sendport");
        nameList.append("receivePort");

        valueList.append("192.168.0.104");
        valueList.append("192.168.0.101");
        valueList.append("6000");
        valueList.append("6000");
    }
};

struct DBParams : public Params
{
    DBParams()
    {
        groupName = "Database";

        nameList.append("dbType");
        nameList.append("hostName");
        nameList.append("dbName");
        nameList.append("port");
        nameList.append("userName");
        nameList.append("passWord");

        valueList.append("QMYSQL");
        valueList.append("42.192.124.206");
        valueList.append("FAIMS");
        valueList.append("3306");
        valueList.append("FAIMSuser");
        valueList.append("123456");
    }
};

struct DBInsertParams : public Params
{
    DBInsertParams()
    {
        groupName = "DataBaseInsert";

        nameList.append("gasType");
        nameList.append("gasVolume");
        nameList.append("startRF");
        nameList.append("remarks");

        valueList.append("default");
        valueList.append("default");
        valueList.append("100");
        valueList.append("default");
    }
};
#endif // PARAMS_H
