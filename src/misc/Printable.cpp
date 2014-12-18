/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#include "Printable.h"

using namespace linuxmon;

Printable::Printable() {
}

namespace linuxmon {
    std::ostream& operator<<(std::ostream& stream, const linuxmon::Printable& p) {
        return stream << (p.asString());
    }
};
