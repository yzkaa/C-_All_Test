#ifndef DBDATAS_H
#define DBDATAS_H

#include <QString>
#include <QVariant>
#include <QPointF>

struct DBValues
{
    //insertData
    QString gasType;
    QString gasVolume;
    QString reMarks;
    int dataLength;
    int curvesNum;
    QVector<QList<QPointF>> pointfList;

    //QSettings
    QString groupName;
    QStringList nameList;
    QList<QVariant> valueList;
    bool remember = true;
    bool isSucess;

};

struct DBDataTableFiled
{
    QString id = "id";
    QString current = "current";
    QString voltage = "voltage";
};

struct SpectrogramTable
{
    QString filed_tableName = "spectrogram_data";

    QString filed_dataTableName = "table_name";
    QString filed_gasType = "gas_typr";
    QString filed_gasVolume = "gas_volume";
    QString filed_reMarks = "remarks";
    QString filed_dataLength = "data_lenth";
    QString filed_curvesNum = "curves_number";
    QString filed_time = "time";

    int value_dataLenth;
    QString value_dataTableName;
    bool isSucess;
};

#endif // DBDATAS_H
