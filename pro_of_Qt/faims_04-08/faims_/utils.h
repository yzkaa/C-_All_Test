#ifndef UTILS_H
#define UTILS_H

#include <QMessageBox>
#include <QVector>
#include <QPointF>
#include <QList>
#include <QSettings>
#include <QFileInfo>
#include <QDir>
#include <QDate>

#include "systemsettings.h"
#include "DataBase/dbdatas.h"
#include "params.h"
class Utils
{
public:
    Utils();
    static void Filter(QList<QPointF> &pointList);

    static void tipMessageBox(QString Info);

    static void peakParameterCalculation(QList<QPointF> &currentData, double &FWHM, double &Area);

    static void systemSettingsInit();

    static QString getSettingFilePath();

    //配置文件读写
    static void readSettings(Params *data);
    static void writeSettings(Params *data);

};

#endif // UTILS_H
