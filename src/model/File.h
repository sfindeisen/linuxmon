/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2011-04-25 (SF): initial version
 */

#ifndef _linuxmon_model_File_H_
#define _linuxmon_model_File_H_

#include "../common.h"

namespace linuxmon {

class File
{
    public:
        /** see readdir(3) for a description of this */
        typedef enum {
            DTBlk, DTChr, DTDir, DTFifo, DTLnk, DTReg, DTSock, DTUnknown
        } TType;

        File(const TType& ftype, const TInode& finode);
        File(const struct stat& ss);

    private:
        TType     ftype;
        TInode    finode;
};

};

#endif
