#ifndef MY_AWESOME_PHONEBOOK_CONTACT_H_
#define MY_AWESOME_PHONEBOOK_CONTACT_H_

#include <string>

namespace phonebook {

class Contact {
 public:
  Contact();
  Contact(const std::string& firstName, const std::string& lastName, const std::string& nickname, const std::string& phoneNumber, const std::string& darkestSecret);

  std::string getFirstName() const;
  std::string getLastName() const;
  std::string getNickname() const;
  std::string getPhoneNumber() const;
  std::string getDarkestSecret() const;

  void setFirstName(const std::string& firstName);
  void setLastName(const std::string& lastName);
  void setNickname(const std::string& nickname);
  void setPhoneNumber(const std::string& phoneNumber);
  void setDarkestSecret(const std::string& darkestSecret);

 private:
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;
};

}  // namespace phonebook

#endif  // MY_AWESOME_PHONEBOOK_CONTACT_H_