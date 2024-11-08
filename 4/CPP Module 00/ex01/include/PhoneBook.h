#ifndef MY_AWESOME_PHONEBOOK_PHONEBOOK_H_
#define MY_AWESOME_PHONEBOOK_PHONEBOOK_H_

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Contact.h"
#include "Utils.h"

namespace phonebook {

class PhoneBook {
 public:
  PhoneBook();

  int addContact();
  int searchContact();
  int exitPhoneBook();

 private:
  Contact contacts[8];
  int oldestContactsIndex;

  std::string truncate(const std::string& str);
  int getContactIndex();
  void printContactList();
  void printContactDetail(int index);
};

}  // namespace phonebook

#endif  // MY_AWESOME_PHONEBOOK_PHONEBOOK_H_