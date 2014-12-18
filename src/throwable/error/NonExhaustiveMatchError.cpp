/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#include "NonExhaustiveMatchError.h"

using namespace std;
using namespace linuxmon;

NonExhaustiveMatchError::NonExhaustiveMatchError()
    : EBLogicError("Non-exhaustive match!")
{
}

NonExhaustiveMatchError::~NonExhaustiveMatchError() throw ()
{
}
