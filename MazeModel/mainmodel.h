#ifndef MAINMODEL_H
#define MAINMODEL_H

#include "mazecommon.h"
#include "Field/field.h"
#include "mazemodel_global.h"

class MAZEMODELSHARED_EXPORT MainModel
{
public:
    MainModel();
    ~MainModel();
private:
    Ptr(Field) _field;
public:
    Ptr(Field) getField();
};

#endif // MAINMODEL_H
