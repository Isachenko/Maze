#ifndef MAZEWIDGET_H
#define MAZEWIDGET_H

#include <QWidget>
#include "mazeview_global.h"

namespace Ui {
class MazeWidget;
}

class MAZEVIEWSHARED_EXPORT MazeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MazeWidget(QWidget *parent = 0);
    ~MazeWidget();

private:
    Ui::MazeWidget *ui;
};

#endif // MAZEWIDGET_H
