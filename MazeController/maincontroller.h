#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include "mainwindow.h"

class MainController : public QObject
{
    Q_OBJECT
public:
    explicit MainController(QObject *parent = 0);
    ~MainController();
    MainWindow *_view;

public:
    void initView(MainWindow *view);

signals:

public slots:
};

#endif // MAINCONTROLLER_H
