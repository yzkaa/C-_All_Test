#ifndef RELATIONMODE_H
#define RELATIONMODE_H

#include <QObject>
#include <QSqlRelationalTableModel>
class RelationMode : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    explicit RelationMode(QObject *parent = nullptr);

signals:

public slots:
    virtual QString tableName() = 0;

    void initHeadName(QStringList nameList);
};

#endif // RELATIONMODE_H
