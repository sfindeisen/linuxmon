/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2011-04-24 (SF): initial version
 */

#ifndef _linuxmon_wrapper_Wrapper_H_
#define _linuxmon_wrapper_Wrapper_H_

#include "../common.h"

namespace linuxmon {

/** RAII */
class Wrapper : public boost::noncopyable
{
    public:
        Wrapper();
        virtual ~Wrapper();

        virtual bool isNull() =0;
        virtual void forget() =0;
};

};

#endif
