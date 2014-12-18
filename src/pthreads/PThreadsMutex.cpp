/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-29 (SF): initial version
 */

#include "PThreadsUtils.h"
#include "PThreadsMutex.h"
#include "../common.h"

using namespace linuxmon;

PThreadsMutex::PThreadsMutex() : boost::noncopyable() {
    PThreadsMutexAttr attr;
    PThreadsUtils::mutex_init(&lk, attr);
}

PThreadsMutex::~PThreadsMutex() {
    try {
        PThreadsUtils::mutex_destroy(&lk);
    } catch (linuxmon::EBAbstractThrowable& e) {
        EB_ERROR(e);
    } catch (...) {
        EB_ERROR("unknown exception in PThreadsMutex::~PThreadsMutex");
    }
}
