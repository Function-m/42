#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <string>
#include <vector>
#include <map>
#include "Client.hpp"

class Channel {
public:
    Channel(const std::string& name, Client* creator);
    ~Channel();

    std::string getName() const;
    void addClient(int clientSocket);
    void removeClient(int clientSocket);
    void broadcastMessage(const std::string& message, int senderSocket);
    bool isOperator(int clientSocket) const;
    void addOperator(int clientSocket);
    void removeOperator(int clientSocket);
    void handleOperatorLeft();

private:
    std::string channelName;
    std::vector<int> clientSockets;
    std::map<int, bool> operators;
};

#endif // CHANNEL_HPP
