#include "robot.h"


int Robot::size() const
{
    return _size;
}

void Robot::setSize(int size)
{
    _size = size;
}

int Robot::sensorsCount() const
{
    return _sensorsCount;
}

void Robot::setSensorsCount(int sensorsCount)
{
    _sensorsCount = sensorsCount;
}
Robot::Robot(int size) :
    _size(size)
{
    
}

Robot::Robot()
{
    
}

Robot::~Robot()
{
    
}

