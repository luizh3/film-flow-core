#ifndef SYNCTASK_H
#define SYNCTASK_H

#include <functional>

#include <film-flow-core/film-flow-core_global.h>

class FILMFLOWCORE_EXPORT SyncTask {
public:
    static void runSync( std::function<void()> callBack );
};

#endif // SYNCTASK_H
