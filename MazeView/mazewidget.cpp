#include "mazewidget.h"
#include "ui_mazewidget.h"

MazeWidget::MazeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MazeWidget)
{
    ui->setupUi(this);
}

MazeWidget::~MazeWidget()
{
    delete ui;
}
