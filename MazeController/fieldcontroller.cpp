#include "fieldcontroller.h"
#include "Field/fieldfilemanager.h"

FieldController::FieldController(QObject *parent)
{

}

FieldController::~FieldController()
{

}

void FieldController::openModel(const QString &fileName)
{
    _modelField = FieldFileManager::loadField(fileName);
    updateView();

}

void FieldController::updateView()
{
    if (_viewField) {
        _viewField->setRobotPosition(_modelField.getRobotPosition());
        _viewField->setRobotSize(_modelField.getRobot().size());
        _viewField->setSize(_modelField.width(), _modelField.height());

        _viewField->update();
    }

}

void FieldController::initView(Ptr(FieldView) fieldView)
{
    _viewField = fieldView;
}
