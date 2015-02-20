#ifndef FIELD_H
#define FIELD_H

#include <QList>
#include <QPointF>

#include "hedge.h"
#include "robot.h"

class Field
{
private:
    QList<Hedge> _hedges;
    Robot _robot;
    QPointF _robotPosition;

    qreal _height;
    qreal _width;

public:
    Field();
    ~Field();
};

#endif // FIELD_H
