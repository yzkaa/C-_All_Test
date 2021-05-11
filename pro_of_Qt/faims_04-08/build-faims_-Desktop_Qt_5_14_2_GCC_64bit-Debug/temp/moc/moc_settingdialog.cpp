/****************************************************************************
** Meta object code from reading C++ file 'settingdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../faims_/settingdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SettingDialog_t {
    QByteArrayData data[8];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingDialog_t qt_meta_stringdata_SettingDialog = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SettingDialog"
QT_MOC_LITERAL(1, 14, 12), // "showPortInfo"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 3), // "idx"
QT_MOC_LITERAL(4, 32, 5), // "apply"
QT_MOC_LITERAL(5, 38, 25), // "checkCustomBaudRatePolicy"
QT_MOC_LITERAL(6, 64, 27), // "checkCustomDevicePathPolicy"
QT_MOC_LITERAL(7, 92, 23) // "on_searchButton_clicked"

    },
    "SettingDialog\0showPortInfo\0\0idx\0apply\0"
    "checkCustomBaudRatePolicy\0"
    "checkCustomDevicePathPolicy\0"
    "on_searchButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    0,   42,    2, 0x08 /* Private */,
       5,    1,   43,    2, 0x08 /* Private */,
       6,    1,   46,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void SettingDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SettingDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showPortInfo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->apply(); break;
        case 2: _t->checkCustomBaudRatePolicy((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->checkCustomDevicePathPolicy((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_searchButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SettingDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_SettingDialog.data,
    qt_meta_data_SettingDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SettingDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SettingDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SettingDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
