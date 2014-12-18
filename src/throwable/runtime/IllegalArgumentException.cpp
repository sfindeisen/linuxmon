/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#include "IllegalArgumentException.h"

using namespace std;
using namespace linuxmon;

IllegalArgumentException::IllegalArgumentException()
    : EBRuntimeException("illegal argument exception")
{
}

IllegalArgumentException::IllegalArgumentException(const char * msg)
    : EBRuntimeException(msg)
{
}

IllegalArgumentException::IllegalArgumentException(const std::string& msg)
    : EBRuntimeException(msg)
{
}

IllegalArgumentException::~IllegalArgumentException() throw ()
{
}
