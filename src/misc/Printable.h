/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#ifndef _linuxmon_misc_Printable_H_
#define _linuxmon_misc_Printable_H_

#include <iostream>

#include "../common-defs.h"
#include "../common-macros.h"

namespace linuxmon {

/** A base class for all printable objects. */
class Printable {
    public:
        virtual TString asString() const =0;

    protected:
        Printable();
};

std::ostream& operator<<(std::ostream& stream, const linuxmon::Printable& p);

};

#endif
