#-------------------------------------------------
#
# Project created by QtCreator 2015-02-17T10:35:15
#
#-------------------------------------------------

QT       += widgets

TARGET = MazeView
TEMPLATE = lib

DEFINES += MAZEVIEW_LIBRARY

SOURCES += mazeview.cpp \
    mainwindow.cpp

HEADERS += mazeview.h\
        mazeview_global.h \
    mainwindow.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    mainwindow.ui
