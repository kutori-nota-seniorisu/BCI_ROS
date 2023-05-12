/****************************************************************************
** Meta object code from reading C++ file 'qnetstreamingreceiver.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/qt_ros/include/qt_ros/qnetstreamingreceiver.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnetstreamingreceiver.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_qt_ros__QNetStreamingReceiver_t {
    QByteArrayData data[10];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qt_ros__QNetStreamingReceiver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qt_ros__QNetStreamingReceiver_t qt_meta_stringdata_qt_ros__QNetStreamingReceiver = {
    {
QT_MOC_LITERAL(0, 0, 29), // "qt_ros::QNetStreamingReceiver"
QT_MOC_LITERAL(1, 30, 8), // "SendChan"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 12), // "nNumChannels"
QT_MOC_LITERAL(4, 53, 8), // "SendRate"
QT_MOC_LITERAL(5, 62, 11), // "nSampleRate"
QT_MOC_LITERAL(6, 74, 20), // "LoggingConfigUpdated"
QT_MOC_LITERAL(7, 95, 17), // "LoggingComUpdated"
QT_MOC_LITERAL(8, 113, 17), // "LoggingEveUpdated"
QT_MOC_LITERAL(9, 131, 3) // "Run"

    },
    "qt_ros::QNetStreamingReceiver\0SendChan\0"
    "\0nNumChannels\0SendRate\0nSampleRate\0"
    "LoggingConfigUpdated\0LoggingComUpdated\0"
    "LoggingEveUpdated\0Run"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qt_ros__QNetStreamingReceiver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       6,    0,   50,    2, 0x06 /* Public */,
       7,    0,   51,    2, 0x06 /* Public */,
       8,    0,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void qt_ros::QNetStreamingReceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QNetStreamingReceiver *_t = static_cast<QNetStreamingReceiver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendChan((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->SendRate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->LoggingConfigUpdated(); break;
        case 3: _t->LoggingComUpdated(); break;
        case 4: _t->LoggingEveUpdated(); break;
        case 5: _t->Run(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QNetStreamingReceiver::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNetStreamingReceiver::SendChan)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QNetStreamingReceiver::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNetStreamingReceiver::SendRate)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QNetStreamingReceiver::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNetStreamingReceiver::LoggingConfigUpdated)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QNetStreamingReceiver::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNetStreamingReceiver::LoggingComUpdated)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (QNetStreamingReceiver::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNetStreamingReceiver::LoggingEveUpdated)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject qt_ros::QNetStreamingReceiver::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_qt_ros__QNetStreamingReceiver.data,
      qt_meta_data_qt_ros__QNetStreamingReceiver,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *qt_ros::QNetStreamingReceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qt_ros::QNetStreamingReceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qt_ros__QNetStreamingReceiver.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qt_ros::QNetStreamingReceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void qt_ros::QNetStreamingReceiver::SendChan(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void qt_ros::QNetStreamingReceiver::SendRate(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void qt_ros::QNetStreamingReceiver::LoggingConfigUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void qt_ros::QNetStreamingReceiver::LoggingComUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void qt_ros::QNetStreamingReceiver::LoggingEveUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
