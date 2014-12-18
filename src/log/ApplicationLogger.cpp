/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#include "ApplicationLogger.h"

using namespace std;
using namespace linuxmon;

ApplicationLogger::ApplicationLogger()
    : AbstractLogger(),
      AbstractSingletonTemplate<ApplicationLogger>(),
      cerrLogger(std::cerr),
      logFacilities(LogFacility_Default)
{
}

ApplicationLogger::~ApplicationLogger() {
}

void ApplicationLogger::log_basic(const AbstractLogger::TLogLevel& level, const TString& fileName, int line, const TString& funcName, const TString& msg) {
    if (LogFacility_STDERR & logFacilities)
        cerrLogger.log(level, fileName, line, funcName, msg);
    if (LogFacility_SYSLOG & logFacilities)
        SysLogger::getInstance().log(level, fileName, line, funcName, msg);
}
