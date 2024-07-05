#ifndef CHANNELMANAGER_HPP
#define CHANNELMANAGER_HPP

#include <map>
#include <string>
#include <vector>

#include "Channel.hpp"

class Client;

class ChannelManager {
   public:
	// Singleton
	static ChannelManager& getInstance();

	// Method for "channels"
	Channel* getChannel(const std::string& name);
	void createChannel(const std::string& name, int creatorSocket);
	void removeChannel(const std::string& name);
	int countChannels() const;

	// Method for "clientChannels"
	std::vector<std::string> getClientChannels(int clientSocket) const;

	// Method for "inviteChannels"
	std::vector<std::string> getInviteChannels(int clientSocket) const;
	void addInviteChannel(int clientSocket, const std::string& channel);
	void removeInviteChannel(int clientSocket, const std::string& channel);
	void removeInviteChannels(int clientSocket);

	// Method for "clientChannels"
	void addClientChannel(int clientSocket, const std::string& channel);
	void removeClientChannel(int clientSocket, const std::string& channel);
	void removeClientChannels(int clientSocket);

   private:
	// No instantiation outside for singletones!!
	ChannelManager() {}
	ChannelManager(const ChannelManager&);
	ChannelManager& operator=(const ChannelManager&);

	// Key : channel name / Value: Channel object
	std::map<std::string, Channel*> channels;

	// Key : client socket / Value: list of channel names
	std::map<int, std::vector<std::string> > clientChannels;

	// Key : client socket / Value: list of channel names
	std::map<int, std::vector<std::string> > inviteChannels;
};

#endif	// CHANNELMANAGER_HPP
