#ifndef CLIENTMANAGER_HPP
#define CLIENTMANAGER_HPP

#include <map>
#include <string>

#include "Client.hpp"

class ClientManager {
   public:
	// Singleton
	static ClientManager& getInstance();

	// For communication
	void sendMessageToClient(int clientSocket, const std::string& message);

	// Methods for "clients"
	void addClient(int socket);
	void removeClient(int socket);
	Client* getClient(int socket);					 // Search by socket
	Client* getClient(const std::string& nickname);	 // Search by nickname
	int countClients() const;

   private:
	// No instantiation outside for singletones!!
	ClientManager() {}
	ClientManager(const ClientManager&);
	ClientManager& operator=(const ClientManager&);

	// Key : client socket / Value: Client object
	std::map<int, Client*> clients;
};

#endif	// CLIENTMANAGER_HPP
