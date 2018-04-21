/****************************************************************************
** Meta object code from reading C++ file 'bluemice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "bluemice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluemice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BlueMice_t {
    QByteArrayData data[22];
    char stringdata[289];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BlueMice_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BlueMice_t qt_meta_stringdata_BlueMice = {
    {
QT_MOC_LITERAL(0, 0, 8), // "BlueMice"
QT_MOC_LITERAL(1, 9, 12), // "startService"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "stopService"
QT_MOC_LITERAL(4, 35, 18), // "onNewDataAvailable"
QT_MOC_LITERAL(5, 54, 8), // "discover"
QT_MOC_LITERAL(6, 63, 10), // "addService"
QT_MOC_LITERAL(7, 74, 21), // "QBluetoothServiceInfo"
QT_MOC_LITERAL(8, 96, 7), // "service"
QT_MOC_LITERAL(9, 104, 13), // "directConnect"
QT_MOC_LITERAL(10, 118, 10), // "fromTarget"
QT_MOC_LITERAL(11, 129, 7), // "onError"
QT_MOC_LITERAL(12, 137, 29), // "QBluetoothSocket::SocketError"
QT_MOC_LITERAL(13, 167, 5), // "error"
QT_MOC_LITERAL(14, 173, 11), // "onConnected"
QT_MOC_LITERAL(15, 185, 14), // "onStateChanged"
QT_MOC_LITERAL(16, 200, 29), // "QBluetoothSocket::SocketState"
QT_MOC_LITERAL(17, 230, 5), // "state"
QT_MOC_LITERAL(18, 236, 10), // "onFinished"
QT_MOC_LITERAL(19, 247, 9), // "leftClick"
QT_MOC_LITERAL(20, 257, 10), // "rightClick"
QT_MOC_LITERAL(21, 268, 20) // "onOrientationChanged"

    },
    "BlueMice\0startService\0\0stopService\0"
    "onNewDataAvailable\0discover\0addService\0"
    "QBluetoothServiceInfo\0service\0"
    "directConnect\0fromTarget\0onError\0"
    "QBluetoothSocket::SocketError\0error\0"
    "onConnected\0onStateChanged\0"
    "QBluetoothSocket::SocketState\0state\0"
    "onFinished\0leftClick\0rightClick\0"
    "onOrientationChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BlueMice[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    1,   88,    2, 0x0a /* Public */,
       9,    0,   91,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x0a /* Public */,
      11,    1,   93,    2, 0x0a /* Public */,
      14,    0,   96,    2, 0x0a /* Public */,
      15,    1,   97,    2, 0x0a /* Public */,
      18,    0,  100,    2, 0x0a /* Public */,
      19,    0,  101,    2, 0x0a /* Public */,
      20,    0,  102,    2, 0x0a /* Public */,
      21,    0,  103,    2, 0x0a /* Public */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BlueMice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BlueMice *_t = static_cast<BlueMice *>(_o);
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
        case 11: _t->leftClick(); break;
        case 12: _t->rightClick(); break;
        case 13: _t->onOrientationChanged(); break;
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

const QMetaObject BlueMice::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BlueMice.data,
      qt_meta_data_BlueMice,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BlueMice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BlueMice::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BlueMice.stringdata))
        return static_cast<void*>(const_cast< BlueMice*>(this));
    return QObject::qt_metacast(_clname);
}

int BlueMice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
