/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2011-04-25 (SF): initial version
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "File.h"

using namespace std;
using namespace linuxmon;

File::File(const TType& ft, const TInode& fi)
    : ftype(ft), finode(fi)
{
}

File::File(const struct stat& ss)
    : ftype(DTUnknown), finode(ss.st_ino)
{
    if (S_ISREG(ss.st_mode))
        ftype = DTReg;
    else
    if (S_ISDIR(ss.st_mode))
        ftype = DTDir;
    else
    if (S_ISCHR(ss.st_mode))
        ftype = DTChr;
    else
    if (S_ISBLK(ss.st_mode))
        ftype = DTBlk;
    else
    if (S_ISFIFO(ss.st_mode))
        ftype = DTFifo;
    else
    if (S_ISLNK(ss.st_mode))
        ftype = DTLnk;
    else
    if (S_ISSOCK(ss.st_mode))
        ftype = DTSock;
    else {
        EB_WARNING("unknown file type (" << (ss.st_mode) << ")");
    }
}
