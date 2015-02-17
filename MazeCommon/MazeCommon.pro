#-------------------------------------------------
#
# Project created by QtCreator 2015-02-17T10:37:00
#
#-------------------------------------------------

QT       -= gui

TARGET = MazeCommon
TEMPLATE = lib

DEFINES += MAZECOMMON_LIBRARY

SOURCES += mazecommon.cpp

HEADERS += mazecommon.h\
        mazecommon_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
