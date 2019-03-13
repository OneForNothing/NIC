/****************************************************************************
** Meta object code from reading C++ file 'statusbarwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../statusbarwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'statusbarwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_statusbarwidget_t {
    QByteArrayData data[16];
    char stringdata[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_statusbarwidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_statusbarwidget_t qt_meta_stringdata_statusbarwidget = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 10),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 8),
QT_MOC_LITERAL(4, 37, 3),
QT_MOC_LITERAL(5, 41, 8),
QT_MOC_LITERAL(6, 50, 4),
QT_MOC_LITERAL(7, 55, 11),
QT_MOC_LITERAL(8, 67, 21),
QT_MOC_LITERAL(9, 89, 3),
QT_MOC_LITERAL(10, 93, 13),
QT_MOC_LITERAL(11, 107, 11),
QT_MOC_LITERAL(12, 119, 21),
QT_MOC_LITERAL(13, 141, 12),
QT_MOC_LITERAL(14, 154, 17),
QT_MOC_LITERAL(15, 172, 23)
    },
    "statusbarwidget\0addnewuser\0\0username\0"
    "uid\0addBuddy\0name\0dealMessage\0"
    "QMap<QString,QString>\0msg\0TypeOfMessage\0"
    "creatwidget\0on_pushButton_clicked\0"
    "addgroupchat\0dealweatherreport\0"
    "on_pushButton_2_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_statusbarwidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06,
       5,    2,   59,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    2,   64,    2, 0x08,
      11,    2,   69,    2, 0x08,
      12,    0,   74,    2, 0x08,
      13,    0,   75,    2, 0x08,
      14,    0,   76,    2, 0x08,
      15,    0,   77,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    6,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void statusbarwidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        statusbarwidget *_t = static_cast<statusbarwidget *>(_o);
        switch (_id) {
        case 0: _t->addnewuser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->addBuddy((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->dealMessage((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->creatwidget((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->addgroupchat(); break;
        case 6: _t->dealweatherreport(); break;
        case 7: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (statusbarwidget::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&statusbarwidget::addnewuser)) {
                *result = 0;
            }
        }
        {
            typedef void (statusbarwidget::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&statusbarwidget::addBuddy)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject statusbarwidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_statusbarwidget.data,
      qt_meta_data_statusbarwidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *statusbarwidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *statusbarwidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_statusbarwidget.stringdata))
        return static_cast<void*>(const_cast< statusbarwidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int statusbarwidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void statusbarwidget::addnewuser(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void statusbarwidget::addBuddy(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
