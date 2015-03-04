#include "directionwidget.h"
#include "ui_directionwidget.h"

#include <QPainter>
#include "mazecommon.h"

DirectionWidget::DirectionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DirectionWidget)
{
    ui->setupUi(this);
    //this->setFixedHeight(100);
    //this->setFixedWidth(100);
}

DirectionWidget::~DirectionWidget()
{
    delete ui;
}

void DirectionWidget::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    QPen pen(QBrush(Qt::darkGreen), LINE_THICKNESS);
    painter.setPen(pen);
    int rx = this->width() / 2;
    int ry = this->height() / 2;
    //visibleZone
    painter.drawEllipse(QPoint(rx, ry), rx - LINE_THICKNESS, ry- LINE_THICKNESS);
    //robot
    pen = QPen(QBrush(Qt::darkGreen), LINE_THICKNESS);
    painter.setPen(pen);
    painter.drawEllipse(QPoint(rx, ry), rx / 2 - LINE_THICKNESS, ry / 2 - LINE_THICKNESS);
}
