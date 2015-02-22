#ifndef FIELD_H
#define FIELD_H

#include <QList>
#include <QPointF>

#include "hedge.h"
#include "Robot/robot.h"

class Field
{
private:
    QList<Hedge> _hedges;
    Robot _robot;
    QPoint _robotPosition;

    int _height = 0;
    int _width = 0;

public:
    Field();
    Field(int height, int width);
    ~Field();

public:
    void appendHedge(Hedge &&hedge);
    void setRobot(QPoint &&pos, Robot &&robot);
};

#endif // FIELD_H
