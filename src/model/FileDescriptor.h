/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2011-04-25 (SF): initial version
 */

#ifndef _linuxmon_model_FileDescriptor_H_
#define _linuxmon_model_FileDescriptor_H_

#include <boost/shared_ptr.hpp>

#include "File.h"

namespace linuxmon {

class FileDescriptor
{
    public:
        FileDescriptor(const TFileDesc& id, const boost::shared_ptr<File>& pFile);

    private:
        TFileDesc               id;
        boost::shared_ptr<File> pFile;
};

};

#endif
