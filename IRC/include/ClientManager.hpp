
#ifndef CLIENTMANAGER_HPP
#define CLIENTMANAGER_HPP

#include <map>
#include <vector>
#include <string>
#include "Client.hpp"

class ClientManager {
public:
	static ClientManager& getInstance();
	void addClient(int socket);
	void removeClient(int socket);
	Client* getClient(int socket);
	Client* getClient(const std::string& nickname);
	void sendMessageToClient(int clientSocket, const std::string& message);

private:
	ClientManager() {}
	ClientManager(const ClientManager&);
	ClientManager& operator=(const ClientManager&);

	std::map<int, Client*> clients;
};

#endif // CLIENTMANAGER_HPP
