#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <set>
#include <string>

#include "Channel.hpp"

class Channel {
   public:
	Channel(const std::string& name, int creatorSocket);
	~Channel();

	// For communication
	void broadcastMessage(const std::string& message, int senderSocket);

	// Methods for "channelInfo"
	enum e_chatInfo { NAME, TOPIC, LIMIT, PASSWORD, INVITE_ONLY, INFO_COUNT };
	void setInfo(int idx, const std::string info = "");
	std::string getInfo(int idx) const;

	// Methods for "clientSockets"
	void addClientSocket(int clientSocket, std::string password = "");
	void removeClientSocket(int clientSocket);

	// Methods for "inviteSockets"
	void addInviteSocket(int clientSocket);
	void removeInviteSocket(int clientSocket);

	// Methods for "operatorSockets"
	bool isOperator(int clientSocket) const;
	void addOperatorSocket(int clientSocket);
	void removeOperatorSocket(int clientSocket);

   private:
	std::string channelInfo[INFO_COUNT];
	std::set<int> clientSockets;
	std::set<int> inviteSockets;
	std::set<int> operatorSockets;
};

#endif	// CHANNEL_HPP
