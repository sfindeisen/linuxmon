/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2011-04-24 (SF): initial version
 */

#include <fstream>

#include "../throwable/runtime/NumberFormatException.h"
#include "../utils/IPv4Utils.h"
#include "../utils/TextUtils.h"
#include "NetService.h"

using namespace std;
using namespace linuxmon;

const boost::regex NetService::reProcNetTcp("^(?:\\s*)([0-9]+)\\:(?:\\s*)([A-Fa-f0-9]{8})\\:([0-9A-Fa-f]{4})(?:\\s+)([0-9A-Fa-f]{8})\\:([0-9A-Fa-f]{4})(?:\\s+)([0-9A-Fa-f]{2})(?:\\s+)([0-9A-Fa-f]{8})\\:([0-9A-Fa-f]{8})(?:\\s+)([0-9A-Fa-f]{2})\\:([0-9A-Fa-f]{8})(?:\\s+)([0-9A-Fa-f]{8})(?:\\s+)([0-9]+)(?:\\s+)([0-9]+)(?:\\s+)([0-9]+)(?:\\s+)([0-9]+)(?:\\s+)([0-9A-Fa-f]+)(?:\\s+)([0-9]+)(?:\\s+)([0-9]+)(?:\\s+)([0-9]+)(?:\\s+)([0-9]+)(?:\\s+)((?:\\-?)[0-9]+)(?:\\s*)$");

const TFileName NetService::sProcNetTcp("/proc/net/tcp");

NetService::NetService() : AbstractSingletonTemplate<NetService>() {
}

void NetService::getTCPConnections() {
    readTCPConnections();
}

inline TIPv4Addr NetService::parseIPv4Addr(const std::string& s) const {
    const TextUtils& tu(TextUtils::getInstance());

    if (8 != (s.length())) {
        EB_THROW(NumberFormatException);
    }

    const char* sc = s.c_str();
    TIPv4Addr addr = 0;

    addr |= tu.parseHexDigit(sc[6]);
    addr <<= 4;
    addr |= tu.parseHexDigit(sc[7]);
    addr <<= 4;
    addr |= tu.parseHexDigit(sc[4]);
    addr <<= 4;
    addr |= tu.parseHexDigit(sc[5]);
    addr <<= 4;
    addr |= tu.parseHexDigit(sc[2]);
    addr <<= 4;
    addr |= tu.parseHexDigit(sc[3]);
    addr <<= 4;
    addr |= tu.parseHexDigit(sc[0]);
    addr <<= 4;
    addr |= tu.parseHexDigit(sc[1]);

    // EB_DEBUG(s << " --> " << (IPv4Utils::asString(addr)));
    return addr;
}

inline TIPv4Port NetService::parseIPv4Port(const std::string& s) const {
    return TextUtils::getInstance().parseHex(s);
}

inline void NetService::readTCPConnections() const {
    boost::smatch regroups;
    std::ifstream ifs(sProcNetTcp.c_str());
    std::string   line;

    while (ifs.good()) {
        getline(ifs, line);

        if (regex_match(line, regroups, reProcNetTcp)) {
            bigint k = atoi(regroups[1].str().c_str());
            TIPv4Addr addrLoc = parseIPv4Addr(regroups[2].str());
            TIPv4Port portLoc = parseIPv4Port(regroups[3].str());
            TIPv4Addr addrRmt = parseIPv4Addr(regroups[4].str());
            TIPv4Port portRmt = parseIPv4Port(regroups[5].str());
            TUID      uid     = parseUID     (regroups[12].str(), false);
            TInode    inode   = parseTInode  (regroups[14].str(), false);

            EB_DEBUG(k << " " << (IPv4Utils::asString(addrLoc)) << ":" << portLoc << " " << (IPv4Utils::asString(addrRmt)) << ":" << portRmt << " uid=" << uid << " inode=" << inode);
        } else {
            EB_WARNING("Unmatched: " << line);
        }
    }
}

