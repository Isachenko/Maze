#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this->ui->actionOpen, SIGNAL(triggered()), SLOT(handleOpenAction()));
}


void MainWindow::setFieldView(Ptr(FieldView) fieldView)
{
    _viewField = fieldView;
    this->ui->fieldlLayout->addWidget(_viewField.data());
}

void MainWindow::setMoveView(Ptr(MooveWidget) moveView)
{
    _moveWidget = moveView;
    this->ui->moveLayout->addWidget(_moveWidget.data());
}

MainWindow::~MainWindow()
{
    _viewField->setParent(nullptr);
    delete ui;
}

void MainWindow::handleOpenAction()
{
    QString fileName = QFileDialog::getOpenFileName(this,
         tr("Open Maze"), "~/", tr("Maze Files (*.maze)"));
    emit openFileTrigered(fileName);
}
