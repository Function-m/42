#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {
 public:
  // Constructor and Destructor
  Bureaucrat(const std::string& name = "default", const int grade = 150);
  Bureaucrat(const Bureaucrat& src);
  ~Bureaucrat();

  // Operator Overload
  Bureaucrat& operator=(const Bureaucrat& rhs);

  // Getter
  std::string getName() const;
  int getGrade() const;

  // Setter
  void increaseGrade();
  void decreaseGrade();

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
  int grade;

  // Exception
  void validateGrade() const;
};

// Operator Overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);

#endif  // BUREAUCRAT_H