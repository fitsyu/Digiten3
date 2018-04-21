/****************************************************************************
** Meta object code from reading C++ file 'graph2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "graph2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graph2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Graph2_t {
    QByteArrayData data[10];
    char stringdata[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Graph2_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Graph2_t qt_meta_stringdata_Graph2 = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Graph2"
QT_MOC_LITERAL(1, 7, 12), // "rangeChanged"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8), // "QCPRange"
QT_MOC_LITERAL(4, 30, 12), // "appendSample"
QT_MOC_LITERAL(5, 43, 6), // "sample"
QT_MOC_LITERAL(6, 50, 13), // "syncRangeWith"
QT_MOC_LITERAL(7, 64, 6), // "xRange"
QT_MOC_LITERAL(8, 71, 6), // "yRange"
QT_MOC_LITERAL(9, 78, 10) // "emitXRange"

    },
    "Graph2\0rangeChanged\0\0QCPRange\0"
    "appendSample\0sample\0syncRangeWith\0"
    "xRange\0yRange\0emitXRange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Graph2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   44,    2, 0x0a /* Public */,
       4,    1,   47,    2, 0x0a /* Public */,
       6,    2,   50,    2, 0x0a /* Public */,
       9,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QReal,    5,
    QMetaType::Void, QMetaType::QVector3D,    5,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    7,    8,
    QMetaType::Void,

       0        // eod
};

void Graph2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Graph2 *_t = static_cast<Graph2 *>(_o);
        switch (_id) {
        case 0: _t->rangeChanged((*reinterpret_cast< QCPRange(*)>(_a[1])),(*reinterpret_cast< QCPRange(*)>(_a[2]))); break;
        case 1: _t->appendSample((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 2: _t->appendSample((*reinterpret_cast< QVector3D(*)>(_a[1]))); break;
        case 3: _t->syncRangeWith((*reinterpret_cast< QCPRange(*)>(_a[1])),(*reinterpret_cast< QCPRange(*)>(_a[2]))); break;
        case 4: _t->emitXRange(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Graph2::*_t)(QCPRange , QCPRange );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Graph2::rangeChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Graph2::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Graph2.data,
      qt_meta_data_Graph2,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Graph2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Graph2::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Graph2.stringdata))
        return static_cast<void*>(const_cast< Graph2*>(this));
    return QWidget::qt_metacast(_clname);
}

int Graph2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Graph2::rangeChanged(QCPRange _t1, QCPRange _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
