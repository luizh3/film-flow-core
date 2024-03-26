#ifndef FILMFLOWCORE_GLOBAL_H
#define FILMFLOWCORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(FILMFLOWCORE_LIBRARY)
#define FILMFLOWCORE_EXPORT Q_DECL_EXPORT
#else
#define FILMFLOWCORE_EXPORT Q_DECL_IMPORT
#endif

#endif // FILMFLOWCORE_GLOBAL_H
