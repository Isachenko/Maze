#-------------------------------------------------
#
# Project created by QtCreator 2015-02-17T10:36:08
#
#-------------------------------------------------

QT       -= gui

TARGET = MazeModel
TEMPLATE = lib

DEFINES += MAZEMODEL_LIBRARY

SOURCES += \
    Field/field.cpp \
    Field/hedge.cpp \
    Field/fieldfilemanager.cpp \
    Robot/robot.cpp \
    mainmodel.cpp

HEADERS +=\
        mazemodel_global.h \
    Field/field.h \
    Field/hedge.h \
    Field/fieldfilemanager.h \
    Robot/robot.h \
    mainmodel.h

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

#common
INCLUDEPATH += "../MazeCommon/"
LIBS += -L"$$OUTPUT_DIR/bin/" -lMazeCommon

QMAKE_CXXFLAGS += -std=c++11
