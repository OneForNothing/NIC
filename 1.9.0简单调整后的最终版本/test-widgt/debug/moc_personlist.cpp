/****************************************************************************
** Meta object code from reading C++ file 'personlist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../personlist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'personlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_personList_t {
    QByteArrayData data[18];
    char stringdata[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_personList_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_personList_t qt_meta_stringdata_personList = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 13),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 8),
QT_MOC_LITERAL(4, 35, 3),
QT_MOC_LITERAL(5, 39, 15),
QT_MOC_LITERAL(6, 55, 12),
QT_MOC_LITERAL(7, 68, 12),
QT_MOC_LITERAL(8, 81, 12),
QT_MOC_LITERAL(9, 94, 12),
QT_MOC_LITERAL(10, 107, 17),
QT_MOC_LITERAL(11, 125, 10),
QT_MOC_LITERAL(12, 136, 19),
QT_MOC_LITERAL(13, 156, 15),
QT_MOC_LITERAL(14, 172, 8),
QT_MOC_LITERAL(15, 181, 4),
QT_MOC_LITERAL(16, 186, 11),
QT_MOC_LITERAL(17, 198, 12)
    },
    "personList\0requestwidget\0\0username\0"
    "uid\0requestnewgroup\0slotAddGroup\0"
    "slotDelGroup\0slotAddBuddy\0slotDelBuddy\0"
    "slotChatWithBuddy\0slotRename\0"
    "slotRenameEditFshed\0addonlinefriend\0"
    "addbuddy\0name\0slotSetName\0addchatgroup\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_personList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x06,
       5,    0,   84,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    0,   85,    2, 0x0a,
       7,    0,   86,    2, 0x0a,
       8,    0,   87,    2, 0x0a,
       9,    0,   88,    2, 0x0a,
      10,    0,   89,    2, 0x0a,
      11,    0,   90,    2, 0x0a,
      12,    0,   91,    2, 0x0a,
      13,    2,   92,    2, 0x0a,
      14,    2,   97,    2, 0x0a,
      16,    0,  102,    2, 0x0a,
      17,    0,  103,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   15,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void personList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        personList *_t = static_cast<personList *>(_o);
        switch (_id) {
        case 0: _t->requestwidget((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->requestnewgroup(); break;
        case 2: _t->slotAddGroup(); break;
        case 3: _t->slotDelGroup(); break;
        case 4: _t->slotAddBuddy(); break;
        case 5: _t->slotDelBuddy(); break;
        case 6: _t->slotChatWithBuddy(); break;
        case 7: _t->slotRename(); break;
        case 8: _t->slotRenameEditFshed(); break;
        case 9: _t->addonlinefriend((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->addbuddy((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->slotSetName(); break;
        case 12: _t->addchatgroup(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (personList::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&personList::requestwidget)) {
                *result = 0;
            }
        }
        {
            typedef void (personList::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&personList::requestnewgroup)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject personList::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_personList.data,
      qt_meta_data_personList,  qt_static_metacall, 0, 0}
};


const QMetaObject *personList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *personList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_personList.stringdata))
        return static_cast<void*>(const_cast< personList*>(this));
    return QListWidget::qt_metacast(_clname);
}

int personList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
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
void personList::requestwidget(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void personList::requestnewgroup()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
