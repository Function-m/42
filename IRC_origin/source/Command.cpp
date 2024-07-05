#include "Command.hpp"
#include "StringUtils.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <sstream>
#include <stdexcept>
#include "IRCServer.hpp"
#include "ClientManager.hpp"
#include "ChannelManager.hpp"
#include "Client.hpp"

void NickCommand::execute(int clientSocket, const std::vector<std::string>& args) {
    if (args.size() < 1) {
        throw std::invalid_argument("NICK command requires a parameter");
    }
    std::string nickname = args[0];
    if (ClientManager::getInstance().getClient(nickname)) {
        throw std::invalid_argument("Nickname already in use");
    }
    Client *client = ClientManager::getInstance().getClient(clientSocket);
    if (client->getNickname() != nickname) {
        client->sendMessage(":" + client->getUserName() + "!~" + client->getHostName() + "@" + client->getServerName() + " NICK :" + nickname + "\r\n");
    }
    client->setNickname(nickname);
}

void UserCommand::execute(int clientSocket, const std::vector<std::string>& args) {
    if (args.size() < 4) {
        throw std::invalid_argument("USER command requires four parameters");
    }

    Client* client = ClientManager::getInstance().getClient(clientSocket);
    if (client->getRegistrationStep() != "USER") {
        throw std::invalid_argument("User already registered");
    }
    client->setUserName(args[0]);
    client->setHostName(args[1]);
    client->setServerName(args[2]);
    client->setRealName(args[3]);
}

void JoinCommand::execute(int clientSocket, const std::vector<std::string>& args) {
    if (args.size() < 1 || args[0].empty()) {
        throw std::invalid_argument("Channel name required");
    }
    std::string channelName = args[0];
    ChannelManager& channelManager = ChannelManager::getInstance();
    Client* client = ClientManager::getInstance().getClient(clientSocket);

    Channel* channel = channelManager.getChannel(channelName); 
    if (!channel) {
        channelManager.createChannel(channelName, client);
        channel = channelManager.getChannel(channelName);
    }

    channel->addClient(clientSocket);

    std::string joinMessage = client->getNickname() + " has joined the channel";
    channel->broadcastMessage(joinMessage, clientSocket);
}

// Not implemented
void PartCommand::execute(int clientSocket, const std::vector<std::string>& args) {
    if (args.size() < 2) {
        ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: Channel name required\r\n");
        return;
    }
    std::string channelName = args[1];
    Channel* channel = ChannelManager::getInstance().getChannel(channelName);
    if (channel) {
        channel->removeClient(clientSocket);
        Client* client = ClientManager::getInstance().getClient(clientSocket);
        if (client) {
            std::string partMessage = client->getNickname() + " has left the channel";
            channel->broadcastMessage(partMessage, clientSocket);
        }
    }
}

// Not implemented
void PrivmsgCommand::execute(int clientSocket, const std::vector<std::string>& args) {
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
            std::string privMessage = client->getNickname() + ": " + message;
            channel->broadcastMessage(privMessage, clientSocket);
        }
    }
}

// Not implemented
void KickCommand::execute(int clientSocket, const std::vector<std::string>& args) {
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
            channel->removeClient(kickClient->getSocket());
            Client* client = ClientManager::getInstance().getClient(clientSocket);
            if (client) {
                std::string kickMessage = userToKick + " was kicked from the channel by " + client->getNickname();
                channel->broadcastMessage(kickMessage, clientSocket);
            }
        }
    }
}

void InviteCommand::execute(int clientSocket, const std::vector<std::string>& args) {
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
void TopicCommand::execute(int clientSocket, const std::vector<std::string>& args) {
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
void ModeCommand::execute(int clientSocket, const std::vector<std::string>& args) {
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

void CapCommand::execute(int clientSocket, const std::vector<std::string>& args) {
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

void PingCommand::execute(int clientSocket, const std::vector<std::string>& args) {
    if (args.size() < 1) {
        throw std::invalid_argument("PING command requires a parameter");
    }
    std::string response = "PONG " + args[0] + "\r\n";
    ClientManager::getInstance().sendMessageToClient(clientSocket, response);
}

void PassCommand::execute(int clientSocket, const std::vector<std::string>& args) {
    (void)clientSocket;
    if (args.size() < 1) {
        throw std::invalid_argument("PASS command requires a parameter");
    }
    if (args[0] != IRCServer::getInstance().getServerPassword()) {
        throw std::invalid_argument("Invalid server password");
    }
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
    this->commands["PING"] = new PingCommand();
    this->commands["PASS"] = new PingCommand();
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
        return NULL;
    }
}
