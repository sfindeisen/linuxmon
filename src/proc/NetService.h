/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2011-04-24 (SF): initial version
 */

#ifndef _linuxmon_service_NetService_H_
#define _linuxmon_service_NetService_H_

#include <boost/regex.hpp>

#include "../model/TCPConnection.h"

namespace linuxmon {

/** Linux /proc/net service. */
class NetService :
    public AbstractSingletonTemplate<NetService>
{
    public:
        void getTCPConnections();

    protected:
        TIPv4Addr parseIPv4Addr(const std::string& s) const;
        TIPv4Port parseIPv4Port(const std::string& s) const;

        void readTCPConnections() const;

    private:
        friend class AbstractSingletonTemplate<NetService>;
        NetService();

        static const boost::regex reProcNetTcp;
        static const TFileName     sProcNetTcp;
};

};

#endif
