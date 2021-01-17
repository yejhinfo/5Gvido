/****************************************************************************
** Meta object code from reading C++ file 'camaraget.h'
**
** Created: Wed May 10 22:00:19 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "camaraget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camaraget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_camaraGet[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      24,   10,   10,   10, 0x08,
      42,   10,   10,   10, 0x08,
      56,   10,   10,   10, 0x08,
      73,   10,   10,   10, 0x08,
      85,   10,   10,   10, 0x08,
      97,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_camaraGet[] = {
    "camaraGet\0\0openCamara()\0readFarme(QImage)\0"
    "closeCamara()\0takingPictures()\0"
    "openvideo()\0readFarme()\0readMessage()\0"
};

void camaraGet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        camaraGet *_t = static_cast<camaraGet *>(_o);
        switch (_id) {
        case 0: _t->openCamara(); break;
        case 1: _t->readFarme((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->closeCamara(); break;
        case 3: _t->takingPictures(); break;
        case 4: _t->openvideo(); break;
        case 5: _t->readFarme(); break;
        case 6: _t->readMessage(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData camaraGet::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject camaraGet::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_camaraGet,
      qt_meta_data_camaraGet, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &camaraGet::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *camaraGet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *camaraGet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_camaraGet))
        return static_cast<void*>(const_cast< camaraGet*>(this));
    return QWidget::qt_metacast(_clname);
}

int camaraGet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
