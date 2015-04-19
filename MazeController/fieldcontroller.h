#ifndef FIELDCONTROLLER_H
#define FIELDCONTROLLER_H

#include <QObject>
#include <QtWidgets/QWidget>

#include "mazecommon.h"
#include "Field/field.h"
#include "fieldview.h"
#include <QTimer>
#include "mazecontroller_global.h"

class MAZECONTROLLERSHARED_EXPORT FieldController : public QObject
{
    Q_OBJECT
public:
    explicit FieldController(QObject *parent = 0);
    ~FieldController();

private:
    Field _modelField;
    bool isModelInited = false;
    Ptr(FieldView) _viewField;
    QTimer _playTimer;


public:
    void openModel(const QString &fileName);

    virtual void initView(Ptr(FieldView) fieldView);
signals:
    void laserValuesChanged(QVector<qreal> laserValues, qreal maxVaue);

public slots:
    void updateView();
    void handleRobotDirectionChangedByUser(double direction);
    void handleRobotGoForwardClicked();
    void handleRobotGoBackClicked();
    void play();
    void pause();
    void moveRoboByTimer();
};

#endif // FIELDCONTROLLER_H
