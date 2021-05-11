#ifndef DATABASESERVER_H
#define DATABASESERVER_H

#include <QObject>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlError>
#include <QtConcurrent>
#include <QTimer>

#include "utils.h"
#include "DataBase/databasethread.h"
#include "params.h"
class DatabaseServer : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseServer(QObject *parent = nullptr);
    ~DatabaseServer();

signals:
    void insertToDatabase(DBValues data);
    void inputSucess();
    void databaseConnectState(bool state);
    void dbInsertSettingsUpdata();
public slots:
    void readSettingsAndConnect();
    void databaseConnectResult(bool state);

    void initAdministrationTable_sqlLite();
private:
    QString gasType;
    QString gasVolume;
    QString remakes;

    QString FingerprintDataTableName = "FingerprintData";
    QString SpectrogramDataTableName = "SpectrogramData";

    //数据库
    QSqlDatabase dataBase;

    DatabaseThread *dbThread = nullptr;
};

#endif // DATABASESERVER_H
