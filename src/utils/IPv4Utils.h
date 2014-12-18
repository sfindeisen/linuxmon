/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2011-04-24 (SF): initial version
 */

#ifndef _linuxmon_utils_IPv4Utils_H_
#define _linuxmon_utils_IPv4Utils_H_

#include "../common.h"

using namespace std;

namespace linuxmon {

class IPv4Utils {
    public:
        static TString asString(const TIPv4Addr& addr);
};

}

#endif
