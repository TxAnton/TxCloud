/****************************************************************************
** Meta object code from reading C++ file 'rgb_component.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../rgb_component.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rgb_component.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RGB_component_t {
    QByteArrayData data[7];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RGB_component_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RGB_component_t qt_meta_stringdata_RGB_component = {
    {
QT_MOC_LITERAL(0, 0, 13), // "RGB_component"
QT_MOC_LITERAL(1, 14, 20), // "change_rgb_component"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 16), // "do_rgb_component"
QT_MOC_LITERAL(4, 53, 11), // "red_toggled"
QT_MOC_LITERAL(5, 65, 13), // "green_toggled"
QT_MOC_LITERAL(6, 79, 12) // "blue_toggled"

    },
    "RGB_component\0change_rgb_component\0\0"
    "do_rgb_component\0red_toggled\0green_toggled\0"
    "blue_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RGB_component[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   44,    2, 0x0a /* Public */,
       4,    0,   45,    2, 0x0a /* Public */,
       5,    0,   46,    2, 0x0a /* Public */,
       6,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RGB_component::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RGB_component *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->change_rgb_component((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->do_rgb_component(); break;
        case 2: _t->red_toggled(); break;
        case 3: _t->green_toggled(); break;
        case 4: _t->blue_toggled(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RGB_component::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RGB_component::change_rgb_component)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RGB_component::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_RGB_component.data,
    qt_meta_data_RGB_component,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RGB_component::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RGB_component::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RGB_component.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int RGB_component::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void RGB_component::change_rgb_component(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
