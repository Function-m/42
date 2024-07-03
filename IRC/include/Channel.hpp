#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <string>
#include <vector>
#include "Client.hpp"

class Channel {
public:
	Channel(const std::string& name);
	~Channel();

	std::string getName() const;
	void addClient(int clientSocket);
	void removeClient(int clientSocket);
	void broadcastMessage(const std::string& message, int senderSocket);

private:
	std::string channelName;
	std::vector<int> clientSockets;
};

#endif // CHANNEL_HPP
