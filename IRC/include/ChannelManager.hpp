#ifndef CHANNELMANAGER_HPP
#define CHANNELMANAGER_HPP

#include <map>
#include <string>
#include "Channel.hpp"

class ChannelManager {
public:
	static ChannelManager& getInstance();
	Channel* getChannel(const std::string& name);
	void createChannel(const std::string& name);
	void removeChannel(const std::string& name);

private:
	ChannelManager() {}
	ChannelManager(const ChannelManager&);
	ChannelManager& operator=(const ChannelManager&);

	std::map<std::string, Channel*> channels;
};

#endif // CHANNELMANAGER_HPP
