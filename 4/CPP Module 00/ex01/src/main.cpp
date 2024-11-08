#include "PhoneBook.h"
#include "Utils.h"

struct cmd_handler {
  std::string cmd;
  int (phonebook::PhoneBook::*handler)();
};

int main() {
  phonebook::PhoneBook phoneBookInstance;
  struct cmd_handler handlers[] = {
      {"ADD", &phonebook::PhoneBook::addContact},
      {"SEARCH", &phonebook::PhoneBook::searchContact},
      {"EXIT", &phonebook::PhoneBook::exitPhoneBook}};

  std::string prompt;
  std::string cmd;
  int ret;
  bool found;
  while (true) {
    utils::clearScreen();

    // 프롬프트 출력
    prompt = "명령어를 입력해 주세요 ("; 
    for (unsigned long i = 0; i < sizeof(handlers) / sizeof(handlers[0]); i++) {
      prompt += handlers[i].cmd;
      if (i != sizeof(handlers) / sizeof(handlers[0]) - 1)
        prompt += ", ";
    }
    prompt += ") : ";
    cmd = utils::getInput(prompt);
   
    // 사용자 입력 처리
    found = false;
    for (unsigned long i = 0; i < sizeof(handlers) / sizeof(handlers[0]); i++) {
      if (handlers[i].cmd == cmd) {
        ret = (phoneBookInstance.*(handlers[i].handler))();
        found = true;
        break;
      }
    }
    if (!found)
      std::cout << "\n유효하지 않은 명령어입니다." << std::endl;

    utils::waitForEnter();
  }
  return 0;
}