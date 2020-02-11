/****************************************************************************
** Meta object code from reading C++ file 'listviewactionlogger.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "listviewactionlogger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'listviewactionlogger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ListViewActionLogger_t {
    QByteArrayData data[12];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ListViewActionLogger_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ListViewActionLogger_t qt_meta_stringdata_ListViewActionLogger = {
    {
QT_MOC_LITERAL(0, 0, 20), // "ListViewActionLogger"
QT_MOC_LITERAL(1, 21, 8), // "reselect"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 9), // "logAction"
QT_MOC_LITERAL(4, 41, 11), // "std::string"
QT_MOC_LITERAL(5, 53, 3), // "str"
QT_MOC_LITERAL(6, 57, 13), // "AVL::AVL<int>"
QT_MOC_LITERAL(7, 71, 4), // "tree"
QT_MOC_LITERAL(8, 76, 7), // "logText"
QT_MOC_LITERAL(9, 84, 14), // "currentChanged"
QT_MOC_LITERAL(10, 99, 11), // "QModelIndex"
QT_MOC_LITERAL(11, 111, 5) // "clear"

    },
    "ListViewActionLogger\0reselect\0\0logAction\0"
    "std::string\0str\0AVL::AVL<int>\0tree\0"
    "logText\0currentChanged\0QModelIndex\0"
    "clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ListViewActionLogger[] = {

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
       3,    2,   42,    2, 0x0a /* Public */,
       8,    1,   47,    2, 0x0a /* Public */,
       9,    2,   50,    2, 0x0a /* Public */,
      11,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 10,    2,    2,
    QMetaType::Void,

       0        // eod
};

void ListViewActionLogger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ListViewActionLogger *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->reselect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->logAction((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< AVL::AVL<int>(*)>(_a[2]))); break;
        case 2: _t->logText((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 3: _t->currentChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 4: _t->clear(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ListViewActionLogger::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ListViewActionLogger::reselect)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ListViewActionLogger::staticMetaObject = { {
    &QListView::staticMetaObject,
    qt_meta_stringdata_ListViewActionLogger.data,
    qt_meta_data_ListViewActionLogger,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ListViewActionLogger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ListViewActionLogger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ListViewActionLogger.stringdata0))
        return static_cast<void*>(this);
    return QListView::qt_metacast(_clname);
}

int ListViewActionLogger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListView::qt_metacall(_c, _id, _a);
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
void ListViewActionLogger::reselect(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
