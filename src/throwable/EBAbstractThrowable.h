/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-30 (SF): initial version
 */

#ifndef _linuxmon_throwable_EBAbstractThrowable_H_
#define _linuxmon_throwable_EBAbstractThrowable_H_

#include "../misc/Printable.h"

namespace linuxmon {

/** A common superclass for all EB exceptions. */
class EBAbstractThrowable : public linuxmon::Printable {
    public:
        EBAbstractThrowable();
        virtual ~EBAbstractThrowable();
};

};

#endif
