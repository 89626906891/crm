/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[394];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 25), // "on_addOrderButton_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 20), // "on_delButton_clicked"
QT_MOC_LITERAL(4, 59, 13), // "orderAccepted"
QT_MOC_LITERAL(5, 73, 12), // "orderCancled"
QT_MOC_LITERAL(6, 86, 25), // "on_calendarWidget_clicked"
QT_MOC_LITERAL(7, 112, 4), // "date"
QT_MOC_LITERAL(8, 117, 29), // "on_actionAdd_worker_triggered"
QT_MOC_LITERAL(9, 147, 30), // "on_editOrderPushButton_clicked"
QT_MOC_LITERAL(10, 178, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(11, 200, 28), // "on_actionAdd_order_triggered"
QT_MOC_LITERAL(12, 229, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(13, 253, 40), // "slot_comboWorkersBox_currentI..."
QT_MOC_LITERAL(14, 294, 4), // "arg1"
QT_MOC_LITERAL(15, 299, 26), // "on_todayPushButton_clicked"
QT_MOC_LITERAL(16, 326, 30), // "on_actionAddDiscount_triggered"
QT_MOC_LITERAL(17, 357, 23), // "on_actionInfo_triggered"
QT_MOC_LITERAL(18, 381, 12) // "moveToCenter"

    },
    "MainWindow\0on_addOrderButton_clicked\0"
    "\0on_delButton_clicked\0orderAccepted\0"
    "orderCancled\0on_calendarWidget_clicked\0"
    "date\0on_actionAdd_worker_triggered\0"
    "on_editOrderPushButton_clicked\0"
    "on_pushButton_clicked\0"
    "on_actionAdd_order_triggered\0"
    "on_actionExit_triggered\0"
    "slot_comboWorkersBox_currentIndexChanged\0"
    "arg1\0on_todayPushButton_clicked\0"
    "on_actionAddDiscount_triggered\0"
    "on_actionInfo_triggered\0moveToCenter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    1,   93,    2, 0x08 /* Private */,
       8,    0,   96,    2, 0x08 /* Private */,
       9,    0,   97,    2, 0x08 /* Private */,
      10,    0,   98,    2, 0x08 /* Private */,
      11,    0,   99,    2, 0x08 /* Private */,
      12,    0,  100,    2, 0x08 /* Private */,
      13,    1,  101,    2, 0x08 /* Private */,
      15,    0,  104,    2, 0x08 /* Private */,
      16,    0,  105,    2, 0x08 /* Private */,
      17,    0,  106,    2, 0x08 /* Private */,
      18,    0,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_addOrderButton_clicked(); break;
        case 1: _t->on_delButton_clicked(); break;
        case 2: _t->orderAccepted(); break;
        case 3: _t->orderCancled(); break;
        case 4: _t->on_calendarWidget_clicked((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 5: _t->on_actionAdd_worker_triggered(); break;
        case 6: _t->on_editOrderPushButton_clicked(); break;
        case 7: _t->on_pushButton_clicked(); break;
        case 8: _t->on_actionAdd_order_triggered(); break;
        case 9: _t->on_actionExit_triggered(); break;
        case 10: _t->slot_comboWorkersBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_todayPushButton_clicked(); break;
        case 12: _t->on_actionAddDiscount_triggered(); break;
        case 13: _t->on_actionInfo_triggered(); break;
        case 14: _t->moveToCenter(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
