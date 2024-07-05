#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <vector>
#include <set>

class Client {
   public:
	Client(int socket);
	~Client();

	int getSocket() const;
	void setSocket(int socket);
	std::string getUserInfo(int idx) const;
	std::string setUserInfo(int idx, const std::string& info);

	int getRegistrationStep() const;
	void setRegistrationStep(int step);

	void sendMessage(const std::string& message);
	std::vector<std::string> receiveMessages();
	std::set<std::string> getChannels() const;

	enum e_registrationStep { PASS, NICK, USER, REGISTERED, REGISTRATION_COUNT };
	enum e_userInfo { NICKNAME, USER_NAME, HOST_NAME, SERVER_NAME, REAL_NAME, INFO_COUNT };

   private:
	int clientSocket;
	int registrationStep;
	struct pollfd pollfd;
	std::string userInfo[INFO_COUNT];
	std::string commandBuffer;
	std::set<std::string> channels;

   public:
	class FatalError : public std::exception {
	   public:
		explicit FatalError(const std::string& msg) : message(msg) {}
		virtual ~FatalError() throw() {}
		virtual const char* what() const throw() {
			return message.c_str();
		}
	   private:
		std::string message;
	};

	class GeneralError : public std::exception {
	   public:
		explicit GeneralError(const std::string& msg) : message(msg) {}
		virtual ~GeneralError() throw() {}
		virtual const char* what() const throw() {
			return message.c_str();
		}
	   private:
		std::string message;
	};
};

#endif // CLIENT_HPP
