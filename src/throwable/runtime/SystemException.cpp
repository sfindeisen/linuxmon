/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#include "SystemException.h"

using namespace std;
using namespace linuxmon;

SystemException::SystemException()
    : EBRuntimeException("system exception")
{
}

SystemException::SystemException(int k)
    : EBRuntimeException(EB_STRING("Error (" << k << "): " << strerror(k)))
{
}

SystemException::SystemException(const char * msg)
    : EBRuntimeException(msg)
{
}

SystemException::SystemException(const std::string& msg)
    : EBRuntimeException(msg)
{
}

SystemException::~SystemException() throw ()
{
}
