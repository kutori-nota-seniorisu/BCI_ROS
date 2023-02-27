/****************************************************************************
** Meta object code from reading C++ file 'main_window.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/qt_ros/include/qt_ros/main_window.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_qt_ros__MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[339];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qt_ros__MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qt_ros__MainWindow_t qt_meta_stringdata_qt_ros__MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 18), // "qt_ros::MainWindow"
QT_MOC_LITERAL(1, 19, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 40), // "on_checkbox_use_environment_s..."
QT_MOC_LITERAL(4, 86, 5), // "state"
QT_MOC_LITERAL(5, 92, 17), // "updateLoggingView"
QT_MOC_LITERAL(6, 110, 25), // "on_button_connect_clicked"
QT_MOC_LITERAL(7, 136, 9), // "InitLines"
QT_MOC_LITERAL(8, 146, 8), // "lineNums"
QT_MOC_LITERAL(9, 155, 11), // "RecvAndDraw"
QT_MOC_LITERAL(10, 167, 6), // "float*"
QT_MOC_LITERAL(11, 174, 6), // "pfData"
QT_MOC_LITERAL(12, 181, 8), // "nEegChan"
QT_MOC_LITERAL(13, 190, 11), // "nNumSamples"
QT_MOC_LITERAL(14, 202, 15), // "UpdateLogConfig"
QT_MOC_LITERAL(15, 218, 12), // "UpdateLogCom"
QT_MOC_LITERAL(16, 231, 12), // "UpdateLogEve"
QT_MOC_LITERAL(17, 244, 30), // "on_checkBox_notch_stateChanged"
QT_MOC_LITERAL(18, 275, 4), // "arg1"
QT_MOC_LITERAL(19, 280, 28), // "on_checkBox_low_stateChanged"
QT_MOC_LITERAL(20, 309, 29) // "on_checkBox_high_stateChanged"

    },
    "qt_ros::MainWindow\0on_actionAbout_triggered\0"
    "\0on_checkbox_use_environment_stateChanged\0"
    "state\0updateLoggingView\0"
    "on_button_connect_clicked\0InitLines\0"
    "lineNums\0RecvAndDraw\0float*\0pfData\0"
    "nEegChan\0nNumSamples\0UpdateLogConfig\0"
    "UpdateLogCom\0UpdateLogEve\0"
    "on_checkBox_notch_stateChanged\0arg1\0"
    "on_checkBox_low_stateChanged\0"
    "on_checkBox_high_stateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qt_ros__MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    1,   75,    2, 0x0a /* Public */,
       5,    0,   78,    2, 0x0a /* Public */,
       6,    0,   79,    2, 0x08 /* Private */,
       7,    1,   80,    2, 0x08 /* Private */,
       9,    3,   83,    2, 0x08 /* Private */,
      14,    0,   90,    2, 0x08 /* Private */,
      15,    0,   91,    2, 0x08 /* Private */,
      16,    0,   92,    2, 0x08 /* Private */,
      17,    1,   93,    2, 0x08 /* Private */,
      19,    1,   96,    2, 0x08 /* Private */,
      20,    1,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int, QMetaType::Long,   11,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void qt_ros::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionAbout_triggered(); break;
        case 1: _t->on_checkbox_use_environment_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->updateLoggingView(); break;
        case 3: _t->on_button_connect_clicked(); break;
        case 4: _t->InitLines((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->RecvAndDraw((*reinterpret_cast< float*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< long(*)>(_a[3]))); break;
        case 6: _t->UpdateLogConfig(); break;
        case 7: _t->UpdateLogCom(); break;
        case 8: _t->UpdateLogEve(); break;
        case 9: _t->on_checkBox_notch_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_checkBox_low_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_checkBox_high_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject qt_ros::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_qt_ros__MainWindow.data,
      qt_meta_data_qt_ros__MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *qt_ros::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qt_ros::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qt_ros__MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int qt_ros::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
