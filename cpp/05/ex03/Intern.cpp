#include "Intern.h"

#include <iostream>

// Constructor and Destructor
Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern::~Intern() {}

// Operator Overload
Intern& Intern::operator=(const Intern& other) {
  (void)other;
  return *this;
}

// Member Function
AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
  typedef struct {
    std::string formName;
    AForm* (*create)(const std::string& target);
  } InternForm;
  
  static const InternForm formList[] = {
    {"shrubbery creation", &Intern::createShrubberyCreation},
    {"robotomy request", &Intern::createRobotomyRequest},
    {"presidential pardon", &Intern::createPresidentialPardon}
  };

  for (size_t i = 0; i < sizeof(formList) / sizeof(formList[0]); i++) {
    if (formList[i].formName == formName) {
      std::cout << "Intern creates " << formName << std::endl;
      return formList[i].create(target);
    }
  }
  std::cerr << "Form name '" << formName << "' does not exist." << std::endl;
  return NULL;
}

// For makeForm
AForm* Intern::createShrubberyCreation(const std::string& target) {
    return new ShrubberyCreationForm(target);
}
AForm* Intern::createRobotomyRequest(const std::string& target) {
    return new RobotomyRequestForm(target);
}
AForm* Intern::createPresidentialPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}