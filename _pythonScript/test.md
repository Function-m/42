### 42/IRC/include/ClientManager.hpp

```cpp
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
```

### 42/IRC/include/Channel.hpp

```cpp
#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <string>
#include <vector>
#include <map>
#include "Client.hpp"

class Channel {
public:
	Channel(const std::string& name, Client* creator);
	~Channel();

	std::string getName() const;
	void addClient(int clientSocket);
	void removeClient(int clientSocket);
	void broadcastMessage(const std::string& message, int senderSocket);
	bool isOperator(int clientSocket) const;
	void addOperator(int clientSocket);
	void removeOperator(int clientSocket);
	void handleOperatorLeft();

private:
	std::string channelName;
	std::vector<int> clientSockets;
	std::map<int, bool> operators;
};

#endif // CHANNEL_HPP
```

### 42/IRC/include/ChannelManager.hpp

```cpp
#ifndef CHANNELMANAGER_HPP
#define CHANNELMANAGER_HPP

#include <map>
#include <string>
#include "Channel.hpp"

class Client;

class ChannelManager {
public:
	static ChannelManager& getInstance();
	Channel* getChannel(const std::string& name);
	void createChannel(const std::string& name, Client* creator);
	void removeChannel(const std::string& name);

private:
	ChannelManager() {}
	ChannelManager(const ChannelManager&);
	ChannelManager& operator=(const ChannelManager&);

	std::map<std::string, Channel*> channels;
};

#endif // CHANNELMANAGER_HPP
```

### 42/IRC/include/Command.hpp

```cpp
#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <vector>
#include <string>
#include <map>

// Command abstract class
class Command {
public:
	virtual ~Command() {}
	virtual void execute(int clientSocket, const std::vector<std::string>& args) = 0;
};

// NICK command class
class NickCommand : public Command {
public:
	void execute(int clientSocket, const std::vector<std::string>& args);
};

// USER command class
class UserCommand : public Command {
public:
	void execute(int clientSocket, const std::vector<std::string>& args);
};

// JOIN command class
class JoinCommand : public Command {
public:
	void execute(int clientSocket, const std::vector<std::string>& args);
};

// PART command class
class PartCommand : public Command {
public:
	void execute(int clientSocket, const std::vector<std::string>& args);
};

// PRIVMSG command class
class PrivmsgCommand : public Command {
public:
	void execute(int clientSocket, const std::vector<std::string>& args);
};

// KICK command class
class KickCommand : public Command {
public:
	void execute(int clientSocket, const std::vector<std::string>& args);
};

// INVITE command class
class InviteCommand : public Command {
public:
	void execute(int clientSocket, const std::vector<std::string>& args);
};

// TOPIC command class
class TopicCommand : public Command {
public:
	void execute(int clientSocket, const std::vector<std::string>& args);
};

// MODE command class
class ModeCommand : public Command {
public:
	void execute(int clientSocket, const std::vector<std::string>& args);
};

// CAP command class
class CapCommand : public Command {
public:
	void execute(int clientSocket, const std::vector<std::string>& args);
};

// Command factory class
class CommandFactory {
public:
	static CommandFactory& getInstance();
	Command* getCommand(const std::string& commandName);

private:
	CommandFactory();
	~CommandFactory();
	CommandFactory(const CommandFactory&);
	CommandFactory& operator=(const CommandFactory&);

	std::map<std::string, Command*> commands;
};

#endif // COMMAND_HPP
```

### 42/IRC/include/IRCServer.hpp

```cpp
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
```

### 42/IRC/include/Client.hpp

```cpp
#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <vector>

class Client {
public:
	Client(int socket);
	~Client();

	int getSocket() const;
	void setSocket(int socket);
	std::string getNickname() const;
	void setNickname(const std::string& nickname);

	void sendMessage(const std::string& message);
	std::vector<std::string> receiveMessages();

private:
	int clientSocket;
	std::string nickname;
	std::string commandBuffer;
};

#endif // CLIENT_HPP
```

### 42/IRC/include/Logging.hpp

```cpp
#ifndef _DEBUG_HPP
#define _DEBUG_HPP

#include <iostream>

#ifdef ENABLE_DEBUG
#define LOG_DEBUG(message) std::cout << "\x1b[36m[DEBUG] \x1b[0m" << message << std::endl
#else
#define LOG_DEBUG(message)
#endif

#define LOG_INFO(message)  std::cout << "\x1b[32m[INFO]  \x1b[0m" << message << std::endl
#define LOG_ERROR(message) std::cerr << "\x1b[31m[ERROR] \x1b[0m" << message << std::endl

#endif // _DEBUG_HPP
```

