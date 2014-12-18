/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#ifndef _linuxmon_throwable_error_NotImplementedError_H_
#define _linuxmon_throwable_error_NotImplementedError_H_

#include "EBLogicError.h"

namespace linuxmon {

class NotImplementedError : public linuxmon::EBLogicError {
    public:
        NotImplementedError();
        virtual ~NotImplementedError() throw();

        virtual TString getName() const;
};

inline TString NotImplementedError::getName() const {
    return "linuxmon::NotImplementedError";
}

};

#endif
