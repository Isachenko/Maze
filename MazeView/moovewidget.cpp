#include "moovewidget.h"
#include "ui_moovewidget.h"

MooveWidget::MooveWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MooveWidget),
    directionWidget(new DirectionWidget)
{
    ui->setupUi(this);
    ui->directionLayout->addWidget(directionWidget.data());
}

MooveWidget::~MooveWidget()
{
    directionWidget->setParent(nullptr);
    delete ui;
}
