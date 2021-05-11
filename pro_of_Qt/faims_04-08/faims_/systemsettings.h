#ifndef SYSTEMSETTINGS_H
#define SYSTEMSETTINGS_H

#include <QString>
struct setting_Database
{
    QString groupName = "DB";
    QString filed_DBType = "Type";
    QString filed_DBHostName = "hostName";
    QString filed_DBName = "DBname";
    QString filed_userName = "userName";
    QString filed_passWord = "passWord";

    QString value_DBType = "QMYSQL";
    QString value_DBHostName = "42.192.124.206";
    QString value_DBName = "FAIMS";
    QString value_userName = "FAIMSuser";
    QString value_passWord = "123456";
};
#endif // SYSTEMSETTINGS_H
