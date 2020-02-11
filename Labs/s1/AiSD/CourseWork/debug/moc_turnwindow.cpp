/****************************************************************************
** Meta object code from reading C++ file 'turnwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../turnwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'turnwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_turnWindow_t {
    QByteArrayData data[7];
    char stringdata0[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_turnWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_turnWindow_t qt_meta_stringdata_turnWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "turnWindow"
QT_MOC_LITERAL(1, 11, 11), // "turn_signal"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "set_90"
QT_MOC_LITERAL(4, 31, 7), // "set_180"
QT_MOC_LITERAL(5, 39, 7), // "set_270"
QT_MOC_LITERAL(6, 47, 7) // "do_turn"

    },
    "turnWindow\0turn_signal\0\0set_90\0set_180\0"
    "set_270\0do_turn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_turnWindow[] = {

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
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   42,    2, 0x08 /* Private */,
       4,    0,   43,    2, 0x08 /* Private */,
       5,    0,   44,    2, 0x08 /* Private */,
       6,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void turnWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<turnWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->turn_signal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->set_90(); break;
        case 2: _t->set_180(); break;
        case 3: _t->set_270(); break;
        case 4: _t->do_turn(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (turnWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&turnWindow::turn_signal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject turnWindow::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_turnWindow.data,
    qt_meta_data_turnWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *turnWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *turnWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_turnWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int turnWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void turnWindow::turn_signal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
