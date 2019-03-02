//
// Created by obyoxar on 23/11/18.
//

#ifndef DUCKBURG_STRINGUTIL_H
#define DUCKBURG_STRINGUTIL_H

#include <string>
#include <cstring>

namespace StringUtil {
    /**
     * Copies a std::string into a char*
     * @param str
     * @return The char*. This needs to be deleted afterwards.
     */
    inline char *mallocFromString(const std::string &str) {
        char *cstr = new char[str.length() + 1];
        std::strcpy(cstr, str.c_str());
        return cstr;
    }

}

#endif //DUCKBURG_STRINGUTIL_H
