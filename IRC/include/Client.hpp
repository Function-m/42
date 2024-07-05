#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <vector>
#include <set>
#include <poll.h>

class Client {
   public:
	Client(int socket);
	~Client();

	// For communication
	void sendMessage(const std::string& message);
	std::vector<std::string> receiveMessages();

	// Methods for "clientSocket"
	int getSocket() const;
	void setSocket(int socket);

	// Methods for "registrationStep"
	enum e_registrationStep { PASS, NICK, USER, REGISTERED, REGISTRATION_COUNT };
	int getRegistrationStep() const;
	void setRegistrationStep(int step);

	// Methods for "UserInfo"
	enum e_userInfo { NICKNAME, USER_NAME, HOST_NAME, SERVER_NAME, REAL_NAME, INFO_COUNT };
	std::string getUserInfo(int idx) const;
	std::string setUserInfo(int idx, const std::string& info);

   private:
	int clientSocket;
	int registrationStep;
	std::string userInfo[INFO_COUNT];
	std::string commandBuffer;

   // Exception classes
   public:
	class FatalError : public std::runtime_error {
	   public:
		explicit FatalError(const std::string& message) : std::runtime_error(message) {}
		virtual ~FatalError() throw() {}
	};
   private:
	class GeneralError : public std::runtime_error {
	   public:
		explicit GeneralError(const std::string& message) : std::runtime_error(message) {}
		virtual ~GeneralError() throw() {}
	};
};

#endif	// CLIENT_HPP
