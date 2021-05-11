/****************************************************************************
** Meta object code from reading C++ file 'databasedialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../pro_of_Qt/faims_04-08/faims_/DataBase/databasedialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'databasedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataBaseDialog_t {
    QByteArrayData data[17];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataBaseDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataBaseDialog_t qt_meta_stringdata_DataBaseDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DataBaseDialog"
QT_MOC_LITERAL(1, 15, 13), // "connectSucess"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "connectFail"
QT_MOC_LITERAL(4, 42, 9), // "errorInfo"
QT_MOC_LITERAL(5, 52, 13), // "isReadyToDraw"
QT_MOC_LITERAL(6, 66, 25), // "QVector<QList<QPointF> >&"
QT_MOC_LITERAL(7, 92, 4), // "data"
QT_MOC_LITERAL(8, 97, 10), // "updateShow"
QT_MOC_LITERAL(9, 108, 14), // "initTreeWidget"
QT_MOC_LITERAL(10, 123, 25), // "on_pushButton_out_clicked"
QT_MOC_LITERAL(11, 149, 11), // "initBtnMenu"
QT_MOC_LITERAL(12, 161, 21), // "actionClearAllTrigger"
QT_MOC_LITERAL(13, 183, 24), // "actionClearSelectTrigger"
QT_MOC_LITERAL(14, 208, 31), // "getCurrentSelectSpectrogramInfo"
QT_MOC_LITERAL(15, 240, 17), // "SpectrogramTable&"
QT_MOC_LITERAL(16, 258, 23) // "spectrogramSearchFilter"

    },
    "DataBaseDialog\0connectSucess\0\0connectFail\0"
    "errorInfo\0isReadyToDraw\0"
    "QVector<QList<QPointF> >&\0data\0"
    "updateShow\0initTreeWidget\0"
    "on_pushButton_out_clicked\0initBtnMenu\0"
    "actionClearAllTrigger\0actionClearSelectTrigger\0"
    "getCurrentSelectSpectrogramInfo\0"
    "SpectrogramTable&\0spectrogramSearchFilter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataBaseDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    1,   70,    2, 0x06 /* Public */,
       5,    1,   73,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   76,    2, 0x0a /* Public */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    0,   80,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,
      14,    1,   82,    2, 0x08 /* Private */,
      16,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,    7,
    QMetaType::Void,

       0        // eod
};

void DataBaseDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataBaseDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectSucess(); break;
        case 1: _t->connectFail((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->isReadyToDraw((*reinterpret_cast< QVector<QList<QPointF> >(*)>(_a[1]))); break;
        case 3: _t->updateShow(); break;
        case 4: _t->initTreeWidget(); break;
        case 5: _t->on_pushButton_out_clicked(); break;
        case 6: _t->initBtnMenu(); break;
        case 7: _t->actionClearAllTrigger(); break;
        case 8: _t->actionClearSelectTrigger(); break;
        case 9: _t->getCurrentSelectSpectrogramInfo((*reinterpret_cast< SpectrogramTable(*)>(_a[1]))); break;
        case 10: _t->spectrogramSearchFilter(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataBaseDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataBaseDialog::connectSucess)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DataBaseDialog::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataBaseDialog::connectFail)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DataBaseDialog::*)(QVector<QList<QPointF>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataBaseDialog::isReadyToDraw)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DataBaseDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DataBaseDialog.data,
    qt_meta_data_DataBaseDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataBaseDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataBaseDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataBaseDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DataBaseDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void DataBaseDialog::connectSucess()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DataBaseDialog::connectFail(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataBaseDialog::isReadyToDraw(QVector<QList<QPointF>> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
