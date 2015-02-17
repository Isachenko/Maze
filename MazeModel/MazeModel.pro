#-------------------------------------------------
#
# Project created by QtCreator 2015-02-17T10:36:08
#
#-------------------------------------------------

QT       -= gui

TARGET = MazeModel
TEMPLATE = lib

DEFINES += MAZEMODEL_LIBRARY

SOURCES += mazemodel.cpp

HEADERS += mazemodel.h\
        mazemodel_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
