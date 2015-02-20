#ifndef FIELDFILEMANAGER_H
#define FIELDFILEMANAGER_H

#include <QString>

#include "field.h"
#include "hedge.h"

class FieldFileManager
{
public:
    FieldFileManager();
    ~FieldFileManager();

    static Field loadField(const QString &fileName);
    static Field saveField(const QString &fileName);

};

#endif // FIELDFILEMANAGER_H