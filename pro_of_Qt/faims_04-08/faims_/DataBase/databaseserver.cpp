#include "databaseserver.h"
#include <QDebug>
#include <QApplication>
DatabaseServer::DatabaseServer(QObject *parent) : QObject(parent)
{

    dbThread = new DatabaseThread(this);

    readSettingsAndConnect();

    connect(this, &DatabaseServer::insertToDatabase, dbThread, &DatabaseThread::getInputData);
    connect(dbThread, &DatabaseThread::inputSucess, this, &DatabaseServer::inputSucess);

    connect(this, &DatabaseServer::databaseConnectState, this, &DatabaseServer::databaseConnectResult);

    connect(this, &DatabaseServer::dbInsertSettingsUpdata, dbThread, &DatabaseThread::readDBInsertParams);
}

DatabaseServer::~DatabaseServer()
{
    dataBase.close();
}

void DatabaseServer::readSettingsAndConnect()
{
    //多次重连先关闭
    dataBase.close();

    //读取配置文件
    DBParams data;
    Utils::readSettings(&data);

    QString dbType;
    QString hostName;
    int port;
    QString dbName;
    QString userName;
    QString passWord;

    if (data.isSucess)
    {
        dbType = data.valueList.at(DBSETTINGSID_DBTYPE).toString();
        hostName = data.valueList.at(DBSETTINGSID_HOSTNAME).toString();
        port = data.valueList.at(DBSETTINGSID_PORT).toInt();
        dbName = data.valueList.at(DBSETTINGSID_DBNAME).toString();
        userName = data.valueList.at(DBSETTINGSID_USERNAME).toString();
        passWord = data.valueList.at(DBSETTINGSID_PASSWORD).toString();
    }
    else
    {
        dbType = "QMYSQL";
        hostName = "42.192.124.206";
        dbName = "FAIMS";
        userName = "FAIMSuser";
        passWord = "123456";
    }

    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName(QApplication::applicationDirPath()+"/FAIMS.dat");    //如果本目录下没有该文件,则会在本目录下生成,
//    dataBase = QSqlDatabase::addDatabase(dbType);
//    dataBase.setHostName(hostName);
//    dataBase.setDatabaseName(dbName);
    dataBase.setPort(port);
    dataBase.setUserName(userName);
    dataBase.setPassword(passWord);

    dataBase.setConnectOptions("MYSQL_OPT_CONNECT_TIMEOUT=1");  //设置连接超时时间

    //连接很慢，不启用线程会卡住主界面
//    QtConcurrent::run([=](){
//        bool state = dataBase.open();
//        emit databaseConnectState(state);
//    });

    bool state = dataBase.open();

    qDebug()<< "state = "<<state;
    QTimer::singleShot(1, this, [=](){
        emit databaseConnectState(state);
    });
}

void DatabaseServer::databaseConnectResult(bool state)
{
    if (state)
    {
        Utils::tipMessageBox("database connect is sucess");
        initAdministrationTable_sqlLite();
    }
    else
    {
        QSqlError error = dataBase.lastError();
        Utils::tipMessageBox(QString("database connect error : %1").arg(error.text()));
    }
}

void DatabaseServer::initAdministrationTable_sqlLite()
{
    QString sql = "CREATE TABLE if not exists `spectrogram_data` ("
                  "`id` INTEGER NOT NULL ,"
                  "`table_name` varchar(50) NOT NULL,"
                  "`gas_type` varchar(50) NOT NULL,"
                  "`gas_volume` varchar(50) NOT NULL,"
                  " `remarks` varchar(100) NOT NULL ,"
                  "`data_lenth` int(11) NOT NULL ,"
                  "`curves_number` int NOT NULL,"
                  "`time` datetime DEFAULT NULL,"
                  "PRIMARY KEY (`id`))";

    QSqlQuery query;

    bool isSuccess = query.exec(sql);
    QString status = isSuccess == true?"成功":"失败";
    QSqlError error = query.lastError();
    Utils::tipMessageBox(QString("管理表初始化%1:%2").arg(status).arg(error.text()));
}
