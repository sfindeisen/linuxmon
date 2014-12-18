/**
 * Author: Stanislaw Findeisen <sf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2011-04-23 (SF) Initial version.
 */

#include "proc/NetService.h"
#include "proc/ProcessService.h"

using namespace linuxmon;

int main() {
    try {
        NetService& procNet(NetService::getInstance());
        procNet.getTCPConnections();

        ProcessService& procSrv(ProcessService::getInstance());
        procSrv.getProcesses();

        MemoryManager::printMemoryInfo();
        EB_INFO("Program complete!");
    } catch (linuxmon::EBAbstractThrowable& e) {
        EB_ERROR(e);
    } catch (std::exception& e) {
        EB_ERROR("Top level: " << (e.what()));
    } catch (...) {
        EB_ERROR("Top level: unknown exception caught!");
    }

    return 0;
}
