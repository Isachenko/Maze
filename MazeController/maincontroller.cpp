#include "maincontroller.h"



MainController::MainController(const Ptr(MainModel) &model, QObject *parent) :
    QObject(parent),
    _modelMain(model)
{

}

MainController::~MainController()
{

}

void MainController::setFieldController(const Ptr(FieldController) fieldController)
{
    _fieldController = fieldController;
}

void MainController::handleOpenMaze(const QString &fileName)
{
    if (!_fieldController.isNull()) {
        _fieldController->openModel(fileName);
    }
}

void MainController::initView(const Ptr(MainWindow) &view, const Ptr(FieldView) &viewField)
{    
    //FieldView
    _viewField = viewField;

    //main View
    _viewMain = view;
    _viewMain->setFieldView(_viewField);
    bool connected = connect(_viewMain.data(), SIGNAL(openFileTrigered(QString)), SLOT(handleOpenMaze(QString)));

    //move View
    _moveWidget = Ptr(MooveWidget)(new MooveWidget());
    _viewMain->setMoveView(_moveWidget);
    connected = connect(_moveWidget.data(), SIGNAL(robotDirectionChangedByUser(double)), _fieldController.data(), SLOT(handleRobotDirectionChangedByUser(double)));
    connected = connect(_moveWidget.data(), SIGNAL(goForwardClicked()), _fieldController.data(), SLOT(handleRobotGoForwardClicked()));
    connected = connect(_moveWidget.data(), SIGNAL(goBackClicked()), _fieldController.data(), SLOT(handleRobotGoBackClicked()));
    connected = connect(_fieldController.data(), SIGNAL(laserValuesChanged(QVector<qreal>,qreal)), _moveWidget.data(), SLOT(handleLaserValuesChanged(QVector<qreal>,qreal)));

    //PlayerPanel
    _playerPanel = Ptr(PlayerPanelWidget)(new PlayerPanelWidget());
    _viewMain->setPlayerPanel(_playerPanel);
    connected = connect(_playerPanel.data(), SIGNAL(playClicked()), _fieldController.data(), SLOT(play()));
    connected = connect(_playerPanel.data(), SIGNAL(pauseClicked()), _fieldController.data(), SLOT(pause()));

}

