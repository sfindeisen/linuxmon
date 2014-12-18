/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#ifndef _linuxmon_throwable_runtime_EBRuntimeException_H_
#define _linuxmon_throwable_runtime_EBRuntimeException_H_

#include <stdexcept>

#include "../EBThrowableTemplate.h"

namespace linuxmon {

typedef EBThrowableTemplate<std::runtime_error> EBRuntimeException;

};

#endif
