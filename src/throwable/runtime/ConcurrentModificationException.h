/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-09-08 (SF): initial version
 */

#ifndef _linuxmon_throwable_runtime_ConcurrentModificationException_H_
#define _linuxmon_throwable_runtime_ConcurrentModificationException_H_

#include "EBRuntimeException.h"

namespace linuxmon {

class ConcurrentModificationException : public linuxmon::EBRuntimeException {
    public:
        ConcurrentModificationException();
        ConcurrentModificationException(const char * msg);
        ConcurrentModificationException(const std::string& msg);
        virtual ~ConcurrentModificationException() throw();

        virtual TString getName() const;
};

inline TString ConcurrentModificationException::getName() const {
    return "linuxmon::ConcurrentModificationException";
}

};

#endif
