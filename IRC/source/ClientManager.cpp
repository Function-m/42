#include "ClientManager.hpp"
#include "Logging.hpp"

ClientManager& ClientManager::getInstance() {
    static ClientManager instance;
    return instance;
}

void ClientManager::addClient(int socket) {
    Client* client = new Client(socket);
    this->clients[socket] = client;
}

void ClientManager::removeClient(int socket) {
    if (this->clients.find(socket) != this->clients.end()) {
        delete this->clients[socket];
        this->clients.erase(socket);
    }
}

Client* ClientManager::getClient(int socket) {
    if (this->clients.find(socket) != this->clients.end()) {
        return this->clients[socket];
    } else {
        return NULL;
    }
}

Client* ClientManager::getClient(const std::string& nickname) {
    for (std::map<int, Client*>::iterator it = this->clients.begin(); it != this->clients.end(); ++it) {
        if (it->second->getNickname() == nickname) {
            return it->second;
        }
    }
    return NULL;
}

void ClientManager::sendMessageToClient(int clientSocket, const std::string& message) {
    Client* client = this->getClient(clientSocket);
    if (client) {
        client->sendMessage(message);
    }
}