
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
