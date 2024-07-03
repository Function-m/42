#ifndef _DEBUG_HPP
#define _DEBUG_HPP

#include <iostream>

#ifdef ENABLE_DEBUG
#define LOG_DEBUG(message)  std::cout << "\x1b[36m[DEBUG] \x1b[0m" << message << std::endl
#else
#define LOG_DEBUG(message)
#endif

#define LOG_INFO(message)   std::cout << "\x1b[32m[INFO]  \x1b[0m" << message << std::endl
#define LOG_ERROR(message)  std::cerr << "\x1b[31m[ERROR] \x1b[0m" << message << std::endl

#endif // _DEBUG_HPP
