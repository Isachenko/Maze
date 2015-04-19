#ifndef DIRECTIONWIDGET_H
#define DIRECTIONWIDGET_H

#include <QtWidgets/QWidget>
#include <QVector>
#include <QPointF>
#include "mazeview_global.h"

namespace Ui {
class MAZEVIEWSHARED_EXPORT DirectionWidget;
}

class DirectionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DirectionWidget(QWidget *parent = 0);
    ~DirectionWidget();

private:
    Ui::DirectionWidget *ui;
    double _direction;
    QVector<qreal> _lasersValues;
    qreal _laserMax;

public:
    double direction() const;
    void setDirection(double direction, bool byUser = false);

    void setLasersValues(const QVector<qreal> &lasersValues);

    void setLaserMax(const qreal &laserMax);

private:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent * e);

signals:
    void directionChangedByUser(double direction);
};

#endif // DIRECTIONWIDGET_H
