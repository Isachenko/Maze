#ifndef FIELDVIEW_H
#define FIELDVIEW_H

#include <QtWidgets/QWidget>
#include "mazecommon.h"
#include <QVector>
#include "Field/field.h"

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
    Field* _fieldModel = nullptr;

    int _sizeX = 100;
    int _sizeY = 100;
private:
    int getScaled(int value, bool byX = true);
    QPointF getScaled(const QPointF &point);
    QRectF getScaled(const QRectF &rect);

public:
    virtual void initModel(Field* field);

    void setSize();

protected:
    void paintEvent(QPaintEvent *event);

};

#endif // FIELDVIEW_H
