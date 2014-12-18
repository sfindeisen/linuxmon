/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2011-04-24 (SF): initial version
 */

#ifndef _linuxmon_service_ProcessService_H_
#define _linuxmon_service_ProcessService_H_

#include <boost/regex.hpp>

#include "../model/LinuxProcess.h"

namespace linuxmon {

/** Linux /proc/net service. */
class ProcessService :
    public AbstractSingletonTemplate<ProcessService>
{
    public:
        void getProcesses();

    protected:
        void readProcess  (const TPID& pid) const;
        void readProcesses()                const;

    private:
        friend class AbstractSingletonTemplate<ProcessService>;
        ProcessService();

        static const boost::regex rePID;
        static const TFileName     sProcNetTcp;
};

};

#endif
