/****************************************************************************
** Meta object code from reading C++ file 'CarClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../View/CarClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CarClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialPortHelper_t {
    QByteArrayData data[4];
    char stringdata0[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialPortHelper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialPortHelper_t qt_meta_stringdata_SerialPortHelper = {
    {
QT_MOC_LITERAL(0, 0, 16), // "SerialPortHelper"
QT_MOC_LITERAL(1, 17, 10), // "infoSignal"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11) // "dataReceive"

    },
    "SerialPortHelper\0infoSignal\0\0dataReceive"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPortHelper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void SerialPortHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SerialPortHelper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->infoSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->dataReceive(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SerialPortHelper::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPortHelper::infoSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SerialPortHelper::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SerialPortHelper.data,
    qt_meta_data_SerialPortHelper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SerialPortHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialPortHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialPortHelper.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SerialPortHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void SerialPortHelper::infoSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_CarClient_t {
    QByteArrayData data[12];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CarClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CarClient_t qt_meta_stringdata_CarClient = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CarClient"
QT_MOC_LITERAL(1, 10, 12), // "analysisData"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "dataArr"
QT_MOC_LITERAL(4, 32, 12), // "dataReceived"
QT_MOC_LITERAL(5, 45, 7), // "CRC16_2"
QT_MOC_LITERAL(6, 53, 2), // "ba"
QT_MOC_LITERAL(7, 56, 6), // "uchar*"
QT_MOC_LITERAL(8, 63, 6), // "crcBuf"
QT_MOC_LITERAL(9, 70, 11), // "mileInfoRet"
QT_MOC_LITERAL(10, 82, 4), // "data"
QT_MOC_LITERAL(11, 87, 12) // "getLittleEnd"

    },
    "CarClient\0analysisData\0\0dataArr\0"
    "dataReceived\0CRC16_2\0ba\0uchar*\0crcBuf\0"
    "mileInfoRet\0data\0getLittleEnd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CarClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    0,   42,    2, 0x08 /* Private */,
       5,    2,   43,    2, 0x08 /* Private */,
       9,    1,   48,    2, 0x08 /* Private */,
      11,    1,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 7,    6,    8,
    QMetaType::Void, QMetaType::QByteArray,   10,
    QMetaType::QString, QMetaType::QByteArray,   10,

       0        // eod
};

void CarClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CarClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->analysisData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->dataReceived(); break;
        case 2: _t->CRC16_2((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< uchar*(*)>(_a[2]))); break;
        case 3: _t->mileInfoRet((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 4: { QString _r = _t->getLittleEnd((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CarClient::staticMetaObject = { {
    QMetaObject::SuperData::link<SerialPortHelper::staticMetaObject>(),
    qt_meta_stringdata_CarClient.data,
    qt_meta_data_CarClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CarClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CarClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CarClient.stringdata0))
        return static_cast<void*>(this);
    return SerialPortHelper::qt_metacast(_clname);
}

int CarClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SerialPortHelper::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_CarClientView_t {
    QByteArrayData data[8];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CarClientView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CarClientView_t qt_meta_stringdata_CarClientView = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CarClientView"
QT_MOC_LITERAL(1, 14, 20), // "on_btn_start_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 19), // "on_btn_stop_clicked"
QT_MOC_LITERAL(4, 56, 23), // "on_btn_controll_clicked"
QT_MOC_LITERAL(5, 80, 22), // "on_btn_release_clicked"
QT_MOC_LITERAL(6, 103, 2), // "em"
QT_MOC_LITERAL(7, 106, 10) // "strMessage"

    },
    "CarClientView\0on_btn_start_clicked\0\0"
    "on_btn_stop_clicked\0on_btn_controll_clicked\0"
    "on_btn_release_clicked\0em\0strMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CarClientView[] = {

 // content:
       8,       // revision
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
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void CarClientView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CarClientView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_start_clicked(); break;
        case 1: _t->on_btn_stop_clicked(); break;
        case 2: _t->on_btn_controll_clicked(); break;
        case 3: _t->on_btn_release_clicked(); break;
        case 4: _t->em((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CarClientView::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CarClientView.data,
    qt_meta_data_CarClientView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CarClientView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CarClientView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CarClientView.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CarClientView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
