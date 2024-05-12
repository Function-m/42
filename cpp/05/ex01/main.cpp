#include <iostream>

#include "Bureaucrat.h"
#include "Form.h"

int main() {
  
  try { // 서명할 수 있는 상황의 테스트
    Bureaucrat bureaucrat("One", 10);
    Form form1("Form 1", 50, 50);
    std::cout << bureaucrat << std::endl;
    std::cout << form1 << std::endl;

    bureaucrat.signForm(form1);
    std::cout << form1 << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  try { // 등급이 너무 낮아 서명할 수 없는 상황의 테스트
    Bureaucrat bureaucrat("Two", 100);
    Form form2("Form 2", 30, 30);
    std::cout << bureaucrat << std::endl;
    std::cout << form2 << std::endl;

    bureaucrat.signForm(form2);
    std::cout << form2 << std::endl;  // 서명 상태 확인
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
 
  try { // 서명 가능한 또 다른 상황
    Bureaucrat bureaucrat("Three", 20);
    Form form3("Form 3", 100, 100);  // 서명 및 실행 등급 요구 100
    std::cout << bureaucrat << std::endl;
    std::cout << form3 << std::endl;

    bureaucrat.signForm(form3);
    std::cout << form3 << std::endl;  // 서명 상태 확인
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
