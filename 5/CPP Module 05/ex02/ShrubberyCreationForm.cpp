#include "ShrubberyCreationForm.h"

#include <fstream>
#include <iostream>

// Constructor and Destructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Operator Overload
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
  if (this != &other) {
    AForm::operator=(other);
    target = other.target;
  }
  return *this;
}

// Member Function
void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  validateIsSigned();
  validateGrade(this->getGradeToExecute(), executor.getGrade());

  std::ofstream ofs((target + "_shrubbery").c_str());
  if (!ofs)
    throw std::runtime_error("File could not be opened");

  ofs << "    $\n"
         "   $$$\n"
         "  $$$$$\n"
         " $$$$$$$\n"
         "$$$$$$$$$\n"
         "   | |\n";
  ofs.close();
}
