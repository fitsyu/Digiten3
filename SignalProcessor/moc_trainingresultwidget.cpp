/****************************************************************************
** Meta object code from reading C++ file 'trainingresultwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "trainingresultwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trainingresultwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AlgorithmTester_t {
    QByteArrayData data[10];
    char stringdata[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AlgorithmTester_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AlgorithmTester_t qt_meta_stringdata_AlgorithmTester = {
    {
QT_MOC_LITERAL(0, 0, 15), // "AlgorithmTester"
QT_MOC_LITERAL(1, 16, 12), // "new_progress"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 16), // "training_started"
QT_MOC_LITERAL(4, 47, 15), // "training_failed"
QT_MOC_LITERAL(5, 63, 15), // "testing_started"
QT_MOC_LITERAL(6, 79, 26), // "prediction_fails_on_sample"
QT_MOC_LITERAL(7, 106, 16), // "testing_finished"
QT_MOC_LITERAL(8, 123, 8), // "accuracy"
QT_MOC_LITERAL(9, 132, 10) // "time_taken"

    },
    "AlgorithmTester\0new_progress\0\0"
    "training_started\0training_failed\0"
    "testing_started\0prediction_fails_on_sample\0"
    "testing_finished\0accuracy\0time_taken"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AlgorithmTester[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    0,   47,    2, 0x06 /* Public */,
       4,    0,   48,    2, 0x06 /* Public */,
       5,    0,   49,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,
       7,    2,   53,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,

       0        // eod
};

void AlgorithmTester::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AlgorithmTester *_t = static_cast<AlgorithmTester *>(_o);
        switch (_id) {
        case 0: _t->new_progress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->training_started(); break;
        case 2: _t->training_failed(); break;
        case 3: _t->testing_started(); break;
        case 4: _t->prediction_fails_on_sample((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->testing_finished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AlgorithmTester::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AlgorithmTester::new_progress)) {
                *result = 0;
            }
        }
        {
            typedef void (AlgorithmTester::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AlgorithmTester::training_started)) {
                *result = 1;
            }
        }
        {
            typedef void (AlgorithmTester::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AlgorithmTester::training_failed)) {
                *result = 2;
            }
        }
        {
            typedef void (AlgorithmTester::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AlgorithmTester::testing_started)) {
                *result = 3;
            }
        }
        {
            typedef void (AlgorithmTester::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AlgorithmTester::prediction_fails_on_sample)) {
                *result = 4;
            }
        }
        {
            typedef void (AlgorithmTester::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AlgorithmTester::testing_finished)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject AlgorithmTester::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_AlgorithmTester.data,
      qt_meta_data_AlgorithmTester,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AlgorithmTester::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AlgorithmTester::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AlgorithmTester.stringdata))
        return static_cast<void*>(const_cast< AlgorithmTester*>(this));
    return QThread::qt_metacast(_clname);
}

int AlgorithmTester::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void AlgorithmTester::new_progress(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AlgorithmTester::training_started()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void AlgorithmTester::training_failed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void AlgorithmTester::testing_started()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void AlgorithmTester::prediction_fails_on_sample(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void AlgorithmTester::testing_finished(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
struct qt_meta_stringdata_TrainingResultWidget_t {
    QByteArrayData data[7];
    char stringdata[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TrainingResultWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TrainingResultWidget_t qt_meta_stringdata_TrainingResultWidget = {
    {
QT_MOC_LITERAL(0, 0, 20), // "TrainingResultWidget"
QT_MOC_LITERAL(1, 21, 18), // "progress_increased"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 15), // "selectAllToggle"
QT_MOC_LITERAL(4, 57, 18), // "do_test_algorithms"
QT_MOC_LITERAL(5, 76, 18), // "use_this_algorithm"
QT_MOC_LITERAL(6, 95, 27) // "increase_progress_bar_value"

    },
    "TrainingResultWidget\0progress_increased\0"
    "\0selectAllToggle\0do_test_algorithms\0"
    "use_this_algorithm\0increase_progress_bar_value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrainingResultWidget[] = {

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
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TrainingResultWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TrainingResultWidget *_t = static_cast<TrainingResultWidget *>(_o);
        switch (_id) {
        case 0: _t->progress_increased(); break;
        case 1: _t->selectAllToggle(); break;
        case 2: _t->do_test_algorithms(); break;
        case 3: _t->use_this_algorithm(); break;
        case 4: _t->increase_progress_bar_value(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TrainingResultWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TrainingResultWidget::progress_increased)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TrainingResultWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TrainingResultWidget.data,
      qt_meta_data_TrainingResultWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TrainingResultWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrainingResultWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TrainingResultWidget.stringdata))
        return static_cast<void*>(const_cast< TrainingResultWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int TrainingResultWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void TrainingResultWidget::progress_increased()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
