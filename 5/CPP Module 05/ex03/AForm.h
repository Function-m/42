#ifndef AFORM_H
#define AFORM_H

#include <iostream>
#include <string>

#include "Bureaucrat.h"

class Bureaucrat;

class AForm {
 public:
  // Constructor and Destructor
  AForm(const std::string& name = "default", const int gradeRequiredToSign = 150, const int gradeRequiredToExecute = 150);
  AForm(const AForm& src);
  virtual ~AForm();

  // Operator Overload
  AForm& operator=(const AForm& rhs);

  // Getter
  std::string getName() const;
  bool isSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  // Setter
  void beSigned(const Bureaucrat& target);

  // Exception
  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };

  // Additional by EX02
  virtual void execute(Bureaucrat const& executor) const = 0;
  class FormNotSignedException : public std::exception {
   public:
    const char* what() const throw();
  };
  void validateIsSigned() const;

 private:
  // Member Variable
  const std::string name;
  bool signedStatus;
  const int gradeRequiredToSign;
  const int gradeRequiredToExecute;

 protected:
  // Exception
  void validateGrade(const int grade) const;
  void validateGrade() const;
  void validateGrade(const int requiredGrade, const int givenGrade) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif