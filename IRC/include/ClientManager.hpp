#ifndef CLIENTMANAGER_HPP
#define CLIENTMANAGER_HPP

#include <map>
#include "Client.hpp"

class ClientManager {
public:
	static ClientManager& getInstance();
	void addClient(int socket);
	void removeClient(int socket);
	Client* getClient(int socket);
	Client* getClient(const std::string& nickname);

private:
	ClientManager() {}
	ClientManager(const ClientManager&);
	ClientManager& operator=(const ClientManager&);

	std::map<int, Client*> clients;
};

#endif // CLIENTMANAGER_HPP
