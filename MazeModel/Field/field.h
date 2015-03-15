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
    QPointF _robotPosition;
    double _robotDirection = 0;

    int _width = 0;
    int _height = 0;

    int _dMove = 3;

public:
    Field();
    Field(int height, int width);
    ~Field();
    
private:
    static qreal range(QPointF a, QPointF b);
    bool isPosAvailabile(QPointF x);

public:
    void appendHedge(Hedge &&hedge);
    void setRobot(QPointF &&pos, Robot &&robot);
    void moveRobotForward();
    void moveRobotBack();
    void moveRobotSmart();
    void moveInTheDirection(qreal direction);
    void calculateLaserValues();

    const QList<Hedge> &getHedges() const ;
    const Robot &getRobot() const ;
    QPointF getRobotPosition() const ;
    int width() const;
    void setWidth(int width);
    int height() const;
    void setHeight(int height);
    double robotDirection() const;
    void setRobotDirection(double robotDirection);
    QPointF robotPosition() const;
    void setRobotPosition(const QPointF &robotPosition);    

    QVector<QPointF> getLasersStarts();
    QVector<QPointF> getLasersEnds();
};

#endif // FIELD_H
