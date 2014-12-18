/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-29 (SF): initial version
 */

#ifndef _linuxmon_misc_SynchronizedObject_H_
#define _linuxmon_misc_SynchronizedObject_H_

#include "../pthreads/PThreadsMutex.h"

namespace linuxmon {

/** A mutex wrapper. */
class SynchronizedObject {
    public:
        virtual void   lock();
        virtual void unlock();

        virtual PThreadsMutex& getMutex();

    protected:
        SynchronizedObject();
        virtual ~SynchronizedObject();

    private:
        PThreadsMutex lk;
};

inline void SynchronizedObject::lock() {
    lk.lock();
}
inline void SynchronizedObject::unlock() {
    lk.unlock();
}
inline PThreadsMutex& SynchronizedObject::getMutex() {
    return lk;
}

};

#endif
