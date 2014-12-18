/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#ifndef _linuxmon_common_macros_H_
#define _linuxmon_common_macros_H_

#include <cstring>

namespace linuxmon {

// TODO wyrugowac uzycia EB_STRING (speed) (przerobic loggery)
#define EB_STRING(e) (((std::stringstream&)(((std::stringstream()).flush())<<e)).str())
#define EB_STRING_C(e) ((EB_STRING(e)).c_str())
#define EB_FILE_LOCATION      "["<<__FILE__<<":"<<__LINE__<<" "<<__FUNCTION__<<"] "

#define EB_ERROR(e)                     \
{                                       \
    linuxmon::ApplicationLogger::getInstance().logError(__FILE__, __LINE__, __FUNCTION__, (EB_STRING(e)));    \
}
#define EB_WARNING(e)                   \
{                                       \
    linuxmon::ApplicationLogger::getInstance().logWarning(__FILE__, __LINE__, __FUNCTION__, (EB_STRING(e)));    \
}
#define EB_INFO(e)                      \
{                                       \
    linuxmon::ApplicationLogger::getInstance().logInfo(__FILE__, __LINE__, __FUNCTION__, (EB_STRING(e)));    \
}
#define EB_DEBUG(e)                     \
{                                       \
    linuxmon::ApplicationLogger::getInstance().logDebug(__FILE__, __LINE__, __FUNCTION__, (EB_STRING(e)));    \
}

#define EB_TRACE                        \
{                                       \
    linuxmon::ApplicationLogger::getInstance().logDebug(__FILE__, __LINE__, __FUNCTION__, "");    \
}

#define EB_TRACE_MSG(e)                 \
{                                       \
    linuxmon::ApplicationLogger::getInstance().logDebug(__FILE__, __LINE__, __FUNCTION__, (EB_STRING(e)));    \
}

#define EB_NEW(p,e)                     \
{                                       \
    linuxmon::MemoryManager::getInstance().registerNew(__FILE__, __LINE__); \
    p = new e;                          \
}

#define EB_NEW_ARRAY(p,e,sz)            \
{                                       \
    linuxmon::MemoryManager::getInstance().registerNewArray(__FILE__, __LINE__); \
    p = new e[sz];                      \
}

#define EB_DELETE(p)                    \
{                                       \
    linuxmon::MemoryManager::getInstance().registerDelete(__FILE__, __LINE__); \
    delete p;                           \
    p = NULL;                           \
}

#define EB_DELETE_VALUE(p)              \
{                                       \
    linuxmon::MemoryManager::getInstance().registerDelete(__FILE__, __LINE__); \
    delete p;                           \
}

#define EB_DELETE_ARRAY(p)              \
{                                       \
    linuxmon::MemoryManager::getInstance().registerDeleteArray(__FILE__, __LINE__); \
    delete [] p;                        \
    p = NULL;                           \
}

#define EB_THROW_OBJ(e)                 \
{                                       \
    throw e;                            \
}

#define EB_THROW(t)                     \
{                                       \
    t e;                                \
    e.setFileName(__FILE__);            \
    e.setFunctionName(__FUNCTION__);    \
    e.setLineNumber(__LINE__);          \
    throw e;                            \
}

#define EB_THROW_ARGS(t,args)           \
{                                       \
    t e(args);                          \
    e.setFileName(__FILE__);            \
    e.setFunctionName(__FUNCTION__);    \
    e.setLineNumber(__LINE__);          \
    throw e;                            \
}

#define EB_THROW_STREAM(t,s)            \
{                                       \
    TStringStream ss;                   \
    ss << s;                            \
    EB_THROW_ARGS(t,ss.str());          \
}

#define EB_MEMCPY(dest,src,sz)          \
{                                       \
    memcpy(dest,src,sz);                \
}

#define EB_MEMZERO(p,sz)                \
{                                       \
    memset(p,0,sz);                     \
}

};

#endif
