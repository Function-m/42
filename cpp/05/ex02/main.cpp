#include <iostream>

#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

int main() {
  try {  // 성공
    Bureaucrat executor("Executor", 1);
    PresidentialPardonForm pardonForm("PARDON_TARGET");
    RobotomyRequestForm robotomyForm("ROBOTOMY_TARGET");
    ShrubberyCreationForm shrubberyForm("SHRUBBERY_TARGET");

    executor.signForm(pardonForm);
    executor.signForm(robotomyForm);
    executor.signForm(shrubberyForm);

    executor.executeForm(pardonForm);
    executor.executeForm(robotomyForm);
    executor.executeForm(shrubberyForm);

  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  
  std::cout << std::endl;

  try {  // 실패
    Bureaucrat badExecutor("BadExecutor", 150);
    PresidentialPardonForm pardonForm("PARDON_TARGET");
    badExecutor.signForm(pardonForm);
    badExecutor.executeForm(pardonForm);
  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  return 0;
}
