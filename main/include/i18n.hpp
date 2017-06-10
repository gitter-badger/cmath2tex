/**
 * @file i18n.hpp
 * @date 08.05.17
 * @author Galarius
 * @copyright Copyright (c) 2017 galarius. All rights reserved.
 * @brief internalization
 * @todo implement
 */

#ifndef cmath2tex_i18n_hpp
#define cmath2tex_i18n_hpp

#include <string>

/**
 * @brief C++11 User-defined literal for internalization
 */
inline std::string operator "" _i18n(const char* str, size_t /*length*/)
{
    // placeholder
    std::string tr(str);
    return tr;
}

#endif  // cmath2tex_i18n_hpp
