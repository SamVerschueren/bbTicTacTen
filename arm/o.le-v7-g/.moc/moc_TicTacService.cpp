/****************************************************************************
** Meta object code from reading C++ file 'TicTacService.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Services/TicTacService.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TicTacService.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TicTacService[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   15,   14,   14, 0x05,
      44,   36,   14,   14, 0x05,
      90,   82,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     122,   14,   14,   14, 0x08,
     142,   14,   14,   14, 0x08,
     171,  165,   14,   14, 0x08,
     215,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TicTacService[] = {
    "TicTacService\0\0id\0onIDReceived(int)\0"
    "players\0onPlayerListRetrieved(QList<Player*>)\0"
    "id,name\0onPlayerChallenged(int,QString)\0"
    "onSocketConnected()\0onSocketDisconnected()\0"
    "error\0onSocketError(QAbstractSocket::SocketError)\0"
    "onDataReceived()\0"
};

void TicTacService::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TicTacService *_t = static_cast<TicTacService *>(_o);
        switch (_id) {
        case 0: _t->onIDReceived((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onPlayerListRetrieved((*reinterpret_cast< const QList<Player*>(*)>(_a[1]))); break;
        case 2: _t->onPlayerChallenged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->onSocketConnected(); break;
        case 4: _t->onSocketDisconnected(); break;
        case 5: _t->onSocketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 6: _t->onDataReceived(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TicTacService::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TicTacService::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TicTacService,
      qt_meta_data_TicTacService, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TicTacService::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TicTacService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TicTacService::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TicTacService))
        return static_cast<void*>(const_cast< TicTacService*>(this));
    return QObject::qt_metacast(_clname);
}

int TicTacService::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void TicTacService::onIDReceived(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TicTacService::onPlayerListRetrieved(const QList<Player*> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TicTacService::onPlayerChallenged(int _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
