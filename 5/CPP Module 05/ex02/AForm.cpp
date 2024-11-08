#include "AForm.h"

// Constructor and Destructor
AForm::AForm(const std::string& name, const int gradeRequiredToSign, const int gradeRequiredToExecute)
    : name(name), gradeRequiredToSign(gradeRequiredToSign), gradeRequiredToExecute(gradeRequiredToExecute) {
  this->signedStatus = false;
  validateGrade();
}
AForm::AForm(const AForm& src)
    : name(src.name), signedStatus(src.signedStatus), gradeRequiredToSign(src.gradeRequiredToSign), gradeRequiredToExecute(src.gradeRequiredToExecute) {}
AForm::~AForm() {}

// Operator Overload
AForm& AForm::operator=(const AForm& rhs) {
  if (this != &rhs) {
    this->signedStatus = rhs.signedStatus;
  }
  return *this;
}
std::ostream& operator<<(std::ostream& os, const AForm& form) {
  os << "Form Name: " << form.getName() << "\n"
     << "Signed Status: " << (form.isSigned() ? "Yes" : "No") << "\n"
     << "Grade Required To Sign: " << form.getGradeToSign() << "\n"
     << "Grade Required To Execute: " << form.getGradeToExecute() << "\n";
  return os;
}

// Getter
std::string AForm::getName() const { return this->name; }
bool AForm::isSigned() const { return this->signedStatus; }
int AForm::getGradeToSign() const { return this->gradeRequiredToSign; }
int AForm::getGradeToExecute() const { return this->gradeRequiredToExecute; }

// Setter
void AForm::beSigned(const Bureaucrat& target) {
  validateGrade(this->gradeRequiredToSign, target.getGrade());
  signedStatus = true;
}

// Exception
const char* AForm::GradeTooHighException::what() const throw() {
  return "Grade Too High.";
}
const char* AForm::GradeTooLowException::what() const throw() {
  return "Grade Too Low.";
}
void AForm::validateGrade(const int grade) const {
  if (grade < 1) {
    throw GradeTooHighException();
  } else if (grade > 150) {
    throw GradeTooLowException();
  }
}
void AForm::validateGrade() const {
  int grade[2] = {
      this->gradeRequiredToSign,
      this->gradeRequiredToExecute};

  for (unsigned int i = 0; i < sizeof(grade) / sizeof(grade[1]); i++) {
    validateGrade(grade[i]);
  }
}
void AForm::validateGrade(const int requiredGrade, const int givenGrade) const {
  if (requiredGrade < givenGrade) {
    throw GradeTooLowException();
  }
}

// Additional by EX02
const char* AForm::FormNotSignedException::what() const throw() {
  return "That form is not signed.";
}
void AForm::validateIsSigned() const {
  if (!this->signedStatus) {
    throw FormNotSignedException();
  }
}
