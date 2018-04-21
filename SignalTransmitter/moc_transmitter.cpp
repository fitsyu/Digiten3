/****************************************************************************
** Meta object code from reading C++ file 'transmitter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "transmitter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'transmitter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Transmitter_t {
    QByteArrayData data[24];
    char stringdata[331];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Transmitter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Transmitter_t qt_meta_stringdata_Transmitter = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Transmitter"
QT_MOC_LITERAL(1, 12, 12), // "startService"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11), // "stopService"
QT_MOC_LITERAL(4, 38, 18), // "onNewDataAvailable"
QT_MOC_LITERAL(5, 57, 8), // "discover"
QT_MOC_LITERAL(6, 66, 10), // "addService"
QT_MOC_LITERAL(7, 77, 21), // "QBluetoothServiceInfo"
QT_MOC_LITERAL(8, 99, 7), // "service"
QT_MOC_LITERAL(9, 107, 13), // "directConnect"
QT_MOC_LITERAL(10, 121, 10), // "fromTarget"
QT_MOC_LITERAL(11, 132, 7), // "onError"
QT_MOC_LITERAL(12, 140, 29), // "QBluetoothSocket::SocketError"
QT_MOC_LITERAL(13, 170, 5), // "error"
QT_MOC_LITERAL(14, 176, 11), // "onConnected"
QT_MOC_LITERAL(15, 188, 14), // "onStateChanged"
QT_MOC_LITERAL(16, 203, 29), // "QBluetoothSocket::SocketState"
QT_MOC_LITERAL(17, 233, 5), // "state"
QT_MOC_LITERAL(18, 239, 10), // "onFinished"
QT_MOC_LITERAL(19, 250, 11), // "clickButton"
QT_MOC_LITERAL(20, 262, 8), // "buttonID"
QT_MOC_LITERAL(21, 271, 19), // "toggleAccelerometer"
QT_MOC_LITERAL(22, 291, 18), // "toggleMagnetometer"
QT_MOC_LITERAL(23, 310, 20) // "onOrientationChanged"

    },
    "Transmitter\0startService\0\0stopService\0"
    "onNewDataAvailable\0discover\0addService\0"
    "QBluetoothServiceInfo\0service\0"
    "directConnect\0fromTarget\0onError\0"
    "QBluetoothSocket::SocketError\0error\0"
    "onConnected\0onStateChanged\0"
    "QBluetoothSocket::SocketState\0state\0"
    "onFinished\0clickButton\0buttonID\0"
    "toggleAccelerometer\0toggleMagnetometer\0"
    "onOrientationChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Transmitter[] = {

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
       1,    0,   89,    2, 0x0a /* Public */,
       3,    0,   90,    2, 0x0a /* Public */,
       4,    0,   91,    2, 0x0a /* Public */,
       5,    0,   92,    2, 0x0a /* Public */,
       6,    1,   93,    2, 0x0a /* Public */,
       9,    0,   96,    2, 0x0a /* Public */,
      10,    0,   97,    2, 0x0a /* Public */,
      11,    1,   98,    2, 0x0a /* Public */,
      14,    0,  101,    2, 0x0a /* Public */,
      15,    1,  102,    2, 0x0a /* Public */,
      18,    0,  105,    2, 0x0a /* Public */,
      19,    1,  106,    2, 0x0a /* Public */,
      21,    0,  109,    2, 0x0a /* Public */,
      22,    0,  110,    2, 0x0a /* Public */,
      23,    0,  111,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Transmitter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Transmitter *_t = static_cast<Transmitter *>(_o);
        switch (_id) {
        case 0: _t->startService(); break;
        case 1: _t->stopService(); break;
        case 2: _t->onNewDataAvailable(); break;
        case 3: _t->discover(); break;
        case 4: _t->addService((*reinterpret_cast< QBluetoothServiceInfo(*)>(_a[1]))); break;
        case 5: _t->directConnect(); break;
        case 6: _t->fromTarget(); break;
        case 7: _t->onError((*reinterpret_cast< QBluetoothSocket::SocketError(*)>(_a[1]))); break;
        case 8: _t->onConnected(); break;
        case 9: _t->onStateChanged((*reinterpret_cast< QBluetoothSocket::SocketState(*)>(_a[1]))); break;
        case 10: _t->onFinished(); break;
        case 11: _t->clickButton((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->toggleAccelerometer(); break;
        case 13: _t->toggleMagnetometer(); break;
        case 14: _t->onOrientationChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothServiceInfo >(); break;
            }
            break;
        }
    }
}

const QMetaObject Transmitter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Transmitter.data,
      qt_meta_data_Transmitter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Transmitter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Transmitter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Transmitter.stringdata))
        return static_cast<void*>(const_cast< Transmitter*>(this));
    return QObject::qt_metacast(_clname);
}

int Transmitter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
