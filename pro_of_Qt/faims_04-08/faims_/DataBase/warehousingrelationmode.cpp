#include "warehousingrelationmode.h"

WarehousingRelationMode::WarehousingRelationMode(QObject *parent) : RelationMode(parent)
{
    /*
    CREATE TABLE if not exists `warehousing_log` (
      `id` bigint(20) NOT NULL AUTO_INCREMENT,
      `data_type` varchar(40) NOT NULL COMMENT '数据类型',
      `remarks` varchar(50) NOT NULL COMMENT '备注信息',
      `time` datetime DEFAULT NULL,
      PRIMARY KEY (`id`)
    ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
    */

    setTable(tableName());

    QStringList headNameList;
    headNameList << "数据类型" << "备注信息" << "入库时间" ;
    initHeadName(headNameList);
}

QString WarehousingRelationMode::tableName()
{
    return "warehousing_log";
}
