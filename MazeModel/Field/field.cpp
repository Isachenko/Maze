#include "field.h"


int Field::width() const
{
    return _width;
}

void Field::setWidth(int width)
{
    _width = width;
}

int Field::height() const
{
    return _height;
}

void Field::setHeight(int height)
{
    _height = height;
}
Field::Field()
{

}

Field::Field(int height, int width) :
    _height(height),
    _width(width)
{

}

Field::~Field()
{

}

void Field::appendHedge(Hedge &&hedge)
{
    _hedges.append(hedge);

}

void Field::setRobot(QPoint &&pos, Robot &&robot)
{
    _robotPosition = pos;
    _robot = robot;
}

const QList<Hedge> &Field::getHedges() const
{
    return _hedges;
}

const Robot &Field::getRobot() const
{
    return _robot;
}

QPoint Field::getRobotPosition() const
{
    return _robotPosition;
}

