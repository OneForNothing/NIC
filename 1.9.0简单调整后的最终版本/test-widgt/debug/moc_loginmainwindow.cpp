/****************************************************************************
** Meta object code from reading C++ file 'loginmainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../loginmainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginmainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_loginMainWindow_t {
    QByteArrayData data[10];
    char stringdata[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_loginMainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_loginMainWindow_t qt_meta_stringdata_loginMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 11),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 21),
QT_MOC_LITERAL(4, 51, 3),
QT_MOC_LITERAL(5, 55, 13),
QT_MOC_LITERAL(6, 69, 24),
QT_MOC_LITERAL(7, 94, 22),
QT_MOC_LITERAL(8, 117, 20),
QT_MOC_LITERAL(9, 138, 21)
    },
    "loginMainWindow\0deelMessage\0\0"
    "QMap<QString,QString>\0msg\0TypeOfMessage\0"
    "on_losePwdButton_clicked\0"
    "on_enterButton_clicked\0on_regButton_clicked\0"
    "on_pushButton_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_loginMainWindow[] = {

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
       1,    2,   39,    2, 0x08,
       6,    0,   44,    2, 0x08,
       7,    0,   45,    2, 0x08,
       8,    0,   46,    2, 0x08,
       9,    0,   47,    2, 0x08,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void loginMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        loginMainWindow *_t = static_cast<loginMainWindow *>(_o);
        switch (_id) {
        case 0: _t->deelMessage((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->on_losePwdButton_clicked(); break;
        case 2: _t->on_enterButton_clicked(); break;
        case 3: _t->on_regButton_clicked(); break;
        case 4: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject loginMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_loginMainWindow.data,
      qt_meta_data_loginMainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *loginMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *loginMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_loginMainWindow.stringdata))
        return static_cast<void*>(const_cast< loginMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int loginMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
