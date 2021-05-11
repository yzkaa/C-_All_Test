/****************************************************************************
** Meta object code from reading C++ file 'relationmode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../faims_/DataBase/relationmode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'relationmode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RelationMode_t {
    QByteArrayData data[5];
    char stringdata0[46];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RelationMode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RelationMode_t qt_meta_stringdata_RelationMode = {
    {
QT_MOC_LITERAL(0, 0, 12), // "RelationMode"
QT_MOC_LITERAL(1, 13, 9), // "tableName"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "initHeadName"
QT_MOC_LITERAL(4, 37, 8) // "nameList"

    },
    "RelationMode\0tableName\0\0initHeadName\0"
    "nameList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RelationMode[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    1,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::QString,
    QMetaType::Void, QMetaType::QStringList,    4,

       0        // eod
};

void RelationMode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RelationMode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->tableName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->initHeadName((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RelationMode::staticMetaObject = { {
    QMetaObject::SuperData::link<QSqlRelationalTableModel::staticMetaObject>(),
    qt_meta_stringdata_RelationMode.data,
    qt_meta_data_RelationMode,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RelationMode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RelationMode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RelationMode.stringdata0))
        return static_cast<void*>(this);
    return QSqlRelationalTableModel::qt_metacast(_clname);
}

int RelationMode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSqlRelationalTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
