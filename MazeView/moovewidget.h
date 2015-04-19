#ifndef MOOVEWIDGET_H
#define MOOVEWIDGET_H

#include "mazecommon.h"
#include "directionwidget.h"
#include "mazeview_global.h"

#include <QtWidgets/QWidget>

namespace Ui {
class MooveWidget;
}

class MAZEVIEWSHARED_EXPORT MooveWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MooveWidget(QWidget *parent = 0);
    ~MooveWidget();

private:
    Ui::MooveWidget *ui;
    Ptr(DirectionWidget) _directionWidget;

signals:
    void robotDirectionChangedByUser(double direction);
    void goForwardClicked();
    void goBackClicked();

public slots:
    void handleLaserValuesChanged(QVector<qreal> laserValues, qreal maxValue);

};

#endif // MOOVEWIDGET_H
