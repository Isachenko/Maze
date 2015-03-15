#ifndef ROBOT_H
#define ROBOT_H

#include <Qt>
#include <QVector>
#include <QPointF>

class Robot
{
private:
    int _size = 0;
    int _lasersCount = 16;
    qreal _laserLenght = 40;
    QVector<qreal> _laserValues;


public:
    Robot(int size);
    Robot();
    ~Robot();

    int size() const;
    void setSize(int size);
    int sensorsCount() const;
    void setSensorsCount(int sensorsCount);
    qreal laserLenght() const;
    void setLaserLenght(const qreal &laserLenght);
    const QVector<qreal> &lasetValues() const;
    void setLasetValues(const QVector<qreal> &lasetValues);
    void setLaserValue(int index, qreal value);
    int lasersCount() const;
    void setLasersCount(int lasersCount);

    qreal getMoveDirection();
};

#endif // ROBOT_H
