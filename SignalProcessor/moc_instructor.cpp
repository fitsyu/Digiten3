/****************************************************************************
** Meta object code from reading C++ file 'instructor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "instructor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'instructor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Instructor_t {
    QByteArrayData data[22];
    char stringdata[328];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Instructor_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Instructor_t qt_meta_stringdata_Instructor = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Instructor"
QT_MOC_LITERAL(1, 11, 16), // "trainingPrepared"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 21), // "TrainingConfiguration"
QT_MOC_LITERAL(4, 51, 20), // "callibrationFinished"
QT_MOC_LITERAL(5, 72, 26), // "nextGestureTrainingStarted"
QT_MOC_LITERAL(6, 99, 17), // "trainingCompleted"
QT_MOC_LITERAL(7, 117, 10), // "callibrate"
QT_MOC_LITERAL(8, 128, 26), // "updateCallibrationProgress"
QT_MOC_LITERAL(9, 155, 14), // "DoNextTraining"
QT_MOC_LITERAL(10, 170, 11), // "tellToSwing"
QT_MOC_LITERAL(11, 182, 9), // "listening"
QT_MOC_LITERAL(12, 192, 20), // "onNewGestureCaptured"
QT_MOC_LITERAL(13, 213, 19), // "onTrainingCompleted"
QT_MOC_LITERAL(14, 233, 5), // "speak"
QT_MOC_LITERAL(15, 239, 11), // "gestureCode"
QT_MOC_LITERAL(16, 251, 12), // "setTrainings"
QT_MOC_LITERAL(17, 264, 14), // "QList<gesture>"
QT_MOC_LITERAL(18, 279, 5), // "value"
QT_MOC_LITERAL(19, 285, 14), // "configTraining"
QT_MOC_LITERAL(20, 300, 13), // "startTraining"
QT_MOC_LITERAL(21, 314, 13) // "configuration"

    },
    "Instructor\0trainingPrepared\0\0"
    "TrainingConfiguration\0callibrationFinished\0"
    "nextGestureTrainingStarted\0trainingCompleted\0"
    "callibrate\0updateCallibrationProgress\0"
    "DoNextTraining\0tellToSwing\0listening\0"
    "onNewGestureCaptured\0onTrainingCompleted\0"
    "speak\0gestureCode\0setTrainings\0"
    "QList<gesture>\0value\0configTraining\0"
    "startTraining\0configuration"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Instructor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    0,   92,    2, 0x06 /* Public */,
       5,    0,   93,    2, 0x06 /* Public */,
       6,    0,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   95,    2, 0x0a /* Public */,
       8,    0,   96,    2, 0x0a /* Public */,
       9,    0,   97,    2, 0x0a /* Public */,
      10,    0,   98,    2, 0x0a /* Public */,
      11,    0,   99,    2, 0x0a /* Public */,
      12,    0,  100,    2, 0x0a /* Public */,
      13,    0,  101,    2, 0x0a /* Public */,
      14,    1,  102,    2, 0x0a /* Public */,
      16,    1,  105,    2, 0x0a /* Public */,
      19,    0,  108,    2, 0x0a /* Public */,
      20,    1,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   21,

       0        // eod
};

void Instructor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Instructor *_t = static_cast<Instructor *>(_o);
        switch (_id) {
        case 0: _t->trainingPrepared((*reinterpret_cast< TrainingConfiguration(*)>(_a[1]))); break;
        case 1: _t->callibrationFinished(); break;
        case 2: _t->nextGestureTrainingStarted(); break;
        case 3: _t->trainingCompleted(); break;
        case 4: _t->callibrate(); break;
        case 5: _t->updateCallibrationProgress(); break;
        case 6: _t->DoNextTraining(); break;
        case 7: _t->tellToSwing(); break;
        case 8: _t->listening(); break;
        case 9: _t->onNewGestureCaptured(); break;
        case 10: _t->onTrainingCompleted(); break;
        case 11: _t->speak((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setTrainings((*reinterpret_cast< const QList<gesture>(*)>(_a[1]))); break;
        case 13: _t->configTraining(); break;
        case 14: _t->startTraining((*reinterpret_cast< TrainingConfiguration(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Instructor::*_t)(TrainingConfiguration );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Instructor::trainingPrepared)) {
                *result = 0;
            }
        }
        {
            typedef void (Instructor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Instructor::callibrationFinished)) {
                *result = 1;
            }
        }
        {
            typedef void (Instructor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Instructor::nextGestureTrainingStarted)) {
                *result = 2;
            }
        }
        {
            typedef void (Instructor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Instructor::trainingCompleted)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Instructor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Instructor.data,
      qt_meta_data_Instructor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Instructor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Instructor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Instructor.stringdata))
        return static_cast<void*>(const_cast< Instructor*>(this));
    return QWidget::qt_metacast(_clname);
}

int Instructor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Instructor::trainingPrepared(TrainingConfiguration _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Instructor::callibrationFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Instructor::nextGestureTrainingStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Instructor::trainingCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
