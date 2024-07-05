#include "Command.hpp"

#include <sys/socket.h>
#include <unistd.h>

#include <sstream>
#include <stdexcept>

#include "ChannelManager.hpp"
#include "Client.hpp"
#include "ClientManager.hpp"
#include "IRCServer.hpp"
#include "StringUtils.hpp"

Command& Command::getInstance() {
	static Command instance;
	return instance;
}

void Command::handleCommand(int clientSocket, const std::string& commandName, const std::vector<std::string>& args) {
	try {
		CommandHandler command = this->getCommand(commandName);
		if (command) {
			(this->*command)(clientSocket, args);
		} else {
			throw Command::GeneralError("Unknown command");
		}
	} catch (const std::exception& e) {
		ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: " + std::string(e.what()) + "\r\n");
	}
}

void Command::handleRegistration(int clientSocket, const std::string& commandName, const std::vector<std::string>& args) {
	try {
		Client* client = ClientManager::getInstance().getClient(clientSocket);

		CommandHandler command = this->getCommand(commandName);
		if (commandName == "CAP") {
			(this->*command)(clientSocket, args);

		} else if (commandName == "PASS" && client->getRegistrationStep() == Client::PASS) {
			(this->*command)(clientSocket, args);
			client->setRegistrationStep(Client::NICK);

		} else if (commandName == "NICK" && client->getRegistrationStep() == Client::NICK) {
			(this->*command)(clientSocket, args);
			client->setRegistrationStep(Client::USER);

		} else if (commandName == "USER" && client->getRegistrationStep() == Client::USER) {
			(this->*command)(clientSocket, args);
			client->setRegistrationStep(Client::REGISTERED);

			// Essential initial messages
			client->sendMessage(":IRCserver 001 " + client->getUserInfo(Client::NICKNAME) + " :Welcome to the Internet Relay Network " + client->getUserInfo(Client::NICKNAME) + "\r\n");
			client->sendMessage(":IRCserver 002 " + client->getUserInfo(Client::NICKNAME) + " :Your host is IRCServer, running version 1.0\r\n");
			client->sendMessage(":IRCserver 003 " + client->getUserInfo(Client::NICKNAME) + " :This server was created at 00:00:00\r\n");
			client->sendMessage(":IRCserver 004 " + client->getUserInfo(Client::NICKNAME) + " IRCserver 1.0  itkol\r\n");
			client->sendMessage(":IRCserver 005 " + client->getUserInfo(Client::NICKNAME) + " CHANTYPES=# CHANMODES=itkol :are supported on this server\r\n");
			client->sendMessage(":IRCserver 251 " + client->getUserInfo(Client::NICKNAME) + " :There are" + StringUtils::toString(ClientManager::getInstance().countClients()) + "users and 0 services on 1 servers\r\n");
			client->sendMessage(":IRCserver 252 " + client->getUserInfo(Client::NICKNAME) + " 0 :operator(s) online\r\n");
			client->sendMessage(":IRCserver 253 " + client->getUserInfo(Client::NICKNAME) + " 0 :unknown connection(s)\r\n");
			client->sendMessage(":IRCserver 254 " + client->getUserInfo(Client::NICKNAME) + StringUtils::toString(ChannelManager::getInstance().countChannels()) + ":channels formed\r\n");
			client->sendMessage(":IRCserver 255 " + client->getUserInfo(Client::NICKNAME) + " :I have " + StringUtils::toString(ClientManager::getInstance().countClients()) + " users, 0 services and 1 servers\r\n");
			client->sendMessage(":IRCserver 375 " + client->getUserInfo(Client::NICKNAME) + " :- server Message of the Day -\r\n");
			client->sendMessage(":IRCserver 372 " + client->getUserInfo(Client::NICKNAME) + " :-\n" + "                      /^--^\\     /^--^\\     /^--^\\\n" + "                      \\____/     \\____/     \\____/\n" + "                     /      \\   /      \\   /      \\\n" + "                    |        | |        | |        |\n" + "                     \\__  __/   \\__  __/   \\__  __/\n" + "|^|^|^|^|^|^|^|^|^|^|^|^\\ \\^|^|^|^/ /^|^|^|^|^\\ \\^|^|^|^|^|^|^|^|^|^|^|^|\n" + "| | | | | | | | | | | | |\\ \\| | |/ /| | | | | | \\ \\ | | | | | | | | | | |\n" + "| | | | | | | | | | | | / / | | |\\ \\| | | | | |/ /| | | | | | | | | | | |\n" + "| | | | | | | | | | | | \\/| | | | \\/| | | | | |\\/ | | | | | | | | | | | |\n" + "#########################################################################\n" + "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |\n" + "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |\r\n");
			client->sendMessage(":IRCServer 376 " + client->getUserInfo(Client::NICKNAME) + " :End of MOTD command\r\n");
		} else {
			throw Command::GeneralError("Invalid command received during registration");
		}
	} catch (const std::exception& e) {
		ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: " + std::string(e.what()) + "\r\n");
	}
}

