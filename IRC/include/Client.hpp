#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <netinet/in.h>

#include <string>
#include <vector>

class Client {
   public:
	Client(int socket);
	~Client();

	void sendMessage(const std::string& message);
	std::vector<std::string> receiveMessages();
	std::string getNickname() const;
	void setNickname(const std::string& nickname);

   private:
	int clientSocket;
	std::string nickname;
	std::string buffer;	 // Command buffer
};

#endif	// CLIENT_HPP
