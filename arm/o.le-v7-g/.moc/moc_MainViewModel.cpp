/****************************************************************************
** Meta object code from reading C++ file 'MainViewModel.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/ViewModels/MainViewModel.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainViewModel.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainViewModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       1,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   15,   14,   14, 0x05,
      69,   61,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     102,   99,   14,   14, 0x08,
     128,  120,   14,   14, 0x08,
     166,   61,   14,   14, 0x08,

 // methods: signature, parameters, type, tag, flags
     198,   99,   14,   14, 0x02,

 // properties: name, type, flags
     229,  213, 0x00495009,

 // properties: notify_signal_id
       0,

       0        // eod
};

static const char qt_meta_stringdata_MainViewModel[] = {
    "MainViewModel\0\0dataModel\0"
    "playerModelChanged(GroupDataModel*)\0"
    "id,name\0playerChallenged(int,QString)\0"
    "id\0onIDReceived(int)\0players\0"
    "onPlayerListRetrieved(QList<Player*>)\0"
    "onPlayerChallenged(int,QString)\0"
    "challenge(int)\0GroupDataModel*\0"
    "playerModel\0"
};

void MainViewModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainViewModel *_t = static_cast<MainViewModel *>(_o);
        switch (_id) {
        case 0: _t->playerModelChanged((*reinterpret_cast< GroupDataModel*(*)>(_a[1]))); break;
        case 1: _t->playerChallenged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->onIDReceived((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onPlayerListRetrieved((*reinterpret_cast< const QList<Player*>(*)>(_a[1]))); break;
        case 4: _t->onPlayerChallenged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->challenge((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainViewModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainViewModel::staticMetaObject = {
    { &ViewModel::staticMetaObject, qt_meta_stringdata_MainViewModel,
      qt_meta_data_MainViewModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainViewModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainViewModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainViewModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainViewModel))
        return static_cast<void*>(const_cast< MainViewModel*>(this));
    return ViewModel::qt_metacast(_clname);
}

int MainViewModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ViewModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< GroupDataModel**>(_v) = getPlayerModel(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MainViewModel::playerModelChanged(GroupDataModel * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainViewModel::playerChallenged(int _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
