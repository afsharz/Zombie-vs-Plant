/****************************************************************************
** Meta object code from reading C++ file 'plantscene.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../plantscene.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plantscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSPlantSceneENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSPlantSceneENDCLASS = QtMocHelpers::stringData(
    "PlantScene",
    "AddedToVector",
    "",
    "type",
    "Zombiewin",
    "Plantwin",
    "Sun_Maker",
    "AddedToVecc",
    "ZombieWin",
    "UpdateTimer",
    "PlantWin"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPlantSceneENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       4,    0,   65,    2, 0x06,    3 /* Public */,
       5,    0,   66,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   67,    2, 0x0a,    5 /* Public */,
       7,    1,   68,    2, 0x0a,    6 /* Public */,
       8,    0,   71,    2, 0x0a,    8 /* Public */,
       9,    0,   72,    2, 0x0a,    9 /* Public */,
      10,    0,   73,    2, 0x0a,   10 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject PlantScene::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_CLASSPlantSceneENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPlantSceneENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPlantSceneENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PlantScene, std::true_type>,
        // method 'AddedToVector'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'Zombiewin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Plantwin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Sun_Maker'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'AddedToVecc'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'ZombieWin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'UpdateTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'PlantWin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void PlantScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlantScene *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->AddedToVector((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->Zombiewin(); break;
        case 2: _t->Plantwin(); break;
        case 3: _t->Sun_Maker(); break;
        case 4: _t->AddedToVecc((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->ZombieWin(); break;
        case 6: _t->UpdateTimer(); break;
        case 7: _t->PlantWin(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlantScene::*)(QString );
            if (_t _q_method = &PlantScene::AddedToVector; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PlantScene::*)();
            if (_t _q_method = &PlantScene::Zombiewin; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PlantScene::*)();
            if (_t _q_method = &PlantScene::Plantwin; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *PlantScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlantScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPlantSceneENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int PlantScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void PlantScene::AddedToVector(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PlantScene::Zombiewin()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PlantScene::Plantwin()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
