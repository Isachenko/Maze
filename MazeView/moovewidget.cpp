#include "moovewidget.h"
#include "ui_moovewidget.h"

MooveWidget::MooveWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MooveWidget),
    _directionWidget(new DirectionWidget)
{
    ui->setupUi(this);
    ui->directionLayout->addWidget(_directionWidget.data());
    connect(_directionWidget.data(), SIGNAL(directionChangedByUser(double)), this, SIGNAL(robotDirectionChangedByUser(double)));
    connect(this->ui->goForwardButton, SIGNAL(clicked()), this, SIGNAL(goForwardClicked()));
    connect(this->ui->goBackButton, SIGNAL(clicked()), this, SIGNAL(goBackClicked()));
}

MooveWidget::~MooveWidget()
{
    _directionWidget->setParent(nullptr);
    delete ui;
}

void MooveWidget::handleLaserValuesChanged(QVector<qreal> laserValues, qreal maxValue)
{
    _directionWidget->setLasersValues(laserValues);
    _directionWidget->setLaserMax(maxValue);
    _directionWidget->update();
}
