/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#ifndef _linuxmon_throwable_runtime_SystemException_H_
#define _linuxmon_throwable_runtime_SystemException_H_

#include "EBRuntimeException.h"

namespace linuxmon {

class SystemException : public linuxmon::EBRuntimeException {
    public:
        SystemException();
        SystemException(int errno_);
        SystemException(const char * msg);
        SystemException(const std::string& msg);
        virtual ~SystemException() throw();

        virtual TString getName() const;
};

inline TString SystemException::getName() const {
    return "linuxmon::SystemException";
}

};

#endif
