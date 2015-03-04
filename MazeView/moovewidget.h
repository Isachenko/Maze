#ifndef MOOVEWIDGET_H
#define MOOVEWIDGET_H

#include "mazecommon.h"
#include "directionwidget.h"

#include <QtWidgets/QWidget>

namespace Ui {
class MooveWidget;
}

class MooveWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MooveWidget(QWidget *parent = 0);
    ~MooveWidget();

private:
    Ui::MooveWidget *ui;
    Ptr(DirectionWidget) directionWidget;

};

#endif // MOOVEWIDGET_H
