/****************************************************************************
** Meta object code from reading C++ file 'glwidget.h'
**
** Created: Tue Apr 3 13:57:19 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "glwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'glwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GLWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      23,    9,    9,    9, 0x0a,
      36,    9,    9,    9, 0x0a,
      51,   49,    9,    9, 0x0a,
      71,    9,    9,    9, 0x0a,
      88,    9,    9,    9, 0x0a,
     103,    9,    9,    9, 0x0a,
     115,  113,    9,    9, 0x0a,
     133,    9,    9,    9, 0x0a,
     149,    9,    9,    9, 0x0a,
     165,    9,    9,    9, 0x0a,
     181,    9,    9,    9, 0x0a,
     200,    9,    9,    9, 0x0a,
     219,    9,    9,    9, 0x0a,
     238,    9,    9,    9, 0x0a,
     253,    9,    9,    9, 0x0a,
     268,    9,    9,    9, 0x0a,
     283,    9,    9,    9, 0x0a,
     296,    9,    9,    9, 0x0a,
     312,    9,    9,    9, 0x0a,
     329,    9,    9,    9, 0x0a,
     347,    9,    9,    9, 0x0a,
     362,    9,    9,    9, 0x0a,
     383,    9,    9,    9, 0x0a,
     403,    9,    9,    9, 0x0a,
     426,    9,    9,    9, 0x0a,
     448,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GLWidget[] = {
    "GLWidget\0\0getR(double)\0getG(double)\0"
    "getB(double)\0p\0set_projection(int)\0"
    "set_example(int)\0set_shine(int)\0"
    "animate()\0i\0mudaCorFundo(int)\0"
    "setEyeX(double)\0setEyeY(double)\0"
    "setEyeZ(double)\0setLookAtX(double)\0"
    "setLookAtY(double)\0setLookAtZ(double)\0"
    "setUpX(double)\0setUpY(double)\0"
    "setUpZ(double)\0loadsphere()\0setLeft(double)\0"
    "setRight(double)\0setBottom(double)\0"
    "setTop(double)\0setNearOrtho(double)\0"
    "setFarOrtho(double)\0setNearPerspec(double)\0"
    "setFarPerspec(double)\0setFovy(double)\0"
};

void GLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GLWidget *_t = static_cast<GLWidget *>(_o);
        switch (_id) {
        case 0: _t->getR((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->getG((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->getB((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->set_projection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->set_example((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->set_shine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->animate(); break;
        case 7: _t->mudaCorFundo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setEyeX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->setEyeY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->setEyeZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->setLookAtX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->setLookAtY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->setLookAtZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->setUpX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->setUpY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->setUpZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->loadsphere(); break;
        case 18: _t->setLeft((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: _t->setRight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: _t->setBottom((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 21: _t->setTop((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 22: _t->setNearOrtho((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 23: _t->setFarOrtho((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 24: _t->setNearPerspec((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 25: _t->setFarPerspec((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 26: _t->setFovy((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GLWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GLWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_GLWidget,
      qt_meta_data_GLWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GLWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GLWidget))
        return static_cast<void*>(const_cast< GLWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int GLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
