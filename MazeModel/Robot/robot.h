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

    int size() const;
    void setSize(int size);
    int sensorsCount() const;
    void setSensorsCount(int sensorsCount);
};

#endif // ROBOT_H
