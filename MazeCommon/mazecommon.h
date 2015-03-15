#ifndef MAZECOMMON_H
#define MAZECOMMON_H

#include "mazecommon_global.h"
#include <QSharedPointer>
#include "mazemath.h"

#define Ptr(x) QSharedPointer<x>

#define LINE_THICKNESS 2



class MAZECOMMONSHARED_EXPORT MazeCommon
{

public:
    MazeCommon();
};

#endif // MAZECOMMON_H
