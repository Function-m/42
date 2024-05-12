#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <string>

#include "AForm.h"
#include "Bureaucrat.h"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm {
 public:
  // Constructor and Destructor
  ShrubberyCreationForm(const std::string& target = "default");
  ShrubberyCreationForm(const ShrubberyCreationForm& src);
  ~ShrubberyCreationForm();

  // Operator Overload
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);

  // Member Function
  void execute(Bureaucrat const& executor) const;

 private:
  // Member Variable
  std::string target;
};

#endif  // SHUBBERYCREATIONFORM_H