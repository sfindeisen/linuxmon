/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-30 (SF): initial version
 */

#ifndef _linuxmon_pthreads_LockHolder_H_
#define _linuxmon_pthreads_LockHolder_H_

#include <boost/noncopyable.hpp>

#include "../misc/SynchronizedObject.h"
#include "PThreadsMutex.h"

namespace linuxmon {

/**
 * PThreadsMutex lock holder. New instance acquires the lock immediately
 * and releases it on destruction (RAII).
 */
class LockHolder : public boost::noncopyable {
    public:
        LockHolder(PThreadsMutex& lk);
        LockHolder(SynchronizedObject& obj);

        virtual ~LockHolder();

    private:
        PThreadsMutex& lk;
};

};

#endif
