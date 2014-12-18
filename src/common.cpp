/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2011-04-24 (SF): initial version
 */

#include <cstdlib>

#include "utils/TextUtils.h"
#include "common.h"

namespace linuxmon {
    TPID parsePID(const TString& s, bool chk) {
        return TextUtils::getInstance().parseLong(s, chk);
    }

    TUID parseUID(const TString& s, bool chk) {
        return TextUtils::getInstance().parseLong(s, chk);
    }

    TFileDesc parseFileDesc(const char* s, bool chk) {
        return TextUtils::getInstance().parseLong(s, chk);
    }

    TInode parseTInode(const TString& s, bool chk) {
        return TextUtils::getInstance().parseLong(s, chk);
    }
}
