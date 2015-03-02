#ifndef FIELDVIEW_H
#define FIELDVIEW_H

#include <QtWidgets/QWidget>

namespace Ui {
class FieldView;
}

class FieldView : public QWidget
{
    Q_OBJECT

public:
    explicit FieldView(QWidget *parent = 0);
    ~FieldView();
private:
    QPoint _robotPosition = QPoint(0, 0);
    qreal _robotSizeX = 0;
    qreal _robotSizeY = 0;
    QList<QRect> _hedges;

    int _sizeX = 100;
    int _sizeY = 100;
private:
    int getScaled(int value, bool byX = true);

public:
    void setRobotPosition(const QPoint &robotPosition);

    void setRobotSize(const qreal &robotSize);

    void setHedges(const QList<QRect> &hedges);

    void setSize(int sizeX, int sizeY);
    QPoint getScaled(const QPoint &point);

protected:
    void paintEvent(QPaintEvent *event);

};

#endif // FIELDVIEW_H
