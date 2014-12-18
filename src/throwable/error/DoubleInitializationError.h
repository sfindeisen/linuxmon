/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#ifndef _linuxmon_throwable_error_DoubleInitializationError_H_
#define _linuxmon_throwable_error_DoubleInitializationError_H_

#include "EBLogicError.h"

namespace linuxmon {

class DoubleInitializationError : public linuxmon::EBLogicError {
    public:
        DoubleInitializationError();
        virtual ~DoubleInitializationError() throw();

        virtual TString getName() const;
};

inline TString DoubleInitializationError::getName() const {
    return "linuxmon::DoubleInitializationError";
}

};

#endif
