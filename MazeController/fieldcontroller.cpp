#include "fieldcontroller.h"
#include "Field/fieldfilemanager.h"
#include <QtMath>
#include <cmath>

#define PLAY_INTERVAL 500

FieldController::FieldController(QObject *parent)
{
    _playTimer.setInterval(PLAY_INTERVAL);
    connect(&_playTimer, SIGNAL(timeout()), this, SLOT(moveRoboByTimer()));
}

FieldController::~FieldController()
{

}

void FieldController::openModel(const QString &fileName)
{
    _modelField = FieldFileManager::loadField(fileName);
    _viewField->initModel(&_modelField);
    _viewField->setSize();
    isModelInited=true;
    updateView();

}

void FieldController::updateView()
{
    if (_viewField) {
        _viewField->update();
    }
    emit laserValuesChanged(_modelField.getRobot().lasetValues(), _modelField.getRobot().laserLenght());
}

void FieldController::handleRobotDirectionChangedByUser(double direction)
{
    if (isModelInited) {
        _modelField.setRobotDirection(direction);
        updateView();
    }
}

void FieldController::handleRobotGoForwardClicked()
{
    if (isModelInited) {
        _modelField.moveRobotForward();
        updateView();
    }

}

void FieldController::handleRobotGoBackClicked()
{
    if (isModelInited) {
        _modelField.moveRobotBack();
        updateView();
    }

}

void FieldController::play()
{
    _playTimer.start();
}

void FieldController::pause()
{
    _playTimer.stop();

}

void FieldController::moveRoboByTimer()
{
    _modelField.moveRobotSmart();
    updateView();
}

void FieldController::initView(Ptr(FieldView) fieldView)
{
    _viewField = fieldView;
}
