
#include "ClientManager.hpp"
#include "Logging.hpp"

ClientManager& ClientManager::getInstance() {
	static ClientManager instance;
	return instance;
}

void ClientManager::addClient(int socket) {
	Client* client = new Client(socket);
	this->clients[socket] = client;
	LOG_INFO("Client added with socket: " + std::to_string(socket));
}

void ClientManager::removeClient(int socket) {
	if (this->clients.find(socket) != this->clients.end()) {
		delete this->clients[socket];
		this->clients.erase(socket);
		LOG_INFO("Client removed with socket: " + std::to_string(socket));
	}
}

Client* ClientManager::getClient(int socket) {
	if (this->clients.find(socket) != this->clients.end()) {
		return this->clients[socket];
	} else {
		LOG_ERROR("Client not found with socket: " + std::to_string(socket));
		return NULL;
	}
}

Client* ClientManager::getClient(const std::string& nickname) {
	for (std::map<int, Client*>::iterator it = this->clients.begin(); it != this->clients.end(); ++it) {
		if (it->second->getNickname() == nickname) {
			return it->second;
		}
	}
	LOG_ERROR("Client not found with nickname: " + nickname);
	return NULL;
}

void ClientManager::sendMessageToClient(int clientSocket, const std::string& message) {
	Client* client = this->getClient(clientSocket);
	if (client) {
		client->sendMessage(message);
	}
}