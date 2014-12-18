/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-30 (SF): initial version
 */

#include "../throwable/EBAbstractThrowable.h"
#include "../common.h"
#include "LockHolder.h"

using namespace linuxmon;

LockHolder::LockHolder(PThreadsMutex& m) : lk(m) {
    lk.lock();
}

LockHolder::LockHolder(SynchronizedObject& obj) : lk(obj.getMutex()) {
    lk.lock();
}

LockHolder::~LockHolder() {
    try {
        lk.unlock();
    } catch (linuxmon::EBAbstractThrowable& e) {
        EB_ERROR(e);
    } catch (...) {
        EB_ERROR("unknown exception in LockHolder::~LockHolder");
    }
}
