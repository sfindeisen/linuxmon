/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#ifndef _linuxmon_utils_TextUtils_H_
#define _linuxmon_utils_TextUtils_H_

#include <cstdlib>
#include <cstdio>

#include "../throwable/runtime/NumberFormatException.h"
#include "../common.h"

#if ('0' != 48)
#error ASCII expected
#endif
#if ('9' != 57)
#error ASCII expected
#endif
#if ('a' != 97)
#error ASCII expected
#endif
#if ('z' != 122)
#error ASCII expected
#endif
#if ('A' != 65)
#error ASCII expected
#endif
#if ('Z' != 90)
#error ASCII expected
#endif

namespace linuxmon {

class TextUtils
    : public AbstractSingletonTemplate<TextUtils>
{
    public:
        /** c is an ASCII value for 0-9, A-F or a-f */
        int    parseHexDigit(const int c)          const;
        bigint parseHex     (const std::string& s) const;

        /** Converts a string to an int. With check, an exception is thrown unless this is a full match. */
        int    parseInt     (const std::string& s, bool check) const;
        /** Converts a string to a long. With check, an exception is thrown unless this is a full match. */
        long   parseLong    (const std::string& s, bool check) const;
        /** Converts a string to an int. With check, an exception is thrown unless this is a full match. */
        int    parseInt     (const char* s       , bool check) const;
        /** Converts a string to a long. With check, an exception is thrown unless this is a full match. */
        long   parseLong    (const char* s       , bool check) const;

        /** This allocates a new buffer using EB_NEW, so you should free it using EB_DELETE_ARRAY. */
        char*  duplicateString(const TString& s)   const;

    protected:
        void init();

    private:
        friend class AbstractSingletonTemplate<TextUtils>;
        TextUtils();

        static const int Ascii2HexLen = 256;
        int  Ascii2Hex     [Ascii2HexLen];
        char Ascii2HexValid[Ascii2HexLen];
};

inline int TextUtils::parseHexDigit(const int c) const {
/*  if (('0' <= c) && (c <= '9'))
        return (c - '0');
    if (('A' <= c) && (c <= 'F'))
        return (10 + c - 'A');
    if (('a' <= c) && (c <= 'f'))
        return (10 + c - 'a');
*/
    if ((0 <= c) && (c < Ascii2HexLen) && (Ascii2HexValid[c])) {
        return (Ascii2Hex[c]);
    }

    EB_THROW_STREAM(NumberFormatException, "illegal hex digit (" << c << ")");
}

// TODO signed / unsigned
inline bigint TextUtils::parseHex(const std::string& s) const {
    if (s.empty()) {
        EB_THROW_ARGS(NumberFormatException, "s is empty!");
    }

    const unsigned int sLen = s.length();

    if ((2 * (sizeof(bigint))) < sLen) {
        EB_THROW_STREAM(NumberFormatException, "length(s) is: " << sLen);
    }

    const char* sc = s.c_str();
    bigint k = 0;

    for (unsigned int i = 0; i < sLen - 1; ++i) {
        k |= parseHexDigit(sc[i]);
        k <<= 4;
    }

    k |= parseHexDigit(sc[sLen-1]);
    return k;
}

inline int TextUtils::parseInt(const std::string& s, bool check) const {
    return parseInt(s.c_str(), check);
}
inline long TextUtils::parseLong(const std::string& s, bool check) const {
    return parseLong(s.c_str(), check);
}

inline int TextUtils::parseInt(const char* s, bool check) const {
    static const int BLen = 20;

    if (check) {
        char buf[1 + BLen];
        int  j = atoi(s);
        int  k = snprintf(buf, BLen, "%d", j);

        if (k < BLen) {
            buf[k] = 0;

            if (strcmp(s, buf)) {
                EB_THROW(NumberFormatException);
            }
        } else {
            // we really should not be here...
            EB_THROW(NumberFormatException);
        }

        return j;
    } else {
        return atoi(s);
    }
}

inline long TextUtils::parseLong(const char* s, bool check) const {
    static const int BLen = 25;

    if (check) {
        char buf[1 + BLen];
        long j = atol(s);
        int  k = snprintf(buf, BLen, "%ld", j);

        if (k < BLen) {
            buf[k] = 0;

            if (strcmp(s, buf)) {
                EB_THROW(NumberFormatException);
            }
        } else {
            // we really should not be here...
            EB_THROW(NumberFormatException);
        }

        return j;
    } else {
        return atol(s);
    }
}

inline char* TextUtils::duplicateString(const TString& s) const {
    const int SLen = s.length();
    char* buf = NULL;
    EB_NEW(buf, char[1 + SLen]);
    strncpy(buf, s.c_str(), SLen);
    buf[SLen] = 0;
    return buf;
}

};

#endif
