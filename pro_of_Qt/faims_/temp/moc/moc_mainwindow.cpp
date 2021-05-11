/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[71];
    char stringdata0[1025];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "connectIsOK"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "about"
QT_MOC_LITERAL(4, 30, 14), // "openSerialPort"
QT_MOC_LITERAL(5, 45, 15), // "closeSerialPort"
QT_MOC_LITERAL(6, 61, 9), // "writeData"
QT_MOC_LITERAL(7, 71, 4), // "data"
QT_MOC_LITERAL(8, 76, 8), // "readData"
QT_MOC_LITERAL(9, 85, 11), // "handleError"
QT_MOC_LITERAL(10, 97, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(11, 126, 5), // "error"
QT_MOC_LITERAL(12, 132, 12), // "updateSvalue"
QT_MOC_LITERAL(13, 145, 18), // "autoOpenSerialPort"
QT_MOC_LITERAL(14, 164, 22), // "on_clearButton_clicked"
QT_MOC_LITERAL(15, 187, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(16, 210, 24), // "on_recoverButton_clicked"
QT_MOC_LITERAL(17, 235, 12), // "opendatafile"
QT_MOC_LITERAL(18, 248, 20), // "opendatafileSelected"
QT_MOC_LITERAL(19, 269, 9), // "savedatas"
QT_MOC_LITERAL(20, 279, 21), // "savedatasfileSelected"
QT_MOC_LITERAL(21, 301, 12), // "savewaveform"
QT_MOC_LITERAL(22, 314, 24), // "savewaveformfileSelected"
QT_MOC_LITERAL(23, 339, 14), // "closeConfigure"
QT_MOC_LITERAL(24, 354, 27), // "on_showsystemButton_clicked"
QT_MOC_LITERAL(25, 382, 26), // "on_setsystemButton_clicked"
QT_MOC_LITERAL(26, 409, 14), // "zeroerrorvalue"
QT_MOC_LITERAL(27, 424, 14), // "zerodriftvalue"
QT_MOC_LITERAL(28, 439, 6), // "svalue"
QT_MOC_LITERAL(29, 446, 6), // "cvalue"
QT_MOC_LITERAL(30, 453, 6), // "tvalue"
QT_MOC_LITERAL(31, 460, 25), // "on_actionFilter_triggered"
QT_MOC_LITERAL(32, 486, 32), // "on_actionCancel_Filter_triggered"
QT_MOC_LITERAL(33, 519, 8), // "estimate"
QT_MOC_LITERAL(34, 528, 4), // "flag"
QT_MOC_LITERAL(35, 533, 12), // "removeSeries"
QT_MOC_LITERAL(36, 546, 19), // "handleMarkerClicked"
QT_MOC_LITERAL(37, 566, 14), // "connectMarkers"
QT_MOC_LITERAL(38, 581, 17), // "disconnectMarkers"
QT_MOC_LITERAL(39, 599, 11), // "pointHoverd"
QT_MOC_LITERAL(40, 611, 5), // "point"
QT_MOC_LITERAL(41, 617, 5), // "state"
QT_MOC_LITERAL(42, 623, 12), // "setPenFormat"
QT_MOC_LITERAL(43, 636, 7), // "newLine"
QT_MOC_LITERAL(44, 644, 16), // "contextMenuEvent"
QT_MOC_LITERAL(45, 661, 18), // "QContextMenuEvent*"
QT_MOC_LITERAL(46, 680, 15), // "mousePressEvent"
QT_MOC_LITERAL(47, 696, 12), // "QMouseEvent*"
QT_MOC_LITERAL(48, 709, 5), // "event"
QT_MOC_LITERAL(49, 715, 16), // "showextremeValue"
QT_MOC_LITERAL(50, 732, 13), // "pointClickedO"
QT_MOC_LITERAL(51, 746, 13), // "pointClickedF"
QT_MOC_LITERAL(52, 760, 14), // "maxPointHoverd"
QT_MOC_LITERAL(53, 775, 6), // "upload"
QT_MOC_LITERAL(54, 782, 12), // "initDatabase"
QT_MOC_LITERAL(55, 795, 14), // "toggleAttached"
QT_MOC_LITERAL(56, 810, 10), // "Set_Legend"
QT_MOC_LITERAL(57, 821, 18), // "setLegendAlignment"
QT_MOC_LITERAL(58, 840, 10), // "toggleBold"
QT_MOC_LITERAL(59, 851, 12), // "toggleItalic"
QT_MOC_LITERAL(60, 864, 15), // "fontSizeChanged"
QT_MOC_LITERAL(61, 880, 18), // "updateLegendLayout"
QT_MOC_LITERAL(62, 899, 13), // "chart_Theme_0"
QT_MOC_LITERAL(63, 913, 13), // "chart_Theme_1"
QT_MOC_LITERAL(64, 927, 13), // "chart_Theme_2"
QT_MOC_LITERAL(65, 941, 13), // "chart_Theme_3"
QT_MOC_LITERAL(66, 955, 13), // "chart_Theme_4"
QT_MOC_LITERAL(67, 969, 13), // "chart_Theme_5"
QT_MOC_LITERAL(68, 983, 13), // "chart_Theme_6"
QT_MOC_LITERAL(69, 997, 13), // "chart_Theme_7"
QT_MOC_LITERAL(70, 1011, 13) // "chart_Theme_8"

    },
    "MainWindow\0connectIsOK\0\0about\0"
    "openSerialPort\0closeSerialPort\0writeData\0"
    "data\0readData\0handleError\0"
    "QSerialPort::SerialPortError\0error\0"
    "updateSvalue\0autoOpenSerialPort\0"
    "on_clearButton_clicked\0on_startButton_clicked\0"
    "on_recoverButton_clicked\0opendatafile\0"
    "opendatafileSelected\0savedatas\0"
    "savedatasfileSelected\0savewaveform\0"
    "savewaveformfileSelected\0closeConfigure\0"
    "on_showsystemButton_clicked\0"
    "on_setsystemButton_clicked\0zeroerrorvalue\0"
    "zerodriftvalue\0svalue\0cvalue\0tvalue\0"
    "on_actionFilter_triggered\0"
    "on_actionCancel_Filter_triggered\0"
    "estimate\0flag\0removeSeries\0"
    "handleMarkerClicked\0connectMarkers\0"
    "disconnectMarkers\0pointHoverd\0point\0"
    "state\0setPenFormat\0newLine\0contextMenuEvent\0"
    "QContextMenuEvent*\0mousePressEvent\0"
    "QMouseEvent*\0event\0showextremeValue\0"
    "pointClickedO\0pointClickedF\0maxPointHoverd\0"
    "upload\0initDatabase\0toggleAttached\0"
    "Set_Legend\0setLegendAlignment\0toggleBold\0"
    "toggleItalic\0fontSizeChanged\0"
    "updateLegendLayout\0chart_Theme_0\0"
    "chart_Theme_1\0chart_Theme_2\0chart_Theme_3\0"
    "chart_Theme_4\0chart_Theme_5\0chart_Theme_6\0"
    "chart_Theme_7\0chart_Theme_8"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      60,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  314,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  315,    2, 0x08 /* Private */,
       4,    0,  316,    2, 0x08 /* Private */,
       5,    0,  317,    2, 0x08 /* Private */,
       6,    1,  318,    2, 0x08 /* Private */,
       8,    0,  321,    2, 0x08 /* Private */,
       9,    1,  322,    2, 0x08 /* Private */,
      12,    0,  325,    2, 0x08 /* Private */,
      13,    0,  326,    2, 0x08 /* Private */,
      14,    0,  327,    2, 0x08 /* Private */,
      15,    0,  328,    2, 0x08 /* Private */,
      16,    0,  329,    2, 0x08 /* Private */,
      17,    0,  330,    2, 0x08 /* Private */,
      18,    0,  331,    2, 0x08 /* Private */,
      19,    0,  332,    2, 0x08 /* Private */,
      20,    0,  333,    2, 0x08 /* Private */,
      21,    0,  334,    2, 0x08 /* Private */,
      22,    0,  335,    2, 0x08 /* Private */,
      23,    0,  336,    2, 0x08 /* Private */,
      24,    0,  337,    2, 0x08 /* Private */,
      25,    0,  338,    2, 0x08 /* Private */,
      26,    0,  339,    2, 0x08 /* Private */,
      27,    0,  340,    2, 0x08 /* Private */,
      28,    0,  341,    2, 0x08 /* Private */,
      29,    0,  342,    2, 0x08 /* Private */,
      30,    0,  343,    2, 0x08 /* Private */,
      31,    0,  344,    2, 0x08 /* Private */,
      32,    0,  345,    2, 0x08 /* Private */,
      33,    1,  346,    2, 0x08 /* Private */,
      35,    0,  349,    2, 0x08 /* Private */,
      36,    0,  350,    2, 0x08 /* Private */,
      37,    0,  351,    2, 0x08 /* Private */,
      38,    0,  352,    2, 0x08 /* Private */,
      39,    2,  353,    2, 0x08 /* Private */,
      42,    0,  358,    2, 0x08 /* Private */,
      43,    0,  359,    2, 0x08 /* Private */,
      44,    1,  360,    2, 0x08 /* Private */,
      46,    1,  363,    2, 0x08 /* Private */,
      49,    0,  366,    2, 0x08 /* Private */,
      50,    1,  367,    2, 0x08 /* Private */,
      51,    1,  370,    2, 0x08 /* Private */,
      52,    2,  373,    2, 0x08 /* Private */,
      53,    0,  378,    2, 0x08 /* Private */,
      54,    0,  379,    2, 0x08 /* Private */,
      55,    0,  380,    2, 0x08 /* Private */,
      56,    0,  381,    2, 0x08 /* Private */,
      57,    0,  382,    2, 0x08 /* Private */,
      58,    0,  383,    2, 0x08 /* Private */,
      59,    0,  384,    2, 0x08 /* Private */,
      60,    0,  385,    2, 0x08 /* Private */,
      61,    0,  386,    2, 0x08 /* Private */,
      62,    0,  387,    2, 0x08 /* Private */,
      63,    0,  388,    2, 0x08 /* Private */,
      64,    0,  389,    2, 0x08 /* Private */,
      65,    0,  390,    2, 0x08 /* Private */,
      66,    0,  391,    2, 0x08 /* Private */,
      67,    0,  392,    2, 0x08 /* Private */,
      68,    0,  393,    2, 0x08 /* Private */,
      69,    0,  394,    2, 0x08 /* Private */,
      70,    0,  395,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPointF, QMetaType::Bool,   40,   41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 45,    2,
    QMetaType::Void, 0x80000000 | 47,   48,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPointF,   40,
    QMetaType::Void, QMetaType::QPointF,   40,
    QMetaType::Void, QMetaType::QPointF, QMetaType::Bool,   40,   41,
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

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectIsOK(); break;
        case 1: _t->about(); break;
        case 2: _t->openSerialPort(); break;
        case 3: _t->closeSerialPort(); break;
        case 4: _t->writeData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 5: _t->readData(); break;
        case 6: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 7: _t->updateSvalue(); break;
        case 8: _t->autoOpenSerialPort(); break;
        case 9: _t->on_clearButton_clicked(); break;
        case 10: _t->on_startButton_clicked(); break;
        case 11: _t->on_recoverButton_clicked(); break;
        case 12: _t->opendatafile(); break;
        case 13: _t->opendatafileSelected(); break;
        case 14: _t->savedatas(); break;
        case 15: _t->savedatasfileSelected(); break;
        case 16: _t->savewaveform(); break;
        case 17: _t->savewaveformfileSelected(); break;
        case 18: _t->closeConfigure(); break;
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
        case 29: _t->removeSeries(); break;
        case 30: _t->handleMarkerClicked(); break;
        case 31: _t->connectMarkers(); break;
        case 32: _t->disconnectMarkers(); break;
        case 33: _t->pointHoverd((*reinterpret_cast< const QPointF(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 34: _t->setPenFormat(); break;
        case 35: _t->newLine(); break;
        case 36: _t->contextMenuEvent((*reinterpret_cast< QContextMenuEvent*(*)>(_a[1]))); break;
        case 37: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 38: _t->showextremeValue(); break;
        case 39: _t->pointClickedO((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 40: _t->pointClickedF((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 41: _t->maxPointHoverd((*reinterpret_cast< const QPointF(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 42: _t->upload(); break;
        case 43: _t->initDatabase(); break;
        case 44: _t->toggleAttached(); break;
        case 45: _t->Set_Legend(); break;
        case 46: _t->setLegendAlignment(); break;
        case 47: _t->toggleBold(); break;
        case 48: _t->toggleItalic(); break;
        case 49: _t->fontSizeChanged(); break;
        case 50: _t->updateLegendLayout(); break;
        case 51: _t->chart_Theme_0(); break;
        case 52: _t->chart_Theme_1(); break;
        case 53: _t->chart_Theme_2(); break;
        case 54: _t->chart_Theme_3(); break;
        case 55: _t->chart_Theme_4(); break;
        case 56: _t->chart_Theme_5(); break;
        case 57: _t->chart_Theme_6(); break;
        case 58: _t->chart_Theme_7(); break;
        case 59: _t->chart_Theme_8(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::connectIsOK)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


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
        if (_id < 60)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 60;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 60)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 60;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::connectIsOK()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