void Command::handleNick(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 1) {
		throw Command::GeneralError("NICK command requires a parameter");
	}
	std::string nickname = args[0];
	if (ClientManager::getInstance().getClient(nickname)) {
		throw Command::GeneralError("Nickname already in use");
	}
	Client* client = ClientManager::getInstance().getClient(clientSocket);
	if (client->getUserInfo(Client::NICKNAME) != nickname) {
		client->sendMessage(":" + client->getUserInfo(Client::USER_NAME) + "!~" + client->getUserInfo(Client::HOST_NAME) + "@" + client->getUserInfo(Client::SERVER_NAME) + " NICK :" + nickname + "\r\n");
	}
	client->setUserInfo(Client::NICKNAME, nickname);
}

void Command::handleUser(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 4) {
		throw std::invalid_argument("USER command requires four parameters");
	}

	Client* client = ClientManager::getInstance().getClient(clientSocket);
	if (client->getRegistrationStep() != Client::USER) {
		throw std::invalid_argument("User already registered");
	}
	client->setUserInfo(Client::USER_NAME, args[0]);
	client->setUserInfo(Client::HOST_NAME, args[1]);
	client->setUserInfo(Client::SERVER_NAME, args[2]);
	client->setUserInfo(Client::REAL_NAME, args[3]);
}

void Command::handleJoin(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 1 || args[0].empty()) {
		throw std::invalid_argument("Channel name required");
	}
	std::string channelName = args[0];
	ChannelManager& channelManager = ChannelManager::getInstance();

	Channel* channel = channelManager.getChannel(channelName);
	if (!channel) {
		channelManager.createChannel(channelName, clientSocket);
		channel = channelManager.getChannel(channelName);
	}

	channel->addClientSocket(clientSocket);

	std::string joinMessage = (ClientManager::getInstance().getClient(clientSocket))->getUserInfo(Client::NICKNAME) + " has joined the channel";
	channel->broadcastMessage(joinMessage, clientSocket);
}

// Not implemented
void Command::handlePart(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 2) {
		ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: Channel name required\r\n");
		return;
	}
	std::string channelName = args[1];
	Channel* channel = ChannelManager::getInstance().getChannel(channelName);
	if (channel) {
		channel->removeClientSocket(clientSocket);
		Client* client = ClientManager::getInstance().getClient(clientSocket);
		if (client) {
			std::string partMessage = client->getUserInfo(Client::NICKNAME) + " has left the channel";
			channel->broadcastMessage(partMessage, clientSocket);
		}
	}
}

// Not implemented
void Command::handlePrivmsg(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 3) {
		ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: Recipient and message required\r\n");
		return;
	}
	std::string recipient = args[1];
	std::string message = args[2];
	Channel* channel = ChannelManager::getInstance().getChannel(recipient);
	if (channel) {
		Client* client = ClientManager::getInstance().getClient(clientSocket);
		if (client) {
			std::string privMessage = client->getUserInfo(Client::NICKNAME) + ": " + message;
			channel->broadcastMessage(privMessage, clientSocket);
		}
	}
}

