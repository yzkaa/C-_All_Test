/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../pro_of_Qt/faims_04-08/faims_/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[80];
    char stringdata0[1224];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "inSertToDatabase"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "DBValues"
QT_MOC_LITERAL(4, 38, 4), // "data"
QT_MOC_LITERAL(5, 43, 21), // "peakParamsCalculation"
QT_MOC_LITERAL(6, 65, 15), // "QList<QPointF>&"
QT_MOC_LITERAL(7, 81, 14), // "receiveNewData"
QT_MOC_LITERAL(8, 96, 14), // "QList<QPointF>"
QT_MOC_LITERAL(9, 111, 14), // "openSerialPort"
QT_MOC_LITERAL(10, 126, 15), // "closeSerialPort"
QT_MOC_LITERAL(11, 142, 5), // "about"
QT_MOC_LITERAL(12, 148, 9), // "writeData"
QT_MOC_LITERAL(13, 158, 8), // "readData"
QT_MOC_LITERAL(14, 167, 11), // "handleError"
QT_MOC_LITERAL(15, 179, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(16, 208, 5), // "error"
QT_MOC_LITERAL(17, 214, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(18, 237, 12), // "updateSvalue"
QT_MOC_LITERAL(19, 250, 22), // "on_clearButton_clicked"
QT_MOC_LITERAL(20, 273, 24), // "on_recoverButton_clicked"
QT_MOC_LITERAL(21, 298, 15), // "seriesListClear"
QT_MOC_LITERAL(22, 314, 20), // "opendatafileSelected"
QT_MOC_LITERAL(23, 335, 9), // "savedatas"
QT_MOC_LITERAL(24, 345, 21), // "savedatasfileSelected"
QT_MOC_LITERAL(25, 367, 12), // "savewaveform"
QT_MOC_LITERAL(26, 380, 24), // "savewaveformfileSelected"
QT_MOC_LITERAL(27, 405, 27), // "on_showsystemButton_clicked"
QT_MOC_LITERAL(28, 433, 26), // "on_setsystemButton_clicked"
QT_MOC_LITERAL(29, 460, 14), // "zeroerrorvalue"
QT_MOC_LITERAL(30, 475, 14), // "zerodriftvalue"
QT_MOC_LITERAL(31, 490, 6), // "svalue"
QT_MOC_LITERAL(32, 497, 6), // "cvalue"
QT_MOC_LITERAL(33, 504, 6), // "tvalue"
QT_MOC_LITERAL(34, 511, 25), // "on_actionFilter_triggered"
QT_MOC_LITERAL(35, 537, 32), // "on_actionCancel_Filter_triggered"
QT_MOC_LITERAL(36, 570, 8), // "estimate"
QT_MOC_LITERAL(37, 579, 4), // "flag"
QT_MOC_LITERAL(38, 584, 11), // "pointHoverd"
QT_MOC_LITERAL(39, 596, 5), // "point"
QT_MOC_LITERAL(40, 602, 5), // "state"
QT_MOC_LITERAL(41, 608, 12), // "setPenFormat"
QT_MOC_LITERAL(42, 621, 7), // "newLine"
QT_MOC_LITERAL(43, 629, 11), // "getExtreMum"
QT_MOC_LITERAL(44, 641, 16), // "contextMenuEvent"
QT_MOC_LITERAL(45, 658, 18), // "QContextMenuEvent*"
QT_MOC_LITERAL(46, 677, 15), // "mousePressEvent"
QT_MOC_LITERAL(47, 693, 12), // "QMouseEvent*"
QT_MOC_LITERAL(48, 706, 5), // "event"
QT_MOC_LITERAL(49, 712, 16), // "showextremeValue"
QT_MOC_LITERAL(50, 729, 13), // "pointClickedO"
QT_MOC_LITERAL(51, 743, 13), // "pointClickedF"
QT_MOC_LITERAL(52, 757, 14), // "maxPointHoverd"
QT_MOC_LITERAL(53, 772, 14), // "toggleAttached"
QT_MOC_LITERAL(54, 787, 10), // "Set_Legend"
QT_MOC_LITERAL(55, 798, 18), // "setLegendAlignment"
QT_MOC_LITERAL(56, 817, 10), // "toggleBold"
QT_MOC_LITERAL(57, 828, 12), // "toggleItalic"
QT_MOC_LITERAL(58, 841, 15), // "fontSizeChanged"
QT_MOC_LITERAL(59, 857, 18), // "updateLegendLayout"
QT_MOC_LITERAL(60, 876, 13), // "chart_Theme_0"
QT_MOC_LITERAL(61, 890, 13), // "chart_Theme_1"
QT_MOC_LITERAL(62, 904, 13), // "chart_Theme_2"
QT_MOC_LITERAL(63, 918, 13), // "chart_Theme_3"
QT_MOC_LITERAL(64, 932, 13), // "chart_Theme_4"
QT_MOC_LITERAL(65, 946, 13), // "chart_Theme_5"
QT_MOC_LITERAL(66, 960, 13), // "chart_Theme_6"
QT_MOC_LITERAL(67, 974, 13), // "chart_Theme_7"
QT_MOC_LITERAL(68, 988, 23), // "initFingerprintSpectrum"
QT_MOC_LITERAL(69, 1012, 24), // "currentDataToCloudServer"
QT_MOC_LITERAL(70, 1037, 23), // "peakParametersInforShow"
QT_MOC_LITERAL(71, 1061, 4), // "FWHM"
QT_MOC_LITERAL(72, 1066, 4), // "Area"
QT_MOC_LITERAL(73, 1071, 25), // "multipleCurvesCalculation"
QT_MOC_LITERAL(74, 1097, 21), // "actionDatabaseTrigger"
QT_MOC_LITERAL(75, 1119, 18), // "showInSertDBDialog"
QT_MOC_LITERAL(76, 1138, 26), // "currentDataInputToDatabase"
QT_MOC_LITERAL(77, 1165, 16), // "exportDataToDraw"
QT_MOC_LITERAL(78, 1182, 25), // "QVector<QList<QPointF> >&"
QT_MOC_LITERAL(79, 1208, 15) // "SettingsTrigger"

    },
    "MainWindow\0inSertToDatabase\0\0DBValues\0"
    "data\0peakParamsCalculation\0QList<QPointF>&\0"
    "receiveNewData\0QList<QPointF>\0"
    "openSerialPort\0closeSerialPort\0about\0"
    "writeData\0readData\0handleError\0"
    "QSerialPort::SerialPortError\0error\0"
    "on_startButton_clicked\0updateSvalue\0"
    "on_clearButton_clicked\0on_recoverButton_clicked\0"
    "seriesListClear\0opendatafileSelected\0"
    "savedatas\0savedatasfileSelected\0"
    "savewaveform\0savewaveformfileSelected\0"
    "on_showsystemButton_clicked\0"
    "on_setsystemButton_clicked\0zeroerrorvalue\0"
    "zerodriftvalue\0svalue\0cvalue\0tvalue\0"
    "on_actionFilter_triggered\0"
    "on_actionCancel_Filter_triggered\0"
    "estimate\0flag\0pointHoverd\0point\0state\0"
    "setPenFormat\0newLine\0getExtreMum\0"
    "contextMenuEvent\0QContextMenuEvent*\0"
    "mousePressEvent\0QMouseEvent*\0event\0"
    "showextremeValue\0pointClickedO\0"
    "pointClickedF\0maxPointHoverd\0"
    "toggleAttached\0Set_Legend\0setLegendAlignment\0"
    "toggleBold\0toggleItalic\0fontSizeChanged\0"
    "updateLegendLayout\0chart_Theme_0\0"
    "chart_Theme_1\0chart_Theme_2\0chart_Theme_3\0"
    "chart_Theme_4\0chart_Theme_5\0chart_Theme_6\0"
    "chart_Theme_7\0initFingerprintSpectrum\0"
    "currentDataToCloudServer\0"
    "peakParametersInforShow\0FWHM\0Area\0"
    "multipleCurvesCalculation\0"
    "actionDatabaseTrigger\0showInSertDBDialog\0"
    "currentDataInputToDatabase\0exportDataToDraw\0"
    "QVector<QList<QPointF> >&\0SettingsTrigger"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      63,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  329,    2, 0x06 /* Public */,
       5,    1,  332,    2, 0x06 /* Public */,
       7,    1,  335,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  338,    2, 0x08 /* Private */,
      10,    0,  339,    2, 0x08 /* Private */,
      11,    0,  340,    2, 0x08 /* Private */,
      12,    1,  341,    2, 0x08 /* Private */,
      13,    0,  344,    2, 0x08 /* Private */,
      14,    1,  345,    2, 0x08 /* Private */,
      17,    0,  348,    2, 0x08 /* Private */,
      18,    0,  349,    2, 0x08 /* Private */,
      19,    0,  350,    2, 0x08 /* Private */,
      20,    0,  351,    2, 0x08 /* Private */,
      21,    0,  352,    2, 0x08 /* Private */,
      22,    0,  353,    2, 0x08 /* Private */,
      23,    0,  354,    2, 0x08 /* Private */,
      24,    0,  355,    2, 0x08 /* Private */,
      25,    0,  356,    2, 0x08 /* Private */,
      26,    0,  357,    2, 0x08 /* Private */,
      27,    0,  358,    2, 0x08 /* Private */,
      28,    0,  359,    2, 0x08 /* Private */,
      29,    0,  360,    2, 0x08 /* Private */,
      30,    0,  361,    2, 0x08 /* Private */,
      31,    0,  362,    2, 0x08 /* Private */,
      32,    0,  363,    2, 0x08 /* Private */,
      33,    0,  364,    2, 0x08 /* Private */,
      34,    0,  365,    2, 0x08 /* Private */,
      35,    0,  366,    2, 0x08 /* Private */,
      36,    1,  367,    2, 0x08 /* Private */,
      38,    2,  370,    2, 0x08 /* Private */,
      41,    0,  375,    2, 0x08 /* Private */,
      42,    1,  376,    2, 0x08 /* Private */,
      43,    1,  379,    2, 0x08 /* Private */,
      44,    1,  382,    2, 0x08 /* Private */,
      46,    1,  385,    2, 0x08 /* Private */,
      49,    0,  388,    2, 0x08 /* Private */,
      50,    1,  389,    2, 0x08 /* Private */,
      51,    1,  392,    2, 0x08 /* Private */,
      52,    2,  395,    2, 0x08 /* Private */,
      53,    0,  400,    2, 0x08 /* Private */,
      54,    0,  401,    2, 0x08 /* Private */,
      55,    0,  402,    2, 0x08 /* Private */,
      56,    0,  403,    2, 0x08 /* Private */,
      57,    0,  404,    2, 0x08 /* Private */,
      58,    0,  405,    2, 0x08 /* Private */,
      59,    0,  406,    2, 0x08 /* Private */,
      60,    0,  407,    2, 0x08 /* Private */,
      61,    0,  408,    2, 0x08 /* Private */,
      62,    0,  409,    2, 0x08 /* Private */,
      63,    0,  410,    2, 0x08 /* Private */,
      64,    0,  411,    2, 0x08 /* Private */,
      65,    0,  412,    2, 0x08 /* Private */,
      66,    0,  413,    2, 0x08 /* Private */,
      67,    0,  414,    2, 0x08 /* Private */,
      68,    0,  415,    2, 0x08 /* Private */,
      69,    0,  416,    2, 0x08 /* Private */,
      70,    2,  417,    2, 0x08 /* Private */,
      73,    0,  422,    2, 0x08 /* Private */,
      74,    0,  423,    2, 0x08 /* Private */,
      75,    0,  424,    2, 0x08 /* Private */,
      76,    1,  425,    2, 0x08 /* Private */,
      77,    1,  428,    2, 0x08 /* Private */,
      79,    0,  431,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void, 0x80000000 | 8,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   37,
    QMetaType::Void, QMetaType::QPointF, QMetaType::Bool,   39,   40,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    4,
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void, 0x80000000 | 45,    2,
    QMetaType::Void, 0x80000000 | 47,   48,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPointF,   39,
    QMetaType::Void, QMetaType::QPointF,   39,
    QMetaType::Void, QMetaType::QPointF, QMetaType::Bool,   39,   40,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   71,   72,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 78,    4,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->inSertToDatabase((*reinterpret_cast< DBValues(*)>(_a[1]))); break;
        case 1: _t->peakParamsCalculation((*reinterpret_cast< QList<QPointF>(*)>(_a[1]))); break;
        case 2: _t->receiveNewData((*reinterpret_cast< const QList<QPointF>(*)>(_a[1]))); break;
        case 3: _t->openSerialPort(); break;
        case 4: _t->closeSerialPort(); break;
        case 5: _t->about(); break;
        case 6: _t->writeData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 7: _t->readData(); break;
        case 8: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 9: _t->on_startButton_clicked(); break;
        case 10: _t->updateSvalue(); break;
        case 11: _t->on_clearButton_clicked(); break;
        case 12: _t->on_recoverButton_clicked(); break;
        case 13: _t->seriesListClear(); break;
        case 14: _t->opendatafileSelected(); break;
        case 15: _t->savedatas(); break;
        case 16: _t->savedatasfileSelected(); break;
        case 17: _t->savewaveform(); break;
        case 18: _t->savewaveformfileSelected(); break;
        case 19: _t->on_showsystemButton_clicked(); break;
        case 20: _t->on_setsystemButton_clicked(); break;
        case 21: _t->zeroerrorvalue(); break;
        case 22: _t->zerodriftvalue(); break;
        case 23: _t->svalue(); break;
        case 24: _t->cvalue(); break;
        case 25: _t->tvalue(); break;
        case 26: _t->on_actionFilter_triggered(); break;
        case 27: _t->on_actionCancel_Filter_triggered(); break;
        case 28: _t->estimate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->pointHoverd((*reinterpret_cast< const QPointF(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 30: _t->setPenFormat(); break;
        case 31: _t->newLine((*reinterpret_cast< const QList<QPointF>(*)>(_a[1]))); break;
        case 32: _t->getExtreMum((*reinterpret_cast< QList<QPointF>(*)>(_a[1]))); break;
        case 33: _t->contextMenuEvent((*reinterpret_cast< QContextMenuEvent*(*)>(_a[1]))); break;
        case 34: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 35: _t->showextremeValue(); break;
        case 36: _t->pointClickedO((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 37: _t->pointClickedF((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 38: _t->maxPointHoverd((*reinterpret_cast< const QPointF(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 39: _t->toggleAttached(); break;
        case 40: _t->Set_Legend(); break;
        case 41: _t->setLegendAlignment(); break;
        case 42: _t->toggleBold(); break;
        case 43: _t->toggleItalic(); break;
        case 44: _t->fontSizeChanged(); break;
        case 45: _t->updateLegendLayout(); break;
        case 46: _t->chart_Theme_0(); break;
        case 47: _t->chart_Theme_1(); break;
        case 48: _t->chart_Theme_2(); break;
        case 49: _t->chart_Theme_3(); break;
        case 50: _t->chart_Theme_4(); break;
        case 51: _t->chart_Theme_5(); break;
        case 52: _t->chart_Theme_6(); break;
        case 53: _t->chart_Theme_7(); break;
        case 54: _t->initFingerprintSpectrum(); break;
        case 55: _t->currentDataToCloudServer(); break;
        case 56: _t->peakParametersInforShow((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 57: _t->multipleCurvesCalculation(); break;
        case 58: _t->actionDatabaseTrigger(); break;
        case 59: _t->showInSertDBDialog(); break;
        case 60: _t->currentDataInputToDatabase((*reinterpret_cast< DBValues(*)>(_a[1]))); break;
        case 61: _t->exportDataToDraw((*reinterpret_cast< QVector<QList<QPointF> >(*)>(_a[1]))); break;
        case 62: _t->SettingsTrigger(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QPointF> >(); break;
            }
            break;
        case 31:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QPointF> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(DBValues );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::inSertToDatabase)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QList<QPointF> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::peakParamsCalculation)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QList<QPointF> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::receiveNewData)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 63)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 63;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 63)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 63;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::inSertToDatabase(DBValues _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::peakParamsCalculation(QList<QPointF> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::receiveNewData(const QList<QPointF> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
