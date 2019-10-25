/****************************************************************************
** Meta object code from reading C++ file 'myimage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../myimage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myimage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyImage_t {
    QByteArrayData data[34];
    char stringdata0[289];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyImage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyImage_t qt_meta_stringdata_MyImage = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MyImage"
QT_MOC_LITERAL(1, 8, 7), // "changed"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 10), // "size_error"
QT_MOC_LITERAL(4, 28, 11), // "info_signal"
QT_MOC_LITERAL(5, 40, 9), // "open_file"
QT_MOC_LITERAL(6, 50, 11), // "const char*"
QT_MOC_LITERAL(7, 62, 4), // "file"
QT_MOC_LITERAL(8, 67, 9), // "save_file"
QT_MOC_LITERAL(9, 77, 11), // "createImage"
QT_MOC_LITERAL(10, 89, 9), // "getPixMap"
QT_MOC_LITERAL(11, 99, 18), // "make_rgb_component"
QT_MOC_LITERAL(12, 118, 9), // "component"
QT_MOC_LITERAL(13, 128, 5), // "value"
QT_MOC_LITERAL(14, 134, 6), // "square"
QT_MOC_LITERAL(15, 141, 7), // "QPoint*"
QT_MOC_LITERAL(16, 149, 11), // "start_point"
QT_MOC_LITERAL(17, 161, 9), // "end_point"
QT_MOC_LITERAL(18, 171, 10), // "line_width"
QT_MOC_LITERAL(19, 182, 6), // "isFill"
QT_MOC_LITERAL(20, 189, 10), // "line_color"
QT_MOC_LITERAL(21, 200, 10), // "fill_color"
QT_MOC_LITERAL(22, 211, 12), // "change_pixel"
QT_MOC_LITERAL(23, 224, 1), // "y"
QT_MOC_LITERAL(24, 226, 1), // "x"
QT_MOC_LITERAL(25, 228, 5), // "color"
QT_MOC_LITERAL(26, 234, 15), // "draw_l_diagonal"
QT_MOC_LITERAL(27, 250, 2), // "x0"
QT_MOC_LITERAL(28, 253, 2), // "y0"
QT_MOC_LITERAL(29, 256, 2), // "x1"
QT_MOC_LITERAL(30, 259, 2), // "y1"
QT_MOC_LITERAL(31, 262, 15), // "draw_r_diagonal"
QT_MOC_LITERAL(32, 278, 4), // "turn"
QT_MOC_LITERAL(33, 283, 5) // "angle"

    },
    "MyImage\0changed\0\0size_error\0info_signal\0"
    "open_file\0const char*\0file\0save_file\0"
    "createImage\0getPixMap\0make_rgb_component\0"
    "component\0value\0square\0QPoint*\0"
    "start_point\0end_point\0line_width\0"
    "isFill\0line_color\0fill_color\0change_pixel\0"
    "y\0x\0color\0draw_l_diagonal\0x0\0y0\0x1\0"
    "y1\0draw_r_diagonal\0turn\0angle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyImage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       3,    0,   82,    2, 0x06 /* Public */,
       4,    5,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   94,    2, 0x0a /* Public */,
       8,    1,   97,    2, 0x0a /* Public */,
       9,    0,  100,    2, 0x0a /* Public */,
      10,    0,  101,    2, 0x0a /* Public */,
      11,    2,  102,    2, 0x0a /* Public */,
      14,    6,  107,    2, 0x0a /* Public */,
      22,    3,  120,    2, 0x0a /* Public */,
      26,    5,  127,    2, 0x0a /* Public */,
      31,    5,  138,    2, 0x0a /* Public */,
      32,    3,  149,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UShort,    2,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Int, 0x80000000 | 6,    7,
    QMetaType::Int, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::QPixmap,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 15, QMetaType::Int, QMetaType::Bool, QMetaType::QColor, QMetaType::QColor,   16,   17,   18,   19,   20,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QColor,   23,   24,   25,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QColor,   27,   28,   29,   30,   25,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QColor,   27,   28,   29,   30,   25,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 15, QMetaType::Int,   16,   17,   33,

       0        // eod
};

void MyImage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyImage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changed((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 1: _t->size_error(); break;
        case 2: _t->info_signal((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< unsigned short(*)>(_a[5]))); break;
        case 3: { int _r = _t->open_file((*reinterpret_cast< const char*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->save_file((*reinterpret_cast< const char*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->createImage(); break;
        case 6: { QPixmap _r = _t->getPixMap();
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->make_rgb_component((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->square((*reinterpret_cast< QPoint*(*)>(_a[1])),(*reinterpret_cast< QPoint*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< QColor(*)>(_a[5])),(*reinterpret_cast< QColor(*)>(_a[6]))); break;
        case 9: _t->change_pixel((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QColor(*)>(_a[3]))); break;
        case 10: _t->draw_l_diagonal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QColor(*)>(_a[5]))); break;
        case 11: _t->draw_r_diagonal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QColor(*)>(_a[5]))); break;
        case 12: _t->turn((*reinterpret_cast< QPoint*(*)>(_a[1])),(*reinterpret_cast< QPoint*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyImage::*)(QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyImage::changed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyImage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyImage::size_error)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyImage::*)(unsigned int , unsigned int , unsigned int , unsigned int , unsigned short );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyImage::info_signal)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyImage::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_MyImage.data,
    qt_meta_data_MyImage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyImage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyImage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyImage.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MyImage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MyImage::changed(QPixmap _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyImage::size_error()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MyImage::info_signal(unsigned int _t1, unsigned int _t2, unsigned int _t3, unsigned int _t4, unsigned short _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
