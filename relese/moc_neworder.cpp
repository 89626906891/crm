/****************************************************************************
** Meta object code from reading C++ file 'neworder.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../neworder.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'neworder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_newOrder_t {
    QByteArrayData data[9];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_newOrder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_newOrder_t qt_meta_stringdata_newOrder = {
    {
QT_MOC_LITERAL(0, 0, 8), // "newOrder"
QT_MOC_LITERAL(1, 9, 5), // "ready"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 17), // "signalCancelOrder"
QT_MOC_LITERAL(4, 34, 8), // "sigClose"
QT_MOC_LITERAL(5, 43, 22), // "on_applyButton_clicked"
QT_MOC_LITERAL(6, 66, 22), // "on_closeButton_clicked"
QT_MOC_LITERAL(7, 89, 25), // "on_plusPushButton_clicked"
QT_MOC_LITERAL(8, 115, 26) // "on_minusPushButton_clicked"

    },
    "newOrder\0ready\0\0signalCancelOrder\0"
    "sigClose\0on_applyButton_clicked\0"
    "on_closeButton_clicked\0on_plusPushButton_clicked\0"
    "on_minusPushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_newOrder[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void newOrder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        newOrder *_t = static_cast<newOrder *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ready(); break;
        case 1: _t->signalCancelOrder(); break;
        case 2: _t->sigClose(); break;
        case 3: _t->on_applyButton_clicked(); break;
        case 4: _t->on_closeButton_clicked(); break;
        case 5: _t->on_plusPushButton_clicked(); break;
        case 6: _t->on_minusPushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (newOrder::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&newOrder::ready)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (newOrder::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&newOrder::signalCancelOrder)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (newOrder::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&newOrder::sigClose)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject newOrder::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_newOrder.data,
      qt_meta_data_newOrder,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *newOrder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *newOrder::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_newOrder.stringdata0))
        return static_cast<void*>(const_cast< newOrder*>(this));
    return QWidget::qt_metacast(_clname);
}

int newOrder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void newOrder::ready()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void newOrder::signalCancelOrder()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void newOrder::sigClose()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