// Not implemented
void Command::handleKick(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 3) {
		ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: User to kick and reason required\r\n");
		return;
	}
	std::string channelName = args[1];
	std::string userToKick = args[2];
	Channel* channel = ChannelManager::getInstance().getChannel(channelName);
	if (channel) {
		if (!channel->isOperator(clientSocket)) {
			ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: You are not an operator\r\n");
			return;
		}
		Client* kickClient = ClientManager::getInstance().getClient(userToKick);
		if (kickClient) {
			channel->removeClientSocket(kickClient->getSocket());
			Client* client = ClientManager::getInstance().getClient(clientSocket);
			if (client) {
				std::string kickMessage = userToKick + " was kicked from the channel by " + client->getUserInfo(Client::NICKNAME);
				channel->broadcastMessage(kickMessage, clientSocket);
			}
		}
	}
}

void Command::handleInvite(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 3) {
		ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: User to invite and channel name required\r\n");
		return;
	}
	std::string userToInvite = args[1];
	std::string channelName = args[2];
	Channel* channel = ChannelManager::getInstance().getChannel(channelName);
	if (channel) {
		if (!channel->isOperator(clientSocket)) {
			ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: You are not an operator\r\n");
			return;
		}
		Client* inviteClient = ClientManager::getInstance().getClient(userToInvite);
		if (inviteClient) {
			std::string inviteMessage = "You have been invited to join " + channelName;
			inviteClient->sendMessage(inviteMessage);
		}
	}
}

// Not implemented
void Command::handleTopic(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 3) {
		ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: Channel name and topic required\r\n");
		return;
	}
	std::string channelName = args[1];
	std::string topic = args[2];
	Channel* channel = ChannelManager::getInstance().getChannel(channelName);
	if (channel) {
		if (!channel->isOperator(clientSocket)) {
			ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: You are not an operator\r\n");
			return;
		}
		std::string topicMessage = "Topic for " + channelName + " set to: " + topic;
		channel->broadcastMessage(topicMessage, -1);
	}
}

// Not implemented
void Command::handleMode(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 3) {
		ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: Channel name and mode required\r\n");
		return;
	}
	std::string channelName = args[1];
	Channel* channel = ChannelManager::getInstance().getChannel(channelName);
	if (channel) {
		if (!channel->isOperator(clientSocket)) {
			ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: You are not an operator\r\n");
			return;
		}
		// Mode implementation can vary depending on requirements
		std::string modeMessage = "Mode command executed";
		ClientManager::getInstance().sendMessageToClient(clientSocket, modeMessage);
	}
}

void Command::handleCap(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 1) {
		ClientManager::getInstance().sendMessageToClient(clientSocket, "CAP * ERROR: CAP command requires parameters\r\n");
		return;
	}
	std::string subCommand = args[0];
	std::ostringstream response;

	if (subCommand == "LS") {
		ClientManager::getInstance().sendMessageToClient(clientSocket, "CAP * LS :\r\n");
	} else if (subCommand == "REQ") {
		if (args.size() < 3) {
			ClientManager::getInstance().sendMessageToClient(clientSocket, "CAP * ERROR: CAP REQ requires parameters\r\n");
		}
		std::string reqParams = args[1];
		ClientManager::getInstance().sendMessageToClient(clientSocket, "CAP * NAK :" + reqParams + "\r\n");
	} else if (subCommand != "END") {
		ClientManager::getInstance().sendMessageToClient(clientSocket, "CAP * ERROR :Unknown CAP subcommand\r\n");
	}
}

void Command::handlePing(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 1) {
		throw std::invalid_argument("PING command requires a parameter");
	}
	std::string response = "PONG " + args[0] + "\r\n";
	ClientManager::getInstance().sendMessageToClient(clientSocket, response);
}

void Command::handlePass(int clientSocket, const std::vector<std::string>& args) {
	(void)clientSocket;
	if (args.size() < 1) {
		throw std::invalid_argument("PASS command requires a parameter");
	}
	if (args[0] != IRCServer::getInstance().getServerPassword()) {
		throw std::invalid_argument("Invalid server password");
	}
}

Command::CommandHandler Command::getCommand(const std::string& commandName) {
	std::map<std::string, Command::CommandHandler>::iterator it = this->commands.find(commandName);
	if (it != this->commands.end()) {
		return it->second;
	}
	return 0;
}
