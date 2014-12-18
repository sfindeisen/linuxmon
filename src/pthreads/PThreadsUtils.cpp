/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-29 (SF): initial version
 */

#include "PThreadsUtils.h"
#include "../common.h"

using namespace std;
using namespace linuxmon;

void PThreadsUtils::mutexattr_init(pthread_mutexattr_t* p) {
    int k = pthread_mutexattr_init(p);
    if (k)
        EB_THROW_STREAM(SystemException, "pthread_mutexattr_init: " << k);
}

void PThreadsUtils::mutexattr_destroy(pthread_mutexattr_t* p) {
    int k = pthread_mutexattr_destroy(p);
    if (k)
        EB_THROW_STREAM(SystemException, "pthread_mutexattr_destroy: " << k);
}

void PThreadsUtils::mutexattr_settype(pthread_mutexattr_t* p, int kind) {
    int k = pthread_mutexattr_settype(p, kind);
    if (k)
        EB_THROW_STREAM(SystemException, "pthread_mutexattr_settype: " << k);
}

void PThreadsUtils::mutex_init(pthread_mutex_t* p, const linuxmon::PThreadsMutexAttr& attr) {
    int k = pthread_mutex_init(p, attr.get());
    if (k)
        EB_THROW_STREAM(SystemException, "pthread_mutex_init: " << k);
}

void PThreadsUtils::mutex_destroy(pthread_mutex_t* p) {
    int k = pthread_mutex_destroy(p);
    if (k)
        EB_THROW_STREAM(SystemException, "pthread_mutex_destroy: " << k);
}

void PThreadsUtils::mutex_lock(pthread_mutex_t* p) {
    int k = pthread_mutex_lock(p);
    if (k)
        EB_THROW_STREAM(SystemException, "pthread_mutex_lock: " << k);
}

void PThreadsUtils::mutex_unlock(pthread_mutex_t* p) {
    int k = pthread_mutex_unlock(p);
    if (k)
        EB_THROW_STREAM(SystemException, "pthread_mutex_unlock: " << k);
}
