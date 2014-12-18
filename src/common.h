/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#ifndef _linuxmon_common_H_
#define _linuxmon_common_H_

#include "common-defs.h"
#include "common-macros.h"
#include "memory/MemoryManager.h"
#include "misc/AbstractSingletonTemplate.h"
#include "log/ApplicationLogger.h"

namespace linuxmon {
    TPID      parsePID      (const TString& s, bool chk);
    TUID      parseUID      (const TString& s, bool chk);
    TFileDesc parseFileDesc (const char* s   , bool chk);
    TInode    parseTInode   (const TString& s, bool chk);
}

#endif
