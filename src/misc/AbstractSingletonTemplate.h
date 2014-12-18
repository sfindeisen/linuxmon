/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#ifndef _linuxmon_misc_AbstractSingletonTemplate_H_
#define _linuxmon_misc_AbstractSingletonTemplate_H_

#include <pthread.h>

#include <iostream>
#include <typeinfo>

#include <boost/noncopyable.hpp>

#include "../memory/MemoryManager.h"
#include "../pthreads/LockHolder.h"
#include "../pthreads/PThreadsUtils.h"
#include "../throwable/runtime/SystemException.h"

namespace linuxmon {

/** A synchronized singleton pattern. */
template <class T> class AbstractSingletonTemplate : public boost::noncopyable {
    public:
        static T& getInstance();
        virtual ~AbstractSingletonTemplate();

    protected:
        static bool           isInstanceInitialized();
        static PThreadsMutex& getInstanceLock();

        AbstractSingletonTemplate();

        static T* instance;

    private:
        /** Basic instance initialization. No synchronisation here! */
        static void initInstance();

        /** Instance is initialized. We use this instead of (NULL != instance) for atomicity. */
        static bool          instanceOK;
        static PThreadsMutex instanceLock;
};

template <class T> T*            AbstractSingletonTemplate<T>::instance     = NULL;
template <class T> bool          AbstractSingletonTemplate<T>::instanceOK   = FALSE;
template <class T> PThreadsMutex AbstractSingletonTemplate<T>::instanceLock;

template <class T> AbstractSingletonTemplate<T>::AbstractSingletonTemplate()
    : boost::noncopyable()
{
}

template <class T> AbstractSingletonTemplate<T>::~AbstractSingletonTemplate()
{
}

template <class T> inline bool AbstractSingletonTemplate<T>::isInstanceInitialized() {
    return instanceOK;
}

template <class T> void AbstractSingletonTemplate<T>::initInstance() {
    EB_NEW(instance, T());
    instanceOK = TRUE;
}

template <class T> T& AbstractSingletonTemplate<T>::getInstance() {
    if (! (isInstanceInitialized())) {
        LockHolder lk(instanceLock);
        if (! (isInstanceInitialized()))
            initInstance();
    }

    return *instance;
}

template <class T> inline PThreadsMutex& AbstractSingletonTemplate<T>::getInstanceLock() {
    return instanceLock;
}

};

#endif
