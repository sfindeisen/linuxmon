/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-29 (SF): initial version
 */

#ifndef _linuxmon_pthreads_PThreadsMutex_H_
#define _linuxmon_pthreads_PThreadsMutex_H_

#include <pthread.h>

#include <boost/noncopyable.hpp>

#include "PThreadsUtils.h"
#include "../common-defs.h"

namespace linuxmon {

/** pthread_mutex_t wrapper (PTHREAD_MUTEX_NORMAL). */
class PThreadsMutex : boost::noncopyable {
    public:
        PThreadsMutex();
        virtual ~PThreadsMutex();

        virtual void   lock();
        virtual void unlock();

    private:
        pthread_mutex_t lk;
};

inline void PThreadsMutex::lock() {
    PThreadsUtils::mutex_lock(&lk);
}
inline void PThreadsMutex::unlock() {
    PThreadsUtils::mutex_unlock(&lk);
}

};

#endif
