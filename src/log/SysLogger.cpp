/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#include "../throwable/error/DoubleInitializationError.h"
#include "../throwable/error/NotInitializedError.h"
#include "../throwable/error/NonExhaustiveMatchError.h"
#include "../utils/TextUtils.h"
#include "SysLogger.h"

using namespace std;
using namespace linuxmon;

SysLogger& SysLogger::getInstance()
{
    if (! (isInstanceInitialized())) {
        EB_THROW(NotInitializedError);
    } else {
        return (*instance);
    }
}

SysLogger& SysLogger::getInstance(const linuxmon::TString& ident, const TFacility& fac)
{
    if (! (isInstanceInitialized())) {
        LockHolder lk(getInstanceLock());
        if (! (isInstanceInitialized())) {
            EB_NEW(instance, SysLogger(ident, fac));
        }
        return *instance;
    } else {
        EB_THROW(DoubleInitializationError);
    }
}

SysLogger::SysLogger()
    : AbstractLogger(), AbstractSingletonTemplate<SysLogger>()
{
    EB_THROW(NotInitializedError);
}

SysLogger::SysLogger(const linuxmon::TString& ident, const TFacility& fac)
    : AbstractSingletonTemplate<SysLogger>()
{
    this->identStr = TextUtils::getInstance().duplicateString(ident);
    openlog(identStr, LOG_PID, eb2posix(fac));
}

SysLogger::~SysLogger() {
    if (identStr) {
        EB_DELETE_ARRAY(identStr);
        identStr = NULL;
    }
}

int SysLogger::eb2posix(const TFacility& fac) const {
    switch (fac) {
        case SYSLOG_AUTHPRIV:
            return LOG_AUTHPRIV;
        case SYSLOG_DAEMON:
            return LOG_DAEMON;
        case SYSLOG_USER:
            return LOG_USER;
        default:
            EB_THROW(NonExhaustiveMatchError);
    }
}
