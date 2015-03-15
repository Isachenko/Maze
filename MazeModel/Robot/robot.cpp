#include "robot.h"

#define EPS 2

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
    return _lasersCount;
}

void Robot::setSensorsCount(int sensorsCount)
{
    _lasersCount = sensorsCount;
}

qreal Robot::laserLenght() const
{
    return _laserLenght;
}

void Robot::setLaserLenght(const qreal &laserLenght)
{
    _laserLenght = laserLenght;
}

const QVector<qreal> &Robot::lasetValues() const
{
    return _laserValues;
}

void Robot::setLasetValues(const QVector<qreal> &lasetValues)
{
    _laserValues = lasetValues;
}

void Robot::setLaserValue(int index, qreal value)
{
    _laserValues[index] = value;
}


int Robot::lasersCount() const
{
    return _lasersCount;
}

void Robot::setLasersCount(int lasersCount)
{
    _lasersCount = lasersCount;
}

//functon, where robot should use its mind
qreal Robot::getMoveDirection()
{
    qreal maxLaserValue = -1;
    int maxLaserIndex = 0;
    int i = 0;
    foreach(qreal value, _laserValues){
        if (value > (maxLaserValue + EPS)) {
            maxLaserValue = value;
            maxLaserIndex = i;
        }
        ++i;
    }
    qreal moveDirection = maxLaserIndex * (2 * M_PI / _lasersCount);
    return moveDirection;
}

Robot::Robot(int size) :
    _size(size)
{
    for(int i = 0; i < _lasersCount; ++i) {
        _laserValues.append(_laserLenght);
    }
    
}

Robot::Robot()
{
    
}

Robot::~Robot()
{
    
}

