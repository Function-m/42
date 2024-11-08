#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class ScalarConverter {
 public:
  static void convert(const std::string& literal);

 private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter&);
  ~ScalarConverter();

  ScalarConverter& operator=(const ScalarConverter&);

  // Helper functions
  static bool isSpecialValue(const std::string& literal);
  static bool isNumber(const std::string& literal);
  static double parseToDouble(const std::string& literal);
};

#endif  // SCALARCONVERTER_HPP
