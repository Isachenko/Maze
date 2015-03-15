#include "directionwidget.h"
#include "ui_directionwidget.h"

#include <QPainter>
#include <qmath.h>
#include <QMouseEvent>
#include "mazecommon.h"

DirectionWidget::DirectionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DirectionWidget)
{
    ui->setupUi(this);
    this->setFixedHeight(150);
    this->setFixedWidth(150);
}

DirectionWidget::~DirectionWidget()
{
    delete ui;
}

void DirectionWidget::setLaserMax(const qreal &laserMax)
{
    _laserMax = laserMax;
}


void DirectionWidget::setLasersValues(const QVector<qreal> &lasersValues)
{
    _lasersValues = lasersValues;
}


double DirectionWidget::direction() const
{
    return _direction;
}

void DirectionWidget::setDirection(double direction, bool byUser)
{
    _direction = direction;
    if (byUser) {
        emit directionChangedByUser(_direction);
    }
}


void DirectionWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen(QBrush(Qt::darkGreen), LINE_THICKNESS);
    painter.setPen(pen);
    qreal rx = this->width() / 2;
    qreal ry = this->height() / 2;
    qreal smallRx = rx / 2;
    qreal smallRy = ry / 2;
    QPointF robotCenter(rx, ry);
    //border
    painter.drawRect(0, 0, this->width(), this->height());

    //visibleZone
    painter.drawEllipse(robotCenter, rx - LINE_THICKNESS, ry- LINE_THICKNESS);
    //robot
    pen = QPen(QBrush(Qt::darkGreen), LINE_THICKNESS);
    painter.setPen(pen);
    painter.drawEllipse(robotCenter, smallRx - LINE_THICKNESS, smallRy- LINE_THICKNESS);
    painter.drawLine(robotCenter, robotCenter + QPointF((smallRx - LINE_THICKNESS) * qCos(_direction), (smallRy - LINE_THICKNESS) * qSin(_direction)));

    //lasers
    painter.setPen(QPen(QBrush(Qt::red), LINE_THICKNESS));
    int lasersCount = _lasersValues.size();
    if (lasersCount > 0) {
        qreal r = rx;
        int i = 0;
        foreach (qreal lasersValue, _lasersValues) {
            qreal laserDirection = _direction + i * (2 * M_PI / lasersCount);
            QPointF laserStart = robotCenter + QPointF((smallRx - LINE_THICKNESS) * qCos(laserDirection), (smallRy - LINE_THICKNESS) * qSin(laserDirection));
            qreal scaledLaserValue = lasersValue / _laserMax * r;
            QPointF laserEnd = robotCenter + QPointF(scaledLaserValue * qCos(laserDirection), scaledLaserValue * qSin(laserDirection));
            painter.drawLine(laserStart, laserEnd);
            ++i;
        }
    }


}

void DirectionWidget::mousePressEvent(QMouseEvent *e)
{
    QPointF pos =  e->pos();

    int rx = this->width() / 2;
    int ry = this->height() / 2;

    double direction = qAtan2((pos.y() - ry), (pos.x() - rx));
    setDirection(direction, true);
    this->update();

}
