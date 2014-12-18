/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#include "NotInitializedError.h"

using namespace std;
using namespace linuxmon;

NotInitializedError::NotInitializedError()
    : EBLogicError("Not initialized!")
{
}

NotInitializedError::~NotInitializedError() throw ()
{
}
