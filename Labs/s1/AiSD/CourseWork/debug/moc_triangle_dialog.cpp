/****************************************************************************
** Meta object code from reading C++ file 'triangle_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../triangle_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'triangle_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_triangleDialog_t {
    QByteArrayData data[7];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_triangleDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_triangleDialog_t qt_meta_stringdata_triangleDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "triangleDialog"
QT_MOC_LITERAL(1, 15, 12), // "sig_turn_tri"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 7), // "QColor*"
QT_MOC_LITERAL(4, 37, 14), // "set_line_color"
QT_MOC_LITERAL(5, 52, 14), // "set_fill_color"
QT_MOC_LITERAL(6, 67, 14) // "sl_triangle_ok"

    },
    "triangleDialog\0sig_turn_tri\0\0QColor*\0"
    "set_line_color\0set_fill_color\0"
    "sl_triangle_ok"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_triangleDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   43,    2, 0x0a /* Public */,
       5,    0,   44,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 3, 0x80000000 | 3, QMetaType::Int,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void triangleDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<triangleDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_turn_tri((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QColor*(*)>(_a[2])),(*reinterpret_cast< QColor*(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->set_line_color(); break;
        case 2: _t->set_fill_color(); break;
        case 3: _t->sl_triangle_ok(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (triangleDialog::*)(bool , QColor * , QColor * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&triangleDialog::sig_turn_tri)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject triangleDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_triangleDialog.data,
    qt_meta_data_triangleDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *triangleDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *triangleDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_triangleDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int triangleDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void triangleDialog::sig_turn_tri(bool _t1, QColor * _t2, QColor * _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
