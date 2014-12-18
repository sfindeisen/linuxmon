/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-29 (SF): initial version
 */

#ifndef _linuxmon_pthreads_PThreadsUtils_H_
#define _linuxmon_pthreads_PThreadsUtils_H_

#include <pthread.h>

#include "PThreadsMutexAttr.h"

namespace linuxmon {

class PThreadsUtils  {
    public:
        static void mutexattr_init   (pthread_mutexattr_t* p);
        static void mutexattr_destroy(pthread_mutexattr_t* p);
        static void mutexattr_settype(pthread_mutexattr_t* p, int kind);

        static void mutex_init   (pthread_mutex_t* p, const linuxmon::PThreadsMutexAttr& attr);
        static void mutex_destroy(pthread_mutex_t* p);
        static void mutex_lock   (pthread_mutex_t* p);
        static void mutex_unlock (pthread_mutex_t* p);
};

};

#endif
