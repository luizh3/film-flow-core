#ifndef RETRYTASK_H
#define RETRYTASK_H

#include <functional>

#include <film-flow-core/film-flow-core_global.h>

class FILMFLOWCORE_EXPORT RetryTask {
public:
    static void exec( std::function<bool()> callBack, const int nrMaxRetry = 5 );
};

#endif // RETRYTASK_H
