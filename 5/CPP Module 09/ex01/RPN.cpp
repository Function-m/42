#include "RPN.hpp"

#include <iostream>
#include <stdexcept>

int RPN(const std::string& expression) {
  std::istringstream iss(expression);
  std::stack<int> stack;
  std::string token;

  while (iss >> token) {
    if (token.size() != 1) {
      throw std::invalid_argument("invalid token");
    }

    // Operand
    if (token[0] >= '0' && token[0] <= '9') {
      stack.push(token[0] - '0');
      continue;
    }

    // Operation
    if (stack.size() < 2) {
      throw std::invalid_argument("not enough operands");
    }
    int operand2 = stack.top();
    stack.pop();
    int operand1 = stack.top();
    stack.pop();
    if (token[0] == '+') {
      stack.push(operand1 + operand2);
    } else if (token[0] == '-') {
      stack.push(operand1 - operand2);
    } else if (token[0] == '*') {
      stack.push(operand1 * operand2);
    } else if (token[0] == '/') {
      if (operand2 == 0) {
        throw std::invalid_argument("division by zero");
      }
      stack.push(operand1 / operand2);
    } else {
      throw std::invalid_argument("invalid operation");
    }
  }
  if (stack.size() != 1) {
    throw std::invalid_argument("too many operands");
  }
  return stack.top();
}
