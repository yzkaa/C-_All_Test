#ifndef DATABASETHREAD_H
#define DATABASETHREAD_H

#include <QObject>
#include <QThread>
#include <QSqlQuery>
#include <QSqlError>
#include <QVector>
#include <QMutex>

#include "utils.h"
class DatabaseThread : public QThread
{
    Q_OBJECT
public:
    explicit DatabaseThread(QObject *parent = nullptr);

    enum insertType
    {

    };
    Q_ENUMS(insertType)
signals:
    void inputSucess();
public slots:
    bool createDataTable();

    void  getInputData(DBValues data);

    bool insertToSpectrogramTable(DBValues data);

    bool insertToDataTable(double x, double y);

    bool insertToDataTable(QVariantList &xList, QVariantList &yList);

    void readDBInsertParams();
protected:
    void run();

private:  
    QMutex mutex;
    //字段
    QString inSert = "insert into ";
    QString noExistent = " if not exists ";
    QString newDatabase = " create database ";
    QString newTable = " create table ";
    QString setUtf8 = " alter database %1 character set utf8 ";
    QString brackets = " (%1) ";
    QString comma = ",";
    QString colon = ":";

    //表数据类型
    QString charType = " varchar(40) ";
    QString intType = " int ";
    QString doubleType = " double ";

    //约束条件
    QString primaryKey = " primary key auto_increment ";
    QString noIsNUll = " not null ";

    QVector<QList<QPointF>> cacheData;

    QString currentDataTableName;

    DBInsertParams insertParams;
};

#endif // DATABASETHREAD_H
