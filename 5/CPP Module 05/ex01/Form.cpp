#include "Form.h"

// Constructor and Destructor
Form::Form(const std::string& name, const int gradeRequiredToSign, const int gradeRequiredToExecute)
    : name(name), gradeRequiredToSign(gradeRequiredToSign), gradeRequiredToExecute(gradeRequiredToExecute) {
  this->signedStatus = false;
  validateGrade();
}
Form::Form(const Form& src)
    : name(src.name), signedStatus(src.signedStatus), gradeRequiredToSign(src.gradeRequiredToSign), gradeRequiredToExecute(src.gradeRequiredToExecute) {}
Form::~Form() {}

// Operator Overload
Form& Form::operator=(const Form& rhs) {
  if (this != &rhs) {
    this->signedStatus = rhs.signedStatus;
  }
  return *this;
}
std::ostream& operator<<(std::ostream& os, const Form& form) {
  os << "Form Name: " << form.getName() << "\n"
     << "Signed Status: " << (form.isSigned() ? "Yes" : "No") << "\n"
     << "Grade Required To Sign: " << form.getGradeToSign() << "\n"
     << "Grade Required To Execute: " << form.getGradeToExecute() << "\n";
  return os;
}

// Getter
std::string Form::getName() const { return this->name; }
bool Form::isSigned() const { return this->signedStatus; }
int Form::getGradeToSign() const { return this->gradeRequiredToSign; }
int Form::getGradeToExecute() const { return this->gradeRequiredToExecute; }

// Setter
void Form::beSigned(const Bureaucrat& target) {
  validateGrade(this->gradeRequiredToSign, target.getGrade());
  signedStatus = true;
}

// Exception
const char* Form::GradeTooHighException::what() const throw() {
  return "Grade Too High.";
}
const char* Form::GradeTooLowException::what() const throw() {
  return "Grade Too Low.";
}
void Form::validateGrade(const int grade) const {
  if (grade < 1) {
    throw GradeTooHighException();
  } else if (grade > 150) {
    throw GradeTooLowException();
  }
}
void Form::validateGrade() const {
  int grade[2] = {
      this->gradeRequiredToSign,
      this->gradeRequiredToExecute};

  for (unsigned int i = 0; i < sizeof(grade) / sizeof(grade[1]); i++) {
    validateGrade(grade[i]);
  }
}
void Form::validateGrade(const int requiredGrade, const int givenGrade) const {
  if (requiredGrade < givenGrade) {
    throw GradeTooLowException();
  }
}
