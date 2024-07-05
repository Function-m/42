#ifndef IRCSERVER_HPP
#define IRCSERVER_HPP

#include <poll.h>

#include <iostream>
#include <string>
#include <vector>

class IRCServer {
   public:
	// Singleton
	static IRCServer& getInstance();
	~IRCServer();

	// Method for running a server
	void run(int port, const std::string& password);

	// Methods for "serverPassword"
	std::string getServerPassword() const;
	void setServerPassword(const std::string& password);

	// Methods for "pollfds"
	void addPollfds(int clientSocket);
	void removePollfds(int clientSocket);

   private:
	// No instantiation outside for singletones!!
	IRCServer() {}
	IRCServer(const IRCServer&);
	IRCServer& operator=(const IRCServer&);

	void processClientMessage(int clientSocket);
	void handleRegistration(int clientSocket, const std::string& commandName, const std::vector<std::string>& args);
	void handleCommand(int clientSocket, const std::string& commandName, const std::vector<std::string>& args);

	int serverSocket;
	std::string serverPassword;
	std::vector<struct pollfd> pollfds;

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

#endif	// IRCSERVER_HPP
