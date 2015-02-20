#ifndef MAZEWIDGET_H
#define MAZEWIDGET_H

#include <QWidget>

namespace Ui {
class MazeWidget;
}

class MazeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MazeWidget(QWidget *parent = 0);
    ~MazeWidget();

private:
    Ui::MazeWidget *ui;
};

#endif // MAZEWIDGET_H
