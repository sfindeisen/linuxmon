/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#include "../throwable/error/DoubleInitializationError.h"
#include "../throwable/error/NotImplementedError.h"
#include "../throwable/error/NotInitializedError.h"
#include "../throwable/error/NonExhaustiveMatchError.h"
#include "../utils/TextUtils.h"
#include "StreamLogger.h"

using namespace std;
using namespace linuxmon;

StreamLogger::StreamLogger(std::ostream& s)
    : AbstractLogger(), os(s)
{
}

StreamLogger::~StreamLogger() {
}

void StreamLogger::log_basic(const AbstractLogger::TLogLevel& level, const TString& fileName, int line, const TString& funcName, const TString& msg) {
    os << (level2stringW(level)) << " " << fileName << ":" << line << " " << funcName << ": " << msg << std::endl;
}
