#ifndef FIELDCONTROLLER_H
#define FIELDCONTROLLER_H

#include <QObject>
#include <QtWidgets/QWidget>
#include "Field/field.h"
#include <QPointer>

class FieldController : public QObject
{
    Q_OBJECT
public:
    explicit FieldController(QPointer<Field> &&modelFiled, QObject *parent = 0);
    ~FieldController();

private:
    QPointer<Field> _modelField;



signals:

public slots:
};

#endif // FIELDCONTROLLER_H
