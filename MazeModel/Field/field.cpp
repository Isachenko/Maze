#include "field.h"

#include <qmath.h>

#include "mazecommon.h"

#define EPS 0.00000001


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

double Field::robotDirection() const
{
    return _robotDirection;
}

void Field::setRobotDirection(double robotDirection)
{
    _robotDirection = robotDirection;
    calculateLaserValues();
}

QPointF Field::robotPosition() const
{
    return _robotPosition;
}

void Field::setRobotPosition(const QPointF &robotPosition)
{
    _robotPosition = robotPosition;
}

QVector<QPointF> Field::getLasersStarts()
{
    QVector<QPointF> lasersStart;
    for(int i = 0; i < _robot.lasersCount(); ++i) {
        qreal laserDirection = (_robotDirection) + i * (2 * M_PI / _robot.lasersCount());
        QPointF laserStart = _robotPosition + QPointF(_robot.size() * qCos(laserDirection), _robot.size() * qSin(laserDirection));
        lasersStart.append(laserStart);
    }
    return lasersStart;
}

QVector<QPointF> Field::getLasersEnds()
{
    QVector<QPointF> lasersEnds;
    int i = 0;
    foreach (qreal laserValue, _robot.lasetValues()) {
        qreal laserDirection = (_robotDirection) + i * (2 * M_PI / _robot.lasersCount());
        QPointF laserEnd = _robotPosition + QPointF(laserValue * qCos(laserDirection), laserValue * qSin(laserDirection));
        lasersEnds.append(laserEnd);
        ++i;
    }
    return lasersEnds;

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

qreal Field::range(QPointF a, QPointF b)
{
    qreal dx = (a.x() - b.x());
    qreal dy = (a.y() - b.y());
    qreal ans = qSqrt((dx*dx) + (dy*dy));
    return ans;
}

bool Field::isPosAvailabile(QPointF x)
{
}

void Field::appendHedge(Hedge &&hedge)
{
    _hedges.append(hedge);

}

void Field::setRobot(QPointF &&pos, Robot &&robot)
{
    _robotPosition = pos;
    _robot = robot;
}

void Field::moveRobotForward()
{
    moveInTheDirection(_robotDirection);
}

void Field::moveRobotBack()
{
    qreal reverseDiresction = _robotDirection + M_PI;    
    moveInTheDirection(reverseDiresction);
}

void Field::moveRobotSmart()
{
    setRobotDirection(_robotDirection + _robot.getMoveDirection());
    moveInTheDirection(_robotDirection);
}

void Field::moveInTheDirection(qreal direction)
{
    qreal dx = _dMove * qCos(direction);
    qreal dy = _dMove * qSin(direction);

    _robotPosition += QPointF(dx, dy);

    calculateLaserValues();
}

void Field::calculateLaserValues()
{
    int lasersCount = _robot.sensorsCount();
    qreal laserLenght = _robot.laserLenght();
    qreal dAlpha = 2 * M_PI / lasersCount;

    QList<qreal> lasersLenght;

    for(int i = 0; i < lasersCount; ++i){
        MazeMath::point robotPos = {_robotPosition.x(), _robotPosition.y()};
        qreal angel = (2 * M_PI) * ((qreal)i / (qreal)lasersCount) + _robotDirection;
        MazeMath::point laserEndPoint = {(laserLenght * qCos(angel)) + _robotPosition.x(), (laserLenght * qSin(angel)) + _robotPosition.y()};
        foreach (const Hedge &hedge, _hedges) {
            MazeMath::rect rect = {hedge.recatangle().left(), hedge.recatangle().top(), hedge.recatangle().right(), hedge.recatangle().bottom()};
            MazeMath::point a = robotPos;
            MazeMath::point b = laserEndPoint;
            bool isInside = true;
            if(-1 == MazeMath::cohenSutherland(&rect, &a, &b)) {
                isInside = false;
            }
            if (isInside) {
                qreal arange = range(QPointF(a.x, a.y), QPointF(robotPos.x, robotPos.y));
                qreal brange = range(QPointF(b.x, b.y), QPointF(robotPos.x, robotPos.y));
                if ((arange < brange) && (arange > EPS)) {
                    laserEndPoint = a;
                } else {
                    laserEndPoint = b;
                }
            }
        }
        _robot.setLaserValue(i, range(QPointF(robotPos.x, robotPos.y), QPointF(laserEndPoint.x, laserEndPoint.y)));
    }


}

const QList<Hedge> &Field::getHedges() const
{
    return _hedges;
}

const Robot &Field::getRobot() const
{
    return _robot;
}

QPointF Field::getRobotPosition() const
{
    return _robotPosition;
}

