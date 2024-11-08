#include "Harl.h"
#include <iostream>

void Harl::debug(void) { std::cout << "\033[31m[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl; }
void Harl::info(void) { std::cout << "\033[32m[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl; }
void Harl::warning(void) { std::cout << "\033[33m[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl; }
void Harl::error(void) { std::cout << "\033[34m[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl; }

void Harl::complain(std::string level) {
  int nowLevel = 0;
  (level == "DEBUG") && (nowLevel = 1);
  (level == "INFO") && (nowLevel = 2);
  (level == "WARNING") && (nowLevel = 3);
  (level == "ERROR") && (nowLevel = 4);

  switch (nowLevel) {
    default:
      std::cout << "\033[35m[ Probably complaining about insignificant problems ]" << std::endl;
      break;
    case 1:
      debug();
    case 2:
      info();
    case 3:
      warning();
    case 4:
      error();
  }
}
