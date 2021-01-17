/****************************************************************************
** Meta object code from reading C++ file 'camthread.h'
**
** Created: Tue May 9 11:04:56 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "camthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Camthread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      35,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      52,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Camthread[] = {
    "Camthread\0\0sig_GetOneFrame(QImage)\0"
    "sig_err(QString)\0readFrame()\0"
};

void Camthread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Camthread *_t = static_cast<Camthread *>(_o);
        switch (_id) {
        case 0: _t->sig_GetOneFrame((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->sig_err((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->readFrame(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Camthread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Camthread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Camthread,
      qt_meta_data_Camthread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Camthread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Camthread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Camthread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Camthread))
        return static_cast<void*>(const_cast< Camthread*>(this));
    return QThread::qt_metacast(_clname);
}

int Camthread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Camthread::sig_GetOneFrame(QImage _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Camthread::sig_err(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
