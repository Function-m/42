#include "Contact.h"

namespace phonebook {

Contact::Contact()
    : firstName(""),
      lastName(""),
      nickname(""),
      phoneNumber(""),
      darkestSecret(""){};

Contact::Contact(const std::string &firstName, const std::string &lastName, const std::string &nickname, const std::string &phoneNumber, const std::string &darkestSecret)
    : firstName(firstName),
      lastName(lastName),
      nickname(nickname),
      phoneNumber(phoneNumber),
      darkestSecret(darkestSecret) {}

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }

void Contact::setFirstName(const std::string &firstName) { this->firstName = firstName; }
void Contact::setLastName(const std::string &lastName) { this->lastName = lastName; }
void Contact::setNickname(const std::string &nickname) { this->nickname = nickname; }
void Contact::setPhoneNumber(const std::string &phoneNumber) { this->phoneNumber = phoneNumber; }
void Contact::setDarkestSecret(const std::string &darkestSecret) { this->darkestSecret = darkestSecret; }

}  // namespace phonebook