/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2011-04-24 (SF): initial version
 */

#include <cerrno>

#include "DIRWrapper.h"

using namespace linuxmon;

DIRWrapper::DIRWrapper(DIR* p) : Wrapper(), fp(p) {
}

DIRWrapper::~DIRWrapper() {
    if (NULL != fp) {
        if (closedir(fp)) {
            EB_WARNING("Error closing dir (" << errno << "): " << (strerror(errno)));
        }
        fp = NULL;
    }
};

DIR* DIRWrapper::getDIR() {
    return fp;
}

bool DIRWrapper::isNull() {
    return (NULL == fp);
}

void DIRWrapper::forget() {
    fp = NULL;
}
