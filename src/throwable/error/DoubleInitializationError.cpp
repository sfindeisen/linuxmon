/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#include "DoubleInitializationError.h"

using namespace std;
using namespace linuxmon;

DoubleInitializationError::DoubleInitializationError()
    : EBLogicError("Double initialization error!")
{
}

DoubleInitializationError::~DoubleInitializationError() throw ()
{
}
