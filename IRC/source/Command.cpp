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
		send(clientSocket, "ERROR: Nickname required\n", 24, 0);
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
		send(clientSocket, "ERROR: USER command requires 4 parameters\n", 41, 0);
		return;
	}
	// Handle USER command
	LOG_INFO("USER command received from client " + std::to_string(clientSocket));
}

// JOIN command class implementation
void JoinCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 2 || args[1].empty()) {
		send(clientSocket, "ERROR: Channel name required\n", 29, 0);
		LOG_ERROR("JOIN command received with no channel name from client " + std::to_string(clientSocket));
		return;
	}
	std::string channelName = args[1];
	ChannelManager& channelManager = ChannelManager::getInstance();
	Channel* channel = channelManager.getChannel(channelName);
	if (!channel) {
		channelManager.createChannel(channelName);
		channel = channelManager.getChannel(channelName);
		LOG_INFO("Channel created: " + channelName);
	}
	channel->addClient(clientSocket);
	Client* client = ClientManager::getInstance().getClient(clientSocket);
	if (client) {
		std::string joinMessage = client->getNickname() + " has joined the channel\n";
		channel->broadcastMessage(joinMessage, clientSocket);
		LOG_INFO("Client " + std::to_string(clientSocket) + " joined channel " + channelName);
	}
}

// PART command class implementation
void PartCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 2) {
		send(clientSocket, "ERROR: Channel name required\n", 29, 0);
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
		send(clientSocket, "ERROR: Recipient and message required\n", 38, 0);
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
		send(clientSocket, "ERROR: User to kick and reason required\n", 40, 0);
		return;
	}
	std::string channelName = args[1];
	std::string userToKick = args[2];
	Channel* channel = ChannelManager::getInstance().getChannel(channelName);
	if (channel) {
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
		send(clientSocket, "ERROR: User to invite and channel name required\n", 48, 0);
		return;
	}
	std::string userToInvite = args[1];
	std::string channelName = args[2];
	Client* inviteClient = ClientManager::getInstance().getClient(userToInvite);
	if (inviteClient) {
		std::string inviteMessage = "You have been invited to join " + channelName + "\n";
		inviteClient->sendMessage(inviteMessage);
		LOG_INFO("Client " + std::to_string(clientSocket) + " invited " + userToInvite + " to channel " + channelName);
	}
}

// TOPIC command class implementation
void TopicCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 3) {
		send(clientSocket, "ERROR: Channel name and topic required\n", 40, 0);
		return;
	}
	std::string channelName = args[1];
	std::string topic = args[2];
	Channel* channel = ChannelManager::getInstance().getChannel(channelName);
	if (channel) {
		std::string topicMessage = "Topic for " + channelName + " set to: " + topic + "\n";
		channel->broadcastMessage(topicMessage, -1);
		LOG_INFO("Topic for channel " + channelName + " set to: " + topic);
	}
}

// MODE command class implementation
void ModeCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 3) {
		send(clientSocket, "ERROR: Channel name and mode required\n", 37, 0);
		return;
	}
	// Mode implementation can vary depending on requirements
	std::string modeMessage = "Mode command executed\n";
	send(clientSocket, modeMessage.c_str(), modeMessage.size(), 0);
	LOG_INFO("Mode command executed by client " + std::to_string(clientSocket));
}

// CAP command class implementation
void CapCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 2) {
		send(clientSocket, "ERROR: CAP command requires parameters\n", 40, 0);
		return;
	}
	std::string subCommand = args[1];
	std::ostringstream response;
	response << "CAP " << subCommand;

	if (subCommand == "LS") {
		response << " multi-prefix sasl\n";
	} else if (subCommand == "REQ") {
		response << " ACK :" << args[2] << "\n";
	} else if (subCommand == "END") {
		response << " END\n";
	} else {
		response << " ERROR :Unknown CAP subcommand\n";
	}

	send(clientSocket, response.str().c_str(), response.str().size(), 0);
	LOG_INFO("CAP command executed: " + subCommand + " by client " + std::to_string(clientSocket));
}

// Command factory class implementation
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
