#ifndef PLAYERPANELWIDGET_H
#define PLAYERPANELWIDGET_H

#include <QtWidgets/QWidget>
#include "mazeview_global.h"

namespace Ui {
class PlayerPanelWidget;
}

class MAZEVIEWSHARED_EXPORT PlayerPanelWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerPanelWidget(QWidget *parent = 0);
    ~PlayerPanelWidget();

private:
    Ui::PlayerPanelWidget *ui;

signals:
    void playClicked();
    void pauseClicked();
};

#endif // PLAYERPANELWIDGET_H
