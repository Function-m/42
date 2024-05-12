#include <iostream>
#include "Bureaucrat.h"

int main() {
  try { // 높은 등급, 예외 발생 예정
    std::cout << "\n* Too High Test *\n";

    Bureaucrat one("one", 2);
    std::cout << one << std::endl;

    one.increaseGrade();
    one.increaseGrade();

    std::cout << "* Test End *\n";
  } catch (const Bureaucrat::GradeTooHighException& e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  } catch (const Bureaucrat::GradeTooLowException& e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  try { // 낮은 등급, 예외 발생 예정
    std::cout << "\n* Too Low Grade Test *\n";

    Bureaucrat two("two", 151);
    std::cout << two << std::endl;

    std::cout << "* Test End *\n";
  } catch (const Bureaucrat::GradeTooHighException& e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  } catch (const Bureaucrat::GradeTooLowException& e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }
  
  try { // 안전한 등급
    std::cout << "\n* Safe Grade Test *\n";

    Bureaucrat three("three", 75);
    std::cout << three << std::endl;
    three.decreaseGrade();
    std::cout << three << std::endl;

    std::cout << "* Test End *\n";
  } catch (const Bureaucrat::GradeTooHighException& e) {
    std::cerr << "Exception caught: " << e.what();
  } catch (const Bureaucrat::GradeTooLowException& e) {
    std::cerr << "Exception caught: " << e.what();
  }

  std::cout << std::endl;
  return 0;
}