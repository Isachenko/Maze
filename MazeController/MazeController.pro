#-------------------------------------------------
#
# Project created by QtCreator 2015-02-17T10:35:45
#
#-------------------------------------------------

QT       -= gui

TARGET = MazeController
TEMPLATE = lib

DEFINES += MAZECONTROLLER_LIBRARY

SOURCES += \
    maincontroller.cpp \
    fieldcontroller.cpp

HEADERS +=\
        mazecontroller_global.h \
    maincontroller.h \
    fieldcontroller.h

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

#model
INCLUDEPATH += "../MazeModel/"
LIBS += -L"$$OUTPUT_DIR/bin/" -lMazeModel
#view
INCLUDEPATH += "../MazeView/"
LIBS += -L"$$OUTPUT_DIR/bin/" -lMazeView
#common
INCLUDEPATH += "../MazeCommon/"
LIBS += -L"$$OUTPUT_DIR/bin/" -lMazeCommon

QMAKE_CXXFLAGS += -std=c++11
