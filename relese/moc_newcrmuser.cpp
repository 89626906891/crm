/****************************************************************************
** Meta object code from reading C++ file 'newcrmuser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../newcrmuser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newcrmuser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_newCrmUser_t {
    QByteArrayData data[7];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_newCrmUser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_newCrmUser_t qt_meta_stringdata_newCrmUser = {
    {
QT_MOC_LITERAL(0, 0, 10), // "newCrmUser"
QT_MOC_LITERAL(1, 11, 12), // "CRMuserReady"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 14), // "CRMuserCancled"
QT_MOC_LITERAL(4, 40, 19), // "CRMuserWindowClosed"
QT_MOC_LITERAL(5, 60, 23), // "on_okpushButton_clicked"
QT_MOC_LITERAL(6, 84, 27) // "on_cancelpushButton_clicked"

    },
    "newCrmUser\0CRMuserReady\0\0CRMuserCancled\0"
    "CRMuserWindowClosed\0on_okpushButton_clicked\0"
    "on_cancelpushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_newCrmUser[] = {

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

void newCrmUser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        newCrmUser *_t = static_cast<newCrmUser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CRMuserReady(); break;
        case 1: _t->CRMuserCancled(); break;
        case 2: _t->CRMuserWindowClosed(); break;
        case 3: _t->on_okpushButton_clicked(); break;
        case 4: _t->on_cancelpushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (newCrmUser::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&newCrmUser::CRMuserReady)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (newCrmUser::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&newCrmUser::CRMuserCancled)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (newCrmUser::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&newCrmUser::CRMuserWindowClosed)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject newCrmUser::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_newCrmUser.data,
      qt_meta_data_newCrmUser,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *newCrmUser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *newCrmUser::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_newCrmUser.stringdata0))
        return static_cast<void*>(const_cast< newCrmUser*>(this));
    return QWidget::qt_metacast(_clname);
}

int newCrmUser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void newCrmUser::CRMuserReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void newCrmUser::CRMuserCancled()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void newCrmUser::CRMuserWindowClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
