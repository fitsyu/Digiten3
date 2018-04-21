/****************************************************************************
** Meta object code from reading C++ file 'signalreceiver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "signalreceiver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'signalreceiver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SignalReceiver_t {
    QByteArrayData data[19];
    char stringdata[258];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SignalReceiver_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SignalReceiver_t qt_meta_stringdata_SignalReceiver = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SignalReceiver"
QT_MOC_LITERAL(1, 15, 14), // "newButtonPress"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 6), // "btCode"
QT_MOC_LITERAL(4, 38, 13), // "new3DGeometry"
QT_MOC_LITERAL(5, 52, 3), // "xyz"
QT_MOC_LITERAL(6, 56, 16), // "pairingDisplayed"
QT_MOC_LITERAL(7, 73, 17), // "QBluetoothAddress"
QT_MOC_LITERAL(8, 91, 7), // "address"
QT_MOC_LITERAL(9, 99, 3), // "pin"
QT_MOC_LITERAL(10, 103, 15), // "pairingFinished"
QT_MOC_LITERAL(11, 119, 30), // "QBluetoothLocalDevice::Pairing"
QT_MOC_LITERAL(12, 150, 7), // "pairing"
QT_MOC_LITERAL(13, 158, 11), // "startServer"
QT_MOC_LITERAL(14, 170, 15), // "clientConnected"
QT_MOC_LITERAL(15, 186, 18), // "clientDisconnected"
QT_MOC_LITERAL(16, 205, 11), // "targetError"
QT_MOC_LITERAL(17, 217, 23), // "QBluetoothServer::Error"
QT_MOC_LITERAL(18, 241, 16) // "onNewDataArrived"

    },
    "SignalReceiver\0newButtonPress\0\0btCode\0"
    "new3DGeometry\0xyz\0pairingDisplayed\0"
    "QBluetoothAddress\0address\0pin\0"
    "pairingFinished\0QBluetoothLocalDevice::Pairing\0"
    "pairing\0startServer\0clientConnected\0"
    "clientDisconnected\0targetError\0"
    "QBluetoothServer::Error\0onNewDataArrived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SignalReceiver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   65,    2, 0x08 /* Private */,
      10,    2,   70,    2, 0x08 /* Private */,
      13,    0,   75,    2, 0x08 /* Private */,
      14,    0,   76,    2, 0x08 /* Private */,
      15,    0,   77,    2, 0x08 /* Private */,
      16,    1,   78,    2, 0x08 /* Private */,
      18,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QVector3D,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7, QMetaType::QString,    8,    9,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 11,    8,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void,

       0        // eod
};

void SignalReceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SignalReceiver *_t = static_cast<SignalReceiver *>(_o);
        switch (_id) {
        case 0: _t->newButtonPress((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->new3DGeometry((*reinterpret_cast< QVector3D(*)>(_a[1]))); break;
        case 2: _t->pairingDisplayed((*reinterpret_cast< QBluetoothAddress(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->pairingFinished((*reinterpret_cast< QBluetoothAddress(*)>(_a[1])),(*reinterpret_cast< QBluetoothLocalDevice::Pairing(*)>(_a[2]))); break;
        case 4: _t->startServer(); break;
        case 5: _t->clientConnected(); break;
        case 6: _t->clientDisconnected(); break;
        case 7: _t->targetError((*reinterpret_cast< QBluetoothServer::Error(*)>(_a[1]))); break;
        case 8: _t->onNewDataArrived(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothAddress >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothAddress >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothLocalDevice::Pairing >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SignalReceiver::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SignalReceiver::newButtonPress)) {
                *result = 0;
            }
        }
        {
            typedef void (SignalReceiver::*_t)(QVector3D );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SignalReceiver::new3DGeometry)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject SignalReceiver::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SignalReceiver.data,
      qt_meta_data_SignalReceiver,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SignalReceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SignalReceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SignalReceiver.stringdata))
        return static_cast<void*>(const_cast< SignalReceiver*>(this));
    return QWidget::qt_metacast(_clname);
}

int SignalReceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void SignalReceiver::newButtonPress(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SignalReceiver::new3DGeometry(QVector3D _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
