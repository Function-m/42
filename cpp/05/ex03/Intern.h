#ifndef INTERN_H
#define INTERN_H

#include <string>

#include "AForm.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

class Intern {
 public:
  // Constructor and Destructor
  Intern();
  Intern(const Intern& other);
  ~Intern();

  // Operator Overload
  Intern& operator=(const Intern& other);

  // Member Function
  AForm* makeForm(const std::string& formName, const std::string& target) const;

 private:

  // For makeForm
  static AForm* createShrubberyCreation(const std::string& target);
  static AForm* createRobotomyRequest(const std::string& target);
  static AForm* createPresidentialPardon(const std::string& target);
};

#endif
