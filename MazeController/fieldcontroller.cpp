#include "fieldcontroller.h"

FieldController::FieldController(QPointer<Field> &&modelFiled, QObject *parent) :
    QObject(parent),
    _modelField(modelFiled)
{

}

FieldController::~FieldController()
{

}

