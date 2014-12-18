/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2011-04-24 (SF): initial version
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#include <cerrno>

#include <fstream>

#include "../model/FileDescriptor.h"
#include "../throwable/runtime/NumberFormatException.h"
#include "../utils/TextUtils.h"
#include "../wrapper/DIRWrapper.h"
#include "ProcessService.h"

using namespace std;
using namespace linuxmon;

const boost::regex ProcessService::rePID("^([0-9]+)$");

ProcessService::ProcessService() : AbstractSingletonTemplate<ProcessService>() {
}

void ProcessService::getProcesses() {
    readProcesses();
}

void ProcessService::readProcess(const TPID& pid) const {
    TFileName dirFD(EB_STRING("/proc/" << pid << "/fd/"));
    DIR* fdd = opendir(dirFD.c_str());

    if (NULL == fdd) {
        EB_THROW_ARGS(SystemException, errno);
    } else {
        DIRWrapper fddWrapper(fdd);
        struct stat statr;
        struct dirent *pdirent;

        // TODO reentrant?
        while ((pdirent = readdir(fdd))) {
            if (DT_LNK == (pdirent->d_type)) {
                std::string s(dirFD + (pdirent->d_name));
                EB_MEMZERO(&statr, sizeof(statr));

                if (stat(s.c_str(), &statr)) {
                    EB_THROW_ARGS(SystemException, errno);
                } else {
                    File* pf = NULL;
                    EB_NEW(pf, File(statr));
                    FileDescriptor fd(parseFileDesc(pdirent->d_name, true), boost::shared_ptr<File>(pf));
                }
            }
        }
    }
}

void ProcessService::readProcesses() const {
    boost::smatch regroups;
    DIR* fdd = opendir("/proc/");

    if (NULL == fdd) {
        EB_THROW_ARGS(SystemException, errno);
    } else {
        DIRWrapper fddWrapper(fdd);
        struct dirent *pdirent;

        // TODO reentrant?
        while ((pdirent = readdir(fdd))) {
            std::string s(pdirent->d_name);

            if ((DT_DIR == (pdirent->d_type)) && (regex_match(s, regroups, rePID))) {
                TPID k = parsePID(regroups[1].str(), false);
                readProcess(k);
            }
        }
    }
}
