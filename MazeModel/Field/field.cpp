#include "field.h"

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
    pos = pos;
    robot = robot;
}

