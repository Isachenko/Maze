#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QString>

#include "fieldview.h"
#include "mazecommon.h"
#include "moovewidget.h"
#include "playerpanelwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Ptr(FieldView) _viewField;
    Ptr(MooveWidget) _moveWidget;
    Ptr(PlayerPanelWidget) _playerPanel;

public:
    void setFieldView(Ptr(FieldView) fieldView);
    void setMoveView(Ptr(MooveWidget) moveView);
    void setPlayerPanel(Ptr(PlayerPanelWidget) playerPanel);

public slots:
    void handleOpenAction();

signals:
    void openFileTrigered(const QString &fileName);
};

#endif // MAINWINDOW_H
