/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2011-04-24 (SF): initial version
 */

#ifndef _linuxmon_wrapper_DIRWrapper_H_
#define _linuxmon_wrapper_DIRWrapper_H_

#include <sys/types.h>
#include <dirent.h>

#include "Wrapper.h"

namespace linuxmon {

class DIRWrapper : public linuxmon::Wrapper {
    public:
        DIRWrapper(DIR *p);
        virtual ~DIRWrapper();

        virtual DIR* getDIR();
        virtual bool isNull();
        virtual void forget();

    private:
        DIR *fp;
};

};

#endif
