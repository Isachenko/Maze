#include "fieldview.h"
#include "ui_fieldview.h"
#include "qmath.h"

FieldView::FieldView(QWidget *parent) :
    QWidget(parent)
{
}

FieldView::~FieldView()
{
}
qreal FieldView::robotDirection() const
{
    return _robotDirection;
}

void FieldView::setRobotDirection(const qreal &robotDirection)
{
    _robotDirection = robotDirection;
}


void FieldView::    setSize(int sizeX, int sizeY)
{
    _sizeX = sizeX;
    _sizeY = sizeY;

}

QPoint FieldView::getScaled(const QPoint &point)
{
    qreal xScale = qreal(this->width()) / qreal(_sizeX);
    qreal yScale = qreal(this->height()) / qreal(_sizeY);
    return QPoint((point.x() * xScale), (point.y() * yScale));
}

int FieldView::getScaled(int value, bool byX)
{
    if (byX) {
        qreal xScale = qreal(this->width()) / qreal(_sizeX);
        return (value * xScale);
    } else {
        qreal yScale = qreal(this->height()) / qreal(_sizeY);
        return (value * yScale);
    }
}


void FieldView::setHedges(const QList<QRect> &hedges)
{
    _hedges = hedges;
}

void FieldView::setRobotSize(const qreal &robotSize)
{
    _robotSize = robotSize;
}

void FieldView::setRobotPosition(const QPoint &robotPosition)
{
    _robotPosition = robotPosition;
}


void FieldView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    //border
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::darkCyan, LINE_THICKNESS));
    painter.drawRect(QRect(0, 0, this->width(), this->height()));

    //robot
    painter.setPen(QPen(Qt::darkGreen, LINE_THICKNESS));
    QPoint robotCenter = getScaled(_robotPosition);
    painter.drawEllipse(robotCenter, getScaled(_robotSize, true),getScaled(_robotSize, false));
    painter.drawLine(robotCenter, robotCenter + getScaled(QPoint(_robotSize * qCos(_robotDirection), _robotSize * qSin(_robotDirection))));
}
