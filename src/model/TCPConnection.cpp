/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2011-04-24 (SF): initial version
 */

#include "TCPConnection.h"

using namespace std;
using namespace linuxmon;

TCPConnection::TCPConnection(const EndPoint& al, const EndPoint& ar, const TUID& u, const TInode& ii)
    : aloc(al), armt(ar), uid(u), inode(ii)
{
}
