/**
 * Author: Stanislaw Findeisen <stf AT eisenbits.com>
 *
 * Changes history:
 *
 * 2010-08-23 (SF): initial version
 */

#include "TextUtils.h"

using namespace std;
using namespace linuxmon;

TextUtils::TextUtils()
    : AbstractSingletonTemplate<TextUtils>()
{
    //EB_DEBUG("sizeof(Ascii2Hex) = " << (sizeof(Ascii2Hex)));
    EB_MEMZERO(Ascii2Hex, (sizeof(Ascii2Hex)));
    //EB_DEBUG("sizeof(Ascii2HexValid) = " << (sizeof(Ascii2HexValid)));
    EB_MEMZERO(Ascii2HexValid, (sizeof(Ascii2HexValid)));

    init();
}

void TextUtils::init() {
    for (int c = '0'; c <= '9'; ++c) {
        Ascii2Hex[c]      = c - '0';
        Ascii2HexValid[c] = 1;
    }
    for (int c = 'A'; c <= 'F'; ++c) {
        Ascii2Hex[c]      = 10 + c - 'A';
        Ascii2HexValid[c] = 1;
    }
    for (int c = 'a'; c <= 'f'; ++c) {
        Ascii2Hex[c]      = 10 + c - 'a';
        Ascii2HexValid[c] = 1;
    }
}
