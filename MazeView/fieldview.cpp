#include "fieldview.h"
#include "ui_fieldview.h"

FieldView::FieldView(QWidget *parent) :
    QWidget(parent)
{
}

FieldView::~FieldView()
{
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
    _robotSizeX = robotSize;
    _robotSizeY = robotSize;
}

void FieldView::setRobotPosition(const QPoint &robotPosition)
{
    _robotPosition = robotPosition;
}


void FieldView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::darkCyan);
    painter.drawRect(QRect(0, 0, this->width(), this->height()));

    //robot
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::darkGreen);
    painter.drawEllipse((getScaled(_robotPosition)), getScaled(_robotSizeX, true),getScaled(_robotSizeY, false));
}
