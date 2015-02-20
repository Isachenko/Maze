#include "maincontroller.h"

MainController::MainController(QObject *parent) : QObject(parent)
{

}

MainController::~MainController()
{

}

void MainController::initView(MainWindow *view) :
    _view(view)
{


}

