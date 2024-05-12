#include <iostream>

#include "AForm.h"
#include "Bureaucrat.h"
#include "Intern.h"

int main() {
  Intern Kingtern;
  Bureaucrat supervisor("Supervisor", 1);
  AForm* form;

  std::cout << "* Generating robotomu request form. *\n";
  form = Kingtern.makeForm("robotomy request", "Bender");
  if (form) {
    std::cout << "Successfully created " << form->getName() << std::endl;
    supervisor.signForm(*form);
    supervisor.executeForm(*form);
    delete form;
  }
  std::cout << std::endl;

  std::cout << "* Generating shrubbery creation form. *\n";
  form = Kingtern.makeForm("shrubbery creation", "Home");
  if (form) {
    std::cout << "Successfully created " << form->getName() << std::endl;
    supervisor.signForm(*form);
    supervisor.executeForm(*form);
    delete form;
  }
  std::cout << std::endl;

  std::cout << "* Generating presidential pardon form.\n";
  form = Kingtern.makeForm("presidential pardon", "Marvin");
  if (form) {
    std::cout << "Successfully created " << form->getName() << std::endl;
    supervisor.signForm(*form);
    supervisor.executeForm(*form);
    delete form;
  }
  std::cout << std::endl;

  std::cout << "* Generating unknown form. *\n";
  form = Kingtern.makeForm("unknown form", "Unknown Target");
  if (!form) {
    std::cout << "Failed to create form. Form type does not exist." << std::endl;
  }
  std::cout << std::endl;

  return 0;
}
