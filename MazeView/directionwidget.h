#ifndef DIRECTIONWIDGET_H
#define DIRECTIONWIDGET_H

#include <QtWidgets/QWidget>

namespace Ui {
class DirectionWidget;
}

class DirectionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DirectionWidget(QWidget *parent = 0);
    ~DirectionWidget();

private:
    Ui::DirectionWidget *ui;

private:
    void paintEvent(QPaintEvent *event);
};

#endif // DIRECTIONWIDGET_H
