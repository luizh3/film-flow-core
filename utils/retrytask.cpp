#include "retrytask.h"

void RetryTask::exec( std::function<bool ()> callBack, const int nrMaxRetry ) {

    int nrRetry = 0;
    bool isSuccess = true;

    do {

        isSuccess = callBack();
        nrRetry++;

    } while ( !isSuccess && nrRetry <= nrMaxRetry );

}
