#include "ChannelManager.hpp"
#include "ClientManager.hpp"
#include "Client.hpp"

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

void ChannelManager::createChannel(const std::string& name, int creatorSocket) {
    if (this->channels.find(name) == this->channels.end()) {
        this->channels[name] = new Channel(name, creatorSocket);
    }
}

void ChannelManager::removeChannel(const std::string& name) {
    if (this->channels.find(name) != this->channels.end()) {
        delete this->channels[name];
        this->channels.erase(name);
    }
}

int ChannelManager::countChannels() const {
    return this->channels.size();
}