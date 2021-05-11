#include "relationmode.h"

RelationMode::RelationMode(QObject *parent) : QSqlRelationalTableModel(parent)
{

}

void RelationMode::initHeadName(QStringList nameList)
{
    int lenth = nameList.size();
    for (int i = 0; i < lenth; i++)
    {
        setHeaderData(i, Qt::Horizontal, nameList.at(i));
    }
}
