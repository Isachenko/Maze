#-------------------------------------------------
#
# Project created by QtCreator 2015-02-17T10:37:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MazeMain
TEMPLATE = app


SOURCES += main.cpp

HEADERS  +=

FORMS +=

LIBS +=


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
#controller
INCLUDEPATH += "../MazeController/"
LIBS += -L"$$OUTPUT_DIR/bin/" -lMazeController
#common
INCLUDEPATH += "../MazeCommon/"
LIBS += -L"$$OUTPUT_DIR/bin/" -lMazeCommon

QMAKE_CXXFLAGS += -std=c++11
