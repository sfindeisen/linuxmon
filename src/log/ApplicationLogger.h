/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#ifndef _linuxmon_log_ApplicationLogger_H_
#define _linuxmon_log_ApplicationLogger_H_

#include "StreamLogger.h"
#include "SysLogger.h"

namespace linuxmon {

/** ApplicationLogger is a singleton. */
class ApplicationLogger :
    public linuxmon::AbstractLogger,
    public AbstractSingletonTemplate<ApplicationLogger>
{
    public:
        static const int LogFacility_SYSLOG  = 0x01;
        static const int LogFacility_STDERR  = 0x02;
        static const int LogFacility_Default = LogFacility_STDERR;

        virtual ~ApplicationLogger();

        virtual void configure(const int logFacilities);

    protected:
        virtual void log_basic(const AbstractLogger::TLogLevel& level, const TString& fileName, int line, const TString& funcName, const TString& msg);

    private:
        friend class AbstractSingletonTemplate<ApplicationLogger>;
        ApplicationLogger();

        StreamLogger cerrLogger;
        int          logFacilities;
};

inline void ApplicationLogger::configure(const int lfmask) {
    LockHolder lk(*this);

    if (LogFacility_SYSLOG & lfmask) {
        // init SysLogger...
        // TODO make this configurable!
        SysLogger::getInstance("linuxmon", SysLogger::SYSLOG_USER);
    }
    logFacilities = lfmask;
}

};

#endif
