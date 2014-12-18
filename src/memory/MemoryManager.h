/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#ifndef _linuxmon_memory_MemoryManager_H_
#define _linuxmon_memory_MemoryManager_H_

#include <iostream>
#include <map>

#include <boost/noncopyable.hpp>

#include "../misc/SynchronizedObject.h"

namespace linuxmon {

/**
 * Memory management for the library.
 *
 * Implementation note:
 *
 * You have to be careful about logging in this class, because logging uses
 * singleton, singleton uses EB_NEW and EB_NEW uses MemoryManager.
 */
class MemoryManager :
    public boost::noncopyable,
    public linuxmon::SynchronizedObject
{
    public:
        static void           printMemoryInfo();
        static MemoryManager& getInstance();

        virtual ~MemoryManager();

        void registerNew        (const TString& fileName, int line);
        void registerNewArray   (const TString& fileName, int line);
        void registerDelete     (const TString& fileName, int line);
        void registerDeleteArray(const TString& fileName, int line);

        virtual TString asString();

    protected:
        void   registerCall(std::map<TString,std::map<int,bigint> >& cmap, const TString& fileName, int line);
        void   printMap(std::ostream& ss, const std::map<TString,std::map<int,bigint> >& cmap) const;

        /** This is NOT synchronized. */
        bigint sumCalls(const std::map<TString,std::map<int,bigint> >& cmap) const;
        /** This is NOT synchronized. */
        bigint sumCalls(const std::map<TString,std::map<int,bigint> >& cmap, const TString& fileName) const;

    private:
        static MemoryManager* instance;
        static bool           instanceOK;
        static PThreadsMutex  instanceLock;

        MemoryManager();

        std::map<TString,std::map<int,bigint> > callsNew;
        std::map<TString,std::map<int,bigint> > callsNewArray;
        std::map<TString,std::map<int,bigint> > callsDelete;
        std::map<TString,std::map<int,bigint> > callsDeleteArray;
};

inline void MemoryManager::registerNew(const TString& fileName, int line) {
    registerCall(callsNew, fileName, line);
}
inline void MemoryManager::registerNewArray(const TString& fileName, int line) {
    registerCall(callsNewArray, fileName, line);
}
inline void MemoryManager::registerDelete(const TString& fileName, int line) {
    registerCall(callsDelete, fileName, line);
}
inline void MemoryManager::registerDeleteArray(const TString& fileName, int line) {
    registerCall(callsDeleteArray, fileName, line);
}

};

#endif
