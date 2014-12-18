/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#ifndef _linuxmon_log_AbstractLogger_H_
#define _linuxmon_log_AbstractLogger_H_

#include "../misc/SynchronizedObject.h"
#include "../throwable/error/NonExhaustiveMatchError.h"
#include "../common-defs.h"
#include "../common-macros.h"

namespace linuxmon {

/** A base logger class. */
class AbstractLogger
      /** We inherit from SynchronizedObject to allow logging from multiple threads. */
    : public linuxmon::SynchronizedObject
{
    public:
        typedef enum {
            LogDebug,
            LogInfo,
            LogWarning,
            LogError
        } TLogLevel;

        virtual ~AbstractLogger();

        virtual void logDebug  (const TString& fileName, int line, const TString& funcName, const TString& msg);
        virtual void logInfo   (const TString& fileName, int line, const TString& funcName, const TString& msg);
        virtual void logWarning(const TString& fileName, int line, const TString& funcName, const TString& msg);
        virtual void logError  (const TString& fileName, int line, const TString& funcName, const TString& msg);

        virtual void log(const TLogLevel& level, const TString& fileName, int line, const TString& funcName, const TString& msg);

    protected:
        static const TString SBLevel_DEBUG;
        static const TString SBLevel_INFO;
        static const TString SBLevel_WARNING;
        static const TString SBLevel_ERROR;

        static const TString SWLevel_DEBUG;
        static const TString SWLevel_INFO;
        static const TString SWLevel_WARNING;
        static const TString SWLevel_ERROR;

        AbstractLogger();

        virtual void log_basic(const TLogLevel& level, const TString& fileName, int line, const TString& funcName, const TString& msg) =0;

        /** basic string */
        virtual const TString& level2stringB(const TLogLevel& level) const;
        /** wide string */
        virtual const TString& level2stringW(const TLogLevel& level) const;
};

inline void AbstractLogger::logDebug(const TString& fileName, int line, const TString& funcName, const TString& msg) {
    log(LogDebug, fileName, line, funcName, msg);
}
inline void AbstractLogger::logInfo   (const TString& fileName, int line, const TString& funcName, const TString& msg) {
    log(LogInfo, fileName, line, funcName, msg);
}
inline void AbstractLogger::logWarning(const TString& fileName, int line, const TString& funcName, const TString& msg) {
    log(LogWarning, fileName, line, funcName, msg);
}
inline void AbstractLogger::logError  (const TString& fileName, int line, const TString& funcName, const TString& msg) {
    log(LogError, fileName, line, funcName, msg);
}

/** TODO optimize this */
inline const TString& AbstractLogger::level2stringB(const TLogLevel& level) const {
    switch (level) {
        case LogDebug:
            return SBLevel_DEBUG;
        case LogInfo:
            return SBLevel_INFO;
        case LogWarning:
            return SBLevel_WARNING;
        case LogError:
            return SBLevel_ERROR;
        default:
            EB_THROW(NonExhaustiveMatchError);
    }
}

/** TODO optimize this */
inline const TString& AbstractLogger::level2stringW(const TLogLevel& level) const {
    switch (level) {
        case LogDebug:
            return SWLevel_DEBUG;
        case LogInfo:
            return SWLevel_INFO;
        case LogWarning:
            return SWLevel_WARNING;
        case LogError:
            return SWLevel_ERROR;
        default:
            EB_THROW(NonExhaustiveMatchError);
    }
}

};

#endif
