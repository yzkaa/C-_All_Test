#include "spectrogramrelationmode.h"

SpectrogramRelationMode::SpectrogramRelationMode(QObject *parent) : RelationMode(parent)
{
    /*
    CREATE TABLE if not exists `spectrogram_data` (
      `id` bigint(20) NOT NULL AUTO_INCREMENT,
      `table_name` varchar(50) NOT NULL COMMENT '数据表名称',
      `gas_type` varchar(50) NOT NULL COMMENT '气体类别',
      `gas_volume` varchar(50) NOT NULL COMMENT '气体体积',
      `remarks` varchar(100) NOT NULL COMMENT '备注信息',
      `data_lenth` int(11) NOT NULL COMMENT '单条数据长度',
      `time` datetime DEFAULT NULL,
      PRIMARY KEY (`id`)
    ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
    */


    setTable(tableName());

    QStringList headNameList;
    headNameList << "数据表名称" << "气体类别" << "气体体积" << "备注信息" << "单条数据长度" <<"曲线条数" << "时间" ;
    initHeadName(headNameList);

    select();

    //去除ID列
    removeColumn(0);
}

void SpectrogramRelationMode::updateShow()
{
    select();
}

QString SpectrogramRelationMode::tableName()
{
    return "spectrogram_data";
}
