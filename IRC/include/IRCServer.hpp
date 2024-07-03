
#ifndef IRCSERVER_HPP
#define IRCSERVER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <poll.h>

class IRCServer {
public:
	static IRCServer& getInstance();
	void run(int port, const std::string& password);
	void stop();
	int getServerSocket() const;
	void setServerSocket(int socket);
	std::string getServerPassword() const;
	void setServerPassword(const std::string& password);

private:
	IRCServer() {}
	IRCServer(const IRCServer&);
	IRCServer& operator=(const IRCServer&);
	void acceptNewClient();
	void processClientMessage(int clientSocket);
	void removeClient(int clientSocket);

	int serverSocket;
	std::string serverPassword;
	std::vector<struct pollfd> pollfds;
};

#endif // IRCSERVER_HPP
