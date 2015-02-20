#ifndef ROBOT_H
#define ROBOT_H

#include <Qt>
#include <QPointF>

class Robot
{
private:
    qreal size;
    quint32 sensorsCount;

public:
    Robot();
    ~Robot();

};

#endif // ROBOT_H
