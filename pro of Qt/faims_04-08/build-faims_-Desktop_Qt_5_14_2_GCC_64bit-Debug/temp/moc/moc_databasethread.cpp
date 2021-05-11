/****************************************************************************
** Meta object code from reading C++ file 'databasethread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../pro_of_Qt/faims_04-08/faims_/DataBase/databasethread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'databasethread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DatabaseThread_t {
    QByteArrayData data[16];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DatabaseThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DatabaseThread_t qt_meta_stringdata_DatabaseThread = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DatabaseThread"
QT_MOC_LITERAL(1, 15, 11), // "inputSucess"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "createDataTable"
QT_MOC_LITERAL(4, 44, 12), // "getInputData"
QT_MOC_LITERAL(5, 57, 8), // "DBValues"
QT_MOC_LITERAL(6, 66, 4), // "data"
QT_MOC_LITERAL(7, 71, 24), // "insertToSpectrogramTable"
QT_MOC_LITERAL(8, 96, 17), // "insertToDataTable"
QT_MOC_LITERAL(9, 114, 1), // "x"
QT_MOC_LITERAL(10, 116, 1), // "y"
QT_MOC_LITERAL(11, 118, 13), // "QVariantList&"
QT_MOC_LITERAL(12, 132, 5), // "xList"
QT_MOC_LITERAL(13, 138, 5), // "yList"
QT_MOC_LITERAL(14, 144, 18), // "readDBInsertParams"
QT_MOC_LITERAL(15, 163, 10) // "insertType"

    },
    "DatabaseThread\0inputSucess\0\0createDataTable\0"
    "getInputData\0DBValues\0data\0"
    "insertToSpectrogramTable\0insertToDataTable\0"
    "x\0y\0QVariantList&\0xList\0yList\0"
    "readDBInsertParams\0insertType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DatabaseThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       1,   68, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x0a /* Public */,
       4,    1,   51,    2, 0x0a /* Public */,
       7,    1,   54,    2, 0x0a /* Public */,
       8,    2,   57,    2, 0x0a /* Public */,
       8,    2,   62,    2, 0x0a /* Public */,
      14,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Bool, 0x80000000 | 5,    6,
    QMetaType::Bool, QMetaType::Double, QMetaType::Double,    9,   10,
    QMetaType::Bool, 0x80000000 | 11, 0x80000000 | 11,   12,   13,
    QMetaType::Void,

 // enums: name, alias, flags, count, data
      15,   15, 0x0,    0,   73,

 // enum data: key, value

       0        // eod
};

void DatabaseThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DatabaseThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->inputSucess(); break;
        case 1: { bool _r = _t->createDataTable();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->getInputData((*reinterpret_cast< DBValues(*)>(_a[1]))); break;
        case 3: { bool _r = _t->insertToSpectrogramTable((*reinterpret_cast< DBValues(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->insertToDataTable((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->insertToDataTable((*reinterpret_cast< QVariantList(*)>(_a[1])),(*reinterpret_cast< QVariantList(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->readDBInsertParams(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DatabaseThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DatabaseThread::inputSucess)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DatabaseThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_DatabaseThread.data,
    qt_meta_data_DatabaseThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DatabaseThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DatabaseThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DatabaseThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int DatabaseThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void DatabaseThread::inputSucess()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
