#-------------------------------------------------
#
# Project created by QtCreator 2012-03-16T18:51:34
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = TrabShaders
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    light.cpp \
    material.cpp \
    camera.cpp \
    help.cpp \
    PCBCGSolver.cxx \
    IDSet.cxx \
    PointTool.cxx

HEADERS  += mainwindow.h \
    glwidget.h \
    light.h \
    material.h \
    camera.h \
    help.h \
    trackball.h \
    IDList.h \
    Polyhedron.h \
    PCBCGSolver.h \
    PointTool.h \
    IDSet.h \
    PolarList.h \
    Point3d.h \
    Point2d.h

FORMS    += mainwindow.ui \
    help.ui

OTHER_FILES += \
    fshader1.glsl \
    fshader3.glsl \
    fshader4.glsl \
    vshader1.glsl \
    vshader3.glsl \
    vshader4.glsl \
    sphere \
    vshader5.glsl \
    fshader5.glsl \
    vshader2.glsl \
    fshader2.glsl \
    fshader6.glsl \
    fshader7.glsl \
    fshader8.glsl \
    vshader6.glsl \
    vshader7.glsl \
    vshader8.glsl \
    fshader9.glsl \
    vshader9.glsl \
    fshader10.glsl \
    vshader10.glsl \
    fshader11.glsl \
    fshader12.glsl \
    vshader11.glsl \
    vshader12.glsl

RESOURCES += \
    resources.qrc
