#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>

#include "Bureaucrat.h"

class Bureaucrat;

class Form {
 public:
  // Constructor and Destructor
  Form(const std::string& name = "default", const int gradeRequiredToSign = 150, const int gradeRequiredToExecute = 150);
  Form(const Form& src);
  ~Form();

  // Operator Overload
  Form& operator=(const Form& rhs);

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

 private:
  // Member Variable
  const std::string name;
  bool signedStatus;
  const int gradeRequiredToSign;
  const int gradeRequiredToExecute;

  // Exception
  void validateGrade(const int grade) const;
  void validateGrade() const;
  void validateGrade(const int requiredGrade, const int givenGrade) const;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif