#include "Client.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <sstream>
#include <stdexcept>

Client::Client(int socket) : clientSocket(socket) {
    int flags = fcntl(clientSocket, F_GETFL, 0);
    fcntl(clientSocket, F_SETFL, flags | O_NONBLOCK);
}

Client::~Client() {
    close(clientSocket);
}

void Client::sendMessage(const std::string& message) {
    send(clientSocket, message.c_str(), message.size(), 0);
}

std::vector<std::string> Client::receiveMessages() {
    char buffer[1024];
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
    std::vector<std::string> messages;
    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0';
        this->buffer += buffer;

        std::string::size_type pos;
        while ((pos = this->buffer.find("\r\n")) != std::string::npos) {
            std::string message = this->buffer.substr(0, pos);
            messages.push_back(message);
            this->buffer.erase(0, pos + 2);
        }
    } else if (bytesReceived == 0) {
        // Client closed connection
        close(clientSocket);
        throw std::runtime_error("Client connection closed");
    } else if (bytesReceived < 0 && errno != EWOULDBLOCK) {
        // recv failed
        close(clientSocket);
        throw std::runtime_error("recv failed");
    }
    return messages;
}

std::string Client::getNickname() const {
    return nickname;
}

void Client::setNickname(const std::string& nickname) {
    this->nickname = nickname;
}
