#ifndef BASE64_H
#define BASE64_H

#include <iostream>
#include <sstream>

using namespace std;

namespace Base64
{
    void Base64Encoding(istream&, ostream&, char makeupChar = '=',
        const char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");

    void Base64Decoding(istream&, ostream&, char plus = '+', char slash = '/');
}

#endif

