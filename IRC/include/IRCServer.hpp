#ifndef IRCSERVER_HPP
#define IRCSERVER_HPP

#include <poll.h>

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Client.hpp"
#include "Command.hpp"

class IRCServer {
   public:
	static IRCServer& getInstance();
	void start(int port, const std::string& password);
	void stop();
	void setNickname(int clientSocket, const std::string& nickname);

   private:
	IRCServer() {}
	IRCServer(const IRCServer&);
	IRCServer& operator=(const IRCServer&);
	void acceptClient();
	void handleClient(int clientSocket);
	void removeClient(int clientSocket);

	int serverSocket;
	std::string serverPassword;
	std::map<int, Client*> clients;
	std::vector<struct pollfd> pollfds;
};

#endif	// IRCSERVER_HPP
