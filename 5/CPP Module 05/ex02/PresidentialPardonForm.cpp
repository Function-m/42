#include "PresidentialPardonForm.h"

#include <iostream>

// Constructor and Destructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), target(other.target) {}
PresidentialPardonForm::~PresidentialPardonForm() {}

// Operator Overload
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
  if (this != &other) {
    AForm::operator=(other);
    target = other.target;
  }
  return *this;
}

// Member Function
void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  validateIsSigned();
  validateGrade(this->getGradeToExecute(), executor.getGrade());

  std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
