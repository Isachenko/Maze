#ifndef ROBOT_H
#define ROBOT_H

#include <Qt>

class Robot
{
private:
    int _size = 0;
    int _sensorsCount = 4;

public:
    Robot(int size);
    Robot();
    ~Robot();

};

#endif // ROBOT_H
