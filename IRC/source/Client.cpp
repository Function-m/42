
#include "Client.hpp"
#include "Logging.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <sstream>
#include <stdexcept>

Client::Client(int socket) : clientSocket(socket) {
	int flags = fcntl(this->clientSocket, F_GETFL, 0);
	fcntl(this->clientSocket, F_SETFL, flags | O_NONBLOCK);
}

Client::~Client() {
	close(this->clientSocket);
}

int Client::getSocket() const {
	return this->clientSocket;
}

void Client::setSocket(int socket) {
	this->clientSocket = socket;
}

std::string Client::getNickname() const {
	return this->nickname;
}

void Client::setNickname(const std::string& nickname) {
	this->nickname = nickname;
}

void Client::sendMessage(const std::string& message) {
	send(this->clientSocket, message.c_str(), message.size(), 0);
	LOG_DEBUG("Sent message to client " + std::to_string(this->clientSocket) + ": " + message);
}

std::vector<std::string> Client::receiveMessages() {
	char buffer[1024];
	int bytesReceived = recv(this->clientSocket, buffer, sizeof(buffer) - 1, 0);
	std::vector<std::string> messages;
	if (bytesReceived > 0) {
		buffer[bytesReceived] = '\0';
		this->commandBuffer += buffer;

		std::string::size_type pos;
		while ((pos = this->commandBuffer.find("\r\n")) != std::string::npos) {
			std::string message = this->commandBuffer.substr(0, pos);
			messages.push_back(message);
			this->commandBuffer.erase(0, pos + 2);
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
