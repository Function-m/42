#include "Client.hpp"
#include "ClientManager.hpp"
#include "ChannelManager.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <sstream>
#include <stdexcept>

Client::Client(int socket) : clientSocket(socket), registrationStep(PASS) {
    int flags = fcntl(this->clientSocket, F_GETFL, 0);
    fcntl(this->clientSocket, F_SETFL, flags | O_NONBLOCK);
}

Client::~Client() {
    close(this->clientSocket);
    ClientManager::getInstance().removeClient(this->clientSocket);
    ChannelManager::getInstance().removeClientChannels(this->clientSocket);
}

int Client::getSocket() const {
    return this->clientSocket;
}

void Client::setSocket(int socket) {
    this->clientSocket = socket;
}

std::string Client::getUserInfo(int idx) const {
    if (idx < 0 || idx >= INFO_COUNT) {
        throw std::runtime_error("Invalid info index");
    }
    return this->userInfo[idx];
}

std::string Client::setUserInfo(int idx, const std::string& info) {
    if (idx < 0 || idx >= INFO_COUNT) {
        throw std::runtime_error("Invalid info index");
    }
    this->userInfo[idx] = info;
    return this->userInfo[idx];
}

int Client::getRegistrationStep() const {
    return this->registrationStep;
}

void Client::setRegistrationStep(int step) {
    if (step < 0 || step >= INFO_COUNT) {
        throw std::runtime_error("Invalid registration step");
    }
    this->registrationStep = step;
}

void Client::sendMessage(const std::string& message) {
    send(this->clientSocket, message.c_str(), message.size(), 0);
}

std::vector<std::string> Client::receiveMessages() {
    char buffer[1024];
    int bytesReceived = recv(this->clientSocket, buffer, sizeof(buffer) - 1, 0);
    std::vector<std::string> messages;
    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0';
        this->commandBuffer += buffer;

        std::string::size_type pos;
        while ((pos = this->commandBuffer.find("\n")) != std::string::npos) {
            std::string message = this->commandBuffer.substr(0, pos);
            if (!message.empty() && message.back() == '\r') {
                message.pop_back();  // Remove the trailing '\r'
            }
            messages.push_back(message);
            this->commandBuffer.erase(0, pos + 1);
        }
    } else if (bytesReceived == 0) {
        // Client closed connection
        close(this->clientSocket);
        throw std::runtime_error("Client connection closed");
    } else if (bytesReceived < 0 && errno != EWOULDBLOCK) {
        // recv failed
        close(this->clientSocket);
        throw std::runtime_error("recv failed");
    }
    return messages;
}

