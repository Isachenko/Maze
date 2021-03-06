#-------------------------------------------------
#
# Project created by QtCreator 2015-02-17T10:35:15
#
#-------------------------------------------------

QT       += widgets

TARGET = MazeView
TEMPLATE = lib

DEFINES += MAZEVIEW_LIBRARY

SOURCES += \
    mainwindow.cpp \
    mazewidget.cpp \
    fieldview.cpp \
    moovewidget.cpp \
    directionwidget.cpp \
    playerpanelwidget.cpp

HEADERS +=\
        mazeview_global.h \
    mainwindow.h \
    mazewidget.h \
    fieldview.h \
    moovewidget.h \
    directionwidget.h \
    playerpanelwidget.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    mainwindow.ui \
    mazewidget.ui \
    moovewidget.ui \
    directionwidget.ui \
    playerpanelwidget.ui

CONFIG(debug, debug|release): {
OUTPUT_DIR = "$$PWD/../../buildMaze/debug"
} else: {
OUTPUT_DIR = "$$PWD/../../buildMaze/release"
}

#common
INCLUDEPATH += "../MazeCommon/"
LIBS += -L"$$OUTPUT_DIR/bin/" -lMazeCommon
#model
INCLUDEPATH += "../MazeModel/"
LIBS += -L"$$OUTPUT_DIR/bin/" -lMazeModel

UI_DIR = "$$OUTPUT_DIR/ui/"
MOC_DIR = "$$OUTPUT_DIR/moc/"
RCC_DIR = "$$OUTPUT_DIR/res/"
DESTDIR = "$$OUTPUT_DIR/bin/"
OBJECTS_DIR = "$$OUTPUT_DIR/obj/"

QMAKE_CXXFLAGS += -std=c++11
