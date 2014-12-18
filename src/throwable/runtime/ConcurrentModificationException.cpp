/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#include "ConcurrentModificationException.h"

using namespace std;
using namespace linuxmon;

ConcurrentModificationException::ConcurrentModificationException()
    : EBRuntimeException("concurrent modification exception")
{
}

ConcurrentModificationException::ConcurrentModificationException(const char * msg)
    : EBRuntimeException(msg)
{
}

ConcurrentModificationException::ConcurrentModificationException(const std::string& msg)
    : EBRuntimeException(msg)
{
}

ConcurrentModificationException::~ConcurrentModificationException() throw ()
{
}
