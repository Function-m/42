#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include <string>

#include "AForm.h"

class PresidentialPardonForm : public AForm {
 public:
  // Constructor and Destructor
  PresidentialPardonForm(const std::string& target = "default");
  PresidentialPardonForm(const PresidentialPardonForm& src);
  ~PresidentialPardonForm();

  // Operator Overload
  PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

  // Member Function
  void execute(Bureaucrat const& executor) const;

 private:
  // Member Variable
  std::string target;
};

#endif  // PRESIDENTIALPARDONFORM_H