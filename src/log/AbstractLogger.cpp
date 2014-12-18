/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#include "../pthreads/LockHolder.h"
#include "../throwable/runtime/EBRuntimeException.h"
#include "AbstractLogger.h"

using namespace std;
using namespace linuxmon;

const TString AbstractLogger::SBLevel_DEBUG  ("[debug]");
const TString AbstractLogger::SBLevel_INFO   ("[info]");
const TString AbstractLogger::SBLevel_WARNING("[warning]");
const TString AbstractLogger::SBLevel_ERROR  ("[error]");

const TString AbstractLogger::SWLevel_DEBUG  ("[debug]  ");
const TString AbstractLogger::SWLevel_INFO   ("[info]   ");
const TString AbstractLogger::SWLevel_WARNING("[warning]");
const TString AbstractLogger::SWLevel_ERROR  ("[error]  ");

AbstractLogger::AbstractLogger() : SynchronizedObject() {
}

AbstractLogger::~AbstractLogger() {
}

void AbstractLogger::log(const TLogLevel& level, const TString& fileName, int line, const TString& funcName, const TString& msg) {
    LockHolder lk(*this);
    log_basic(level, fileName, line, funcName, msg);
}
