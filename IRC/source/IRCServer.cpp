#include "IRCServer.hpp"

#include <fcntl.h>
#include <netinet/in.h>
#include <unistd.h>

#include <sstream>
#include <stdexcept>

#include "ChannelManager.hpp"
#include "ClientManager.hpp"
#include "Command.hpp"
#include "StringUtils.hpp"

IRCServer &IRCServer::getInstance() {
	static IRCServer instance;
	return instance;
}

IRCServer::~IRCServer() {
	for (std::vector<struct pollfd>::iterator it = this->pollfds.begin(); it != this->pollfds.end(); ++it) {
		close(it->fd);
	}
}

void IRCServer::run(int port, const std::string &password) {
	// Initialize the server
	this->serverPassword = password;
	this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (this->serverSocket < 0) {
		throw IRCServer::FatalError("Socket creation failed");
	}
	sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	if (bind(this->serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
		throw IRCServer::FatalError("Socket binding failed");
	}
	if (listen(this->serverSocket, 5) < 0) {
		throw IRCServer::FatalError("Socket listening failed");
	}
	struct pollfd pfd;
	pfd.fd = this->serverSocket;
	pfd.events = POLLIN;
	this->pollfds.push_back(pfd);

	// Run the server
	while (true) {
		try {
			if (poll(&this->pollfds[0], this->pollfds.size(), -1)) {
				throw IRCServer::FatalError("Poll failed");
			}
			for (size_t i = 0; i < this->pollfds.size(); ++i) {
				// Accept new client
				if (this->pollfds[i].fd == this->serverSocket) {
					int clientSocket = accept(this->serverSocket, NULL, NULL);
					if (clientSocket < 0) {
						throw IRCServer::GeneralError("Client connection acceptance failed");
					}
					ClientManager::getInstance().addClient(clientSocket);
					StringUtils::logInfo("New client connected with socket: " + StringUtils::toString(clientSocket));
				// Process client message
				} else {
					this->processClientMessage(this->pollfds[i].fd);
				}
			}
		} catch (const IRCServer::GeneralError &e) {
			StringUtils::logError("General exception occurred while running the server: " + std::string(e.what()));
		}
	}
}

void IRCServer::processClientMessage(int clientSocket) {
	Client *client = ClientManager::getInstance().getClient(clientSocket);

	try {
		std::vector<std::string> messages = client->receiveMessages();
		for (std::vector<std::string>::iterator it = messages.begin(); it != messages.end(); ++it) {
			StringUtils::logDebug("Received from client " + StringUtils::toString(clientSocket) + ": " + *it);
			std::istringstream iss(*it);
			std::string commandName;
			std::vector<std::string> args;
			std::string arg;

			iss >> commandName;
			while (iss >> arg) {
				args.push_back(arg);
			}

			if (client->getRegistrationStep() != Client::REGISTERED) {
				Command::getInstance().handleRegistration(clientSocket, commandName, args);
			} else {
				Command::getInstance().handleCommand(clientSocket, commandName, args);
			}
		}
	} catch (const Client::FatalError &e) {
		ClientManager::getInstance().removeClient(clientSocket);
	}
}

void IRCServer::handleRegistration(int clientSocket, const std::string &commandName, const std::vector<std::string> &args) {
}

void IRCServer::handleCommand(int clientSocket, const std::string &commandName, const std::vector<std::string> &args) {

}

void IRCServer::addPollfds(int clientSocket) {
	struct pollfd pfd;
	pfd.fd = clientSocket;
	pfd.events = POLLIN;
	this->pollfds.push_back(pfd);
}

void IRCServer::removePollfds(int clientSocket) {
	for (std::vector<struct pollfd>::iterator it = this->pollfds.begin(); it != this->pollfds.end(); ++it) {
		if (it->fd == clientSocket) {
			this->pollfds.erase(it);
			break;
		}
	}
}
