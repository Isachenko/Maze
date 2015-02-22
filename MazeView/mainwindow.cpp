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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleOpenAction()
{
    QString fileName = QFileDialog::getOpenFileName(this,
         tr("Open Image"), "~/", tr("Image Files (*.maze)"));
    emit openFileTrigered(fileName);
}
