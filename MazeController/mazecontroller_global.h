#ifndef MAZECONTROLLER_GLOBAL_H
#define MAZECONTROLLER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MAZECONTROLLER_LIBRARY)
#  define MAZECONTROLLERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define MAZECONTROLLERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // MAZECONTROLLER_GLOBAL_H
