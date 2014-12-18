/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#include "MemoryManager.h"
#include "../pthreads/LockHolder.h"
#include "../pthreads/PThreadsUtils.h"
#include "../common.h"

using namespace std;
using namespace linuxmon;

MemoryManager* MemoryManager::instance     = NULL;
bool           MemoryManager::instanceOK   = FALSE;
PThreadsMutex  MemoryManager::instanceLock;

void MemoryManager::printMemoryInfo() {
    EB_DEBUG(MemoryManager::getInstance().asString());
}

MemoryManager& MemoryManager::getInstance() {
    if (! instanceOK) {
        LockHolder lk(instanceLock);

        if (! instanceOK) {
            instance   = new MemoryManager();
            instance->registerNew(__FILE__, __LINE__ - 1);
            instanceOK = TRUE;
        }
    }

    return *instance;
}

MemoryManager::MemoryManager()
    : boost::noncopyable(), SynchronizedObject()
{
}

MemoryManager::~MemoryManager() {
    EB_TRACE_MSG("MemoryManager: delete!");
    EB_TRACE_MSG(asString());
}

void MemoryManager::registerCall(map<TString,map<int,bigint> >& cmap, const TString& fileName, int line) {
    // TODO this locks the whole instance...
    LockHolder lk(*this);

    map<int,bigint>& fmap = cmap[fileName];
    if (fmap.end() == fmap.find(line))
        fmap.insert(pair<int,bigint>(line,0));
    fmap[line] += 1;
}

void MemoryManager::printMap(std::ostream& ss, const std::map<TString,std::map<int,bigint> >& cmap) const {
    map<TString,map<int,bigint> >::const_iterator it;
    map<int,bigint>::const_iterator fit;

    for (it = cmap.begin(); it != cmap.end(); ++it) {
        ss << "File " << (it->first) << ": " << sumCalls(cmap, it->first) << endl;
        for (fit = it->second.begin(); fit != (it->second.end()); ++fit) {
            ss << "     line " << (fit->first) << ": " << (fit->second) << endl;
        }
    }
}

bigint MemoryManager::sumCalls(const std::map<TString,map<int,bigint> >& cmap) const {
    map<TString,map<int,bigint> >::const_iterator it;
    map<int,bigint>::const_iterator fit;
    bigint callsTotal = 0;

    for (it = cmap.begin(); it != cmap.end(); ++it) {
        for (fit = it->second.begin(); (it->second.end()) != fit; ++fit) {
            callsTotal += (fit->second);
        }
    }

    return callsTotal;
}

bigint MemoryManager::sumCalls(const std::map<TString,map<int,bigint> >& cmap, const TString& fileName) const {
    map<TString,map<int,bigint> >::const_iterator it = cmap.find(fileName);
    bigint callsTotal = 0;

    if (cmap.end() != it) {
        for (map<int,bigint>::const_iterator fit = it->second.begin(); (it->second.end()) != fit; ++fit) {
            callsTotal += (fit->second);
        }
    }

    return callsTotal;
}

TString MemoryManager::asString() {
    TStringStream ss;
    LockHolder lk(*this);

    ss << "new calls: " << sumCalls(callsNew) << endl;
    printMap(ss, callsNew);
    ss << "new [] calls: " << sumCalls(callsNewArray) << endl;
    printMap(ss, callsNewArray);
    ss << "delete calls: " << sumCalls(callsDelete) << endl;
    printMap(ss, callsDelete);
    ss << "delete [] calls: " << sumCalls(callsDeleteArray) << endl;
    printMap(ss, callsDeleteArray);
    return ss.str();
}
