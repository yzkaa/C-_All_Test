#ifndef SPECTROGRAMRELATIONMODE_H
#define SPECTROGRAMRELATIONMODE_H

#include <QObject>
#include "relationmode.h"
class SpectrogramRelationMode : public RelationMode
{
    Q_OBJECT
public:
    explicit SpectrogramRelationMode(QObject *parent = nullptr);

    void updateShow();
signals:

public slots:
    QString tableName();
};

#endif // SPECTROGRAMRELATIONMODE_H
