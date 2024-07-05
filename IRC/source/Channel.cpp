#include "Channel.hpp"
#include <algorithm>
#include "ClientManager.hpp"
#include "ChannelManager.hpp"

Channel::Channel(const std::string& name, int creatorSocket) {
    if (name[0] != '#' || name.size() > 9 || name == "#root" || name == "#admin") {
        throw std::runtime_error("Invalid channel name");
    }
    this->channelInfo[NAME] = name;
    this->channelInfo[TOPIC] = "";
    this->channelInfo[LIMIT] = "0";
    this->channelInfo[PASSWORD] = "";
    this->channelInfo[INVITE_ONLY] = "0";

    addClientSocket(creatorSocket);
    addOperatorSocket(creatorSocket);
}

Channel::~Channel() {}

void Channel::addClientSocket(int clientSocket, const std::string password) {
    if (this->channelInfo[PASSWORD] != password) {
        throw std::runtime_error("Invalid password");
    }
    if (this->channelInfo[INVITE_ONLY] == "1" && this->inviteSockets.find(clientSocket) == this->inviteSockets.end()) {
        throw std::runtime_error("You need to be invited to join this channel");
    }
    if (this->channelInfo[LIMIT] != "0" && this->clientSockets.size() >= std::stoi(this->channelInfo[LIMIT])) {
        throw std::runtime_error("Channel is full");
    }
    if (this->channelInfo[TOPIC] != "") {
        (ClientManager::getInstance().getClient(clientSocket))->sendMessage("TOPIC " + this->channelInfo[TOPIC]);
    }
    this->clientSockets.insert(clientSocket);
}

void Channel::removeClientSocket(int clientSocket) {
    this->clientSockets.erase(clientSocket);
    this->removeOperatorSocket(clientSocket);
    if (this->clientSockets.empty()) {
        ChannelManager::getInstance().removeChannel(this->channelInfo[NAME]);
    }
}

void Channel::addInviteSocket(int clientSocket) {
    this->inviteSockets.insert(clientSocket);
}

void Channel::removeInviteSocket(int clientSocket) {
    this->inviteSockets.erase(clientSocket);
}

void Channel::setInfo(int idx, const std::string info) {
    std::string message;
    if (info == this->channelInfo[idx]) {
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
		case NAME:
			throw std::runtime_error("Cannot change channel name");
			break;
        case LIMIT:
			if (std::stoi(info) < this->clientSockets.size()) {
				throw std::runtime_error("Cannot set limits lower than current number of clients");
			}
            message = "LIMITS";
			break;
		default:
			return;
	}
    if (info == "") {
        this->broadcastMessage("Channel " + this->channelInfo[NAME] + " " + message + " has been removed", -1);
    } else {
        this->broadcastMessage("Channel " + this->channelInfo[NAME] + " " + message + " has been updated", -1);
    }
    this->channelInfo[idx] = info;
}

std::string Channel::getInfo(int idx) const {
    if (idx < 0 || idx >= INFO_COUNT) {
        throw std::runtime_error("Invalid info index");
    }
    return this->channelInfo[idx];
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
    return this->operatorSockets.find(clientSocket) != this->operatorSockets.end();
}

void Channel::addOperatorSocket(int clientSocket) {
    this->operatorSockets.insert(clientSocket);
}

void Channel::removeOperatorSocket(int clientSocket) {
    this->operatorSockets.erase(clientSocket);
    if (!this->clientSockets.empty() && this->operatorSockets.empty()) {
        this->addOperatorSocket(*this->clientSockets.begin());
    }
}
