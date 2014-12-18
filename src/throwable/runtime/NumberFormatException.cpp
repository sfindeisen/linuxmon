/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2011-04-24 (SF): initial version
 */

#include "NumberFormatException.h"

using namespace std;
using namespace linuxmon;

NumberFormatException::NumberFormatException()
    : IllegalArgumentException("number format exception")
{
}

NumberFormatException::NumberFormatException(const char * msg)
    : IllegalArgumentException(msg)
{
}

NumberFormatException::NumberFormatException(const std::string& msg)
    : IllegalArgumentException(msg)
{
}

NumberFormatException::~NumberFormatException() throw ()
{
}
