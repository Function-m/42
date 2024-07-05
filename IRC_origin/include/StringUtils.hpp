#ifndef STRINGUTILS_HPP
#define STRINGUTILS_HPP

#include <iostream>
#include <sstream>
#include <string>

namespace StringUtils {

    inline void logDebug(const std::string& message) {
    #ifdef ENABLE_DEBUG
        std::cout << "\x1b[36m[DEBUG] \x1b[0m" << message << std::endl;
    #else
        (void)message;
    #endif
    }

    inline void logInfo(const std::string& message) {
        std::cout << "\x1b[32m[INFO]  \x1b[0m" << message << std::endl;
    }

    inline void logError(const std::string& message) {
        std::cerr << "\x1b[31m[ERROR] \x1b[0m" << message << std::endl;
    }

    template <typename T>
    std::string toString(T value) {
        std::stringstream ss;
        ss << value;
        return ss.str();
    }

} // namespace StringUtils

#endif // STRINGUTILS_HPP
