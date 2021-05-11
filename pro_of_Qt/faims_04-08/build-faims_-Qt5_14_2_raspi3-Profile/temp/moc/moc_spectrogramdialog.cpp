/****************************************************************************
** Meta object code from reading C++ file 'spectrogramdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../faims_/spectrogramdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spectrogramdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SpectrogramDialog_t {
    QByteArrayData data[26];
    char stringdata0[428];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SpectrogramDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SpectrogramDialog_t qt_meta_stringdata_SpectrogramDialog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "SpectrogramDialog"
QT_MOC_LITERAL(1, 18, 15), // "DrawSpectrogram"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 16), // "QVector<double>&"
QT_MOC_LITERAL(4, 52, 15), // "SpectrogramData"
QT_MOC_LITERAL(5, 68, 18), // "ControlStateChange"
QT_MOC_LITERAL(6, 87, 5), // "State"
QT_MOC_LITERAL(7, 93, 17), // "toDrawSpectrogram"
QT_MOC_LITERAL(8, 111, 23), // "getSpectrogramParameter"
QT_MOC_LITERAL(9, 135, 25), // "QVector<QList<QPointF> >&"
QT_MOC_LITERAL(10, 161, 4), // "data"
QT_MOC_LITERAL(11, 166, 4), // "yMin"
QT_MOC_LITERAL(12, 171, 4), // "yMax"
QT_MOC_LITERAL(13, 176, 4), // "xMin"
QT_MOC_LITERAL(14, 181, 4), // "xMax"
QT_MOC_LITERAL(15, 186, 30), // "on_pushButton_OpenFile_clicked"
QT_MOC_LITERAL(16, 217, 24), // "on_BackgroundColorChange"
QT_MOC_LITERAL(17, 242, 21), // "on_ControlStateChange"
QT_MOC_LITERAL(18, 264, 5), // "event"
QT_MOC_LITERAL(19, 270, 7), // "QEvent*"
QT_MOC_LITERAL(20, 278, 11), // "showEnhance"
QT_MOC_LITERAL(21, 290, 14), // "Pre_processing"
QT_MOC_LITERAL(22, 305, 28), // "on_pushButton_Remove_clicked"
QT_MOC_LITERAL(23, 334, 26), // "on_pushButton_Back_clicked"
QT_MOC_LITERAL(24, 361, 28), // "on_pushButton_Change_clicked"
QT_MOC_LITERAL(25, 390, 37) // "on_pushButton_SaveSpectrogram..."

    },
    "SpectrogramDialog\0DrawSpectrogram\0\0"
    "QVector<double>&\0SpectrogramData\0"
    "ControlStateChange\0State\0toDrawSpectrogram\0"
    "getSpectrogramParameter\0"
    "QVector<QList<QPointF> >&\0data\0yMin\0"
    "yMax\0xMin\0xMax\0on_pushButton_OpenFile_clicked\0"
    "on_BackgroundColorChange\0on_ControlStateChange\0"
    "event\0QEvent*\0showEnhance\0Pre_processing\0"
    "on_pushButton_Remove_clicked\0"
    "on_pushButton_Back_clicked\0"
    "on_pushButton_Change_clicked\0"
    "on_pushButton_SaveSpectrogram_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpectrogramDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       5,    1,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   90,    2, 0x0a /* Public */,
       8,    5,   93,    2, 0x0a /* Public */,
      15,    0,  104,    2, 0x08 /* Private */,
      16,    0,  105,    2, 0x08 /* Private */,
      17,    1,  106,    2, 0x08 /* Private */,
      18,    1,  109,    2, 0x08 /* Private */,
      20,    0,  112,    2, 0x08 /* Private */,
      21,    0,  113,    2, 0x08 /* Private */,
      22,    0,  114,    2, 0x08 /* Private */,
      23,    0,  115,    2, 0x08 /* Private */,
      24,    0,  116,    2, 0x08 /* Private */,
      25,    0,  117,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,   10,   11,   12,   13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Bool, 0x80000000 | 19,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SpectrogramDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SpectrogramDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DrawSpectrogram((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 1: _t->ControlStateChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->toDrawSpectrogram((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 3: _t->getSpectrogramParameter((*reinterpret_cast< QVector<QList<QPointF> >(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5]))); break;
        case 4: _t->on_pushButton_OpenFile_clicked(); break;
        case 5: _t->on_BackgroundColorChange(); break;
        case 6: _t->on_ControlStateChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: { bool _r = _t->event((*reinterpret_cast< QEvent*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->showEnhance(); break;
        case 9: _t->Pre_processing(); break;
        case 10: _t->on_pushButton_Remove_clicked(); break;
        case 11: _t->on_pushButton_Back_clicked(); break;
        case 12: _t->on_pushButton_Change_clicked(); break;
        case 13: _t->on_pushButton_SaveSpectrogram_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SpectrogramDialog::*)(QVector<double> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpectrogramDialog::DrawSpectrogram)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SpectrogramDialog::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpectrogramDialog::ControlStateChange)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SpectrogramDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_SpectrogramDialog.data,
    qt_meta_data_SpectrogramDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SpectrogramDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpectrogramDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SpectrogramDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SpectrogramDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void SpectrogramDialog::DrawSpectrogram(QVector<double> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SpectrogramDialog::ControlStateChange(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
