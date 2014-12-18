/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#include "NotImplementedError.h"

using namespace std;
using namespace linuxmon;

NotImplementedError::NotImplementedError()
    : EBLogicError("Not implemented!")
{
}

NotImplementedError::~NotImplementedError() throw ()
{
}
