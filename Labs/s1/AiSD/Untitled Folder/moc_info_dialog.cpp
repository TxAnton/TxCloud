/****************************************************************************
** Meta object code from reading C++ file 'info_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "info_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'info_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_infoDialog_t {
    QByteArrayData data[8];
    char stringdata0[46];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_infoDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_infoDialog_t qt_meta_stringdata_infoDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "infoDialog"
QT_MOC_LITERAL(1, 11, 8), // "set_info"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "size"
QT_MOC_LITERAL(4, 26, 2), // "bf"
QT_MOC_LITERAL(5, 29, 5), // "width"
QT_MOC_LITERAL(6, 35, 6), // "height"
QT_MOC_LITERAL(7, 42, 3) // "bpp"

    },
    "infoDialog\0set_info\0\0size\0bf\0width\0"
    "height\0bpp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_infoDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    5,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UShort,    3,    4,    5,    6,    7,

       0        // eod
};

void infoDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<infoDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->set_info((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< unsigned short(*)>(_a[5]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject infoDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_infoDialog.data,
    qt_meta_data_infoDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *infoDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *infoDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_infoDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int infoDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
