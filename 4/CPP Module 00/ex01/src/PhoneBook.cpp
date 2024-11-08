#include "PhoneBook.h"

namespace phonebook {

PhoneBook::PhoneBook() : oldestContactsIndex(0){};

int PhoneBook::addContact() {
  utils::clearScreen();

  std::string firstName = utils::getInput("First name      : ");
  std::string lastName = utils::getInput("Last name       : ");
  std::string nickname = utils::getInput("Nickname        : ");
  std::string phoneNumber = utils::getNumericInput("Phone number    : ");
  std::string darkestSecret = utils::getInput("Darkest secret  : ");

  contacts[oldestContactsIndex] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
  oldestContactsIndex = (oldestContactsIndex + 1) % 8;
  return 0;
}

int PhoneBook::searchContact() {
  printContactList();
  int index = getContactIndex();
  if (index != -1)
    printContactDetail(index);
  return 0;
}

int PhoneBook::exitPhoneBook() {
  std::cout << "\n프로그램을 종료합니다.\n"
            << std::endl;
  exit(EXIT_SUCCESS);
}

std::string PhoneBook::truncate(const std::string &str) {
  if (str.size() > 10) {
    return str.substr(0, 9) + '.';
  }
  return str;
}

void PhoneBook::printContactList() {
  utils::clearScreen();
  std::cout << std::right
            << std::setw(10) << "Index"
            << "|"
            << std::setw(10) << "First Name"
            << "|"
            << std::setw(10) << "Last Name"
            << "|"
            << std::setw(10) << "Nickname" << std::endl;

  std::cout << std::setfill('-') << std::setw(49) << "" << std::setfill(' ') << std::endl;

  for (int i = 0; i < 8; i++) {
    std::cout << std::right
              << std::setw(10) << i << "|"
              << std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
              << std::setw(10) << truncate(contacts[i].getLastName()) << "|"
              << std::setw(10) << truncate(contacts[i].getNickname()) << "\n";
  }
  std::cout << std::endl;
}

void PhoneBook::printContactDetail(int index) {
  utils::clearScreen();
  std::cout << std::left
            << std::setw(16) << "First Name"
            << ": " << contacts[index].getFirstName() << "\n"
            << std::setw(16) << "Last Name"
            << ": " << contacts[index].getLastName() << "\n"
            << std::setw(16) << "Nickname"
            << ": " << contacts[index].getNickname() << "\n"
            << std::setw(16) << "Phone Number"
            << ": " << contacts[index].getPhoneNumber() << "\n"
            << std::setw(16) << "Darkest Secret"
            << ": " << contacts[index].getDarkestSecret() << std::endl;
}

int PhoneBook::getContactIndex() {
  std::string input = utils::getNumericInput("INDEX를 입력해 주세요 (0-7): ");
  std::istringstream iss(input);

  int index;
  if (!(iss >> index) || index < 0 || index >= 8 || !iss.eof()) {
    utils::clearScreen();
    std::cout << "잘못된 INDEX입니다." << std::endl;
    return -1;
  }

  if (contacts[index].getFirstName().empty()) {
    utils::clearScreen();
    std::cout << "INDEX에 해당하는 CONTACT가 없습니다 (" << index << ")." << std::endl;
    return -1;
  }

  return index;
}

}  // namespace phonebook
