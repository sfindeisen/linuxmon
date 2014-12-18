/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2011-04-24 (SF): initial version
 */

#ifndef _linuxmon_model_EndPoint_H_
#define _linuxmon_model_EndPoint_H_

#include "../common.h"

namespace linuxmon {

/** TCP or UDP endpoint (IPv4 address + port number). */
class EndPoint
{
    public:
        EndPoint(const TIPv4Addr& addr, const TIPv4Port& port);

    private:
        TIPv4Addr addr;
        TIPv4Port port;
};

};

#endif
