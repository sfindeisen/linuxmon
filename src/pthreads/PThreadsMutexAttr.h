/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-29 (SF): initial version
 */

#ifndef _linuxmon_pthreads_PThreadsMutexAttr_H_
#define _linuxmon_pthreads_PThreadsMutexAttr_H_

#include <pthread.h>

#include <boost/noncopyable.hpp>

#include "../common-defs.h"

namespace linuxmon {

/** pthread_mutexattr_t wrapper (PTHREAD_MUTEX_NORMAL by default). */
class PThreadsMutexAttr : boost::noncopyable {
    public:
        PThreadsMutexAttr();
        virtual ~PThreadsMutexAttr();

        virtual const pthread_mutexattr_t* get() const;

    private:
        pthread_mutexattr_t attr;
};

inline const pthread_mutexattr_t* PThreadsMutexAttr::get() const {
    return &attr;
}

};

#endif
