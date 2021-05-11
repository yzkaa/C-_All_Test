#ifndef WAREHOUSINGRELATIONMODE_H
#define WAREHOUSINGRELATIONMODE_H

#include <QObject>
#include "relationmode.h"
class WarehousingRelationMode : public RelationMode
{
    Q_OBJECT
public:
    explicit WarehousingRelationMode(QObject *parent = nullptr);

signals:

public slots:
    QString tableName();
};

#endif // WAREHOUSINGRELATIONMODE_H
