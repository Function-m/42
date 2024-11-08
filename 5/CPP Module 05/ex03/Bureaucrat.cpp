#include "Bureaucrat.h"

// Constructor and Destructor
Bureaucrat::Bureaucrat(const std::string& name, const int grade) : name(name), grade(grade) {
  validateGrade();
}
Bureaucrat::Bureaucrat(const Bureaucrat& src) : name(src.name), grade(src.grade) {}
Bureaucrat::~Bureaucrat() {}

// Operator Overload
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
  if (this != &rhs) {
    // const 멤버는 대입이 불가능하므로 name은 무시합니다.
    this->grade = rhs.grade;
  }
  return (*this);
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs) {
  os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
  return os;
}

// Getter
std::string Bureaucrat::getName() const { return this->name; }
int Bureaucrat::getGrade() const { return this->grade; }

// Setter
void Bureaucrat::increaseGrade() {
  this->grade--;
  this->validateGrade();
}
void Bureaucrat::decreaseGrade() {
  this->grade++;
  this->validateGrade();
}

// Exeception
const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade Too High.";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade Too Low.";
}
void Bureaucrat::validateGrade() const {
  if (this->grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  } else if (this->grade > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
}

// Additional by EX01
void Bureaucrat::signForm(AForm& form) {
  try {
    form.beSigned(*this);
    std::cout << name << " signed " << form.getName() << std::endl;
  } catch (const AForm::GradeTooLowException& e) {
    std::cout << name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
  }
}

// Additional by EX02
void Bureaucrat::executeForm(AForm const& form) {
  try {
    form.execute(*this);
    std::cout << name << " executed " << form.getName() << std::endl;
  } catch (const std::exception& e) {
    std::cout << name << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
  }
}
