#ifndef FIELDFILEMANAGER_H
#define FIELDFILEMANAGER_H

#include <QString>

#include "field.h"
#include "hedge.h"
#include "../mazemodel_global.h"

class MAZEMODELSHARED_EXPORT FieldFileManager
{
public:
    FieldFileManager();
    ~FieldFileManager();

    static Field loadField(const QString &fileName);
    static bool saveField(const QString &fileName);
    static Field &&generate(QPointF size);

};

#endif // FIELDFILEMANAGER_H
