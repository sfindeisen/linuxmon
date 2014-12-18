/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#ifndef _linuxmon_throwable_error_NonExhaustiveMatchError_H_
#define _linuxmon_throwable_error_NonExhaustiveMatchError_H_

#include "EBLogicError.h"

namespace linuxmon {

class NonExhaustiveMatchError : public linuxmon::EBLogicError {
    public:
        NonExhaustiveMatchError();
        virtual ~NonExhaustiveMatchError() throw();

        virtual TString getName() const;
};

inline TString NonExhaustiveMatchError::getName() const {
    return "linuxmon::NonExhaustiveMatchError";
}

};

#endif
