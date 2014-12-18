/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2011-04-24 (SF): initial version
 */

#include "IPv4Utils.h"

using namespace std;

namespace linuxmon {

TString IPv4Utils::asString(const TIPv4Addr& addr) {
    TStringStream ss;
    int ip4 =  addr        & 0xFF;
    int ip3 = (addr >>  8) & 0xFF;
    int ip2 = (addr >> 16) & 0xFF;
    int ip1 = (addr >> 24) & 0xFF;
    ss << ip1 << "." << ip2 << "." << ip3 << "." << ip4;
    return ss.str();
}

}
