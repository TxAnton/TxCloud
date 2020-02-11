/****************************************************************************
** Meta object code from reading C++ file 'drawgraphicsview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "drawgraphicsview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drawgraphicsview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DrawGraphicsView_t {
    QByteArrayData data[32];
    char stringdata0[353];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawGraphicsView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawGraphicsView_t qt_meta_stringdata_DrawGraphicsView = {
    {
QT_MOC_LITERAL(0, 0, 16), // "DrawGraphicsView"
QT_MOC_LITERAL(1, 17, 17), // "sig_draw_triangle"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 7), // "QPoint*"
QT_MOC_LITERAL(4, 44, 8), // "uint32_t"
QT_MOC_LITERAL(5, 53, 13), // "sig_draw_line"
QT_MOC_LITERAL(6, 67, 15), // "sig_draw_invert"
QT_MOC_LITERAL(7, 83, 10), // "sig_rotate"
QT_MOC_LITERAL(8, 94, 7), // "sig_cut"
QT_MOC_LITERAL(9, 102, 11), // "updateImage"
QT_MOC_LITERAL(10, 114, 6), // "pixmap"
QT_MOC_LITERAL(11, 121, 7), // "sl_turn"
QT_MOC_LITERAL(12, 129, 4), // "Mode"
QT_MOC_LITERAL(13, 134, 4), // "mode"
QT_MOC_LITERAL(14, 139, 11), // "sl_turn_tri"
QT_MOC_LITERAL(15, 151, 6), // "isFill"
QT_MOC_LITERAL(16, 158, 7), // "QColor*"
QT_MOC_LITERAL(17, 166, 10), // "line_color"
QT_MOC_LITERAL(18, 177, 10), // "fill_color"
QT_MOC_LITERAL(19, 188, 10), // "line_width"
QT_MOC_LITERAL(20, 199, 11), // "sl_turn_inv"
QT_MOC_LITERAL(21, 211, 11), // "sl_turn_cut"
QT_MOC_LITERAL(22, 223, 11), // "sl_turn_lin"
QT_MOC_LITERAL(23, 235, 11), // "sl_turn_rot"
QT_MOC_LITERAL(24, 247, 15), // "mousePressEvent"
QT_MOC_LITERAL(25, 263, 12), // "QMouseEvent*"
QT_MOC_LITERAL(26, 276, 5), // "event"
QT_MOC_LITERAL(27, 282, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(28, 297, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(29, 315, 10), // "clearGroup"
QT_MOC_LITERAL(30, 326, 19), // "QGraphicsItemGroup*"
QT_MOC_LITERAL(31, 346, 6) // "group_"

    },
    "DrawGraphicsView\0sig_draw_triangle\0\0"
    "QPoint*\0uint32_t\0sig_draw_line\0"
    "sig_draw_invert\0sig_rotate\0sig_cut\0"
    "updateImage\0pixmap\0sl_turn\0Mode\0mode\0"
    "sl_turn_tri\0isFill\0QColor*\0line_color\0"
    "fill_color\0line_width\0sl_turn_inv\0"
    "sl_turn_cut\0sl_turn_lin\0sl_turn_rot\0"
    "mousePressEvent\0QMouseEvent*\0event\0"
    "mouseMoveEvent\0mouseReleaseEvent\0"
    "clearGroup\0QGraphicsItemGroup*\0group_"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawGraphicsView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    7,   94,    2, 0x06 /* Public */,
       5,    4,  109,    2, 0x06 /* Public */,
       6,    2,  118,    2, 0x06 /* Public */,
       7,    3,  123,    2, 0x06 /* Public */,
       8,    2,  130,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,  135,    2, 0x0a /* Public */,
      11,    1,  138,    2, 0x0a /* Public */,
      14,    4,  141,    2, 0x0a /* Public */,
      20,    0,  150,    2, 0x0a /* Public */,
      21,    0,  151,    2, 0x0a /* Public */,
      22,    2,  152,    2, 0x0a /* Public */,
      23,    1,  157,    2, 0x0a /* Public */,
      24,    1,  160,    2, 0x08 /* Private */,
      27,    1,  163,    2, 0x08 /* Private */,
      28,    1,  166,    2, 0x08 /* Private */,
      29,    1,  169,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 4, QMetaType::Bool, QMetaType::QColor, QMetaType::QColor,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, QMetaType::Double, QMetaType::QColor,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    2,    2,

 // slots: parameters
    QMetaType::Int, QMetaType::QPixmap,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 16, 0x80000000 | 16, QMetaType::Int,   15,   17,   18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 16,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, 0x80000000 | 30,   31,

       0        // eod
};

void DrawGraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DrawGraphicsView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_draw_triangle((*reinterpret_cast< QPoint*(*)>(_a[1])),(*reinterpret_cast< QPoint*(*)>(_a[2])),(*reinterpret_cast< QPoint*(*)>(_a[3])),(*reinterpret_cast< uint32_t(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< QColor(*)>(_a[6])),(*reinterpret_cast< QColor(*)>(_a[7]))); break;
        case 1: _t->sig_draw_line((*reinterpret_cast< QPoint*(*)>(_a[1])),(*reinterpret_cast< QPoint*(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< QColor(*)>(_a[4]))); break;
        case 2: _t->sig_draw_invert((*reinterpret_cast< QPoint*(*)>(_a[1])),(*reinterpret_cast< uint32_t(*)>(_a[2]))); break;
        case 3: _t->sig_rotate((*reinterpret_cast< QPoint*(*)>(_a[1])),(*reinterpret_cast< QPoint*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->sig_cut((*reinterpret_cast< QPoint*(*)>(_a[1])),(*reinterpret_cast< QPoint*(*)>(_a[2]))); break;
        case 5: { int _r = _t->updateImage((*reinterpret_cast< QPixmap(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->sl_turn((*reinterpret_cast< Mode(*)>(_a[1]))); break;
        case 7: _t->sl_turn_tri((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QColor*(*)>(_a[2])),(*reinterpret_cast< QColor*(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 8: _t->sl_turn_inv(); break;
        case 9: _t->sl_turn_cut(); break;
        case 10: _t->sl_turn_lin((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QColor*(*)>(_a[2]))); break;
        case 11: _t->sl_turn_rot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 13: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 14: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 15: _t->clearGroup((*reinterpret_cast< QGraphicsItemGroup*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DrawGraphicsView::*)(QPoint * , QPoint * , QPoint * , uint32_t , bool , QColor , QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DrawGraphicsView::sig_draw_triangle)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DrawGraphicsView::*)(QPoint * , QPoint * , double , QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DrawGraphicsView::sig_draw_line)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DrawGraphicsView::*)(QPoint * , uint32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DrawGraphicsView::sig_draw_invert)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DrawGraphicsView::*)(QPoint * , QPoint * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DrawGraphicsView::sig_rotate)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DrawGraphicsView::*)(QPoint * , QPoint * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DrawGraphicsView::sig_cut)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DrawGraphicsView::staticMetaObject = { {
    &QGraphicsView::staticMetaObject,
    qt_meta_stringdata_DrawGraphicsView.data,
    qt_meta_data_DrawGraphicsView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DrawGraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawGraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DrawGraphicsView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int DrawGraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void DrawGraphicsView::sig_draw_triangle(QPoint * _t1, QPoint * _t2, QPoint * _t3, uint32_t _t4, bool _t5, QColor _t6, QColor _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DrawGraphicsView::sig_draw_line(QPoint * _t1, QPoint * _t2, double _t3, QColor _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DrawGraphicsView::sig_draw_invert(QPoint * _t1, uint32_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DrawGraphicsView::sig_rotate(QPoint * _t1, QPoint * _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DrawGraphicsView::sig_cut(QPoint * _t1, QPoint * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
