/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#ifndef _linuxmon_log_SysLogger_H_
#define _linuxmon_log_SysLogger_H_

#include <syslog.h>

#include "AbstractLogger.h"
#include "../misc/AbstractSingletonTemplate.h"

namespace linuxmon {

class SysLogger :
    public linuxmon::AbstractLogger,
    public AbstractSingletonTemplate<SysLogger>
{
    public:
        typedef enum {
            SYSLOG_AUTHPRIV, SYSLOG_DAEMON, SYSLOG_USER
        } TFacility;

        static SysLogger& getInstance();
        static SysLogger& getInstance(const linuxmon::TString& ident, const TFacility& facility);

        virtual ~SysLogger();

    protected:
        virtual int eb2posix(const TFacility& fac) const;
        virtual int level2priority(const TLogLevel& level) const;

        virtual void log_basic(const AbstractLogger::TLogLevel& level, const TString& fileName, int line, const TString& funcName, const TString& msg);

    private:
        SysLogger();
        SysLogger(const linuxmon::TString& ident, const TFacility& facility);

        /** This is used by syslog facility... */
        const char* identStr;
};

/** TODO optimize this */
inline int SysLogger::level2priority(const TLogLevel& level) const {
    switch (level) {
        case LogDebug:
            return LOG_DEBUG;
        case LogInfo:
            return LOG_INFO;
        case LogWarning:
            return LOG_WARNING;
        case LogError:
            return LOG_ERR;
        default:
            EB_THROW(NonExhaustiveMatchError);
    }
}

/** The actual syslog call. */
inline void SysLogger::log_basic(const AbstractLogger::TLogLevel& level, const TString& fileName, int line, const TString& funcName, const TString& msg) {
    syslog(level2priority(level), "%s", (EB_STRING_C((level2stringB(level)) << " " << fileName << ":" << line << " " << funcName << ": " << msg)));
}

};

#endif
