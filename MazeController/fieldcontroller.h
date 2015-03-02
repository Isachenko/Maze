#ifndef FIELDCONTROLLER_H
#define FIELDCONTROLLER_H

#include <QObject>
#include <QtWidgets/QWidget>

#include "mazecommon.h"
#include "Field/field.h"
#include "fieldview.h"

class FieldController : public QObject
{
    Q_OBJECT
public:
    explicit FieldController(QObject *parent = 0);
    ~FieldController();

private:
    Field _modelField;
    Ptr(FieldView) _viewField;

public:
    void openModel(const QString &fileName);

    virtual void initView(Ptr(FieldView) fieldView);



signals:

public slots:
    void updateView();
};

#endif // FIELDCONTROLLER_H
