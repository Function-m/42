#include "Command.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <sstream>
#include <stdexcept>
#include "IRCServer.hpp"

// NICK command class implementation
void NickCommand::execute(int clientSocket, const std::vector<std::string>& args) {
    if (args.size() < 2) {
        send(clientSocket, "ERROR: Nickname required\n", 24, 0);
        return;
    }
    std::string nickname = args[1];
    IRCServer::getInstance().setNickname(clientSocket, nickname);
}

// USER command class implementation
void UserCommand::execute(int clientSocket, const std::vector<std::string>& args) {
    if (args.size() < 5) {
        send(clientSocket, "ERROR: USER command requires 4 parameters\n", 41, 0);
        return;
    }
    // Handle USER command
}

// JOIN command class implementation
void JoinCommand::execute(int clientSocket, const std::vector<std::string>& args) {
    if (args.size() < 2) {
        send(clientSocket, "ERROR: Channel name required\n", 29, 0);
        return;
    }
    // Handle JOIN command
}

// PART command class implementation
void PartCommand::execute(int clientSocket, const std::vector<std::string>& args) {
    if (args.size() < 2) {
        send(clientSocket, "ERROR: Channel name required\n", 29, 0);
        return;
    }
    // Handle PART command
}

// PRIVMSG command class implementation
void PrivmsgCommand::execute(int clientSocket, const std::vector<std::string>& args) {
    if (args.size() < 3) {
        send(clientSocket, "ERROR: Recipient and message required\n", 38, 0);
        return;
    }
    // Handle PRIVMSG command
}

// KICK command class implementation
void KickCommand::execute(int clientSocket, const std::vector<std::string>& args) {
    if (args.size() < 3) {
        send(clientSocket, "ERROR: User to kick and reason required\n", 40, 0);
        return;
    }
    // Handle KICK command
}

// INVITE command class implementation
void InviteCommand::execute(int clientSocket, const std::vector<std::string>& args) {
    if (args.size() < 3) {
        send(clientSocket, "ERROR: User to invite and channel name required\n", 48, 0);
        return;
    }
    // Handle INVITE command
}

// TOPIC command class implementation
void TopicCommand::execute(int clientSocket, const std::vector<std::string>& args) {
    if (args.size() < 3) {
        send(clientSocket, "ERROR: Channel name and topic required\n", 40, 0);
        return;
    }
    // Handle TOPIC command
}

// MODE command class implementation
void ModeCommand::execute(int clientSocket, const std::vector<std::string>& args) {
    if (args.size() < 3) {
        send(clientSocket, "ERROR: Channel name and mode required\n", 37, 0);
        return;
    }
    // Handle MODE command
}

// Command factory class implementation
CommandFactory::CommandFactory() {
    commands["NICK"] = new NickCommand();
    commands["USER"] = new UserCommand();
    commands["JOIN"] = new JoinCommand();
    commands["PART"] = new PartCommand();
    commands["PRIVMSG"] = new PrivmsgCommand();
    commands["KICK"] = new KickCommand();
    commands["INVITE"] = new InviteCommand();
    commands["TOPIC"] = new TopicCommand();
    commands["MODE"] = new ModeCommand();
}

CommandFactory::~CommandFactory() {
    for (std::map<std::string, Command*>::iterator it = commands.begin(); it != commands.end(); ++it) {
        delete it->second;
    }
}

Command* CommandFactory::getCommand(const std::string& commandName) {
    if (commands.find(commandName) != commands.end()) {
        return commands[commandName];
    } else {
        return nullptr;
    }
}