### 42/IRC/source/IRCServer.cpp

```cpp
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
		for

 (std::vector<std::string>::iterator it = messages.begin(); it != messages.end(); ++it) {
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
```

### 42/IRC/source/Client.cpp

```cpp
#include "Client.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <sstream>
#include <stdexcept>

Client::Client(int socket) : clientSocket(socket) {
	int flags = fcntl(this->clientSocket, F_GETFL, 0);
	fcntl(this->clientSocket, F_SETFL, flags | O_NONBLOCK);
}

Client::~Client() {
	close(this->clientSocket);
}

int Client::getSocket() const {
	return this->clientSocket;
}

void Client::setSocket(int socket) {
	this->clientSocket = socket;
}

std::string Client::getNickname() const {
	return this->nickname;
}

void Client::setNickname(const std::string& nickname) {
	this->nickname = nickname;
}

void Client::sendMessage(const std::string& message) {
	send(this->clientSocket, message.c_str(), message.size(), 0);
}

std::vector<std::string> Client::receiveMessages() {
	char buffer[1024];
	int bytesReceived = recv(this->clientSocket, buffer, sizeof(buffer) - 1, 0);
	std::vector<std::string> messages;
	if (bytesReceived > 0) {
		buffer[bytesReceived] = '\0';
		this->commandBuffer += buffer;

		std::string::size_type pos;
		while ((pos = this->commandBuffer.find("\r\n")) != std::string::npos) {
			std::string message = this->commandBuffer.substr(0, pos);
			messages.push_back(message);
			this->commandBuffer.erase(0, pos + 2);
		}
	} else if (bytesReceived == 0) {
		// Client closed connection
		close(this->clientSocket);
		throw std::runtime_error("Client connection closed");
	} else if (bytesReceived < 0 && errno != EWOULDBLOCK) {
		// recv failed
		close(this->clientSocket);
		throw std::runtime_error("recv failed");
	}
	return messages;
}
```

### 42/IRC/source/Channel.cpp

```cpp
#include "Channel.hpp"
#include <algorithm>
#include "ClientManager.hpp"
#include "ChannelManager.hpp"

Channel::Channel(const std::string& name, Client* creator) : channelName(name) {
	addClient(creator->getSocket());
	addOperator(creator->getSocket());
}

Channel::~Channel() {}

std::string Channel::getName() const {
	return this->channelName;
}

void Channel::addClient(int clientSocket) {
	this->clientSockets.push_back(clientSocket);
}

void Channel::removeClient(int clientSocket) {
	this->clientSockets.erase(std::remove(this->clientSockets.begin(), this->clientSockets.end(), clientSocket), this->clientSockets.end());
	removeOperator(clientSocket);
	if (this->clientSockets.empty()) {
		ChannelManager::getInstance().removeChannel(this->channelName);
	} else if (this->operators.empty()) {
		handleOperatorLeft();
	}
}

void Channel::broadcastMessage(const std::string& message, int senderSocket) {
	ClientManager& clientManager = ClientManager::getInstance();
	for (std::vector<int>::iterator it = this->clientSockets.begin(); it != this->clientSockets.end(); ++it) {
		if (*it != senderSocket) {
			Client* client = clientManager.getClient(*it);
			if (client) {
				client->sendMessage(message);
			}
		}
	}
}

bool Channel::isOperator(int clientSocket) const {
	std::map<int, bool>::const_iterator it = this->operators.find(clientSocket);
	return it != this->operators.end() && it->second;
}

void Channel::addOperator(int clientSocket) {
	this->operators[clientSocket] = true;
}

void Channel::removeOperator(int clientSocket) {
	this->operators.erase(clientSocket);
}

void Channel::handleOperatorLeft() {
	if (!this->clientSockets.empty()) {
		addOperator(this->clientSockets.front());
	}
}
```

### 42/IRC/source/ChannelManager.cpp

```cpp
#include "ChannelManager.hpp"
#include "ClientManager.hpp"
#include "Client.hpp"

ChannelManager& ChannelManager::getInstance() {
	static ChannelManager instance;
	return instance;
}

Channel* ChannelManager::getChannel(const std::string& name) {
	if (this->channels.find(name) != this->channels.end()) {
		return this->channels[name];
	} else {
		return NULL;
	}
}

void ChannelManager::createChannel(const std::string& name, Client* creator) {
	if (this->channels.find(name) == this->channels.end()) {
		this->channels[name] = new Channel(name, creator);
	}
}

void ChannelManager::removeChannel(const std::string& name) {
	if (this->channels.find(name) != this->channels.end()) {
		delete this->channels[name];
		this->channels.erase(name);
	}
}
```

