#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal) {
  if (isSpecialValue(literal)) {
    std::cout << "char: impossible\n"
                 "int: impossible\n"
                 "float: " << literal << (literal[literal.length() - 2] == 'f' ? "" : "f") << "\n"
                  "double: " << (literal[literal.length() - 2] == 'f' ? literal.substr(0, literal.length() - 1) : literal) << std::endl;

  } else if (isNumber(literal)) {
    double number = parseToDouble(literal);

    std::cout << "char: ";
    if (number == static_cast<int>(number) && isprint(static_cast<int>(number)))
      std::cout << "'" << static_cast<char>(number) << "'\n";
    else
      std::cout << "Non displayable\n";
    
    std::cout << "int: ";
    if (std::isnan(number) || std::isinf(number))
      std::cout << "impossible\n";
    else if (number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min())
      std::cout << "impossible\n";
    else
      std::cout << static_cast<int>(number) << "\n";
    
    std::cout << "float: ";
    if (std::isnan(number))
      std::cout << "nanf\n";
    else if (std::isinf(number))
      std::cout << (number < 0 ? "-inff" : "+inff") << "\n";
    else if (number > std::numeric_limits<float>::max() || number < std::numeric_limits<float>::min())
      std::cout << "impossible\n";
    else if (number == static_cast<int>(number))
      std::cout << static_cast<float>(number) << ".0f\n";
    else
      std::cout << static_cast<float>(number) << "f\n";
    
    std::cout << "double: ";
    if (std::isnan(number))
      std::cout << "nan" << std::endl;
    else if (std::isinf(number))
      std::cout << (number < 0 ? "-inf" : "+inf") << std::endl;
    else if (number > std::numeric_limits<double>::max() || number < std::numeric_limits<double>::min())
      std::cout << "impossible" << std::endl;
    else if (number == static_cast<int>(number))
      std::cout << static_cast<double>(number) << ".0" << std::endl;
    else
      std::cout << static_cast<double>(number) << std::endl;

  } else if (literal.length() == 1) {
    std::cout << "char: '" << literal << "'\n"
                 "int: " << static_cast<int>(literal[0]) << "\n"
                 "float: " << static_cast<float>(literal[0]) << ".0f\n"
                 "double: " << static_cast<double>(literal[0]) << std::endl;

  } else {
    std::cerr << "Not a valid input.\n";
  }
}

bool ScalarConverter::isSpecialValue(const std::string& literal) {
  return literal == "nan" || literal == "-inf" || literal == "+inf" || literal == "-inff" || literal == "+inff";
}

bool ScalarConverter::isNumber(const std::string& literal) {
    char* end;
    std::strtod(literal.c_str(), &end);
    
    if (*end == '\0') {
        return true;
    } else if (*end == 'f' && *(end + 1) == '\0') {
        return true;
    }
    return false;
}

double ScalarConverter::parseToDouble(const std::string& literal) {
  char* end;
  double result;

  if (literal.back() == 'f') {
    result = std::strtod(literal.substr(0, literal.length() - 1).c_str(), &end);
  } else {
    result = std::strtod(literal.c_str(), &end);
  }
  return result;
}
