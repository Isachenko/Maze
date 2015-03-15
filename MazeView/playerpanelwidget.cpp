#include "playerpanelwidget.h"
#include "ui_playerpanelwidget.h"

#include <QPalette>

PlayerPanelWidget::PlayerPanelWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerPanelWidget)
{
    ui->setupUi(this);
    ui->playButton->setStyleSheet("background-color: green");
    ui->pauseButton->setStyleSheet("background-color: #FFAAAA");

    connect(this->ui->playButton, SIGNAL(clicked()), this, SIGNAL(playClicked()));
    connect(this->ui->pauseButton, SIGNAL(clicked()), this, SIGNAL(pauseClicked()));
}

PlayerPanelWidget::~PlayerPanelWidget()
{
    delete ui;
}
