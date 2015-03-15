#include <QApplication>
#include <QPointer>
#include <QSharedPointer>

#include "mainwindow.h"
#include "maincontroller.h"
#include "mainmodel.h"
#include "mazecommon.h"
#include "Field/field.h"
#include "fieldcontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //field
    Ptr(FieldView) viewField(new FieldView);
    Ptr(FieldController) controllerField(new FieldController());
    controllerField->initView(viewField);

    //main
    Ptr(MainWindow) windowMain(new MainWindow());
    Ptr(MainModel) modelMain(new MainModel());
    MainController controllerMain(modelMain);
    controllerMain.setFieldController(controllerField);
    controllerMain.initView(windowMain, viewField);

    windowMain->show();

    return a.exec();
}
