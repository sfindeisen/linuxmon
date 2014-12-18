/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#include <cstdint>
#include <climits>

#ifndef _linuxmon_common_defs_H_
#define _linuxmon_common_defs_H_

#if ((CHAR_BIT) != (8))
#error unsupported char size
#endif

#if ((__SIZEOF_INT__)<(2))
#error sizeof int must be at least 2
#endif
#if ((__SIZEOF_LONG__)<(4))
#error sizeof long must be at least 4
#endif
#if ((__SIZEOF_LONG_LONG__)<(8))
#error sizeof long long must be at least 8
#endif

#include <string>
#include <sstream>

namespace linuxmon {

typedef std::string       TFileName;
typedef std::string       TString;
typedef std::stringstream TStringStream;

typedef unsigned long ulong;
typedef     long long bigint;

#ifndef FALSE
#define FALSE (0)
#endif

#ifndef TRUE
#define TRUE  (1)
#endif

#ifndef NULL
#define NULL (0)
#endif

#ifndef CALL_MEMBER_FN
#define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))
#endif

typedef uint32_t TIPv4Addr;

/** TCP or UDP port number. */
typedef uint16_t TIPv4Port;

// TODO proper types
typedef ulong TPID;
typedef ulong TUID;
typedef ulong TInode;
typedef ulong TFileDesc;

};

#endif
