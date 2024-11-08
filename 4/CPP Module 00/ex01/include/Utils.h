#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <limits>
#include <string>

namespace utils {

void clearScreen(int lines = -1);
void waitForEnter();
bool isNumber(const std::string &str);
bool isOnlyWhitespace(const std::string &input);
std::string removeAnsiEscapeCodes(const std::string &input);
std::string getInput(const std::string &prompt = "");
std::string getNumericInput(const std::string &prompt = "");

}  // namespace utils

#endif  // UTILS_H_