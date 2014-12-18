/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2011-04-24 (SF): initial version
 */

#include "EndPoint.h"

using namespace std;
using namespace linuxmon;

EndPoint::EndPoint(const TIPv4Addr& a, const TIPv4Port& p) : addr(a), port(p) {
}
