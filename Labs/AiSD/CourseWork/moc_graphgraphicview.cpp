/****************************************************************************
** Meta object code from reading C++ file 'graphgraphicview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "graphgraphicview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphgraphicview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GraphGraphicView_t {
    QByteArrayData data[15];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphGraphicView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphGraphicView_t qt_meta_stringdata_GraphGraphicView = {
    {
QT_MOC_LITERAL(0, 0, 16), // "GraphGraphicView"
QT_MOC_LITERAL(1, 17, 11), // "slotDrawAvl"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "_slotDrawAvl"
QT_MOC_LITERAL(4, 43, 13), // "AVL::AVL<int>"
QT_MOC_LITERAL(5, 57, 3), // "avl"
QT_MOC_LITERAL(6, 61, 3), // "lvl"
QT_MOC_LITERAL(7, 65, 6), // "xCoord"
QT_MOC_LITERAL(8, 72, 14), // "slotAlarmTimer"
QT_MOC_LITERAL(9, 87, 11), // "resizeEvent"
QT_MOC_LITERAL(10, 99, 13), // "QResizeEvent*"
QT_MOC_LITERAL(11, 113, 5), // "event"
QT_MOC_LITERAL(12, 119, 20), // "deleteItemsFromGroup"
QT_MOC_LITERAL(13, 140, 19), // "QGraphicsItemGroup*"
QT_MOC_LITERAL(14, 160, 7) // "group_1"

    },
    "GraphGraphicView\0slotDrawAvl\0\0"
    "_slotDrawAvl\0AVL::AVL<int>\0avl\0lvl\0"
    "xCoord\0slotAlarmTimer\0resizeEvent\0"
    "QResizeEvent*\0event\0deleteItemsFromGroup\0"
    "QGraphicsItemGroup*\0group_1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphGraphicView[] = {

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
       1,    0,   39,    2, 0x08 /* Private */,
       3,    3,   40,    2, 0x08 /* Private */,
       8,    0,   47,    2, 0x08 /* Private */,
       9,    1,   48,    2, 0x08 /* Private */,
      12,    1,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int, QMetaType::Float,    5,    6,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void GraphGraphicView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GraphGraphicView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotDrawAvl(); break;
        case 1: _t->_slotDrawAvl((*reinterpret_cast< AVL::AVL<int>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 2: _t->slotAlarmTimer(); break;
        case 3: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 4: _t->deleteItemsFromGroup((*reinterpret_cast< QGraphicsItemGroup*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GraphGraphicView::staticMetaObject = { {
    &QGraphicsView::staticMetaObject,
    qt_meta_stringdata_GraphGraphicView.data,
    qt_meta_data_GraphGraphicView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GraphGraphicView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphGraphicView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GraphGraphicView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int GraphGraphicView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
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
