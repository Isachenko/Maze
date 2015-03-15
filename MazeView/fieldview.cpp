#include "fieldview.h"
#include "ui_fieldview.h"
#include "qmath.h"
#include "Field/hedge.h"

FieldView::FieldView(QWidget *parent) :
    QWidget(parent)
{
}

FieldView::~FieldView()
{
}

void FieldView::setSize()
{
    _sizeX = _fieldModel->width();
    _sizeY = _fieldModel->height();

}

QPointF FieldView::getScaled(const QPointF &point)
{
    qreal xScale = qreal(this->width()) / qreal(_sizeX);
    qreal yScale = qreal(this->height()) / qreal(_sizeY);
    return QPointF((point.x() * xScale), (point.y() * yScale));
}

QRectF FieldView::getScaled(const QRectF &rect)
{
    qreal xScale = qreal(this->width()) / qreal(_sizeX);
    qreal yScale = qreal(this->height()) / qreal(_sizeY);
    return QRectF(rect.left() * xScale, rect.top() * yScale, rect.width() * xScale, rect.height() * yScale);
}

void FieldView::initModel(Field *field)
{
    _fieldModel = field;
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


void FieldView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //border
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::darkCyan, LINE_THICKNESS));
    painter.drawRect(QRectF(0, 0, this->width(), this->height()));

    if (_fieldModel) {
        //robot
        painter.setPen(QPen(Qt::darkGreen, LINE_THICKNESS));
        QPointF robotCenter = getScaled(_fieldModel->getRobotPosition());
        int robotSize = _fieldModel->getRobot().size();
        painter.drawEllipse(robotCenter, getScaled(robotSize, true),getScaled(robotSize, false));
        qreal robotDirection = _fieldModel->robotDirection();
        painter.drawLine(robotCenter, robotCenter + getScaled(QPointF(robotSize * qCos(robotDirection), robotSize * qSin(robotDirection))));

        //hedges
        painter.setBrush(QBrush(Qt::black));
        foreach(const Hedge &hedge, _fieldModel->getHedges()) {
            painter.fillRect(getScaled(hedge.recatangle()), Qt::darkRed);
        }

        painter.setPen(QPen(Qt::red, LINE_THICKNESS));
        //lasers
        int i = 0;
        QVector<QPointF> laserEnds = _fieldModel->getLasersEnds();
        foreach(const QPointF &laserStart, _fieldModel->getLasersStarts()) {
            painter.drawLine(QLineF(getScaled(laserStart), getScaled(laserEnds.at(i))));
            ++i;
        }
    }
}
