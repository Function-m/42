#ifndef IRCSERVER_HPP
#define IRCSERVER_HPP

#include <poll.h>

#include <iostream>
#include <string>
#include <vector>

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
	void handleRegistration(int clientSocket, const std::string& commandName, const std::vector<std::string>& args);
	void handleCommand(int clientSocket, const std::string& commandName, const std::vector<std::string>& args);

	int serverSocket;
	std::string serverPassword;
	std::vector<struct pollfd> pollfds;

   public:
	class FatalError : public std::exception {
	   public:
		explicit FatalError(const std::string& msg) : message(msg) {}
		virtual ~FatalError() throw() {}
		virtual const char* what() const throw() {
			return message.c_str();
		}
	   private:
		std::string message;
	};

	class GeneralError : public std::exception {
	   public:
		explicit GeneralError(const std::string& msg) : message(msg) {}
		virtual ~GeneralError() throw() {}
		virtual const char* what() const throw() {
			return message.c_str();
		}
	   private:
		std::string message;
	};
};

#endif	// IRCSERVER_HPP
