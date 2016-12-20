/****************************************************************************
** Meta object code from reading C++ file 'newworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../newworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_newworker_t {
    QByteArrayData data[7];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_newworker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_newworker_t qt_meta_stringdata_newworker = {
    {
QT_MOC_LITERAL(0, 0, 9), // "newworker"
QT_MOC_LITERAL(1, 10, 11), // "workerReady"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 20), // "signal_workerCanclel"
QT_MOC_LITERAL(4, 44, 14), // "sigWorkerClose"
QT_MOC_LITERAL(5, 59, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 81, 23) // "on_pushButton_2_clicked"

    },
    "newworker\0workerReady\0\0signal_workerCanclel\0"
    "sigWorkerClose\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_newworker[] = {

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

void newworker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        newworker *_t = static_cast<newworker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->workerReady(); break;
        case 1: _t->signal_workerCanclel(); break;
        case 2: _t->sigWorkerClose(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (newworker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&newworker::workerReady)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (newworker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&newworker::signal_workerCanclel)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (newworker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&newworker::sigWorkerClose)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject newworker::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_newworker.data,
      qt_meta_data_newworker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *newworker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *newworker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_newworker.stringdata0))
        return static_cast<void*>(const_cast< newworker*>(this));
    return QWidget::qt_metacast(_clname);
}

int newworker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void newworker::workerReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void newworker::signal_workerCanclel()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void newworker::sigWorkerClose()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
