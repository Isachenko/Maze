#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QSharedPointer>
#include "mainwindow.h"
#include "mainmodel.h"
#include "mazecommon.h"
#include "fieldcontroller.h"
#include "moovewidget.h"
#include "mazecontroller_global.h"

class MAZECONTROLLERSHARED_EXPORT MainController : public QObject
{
    Q_OBJECT
public:
    explicit MainController(const Ptr(MainModel) &model, QObject *parent = 0);
    ~MainController();

private:
    Ptr(MainWindow) _viewMain;
    Ptr(MainModel) _modelMain;
    Ptr(FieldController) _fieldController;
    Ptr(FieldView) _viewField;
    Ptr(MooveWidget) _moveWidget;
    Ptr(PlayerPanelWidget) _playerPanel;

public:
    virtual void initView(const Ptr(MainWindow) &view, const Ptr(FieldView) &viewField);
    virtual void setFieldController(const Ptr(FieldController) fieldController);

signals:

public slots:

private slots:
    void handleOpenMaze(const QString &fileName);
};

#endif // MAINCONTROLLER_H