### 42/IRC/source/Command.cpp

```cpp
#include "Command.hpp"
#include "Logging.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <sstream>
#include <stdexcept>
#include "IRCServer.hpp"
#include "ClientManager.hpp"
#include "ChannelManager.hpp"

// NICK command class implementation
void NickCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 2) {
		ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: Nickname required\n");
		return;
	}
	std::string nickname = args[1];
	Client* client = ClientManager::getInstance().getClient(clientSocket);
	if (client) {
		client->setNickname(nickname);
		LOG_INFO("Client " + std::to_string(clientSocket) + " set nickname to " + nickname);
	}
}

// USER command class implementation
void UserCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 5) {
		ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: USER command requires 4 parameters\n");
		return;
	}
	LOG_INFO("USER command received from client " + std::to_string(clientSocket));
}

// JOIN command class implementation
void JoinCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 2 || args[1].empty()) {
		ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: Channel name required\n");
		LOG_ERROR("JOIN command received with no channel name from client " + std::to_string(clientSocket));
		return;
	}
	std::string channelName = args[1];
	ChannelManager& channelManager = ChannelManager::getInstance();
	Channel* channel = channelManager.getChannel(channelName);
	Client* client = ClientManager::getInstance().getClient(clientSocket);
	if (!channel) {
		channelManager.createChannel(channelName, client);
		channel = channelManager.getChannel(channelName);
		LOG_INFO("Channel created: " + channelName);
	}
	channel->addClient(clientSocket);
	if (client) {
		std::string joinMessage = client->getNickname() + " has joined the channel\n";
		channel->broadcastMessage(joinMessage, clientSocket);
		LOG_INFO("Client " + std::to_string(clientSocket) + " joined channel " + channelName);
	}
}

// PART command class implementation
void PartCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 2) {


		ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: Channel name required\n");
		return;
	}
	std::string channelName = args[1];
	Channel* channel = ChannelManager::getInstance().getChannel(channelName);
	if (channel) {
		channel->removeClient(clientSocket);
		Client* client = ClientManager::getInstance().getClient(clientSocket);
		if (client) {
			std::string partMessage = client->getNickname() + " has left the channel\n";
			channel->broadcastMessage(partMessage, clientSocket);
			LOG_INFO("Client " + std::to_string(clientSocket) + " left channel " + channelName);
		}
	}
}

// PRIVMSG command class implementation
void PrivmsgCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 3) {
		ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: Recipient and message required\n");
		return;
	}
	std::string recipient = args[1];
	std::string message = args[2];
	Channel* channel = ChannelManager::getInstance().getChannel(recipient);
	if (channel) {
		Client* client = ClientManager::getInstance().getClient(clientSocket);
		if (client) {
			std::string privMessage = client->getNickname() + ": " + message + "\n";
			channel->broadcastMessage(privMessage, clientSocket);
			LOG_INFO("Client " + std::to_string(clientSocket) + " sent message to channel " + recipient + ": " + message);
		}
	}
}

// KICK command class implementation
void KickCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 3) {
		ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: User to kick and reason required\n");
		return;
	}
	std::string channelName = args[1];
	std::string userToKick = args[2];
	Channel* channel = ChannelManager::getInstance().getChannel(channelName);
	if (channel) {
		if (!channel->isOperator(clientSocket)) {
			ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: You are not an operator\n");
			return;
		}
		Client* kickClient = ClientManager::getInstance().getClient(userToKick);
		if (kickClient) {
			channel->removeClient(kickClient->getSocket());
			Client* client = ClientManager::getInstance().getClient(clientSocket);
			if (client) {
				std::string kickMessage = userToKick + " was kicked from the channel by " + client->getNickname() + "\n";
				channel->broadcastMessage(kickMessage, clientSocket);
				LOG_INFO("Client " + std::to_string(clientSocket) + " kicked " + userToKick + " from channel " + channelName);
			}
		}
	}
}

// INVITE command class implementation
void InviteCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 3) {
		ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: User to invite and channel name required\n");
		return;
	}
	std::string userToInvite = args[1];
	std::string channelName = args[2];
	Channel* channel = ChannelManager::getInstance().getChannel(channelName);
	if (channel) {
		if (!channel->isOperator(clientSocket)) {
			ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: You are not an operator\n");
			return;
		}
		Client* inviteClient = ClientManager::getInstance().getClient(userToInvite);
		if (inviteClient) {
			std::string inviteMessage = "You have been invited to join " + channelName + "\n";
			inviteClient->sendMessage(inviteMessage);
			LOG_INFO("Client " + std::to_string(clientSocket) + " invited " + userToInvite + " to channel " + channelName);
		}
	}
}

// TOPIC command class implementation
void TopicCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 3) {
		ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: Channel name and topic required\n");
		return;
	}
	std::string channelName = args[1];
	std::string topic = args[2];
	Channel* channel = ChannelManager::getInstance().getChannel(channelName);
	if (channel) {
		if (!channel->isOperator(clientSocket)) {
			ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: You are not an operator\n");
			return;
		}
		std::string topicMessage = "Topic for " + channelName + " set to: " + topic + "\n";
		channel->broadcastMessage(topicMessage, -1);
		LOG_INFO("Topic for channel " + channelName + " set to: " + topic);
	}
}

// MODE command class implementation
void ModeCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 3) {
		ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: Channel name and mode required\n");
		return;
	}
	std::string channelName = args[1];
	Channel* channel = ChannelManager::getInstance().getChannel(channelName);
	if (channel) {
		if (!channel->isOperator(clientSocket)) {
			ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: You are not an operator\n");
			return;
		}
		std::string modeMessage = "Mode command executed\n";
		ClientManager::getInstance().sendMessageToClient(clientSocket, modeMessage);
		LOG_INFO("Mode command executed by client " + std::to_string(clientSocket));
	}
}

// CAP command class implementation
void CapCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 2) {
		ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: CAP command requires parameters\n");
		return;
	}
	std::string subCommand = args[1];
	std::ostringstream response;

	if (subCommand == "LS") {
		// CAP LS와 CAP LS 302 처리
		if (args.size() == 3 && args[2] == "302") {
			ClientManager::getInstance().sendMessageToClient(clientSocket, "CAP LS 302 :multi-prefix sasl\n");
		} else {
			ClientManager::getInstance().sendMessageToClient(clientSocket, "CAP LS :multi-prefix sasl\n");
		}
	} else if (subCommand == "REQ") {
		if (args.size() < 3) {
			ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: CAP REQ requires parameters\n");
			return;
		}
		std::string reqParams = args[2];
		ClientManager::getInstance().sendMessageToClient(clientSocket, "CAP ACK :" + reqParams + "\n");
	} else if (subCommand == "END") {
		ClientManager::getInstance().sendMessageToClient(clientSocket, "CAP END\n");
	} else {
		ClientManager::getInstance().sendMessageToClient(clientSocket, "CAP ERROR :Unknown CAP subcommand\n");
	}

	LOG_INFO("CAP command executed: " + subCommand + " by client " + std::to_string(clientSocket));
}

CommandFactory& CommandFactory::getInstance() {
	static CommandFactory instance;
	return instance;
}

CommandFactory::CommandFactory() {
	this->commands["NICK"] = new NickCommand();
	this->commands["USER"] = new UserCommand();
	this->commands["JOIN"] = new JoinCommand();
	this->commands["PART"] = new PartCommand();
	this->commands["PRIVMSG"] = new PrivmsgCommand();
	this->commands["KICK"] = new KickCommand();
	this->commands["INVITE"] = new InviteCommand();
	this->commands["TOPIC"] = new TopicCommand();
	this->commands["MODE"] = new ModeCommand();
	this->commands["CAP"] = new CapCommand();
}

CommandFactory::~CommandFactory() {
	for (std::map<std::string, Command*>::iterator it = this->commands.begin(); it != this->commands.end(); ++it) {
		delete it->second;
	}
}

Command* CommandFactory::getCommand(const std::string& commandName) {
	if (this->commands.find(commandName) != this->commands.end()) {
		return this->commands[commandName];
	} else {
		LOG_ERROR("Command not found: " + commandName);
		return NULL;
	}
}
```

### 42/IRC/source/main.cpp

```cpp
#include "IRCServer.hpp"

int main(int argc, char* argv[]) {
	if (argc != 3) {
		std::cerr << "Usage: " << argv[0] << " <port> <password>" << std::endl;
		return EXIT_FAILURE;
	}

	int port = std::atoi(argv[1]);
	std::string password = argv[2];

	try {
		IRCServer::getInstance().run(port, password);
	} catch (const std::exception& e) {
		std::cerr << "Exception occurred while running the server: " << e.what() << std::endl;
		IRCServer::getInstance().stop();
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
```

### 42/IRC/source/ClientManager.cpp

```cpp
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
```