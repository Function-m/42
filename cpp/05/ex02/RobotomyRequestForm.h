#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <string>

#include "AForm.h"

class RobotomyRequestForm : public AForm {
 public:
  // Constructor and Destructor
  RobotomyRequestForm(const std::string& target = "default");
  RobotomyRequestForm(const RobotomyRequestForm& src);
  ~RobotomyRequestForm();

  // Operator Overload
  RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

  // Member Function
  void execute(const Bureaucrat& executor) const;

 private:
  // Member Variable
  std::string target;
};

#endif  // ROBOTOMYREQUESTFORM_H