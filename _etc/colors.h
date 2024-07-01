#ifndef COLORS_H
#define COLORS_H

// ANSI Escape Codes for text color
#define ANSI_RED     "\x1b[31m"
#define ANSI_GREEN   "\x1b[32m"
#define ANSI_YELLOW  "\x1b[33m"
#define ANSI_BLUE    "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN    "\x1b[36m"
#define ANSI_RESET   "\x1b[0m"

// ANSI Escape Codes for text color with auto-reset
#define COLOR_RED(x)     "\x1b[31m" << (x) << "\x1b[0m"
#define COLOR_GREEN(x)   "\x1b[32m" << (x) << "\x1b[0m"
#define COLOR_YELLOW(x)  "\x1b[33m" << (x) << "\x1b[0m"
#define COLOR_BLUE(x)    "\x1b[34m" << (x) << "\x1b[0m"
#define COLOR_MAGENTA(x) "\x1b[35m" << (x) << "\x1b[0m"
#define COLOR_CYAN(x)    "\x1b[36m" << (x) << "\x1b[0m"

#endif
