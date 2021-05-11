#include "databasethread.h"
#include <QDebug>
DatabaseThread::DatabaseThread(QObject *parent) : QThread(parent)
{
    //读取入库参数
    readDBInsertParams();
}

bool DatabaseThread::createDataTable()
{
    //表名
    QDateTime time = QDateTime::currentDateTime();
    currentDataTableName = "DataTable" + time.toString("yyyyMMddhhmmss");

    //创建表
//    DBDataTableFiled filed;
//    QString initTable = newTable + noExistent + currentDataTableName + brackets.arg(filed.id + intType + primaryKey + comma+
//                                                                         filed.current + doubleType + noIsNUll + comma+
//                                                                         filed.voltage + doubleType + noIsNUll);

    QString createSql = "CREATE TABLE IF NOT EXISTS `" + currentDataTableName +
                    "` (`id` INTEGER,"
                    "`current`  double(7,3)  NOT NULL,"
                    "`voltage`  double(7,3)  NOT NULL,"
                    "PRIMARY KEY ( `id` ));";
    QSqlQuery query;
    bool isSucess = query.exec(createSql);

    if (!isSucess)
    {
        QSqlError error = query.lastError();

        Utils::tipMessageBox(QString("数据表创建错误：%1").arg(error.text()));
    }

    return isSucess;
}

void DatabaseThread::getInputData(DBValues data)
{
    qDebug()<<"有数据录入";
    cacheData.append(data.pointfList);

    //数据表创建并保存数据
    if (createDataTable())
    {
        //管理表插入一条记录
        insertToSpectrogramTable(data);
    }

}

bool DatabaseThread::insertToSpectrogramTable(DBValues data)
{
    QSqlQuery query;

//    SpectrogramTable filed;
//    QString prepareSql = "insert into %1(%2) values(%3)";
//    query.prepare(prepareSql.arg(filed.filed_tableName)
//                  .arg(filed.filed_dataTableName + comma +
//                       filed.filed_gasType + comma +
//                       filed.filed_gasVolume + comma +
//                       filed.filed_reMarks + comma +
//                       filed.filed_time)
//                  .arg(colon + filed.filed_dataTableName + comma +
//                       colon + filed.filed_gasType + comma +
//                       colon + filed.filed_gasVolume + comma +
//                       colon + filed.filed_reMarks + comma +
//                       colon + filed.filed_time));

    QDateTime time = QDateTime::currentDateTime();
    query.prepare("insert into spectrogram_data (table_name, gas_type, gas_volume, remarks, data_lenth, curves_number, time)"
                  "values (:table_name, :gas_type, :gas_volume, :remarks, :data_lenth, :curves_number, :time)");
    query.bindValue(":table_name", currentDataTableName);
    query.bindValue(":gas_type", data.gasType);
    query.bindValue(":gas_volume", data.gasVolume);
    query.bindValue(":remarks", data.reMarks);
    query.bindValue(":data_lenth", data.dataLength);
    query.bindValue(":curves_number", data.curvesNum);
    query.bindValue(":time", time);

    bool isSucess = query.exec();

    if (!isSucess)
    {
        QSqlError error = query.lastError();
        Utils::tipMessageBox(QString("管理表插入错误:%1").arg(error.text()));
    }
    else
    {
        //启动线程录入数据
        this->start();
    }
}

bool DatabaseThread::insertToDataTable(double x, double y)
{
    DBDataTableFiled filed;
    QSqlQuery query;
    QString sql = inSert + currentDataTableName + brackets.arg(filed.current + comma + filed.voltage)
            + "value" + brackets.arg(colon + filed.current + comma + colon + filed.voltage);

    query.prepare(sql);
    query.bindValue(colon + filed.current, y);
    query.bindValue(colon + filed.voltage, x);

    if (!query.exec())
    {
        QSqlError error = query.lastError();
        qDebug()<<"数据表插入错误" << error.text();
        Utils::tipMessageBox(QString("数据表插入错误%1").arg(error.text()));
        return false;
    }

    return true;
}

bool DatabaseThread::insertToDataTable(QVariantList &xList, QVariantList &yList)
{
    DBDataTableFiled filed;
    QString sql = inSert + currentDataTableName + brackets.arg(filed.current + comma + filed.voltage)
            + " values " + brackets.arg(colon + filed.current + comma + colon + filed.voltage);

    //开启事务
    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(colon + filed.current, yList);
    query.bindValue(colon + filed.voltage, xList);

    if (!query.execBatch())
    {
        QSqlError error = query.lastError();
        qDebug()<<"数据表插入错误" << error.text();
        Utils::tipMessageBox(QString("数据表插入错误%1").arg(error.text()));
        return false;
    }

    return true;
}

void DatabaseThread::readDBInsertParams()
{
    Utils::readSettings(&insertParams);
}

void DatabaseThread::run()
{
    while(!cacheData.isEmpty())
    {
//        mutex.lock();
//        QList<QPointF> data = cacheData.first();
//        cacheData.removeFirst();
//        mutex.unlock();

        mutex.lock();
        QVector<QList<QPointF>> data;
        data.swap(cacheData);
        mutex.unlock();


        QVariantList xList;
        QVariantList yList;
        QList<QPointF>::const_iterator it;
        QSqlDatabase::database().transaction();
//        for (int i = 0; i < data.size(); i++)
//        {
//            for (int i2 = 0; i2 < data.at(i).size(); i2++)
//            {
//                xList << data.at(i).at(i2).x();
//                yList << data.at(i).at(i2).y();
//                if (i2 % 100 == 0)
//                {
//                    if (!insertToDataTable(xList, yList))
//                    {
//                        return;
//                    }
//                    xList.clear();
//                    yList.clear();
//                }
//            }
//            if (!xList.isEmpty() && !yList.isEmpty())
//            {
//                if (!insertToDataTable(xList, yList))
//                {
//                    return;
//                }
//                xList.clear();
//                yList.clear();
//            }
//        }

        for (int i = 0; i < data.size(); i++)
        {
            it = data.at(i).begin();
            for (;it != data.at(i).end(); it++)
            {
                xList << (*it).x();
                yList << (*it).y();
            }
        }

        if (!insertToDataTable(xList, yList))
        {
            return;
        }
        else
        {
            qDebug()<<"数据入库成功";
        }
        QSqlDatabase::database().commit();
    }

    emit inputSucess();
}
