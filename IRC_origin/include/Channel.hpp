#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <string>
#include <set>
#include "Client.hpp"

class Channel {
public:
    Channel(const std::string& name, int creatorSocket);
    ~Channel();

    void addClient(int clientSocketconst, std::string password = "");
    void removeClient(int clientSocket);

    void addInvite(int clientSocket);
    void removeInvite(int clientSocket);

    void setInfo(int idx, const std::string info = "");
    std::string getInfo(int idx) const;

    bool isOperator(int clientSocket) const;
    void addOperator(int clientSocket);
    void removeOperator(int clientSocket);

    void broadcastMessage(const std::string& message, int senderSocket);

    enum e_chatInfo { CHAT_NAME, TOPIC, LIMITS, PASSWORD, INVITE_ONLY, INFO_COUNT };

private:
    std::string chatInfo[INFO_COUNT];

    std::set<int> clientSockets;
    std::set<int> inviteSockets;
    std::set<int> operators;

};

#endif // CHANNEL_HPP
