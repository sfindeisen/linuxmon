/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2011-04-24 (SF): initial version
 */

#ifndef _linuxmon_throwable_runtime_NumberFormatException_H_
#define _linuxmon_throwable_runtime_NumberFormatException_H_

#include "IllegalArgumentException.h"

namespace linuxmon {

class NumberFormatException : public linuxmon::IllegalArgumentException {
    public:
        NumberFormatException();
        NumberFormatException(const char * msg);
        NumberFormatException(const std::string& msg);
        virtual ~NumberFormatException() throw();

        virtual TString getName() const;
};

inline TString NumberFormatException::getName() const {
    return "linuxmon::NumberFormatException";
}

};

#endif
