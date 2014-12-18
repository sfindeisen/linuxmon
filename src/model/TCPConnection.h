/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2011-04-24 (SF): initial version
 */

#ifndef _linuxmon_model_TCPConnection_H_
#define _linuxmon_model_TCPConnection_H_

#include "EndPoint.h"

namespace linuxmon {

/** An IPv4/TCP connection. */
class TCPConnection
{
    public:
        TCPConnection(const EndPoint& aloc, const EndPoint& armt, const TUID& uid, const TInode& inode);

    private:
        EndPoint aloc;
        EndPoint armt;
        TUID     uid;
        TInode   inode;
};

};

#endif
