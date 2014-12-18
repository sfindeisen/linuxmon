/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#ifndef _linuxmon_throwable_runtime_IllegalArgumentException_H_
#define _linuxmon_throwable_runtime_IllegalArgumentException_H_

#include "EBRuntimeException.h"

namespace linuxmon {

class IllegalArgumentException : public linuxmon::EBRuntimeException {
    public:
        IllegalArgumentException();
        IllegalArgumentException(const char * msg);
        IllegalArgumentException(const std::string& msg);
        virtual ~IllegalArgumentException() throw();

        virtual TString getName() const;
};

inline TString IllegalArgumentException::getName() const {
    return "linuxmon::IllegalArgumentException";
}

};

#endif
