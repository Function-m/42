#include "Channel.hpp"
#include <algorithm>
#include "ClientManager.hpp"
#include "ChannelManager.hpp"

Channel::Channel(const std::string& name, int creatorSocket) {
    if (name[0] != '#' || name.size() > 9 || name == "#root" || name == "#admin") {
        throw std::runtime_error("Invalid channel name");
    }
    this->chatInfo[CHAT_NAME] = name;
    this->chatInfo[TOPIC] = "";
    this->chatInfo[LIMITS] = "0";
    this->chatInfo[PASSWORD] = "";
    this->chatInfo[INVITE_ONLY] = "0";

    addClient(creatorSocket);
    addOperator(creatorSocket);
}

Channel::~Channel() {}

void Channel::addClient(int clientSocket, const std::string password) {
    if (this->chatInfo[PASSWORD] != password) {
        throw std::runtime_error("Invalid password");
    }
    if (this->chatInfo[INVITE_ONLY] == "1" && this->inviteSockets.find(clientSocket) == this->inviteSockets.end()) {
        throw std::runtime_error("You need to be invited to join this channel");
    }
    if (this->chatInfo[LIMITS] != "0" && this->clientSockets.size() >= std::stoi(this->chatInfo[LIMITS])) {
        throw std::runtime_error("Channel is full");
    }
    if (this->chatInfo[TOPIC] != "") {
        (ClientManager::getInstance().getClient(clientSocket))->sendMessage("TOPIC " + this->chatInfo[TOPIC]);
    }
    this->clientSockets.insert(clientSocket);
}

void Channel::removeClient(int clientSocket) {
    this->clientSockets.erase(clientSocket);
    this->removeOperator(clientSocket);
    if (this->clientSockets.empty()) {
        ChannelManager::getInstance().removeChannel(this->chatInfo[CHAT_NAME]);
    }
}

void Channel::addInvite(int clientSocket) {
    this->inviteSockets.insert(clientSocket);
}

void Channel::removeInvite(int clientSocket) {
    this->inviteSockets.erase(clientSocket);
}

void Channel::setInfo(int idx, const std::string info) {
    std::string message;
    if (info == this->chatInfo[idx]) {
        return;
    }
    switch (idx) {
		case TOPIC:
            if (info.size() > 50) {
                throw std::runtime_error("Topic is too long");
            }
			message = "TOPIC";
			break;
		case PASSWORD:
            if (info.size() > 50) {
                throw std::runtime_error("Password is too long");
            }
			message = "PASSWORD";
			break;
		case INVITE_ONLY:
            if (info != "0" && info != "1") {
                throw std::runtime_error("Invalid invite only value");
            }
			message = "INVITE_ONLY";
			break;
		case CHAT_NAME:
			throw std::runtime_error("Cannot change channel name");
			break;
        case LIMITS:
			if (std::stoi(info) < this->clientSockets.size()) {
				throw std::runtime_error("Cannot set limits lower than current number of clients");
			}
            message = "LIMITS";
			break;
		default:
			return;
	}
    if (info == "") {
        this->broadcastMessage("Channel " + this->chatInfo[CHAT_NAME] + " " + message + " has been removed", -1);
    } else {
        this->broadcastMessage("Channel " + this->chatInfo[CHAT_NAME] + " " + message + " has been updated", -1);
    }
    this->chatInfo[idx] = info;
}

std::string Channel::getInfo(int idx) const {
    if (idx < 0 || idx >= INFO_COUNT) {
        throw std::runtime_error("Invalid info index");
    }
    return this->chatInfo[idx];
}

void Channel::broadcastMessage(const std::string& message, int senderSocket) {
    ClientManager& clientManager = ClientManager::getInstance();
    for (std::set<int>::iterator it = this->clientSockets.begin(); it != this->clientSockets.end(); ++it) {
        if (*it != senderSocket) {
            (clientManager.getClient(*it))->sendMessage(message);
        }
    }
}

bool Channel::isOperator(int clientSocket) const {
    return this->operators.find(clientSocket) != this->operators.end();
}

void Channel::addOperator(int clientSocket) {
    this->operators.insert(clientSocket);
}

void Channel::removeOperator(int clientSocket) {
    this->operators.erase(clientSocket);
    if (!this->clientSockets.empty() && this->operators.empty()) {
        this->addOperator(*this->clientSockets.begin());
    }
}
