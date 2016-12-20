/****************************************************************************
** Meta object code from reading C++ file 'newdiscount.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../newdiscount.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newdiscount.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_newdiscount_t {
    QByteArrayData data[7];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_newdiscount_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_newdiscount_t qt_meta_stringdata_newdiscount = {
    {
QT_MOC_LITERAL(0, 0, 11), // "newdiscount"
QT_MOC_LITERAL(1, 12, 13), // "discountReady"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 20), // "signalCancelDiscount"
QT_MOC_LITERAL(4, 48, 16), // "sigDiscountClose"
QT_MOC_LITERAL(5, 65, 35), // "on_acceptDiscountPushButton_c..."
QT_MOC_LITERAL(6, 101, 35) // "on_cancelDiscountPushButton_c..."

    },
    "newdiscount\0discountReady\0\0"
    "signalCancelDiscount\0sigDiscountClose\0"
    "on_acceptDiscountPushButton_clicked\0"
    "on_cancelDiscountPushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_newdiscount[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void newdiscount::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        newdiscount *_t = static_cast<newdiscount *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->discountReady(); break;
        case 1: _t->signalCancelDiscount(); break;
        case 2: _t->sigDiscountClose(); break;
        case 3: _t->on_acceptDiscountPushButton_clicked(); break;
        case 4: _t->on_cancelDiscountPushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (newdiscount::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&newdiscount::discountReady)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (newdiscount::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&newdiscount::signalCancelDiscount)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (newdiscount::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&newdiscount::sigDiscountClose)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject newdiscount::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_newdiscount.data,
      qt_meta_data_newdiscount,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *newdiscount::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *newdiscount::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_newdiscount.stringdata0))
        return static_cast<void*>(const_cast< newdiscount*>(this));
    return QWidget::qt_metacast(_clname);
}

int newdiscount::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void newdiscount::discountReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void newdiscount::signalCancelDiscount()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void newdiscount::sigDiscountClose()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
