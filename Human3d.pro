#-------------------------------------------------
#
# Project created by QtCreator 2021-02-05T16:00:19
#
#-------------------------------------------------

QT       += core gui
QT       += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Human3dApp
TEMPLATE = app

DESTDIR = $$PWD/bin

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    stlfileloader.cpp \
    rrglwidget.cpp \
    humangl.cpp \
    sensorloader.cpp \
    rotateparameterform.cpp

HEADERS  += mainwindow.h \
    stlfileloader.h \
    rrglwidget.h \
    humangl.h \
    sensorloader.h \
    rotateparameterform.h

FORMS    += mainwindow.ui \
    rotateparameterform.ui

DISTFILES +=

LIBS += -lglut -lGLU


RESOURCES += \
    images.qrc

