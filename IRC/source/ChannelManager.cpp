#include "ChannelManager.hpp"

ChannelManager& ChannelManager::getInstance() {
	static ChannelManager instance;
	return instance;
}

Channel* ChannelManager::getChannel(const std::string& name) {
	if (this->channels.find(name) != this->channels.end()) {
		return this->channels[name];
	} else {
		return NULL;
	}
}

void ChannelManager::createChannel(const std::string& name) {
	if (this->channels.find(name) == this->channels.end()) {
		this->channels[name] = new Channel(name);
	}
}

void ChannelManager::removeChannel(const std::string& name) {
	if (this->channels.find(name) != this->channels.end()) {
		delete this->channels[name];
		this->channels.erase(name);
	}
}
