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

CONFIG(debug, debug|release): {
OUTPUT_DIR = "$$PWD/../../buildMaze/debug"
} else: {
OUTPUT_DIR = "$$PWD/../../buildMaze/release"
}

UI_DIR = "$$OUTPUT_DIR/ui/"
MOC_DIR = "$$OUTPUT_DIR/moc/"
RCC_DIR = "$$OUTPUT_DIR/res/"
DESTDIR = "$$OUTPUT_DIR/bin/"
OBJECTS_DIR = "$$OUTPUT_DIR/obj/"
