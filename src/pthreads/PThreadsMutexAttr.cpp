/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-29 (SF): initial version
 */

#include "PThreadsMutexAttr.h"
#include "PThreadsUtils.h"
#include "../common.h"

using namespace linuxmon;

PThreadsMutexAttr::PThreadsMutexAttr() : boost::noncopyable() {
    PThreadsUtils::mutexattr_init   (&attr);
    PThreadsUtils::mutexattr_settype(&attr, PTHREAD_MUTEX_NORMAL);
}

PThreadsMutexAttr::~PThreadsMutexAttr() {
    try {
        PThreadsUtils::mutexattr_destroy(&attr);
    } catch (linuxmon::EBAbstractThrowable& e) {
        EB_ERROR(e);
    } catch (...) {
        EB_ERROR("unknown exception in PThreadsMutexAttr::~PThreadsMutexAttr");
    }
}
