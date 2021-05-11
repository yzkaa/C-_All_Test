#ifndef FINGERPRINTRELATIONMODE_H
#define FINGERPRINTRELATIONMODE_H

#include <QObject>

#include "relationmode.h"
class FingerprintRelationMode : public RelationMode
{
    Q_OBJECT
public:
    explicit FingerprintRelationMode(QObject *parent = nullptr);

signals:

public slots:
    QString tableName();
};

#endif // FINGERPRINTRELATIONMODE_H
