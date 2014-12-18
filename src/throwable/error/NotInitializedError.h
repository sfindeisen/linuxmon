/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#ifndef _linuxmon_throwable_error_NotInitializedError_H_
#define _linuxmon_throwable_error_NotInitializedError_H_

#include "EBLogicError.h"

namespace linuxmon {

class NotInitializedError : public linuxmon::EBLogicError {
    public:
        NotInitializedError();
        virtual ~NotInitializedError() throw();

        virtual TString getName() const;
};

inline TString NotInitializedError::getName() const {
    return "linuxmon::NotInitializedError";
}

};

#endif
