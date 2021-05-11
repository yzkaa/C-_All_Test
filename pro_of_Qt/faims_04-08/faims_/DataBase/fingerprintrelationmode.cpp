#include "fingerprintrelationmode.h"

FingerprintRelationMode::FingerprintRelationMode(QObject *parent) : RelationMode(parent)
{
    /*
    CREATE TABLE if not exists `fingerprint_spectrum` (
      `id` bigint(20) NOT NULL AUTO_INCREMENT,
      `table_name` varchar(40) NOT NULL COMMENT '数据表名称',
      `remarks` varchar(50) NOT NULL COMMENT '备注信息',
      `time` datetime DEFAULT NULL,
      PRIMARY KEY (`id`)
    ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
    */
    setTable(tableName());

    QStringList headNameList;
    headNameList << "数据表名称" << "备注信息" << "时间" ;
    initHeadName(headNameList);
}

QString FingerprintRelationMode::tableName()
{
    return "fingerprint_spectrum";
}
