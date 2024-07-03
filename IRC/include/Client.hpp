
#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <vector>

class Client {
public:
	Client(int socket);
	~Client();

	int getSocket() const;
	void setSocket(int socket);
	std::string getNickname() const;
	void setNickname(const std::string& nickname);

	void sendMessage(const std::string& message);
	std::vector<std::string> receiveMessages();

private:
	int clientSocket;
	std::string nickname;
	std::string commandBuffer;
};

#endif // CLIENT_HPP
