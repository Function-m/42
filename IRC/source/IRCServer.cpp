#include "IRCServer.hpp"

#include <fcntl.h>
#include <netinet/in.h>
#include <unistd.h>

#include <algorithm>
#include <sstream>
#include <stdexcept>

IRCServer& IRCServer::getInstance() {
	static IRCServer instance;
	return instance;
}

void IRCServer::start(int port, const std::string& password) {
	try {
		serverPassword = password;
		serverSocket = socket(AF_INET, SOCK_STREAM, 0);
		if (serverSocket < 0) {
			throw std::runtime_error("Socket creation failed");
		}

		sockaddr_in serverAddr;
		serverAddr.sin_family = AF_INET;
		serverAddr.sin_port = htons(port);
		serverAddr.sin_addr.s_addr = INADDR_ANY;

		if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
			throw std::runtime_error("Socket binding failed");
		}

		if (listen(serverSocket, 5) < 0) {
			throw std::runtime_error("Socket listening failed");
		}

		struct pollfd pfd;
		pfd.fd = serverSocket;
		pfd.events = POLLIN;
		pollfds.push_back(pfd);

		std::cout << "IRC server started on port " << port << std::endl;

		while (true) {
			int pollCount = poll(&pollfds[0], pollfds.size(), -1);
			if (pollCount < 0) {
				throw std::runtime_error("Poll failed");
			}

			for (size_t i = 0; i < pollfds.size(); ++i) {
				if (pollfds[i].revents & POLLIN) {
					if (pollfds[i].fd == serverSocket) {
						acceptClient();
					} else {
						handleClient(pollfds[i].fd);
					}
				}
			}
		}
	} catch (const std::exception& e) {
		std::cerr << "Exception occurred while running the server: " << e.what() << std::endl;
		stop();
	}
}

void IRCServer::stop() {
	close(serverSocket);
	// Close all client sockets and free memory
	for (std::map<int, Client*>::iterator it = clients.begin(); it != clients.end(); ++it) {
		delete it->second;
	}
	clients.clear();
	pollfds.clear();
}

void IRCServer::acceptClient() {
	try {
		int clientSocket = accept(serverSocket, NULL, NULL);
		if (clientSocket < 0) {
			throw std::runtime_error("Client connection acceptance failed");
		}

		// Create client object and add to map
		clients[clientSocket] = new Client(clientSocket);

		struct pollfd pfd;
		pfd.fd = clientSocket;
		pfd.events = POLLIN;
		pollfds.push_back(pfd);

		std::cout << "New client connected" << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception occurred while accepting a client: " << e.what() << std::endl;
	}
}

void IRCServer::handleClient(int clientSocket) {
	Client* client = clients[clientSocket];
	CommandFactory commandFactory;

	try {
		std::vector<std::string> messages = client->receiveMessages();
		for (std::vector<std::string>::iterator it = messages.begin(); it != messages.end(); ++it) {
			std::istringstream iss(*it);
			std::string commandName;
			std::vector<std::string> args;
			std::string arg;

			iss >> commandName;
			while (iss >> arg) {
				args.push_back(arg);
			}

			Command* command = commandFactory.getCommand(commandName);
			if (command) {
				command->execute(clientSocket, args);
			} else {
				client->sendMessage("ERROR: Unknown command\n");
			}
		}
	} catch (const std::exception& e) {
		std::cerr << "Exception occurred while handling a client: " << e.what() << std::endl;
		close(clientSocket);
		removeClient(clientSocket);
	}
}

void IRCServer::removeClient(int clientSocket) {
	if (clients.find(clientSocket) != clients.end()) {
		delete clients[clientSocket];
		clients.erase(clientSocket);
	}

	for (std::vector<struct pollfd>::iterator it = pollfds.begin(); it != pollfds.end(); ++it) {
		if (it->fd == clientSocket) {
			pollfds.erase(it);
			break;
		}
	}
}

void IRCServer::setNickname(int clientSocket, const std::string& nickname) {
	if (clients.find(clientSocket) != clients.end()) {
		clients[clientSocket]->setNickname(nickname);
	}
}
