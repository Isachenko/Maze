#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QString>

#include "fieldview.h"
#include "mazecommon.h"

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

public:
    void setFieldView(Ptr(FieldView) fieldView);

public slots:
    void handleOpenAction();

signals:
    void openFileTrigered(const QString &fileName);
};

#endif // MAINWINDOW_H
