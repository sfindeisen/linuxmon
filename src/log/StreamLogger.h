/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#ifndef _linuxmon_log_StreamLogger_H_
#define _linuxmon_log_StreamLogger_H_

#include "AbstractLogger.h"

namespace linuxmon {

class StreamLogger : public linuxmon::AbstractLogger {
    public:
        StreamLogger(std::ostream& os);
        virtual ~StreamLogger();

    protected:
        virtual void log_basic(const AbstractLogger::TLogLevel& level, const TString& fileName, int line, const TString& funcName, const TString& msg);

    private:
        std::ostream& os;
};

};

#endif
