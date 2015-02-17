#-------------------------------------------------
#
# Project created by QtCreator 2015-02-17T10:35:45
#
#-------------------------------------------------

QT       -= gui

TARGET = MazeController
TEMPLATE = lib

DEFINES += MAZECONTROLLER_LIBRARY

SOURCES += mazecontroller.cpp \
    maincontroller.cpp

HEADERS += mazecontroller.h\
        mazecontroller_global.h \
    maincontroller.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
