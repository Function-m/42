#include "Channel.hpp"
#include <algorithm>
#include "ClientManager.hpp"

Channel::Channel(const std::string& name) : channelName(name) {}

Channel::~Channel() {}

std::string Channel::getName() const {
	return this->channelName;
}

void Channel::addClient(int clientSocket) {
	this->clientSockets.push_back(clientSocket);
}

void Channel::removeClient(int clientSocket) {
	this->clientSockets.erase(std::remove(this->clientSockets.begin(), this->clientSockets.end(), clientSocket), this->clientSockets.end());
}

void Channel::broadcastMessage(const std::string& message, int senderSocket) {
	ClientManager& clientManager = ClientManager::getInstance();
	for (std::vector<int>::iterator it = this->clientSockets.begin(); it != this->clientSockets.end(); ++it) {
		if (*it != senderSocket) {
			Client* client = clientManager.getClient(*it);
			if (client) {
				client->sendMessage(message);
			}
		}
	}
}
