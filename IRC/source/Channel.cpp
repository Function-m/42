
#include "Channel.hpp"
#include <algorithm>
#include "ClientManager.hpp"
#include "ChannelManager.hpp"

Channel::Channel(const std::string& name, Client* creator) : channelName(name) {
	addClient(creator->getSocket());
	addOperator(creator->getSocket());
}

Channel::~Channel() {}

std::string Channel::getName() const {
	return this->channelName;
}

void Channel::addClient(int clientSocket) {
	this->clientSockets.push_back(clientSocket);
}

void Channel::removeClient(int clientSocket) {
	this->clientSockets.erase(std::remove(this->clientSockets.begin(), this->clientSockets.end(), clientSocket), this->clientSockets.end());
	removeOperator(clientSocket);
	if (this->clientSockets.empty()) {
		ChannelManager::getInstance().removeChannel(this->channelName);
	} else if (this->operators.empty()) {
		handleOperatorLeft();
	}
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

bool Channel::isOperator(int clientSocket) const {
	std::map<int, bool>::const_iterator it = this->operators.find(clientSocket);
	return it != this->operators.end() && it->second;
}

void Channel::addOperator(int clientSocket) {
	this->operators[clientSocket] = true;
}

void Channel::removeOperator(int clientSocket) {
	this->operators.erase(clientSocket);
}

void Channel::handleOperatorLeft() {
	if (!this->clientSockets.empty()) {
		addOperator(this->clientSockets.front());
	}
}
