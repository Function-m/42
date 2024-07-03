
#include "IRCServer.hpp"

#include <fcntl.h>
#include <netinet/in.h>
#include <unistd.h>

#include <sstream>
#include <stdexcept>

#include "ChannelManager.hpp"
#include "ClientManager.hpp"
#include "Command.hpp"
#include "Logging.hpp"

IRCServer &IRCServer::getInstance() {
	static IRCServer instance;
	return instance;
}

void IRCServer::run(int port, const std::string &password) {
	this->serverPassword = password;
	this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (this->serverSocket < 0) {
		throw std::runtime_error("Socket creation failed");
	}
	LOG_INFO("Socket created successfully");

	sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);
	serverAddr.sin_addr.s_addr = INADDR_ANY;

	if (bind(this->serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
		throw std::runtime_error("Socket binding failed");
	}
	LOG_INFO("Socket bound to port " + std::to_string(port));

	if (listen(this->serverSocket, 5) < 0) {
		throw std::runtime_error("Socket listening failed");
	}
	LOG_INFO("Socket is listening");

	struct pollfd pfd;
	pfd.fd = this->serverSocket;
	pfd.events = POLLIN;
	this->pollfds.push_back(pfd);

	LOG_INFO("IRC server started on port " + std::to_string(port));

	while (true) {
		int pollCount = poll(&this->pollfds[0], this->pollfds.size(), -1);
		if (pollCount < 0) {
			throw std::runtime_error("Poll failed");
		}

		for (size_t i = 0; i < this->pollfds.size(); ++i) {
			if (this->pollfds[i].revents & POLLIN) {
				if (this->pollfds[i].fd == this->serverSocket) {
					this->acceptNewClient();
				} else {
					this->processClientMessage(this->pollfds[i].fd);
				}
			}
		}
	}
}

void IRCServer::stop() {
	close(this->serverSocket);
	ClientManager::getInstance().~ClientManager();
	this->pollfds.clear();
	LOG_INFO("Server stopped");
}

void IRCServer::acceptNewClient() {
	try {
		int clientSocket = accept(this->serverSocket, NULL, NULL);
		if (clientSocket < 0) {
			throw std::runtime_error("Client connection acceptance failed");
		}

		ClientManager::getInstance().addClient(clientSocket);

		struct pollfd pfd;
		pfd.fd = clientSocket;
		pfd.events = POLLIN;
		this->pollfds.push_back(pfd);

		LOG_INFO("New client connected with socket: " + std::to_string(clientSocket));
	} catch (const std::exception &e) {
		LOG_ERROR("Exception occurred while accepting a client: " + std::string(e.what()));
	}
}

void IRCServer::processClientMessage(int clientSocket) {
	Client *client = ClientManager::getInstance().getClient(clientSocket);
	CommandFactory &commandFactory = CommandFactory::getInstance();

	try {
		std::vector<std::string> messages = client->receiveMessages();
		for (std::vector<std::string>::iterator it = messages.begin(); it != messages.end(); ++it) {
			LOG_DEBUG("Received from client " + std::to_string(clientSocket) + ": " + *it);
			std::istringstream iss(*it);
			std::string commandName;
			std::vector<std::string> args;
			std::string arg;

			iss >> commandName;
			while (iss >> arg) {
				args.push_back(arg);
			}

			Command *command = commandFactory.getCommand(commandName);
			if (command) {
				LOG_DEBUG("Executing command: " + commandName + " from client: " + std::to_string(clientSocket));
				command->execute(clientSocket, args);
			} else {
				std::string errorMsg = "ERROR: Unknown command: " + commandName;
				ClientManager::getInstance().sendMessageToClient(clientSocket, errorMsg);
				LOG_ERROR("Unknown command received from client " + std::to_string(clientSocket) + ": " + commandName);
			}
		}
	} catch (const std::exception &e) {
		LOG_ERROR("Exception occurred while handling a client: " + std::string(e.what()));
		close(clientSocket);
		this->removeClient(clientSocket);
	}
}

void IRCServer::removeClient(int clientSocket) {
	ClientManager::getInstance().removeClient(clientSocket);

	for (std::vector<struct pollfd>::iterator it = this->pollfds.begin(); it != this->pollfds.end(); ++it) {
		if (it->fd == clientSocket) {
			this->pollfds.erase(it);
			break;
		}
	}
	LOG_INFO("Client removed: " + std::to_string(clientSocket));
}

int IRCServer::getServerSocket() const {
	return this->serverSocket;
}

void IRCServer::setServerSocket(int socket) {
	this->serverSocket = socket;
}

std::string IRCServer::getServerPassword() const {
	return this->serverPassword;
}

void IRCServer::setServerPassword(const std::string &password) {
	this->serverPassword = password;
}
