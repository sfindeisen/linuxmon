/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#ifndef _linuxmon_throwable_error_EBLogicError_H_
#define _linuxmon_throwable_error_EBLogicError_H_

#include <stdexcept>

#include "../EBThrowableTemplate.h"

namespace linuxmon {

typedef EBThrowableTemplate<std::logic_error> EBLogicError;

};

#endif
