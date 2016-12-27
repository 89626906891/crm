/****************************************************************************
** Meta object code from reading C++ file 'crmusers.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../crmusers.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'crmusers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CRMusers_t {
    QByteArrayData data[8];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CRMusers_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CRMusers_t qt_meta_stringdata_CRMusers = {
    {
QT_MOC_LITERAL(0, 0, 8), // "CRMusers"
QT_MOC_LITERAL(1, 9, 31), // "on_addCrmUserPushButton_clicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 30), // "on_blockuserPushButton_clicked"
QT_MOC_LITERAL(4, 73, 26), // "on_tableView_doubleClicked"
QT_MOC_LITERAL(5, 100, 5), // "index"
QT_MOC_LITERAL(6, 106, 15), // "CRMuserAccepted"
QT_MOC_LITERAL(7, 122, 16) // "newCRMuserCancel"

    },
    "CRMusers\0on_addCrmUserPushButton_clicked\0"
    "\0on_blockuserPushButton_clicked\0"
    "on_tableView_doubleClicked\0index\0"
    "CRMuserAccepted\0newCRMuserCancel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CRMusers[] = {

 // content:
       7,       // revision
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
       3,    0,   40,    2, 0x08 /* Private */,
       4,    1,   41,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CRMusers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CRMusers *_t = static_cast<CRMusers *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_addCrmUserPushButton_clicked(); break;
        case 1: _t->on_blockuserPushButton_clicked(); break;
        case 2: _t->on_tableView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->CRMuserAccepted(); break;
        case 4: _t->newCRMuserCancel(); break;
        default: ;
        }
    }
}

const QMetaObject CRMusers::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CRMusers.data,
      qt_meta_data_CRMusers,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CRMusers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CRMusers::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CRMusers.stringdata0))
        return static_cast<void*>(const_cast< CRMusers*>(this));
    return QWidget::qt_metacast(_clname);
}

int CRMusers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
