/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2011-04-25 (SF): initial version
 */

#include "FileDescriptor.h"

using namespace std;
using namespace linuxmon;

FileDescriptor::FileDescriptor(const TFileDesc& i, const boost::shared_ptr<File>& p)
    : id(i), pFile(p)
{
}
