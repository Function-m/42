#include "RobotomyRequestForm.h"

#include <iostream>

// Constructor and Destructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {
  srand(time(NULL));
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {}
RobotomyRequestForm::~RobotomyRequestForm() {}

// Operator Overload
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
  if (this != &other) {
    AForm::operator=(other);
    target = other.target;
  }
  return *this;
}

// Member Function
void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  validateIsSigned();
  validateGrade(this->getGradeToExecute(), executor.getGrade());

  std::cout << "Drilling noises... Brrr..BaBaPwaPACK!\n";

  if (rand() % 2 == 0) {
    std::cout << target << " has been robotomized successfully." << std::endl;
  } else {
    std::cout << "Failed to robotomize " << target << "." << std::endl;
  }
}
