#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <map>
#include <string>
#include <vector>

class Command {
   public:
    // Singleton
	static Command& getInstance();

	// Command handler
	void handleCommand(int clientSocket, const std::string& commandName, const std::vector<std::string>& args);
	void handleRegistration(int clientSocket, const std::string& commandName, const std::vector<std::string>& args);

   private:
	// Don't forget mappping for the following commands!!
	typedef void (Command::*CommandHandler)(int clientSocket, const std::vector<std::string>& args);
	std::map<std::string, CommandHandler> commands;
	Command() {
		commands["NICK"] = &Command::handleNick;
		commands["USER"] = &Command::handleUser;
		commands["JOIN"] = &Command::handleJoin;
		commands["PART"] = &Command::handlePart;
		commands["PRIVMSG"] = &Command::handlePrivmsg;
		commands["KICK"] = &Command::handleKick;
		commands["INVITE"] = &Command::handleInvite;
		commands["TOPIC"] = &Command::handleTopic;
		commands["MODE"] = &Command::handleMode;
		commands["CAP"] = &Command::handleCap;
		commands["PING"] = &Command::handlePing;
		commands["PASS"] = &Command::handlePass;
		commands["QUIT"] = &Command::handleQuit;
	}
	CommandHandler getCommand(const std::string& commandName);
	void handleNick(int clientSocket, const std::vector<std::string>& args);
	void handleUser(int clientSocket, const std::vector<std::string>& args);
	void handleJoin(int clientSocket, const std::vector<std::string>& args);
	void handlePart(int clientSocket, const std::vector<std::string>& args);
	void handlePrivmsg(int clientSocket, const std::vector<std::string>& args);
	void handleKick(int clientSocket, const std::vector<std::string>& args);
	void handleInvite(int clientSocket, const std::vector<std::string>& args);
	void handleTopic(int clientSocket, const std::vector<std::string>& args);
	void handleMode(int clientSocket, const std::vector<std::string>& args);
	void handleCap(int clientSocket, const std::vector<std::string>& args);
	void handlePing(int clientSocket, const std::vector<std::string>& args);
	void handlePass(int clientSocket, const std::vector<std::string>& args);
	void handleQuit(int clientSocket, const std::vector<std::string>& args);

	// No instantiation outside for singletones!!
	~Command();
	Command(const Command&);
	Command& operator=(const Command&);

   // Exception classes
   public:
	class FatalError : public std::runtime_error {
	   public:
		explicit FatalError(const std::string& message) : std::runtime_error(message) {}
		virtual ~FatalError() throw() {}
	};
   private:
	class GeneralError : public std::runtime_error {
	   public:
		explicit GeneralError(const std::string& message) : std::runtime_error(message) {}
		virtual ~GeneralError() throw() {}
	};
};

#endif	// COMMAND_HPP
