#include "IRCServer.hpp"
#include <fcntl.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sstream>
#include <stdexcept>
#include "ChannelManager.hpp"
#include "ClientManager.hpp"
#include "Command.hpp"
#include "Logging.hpp"

IRCServer &IRCServer::getInstance() {
    static IRCServer instance;
    return instance;
}

void IRCServer::run(int port, const std::string &password) {
    this->serverPassword = password;
    this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (this->serverSocket < 0) {
        throw std::runtime_error("Socket creation failed");
    }
    LOG_INFO("Socket created successfully");

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(this->serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        throw std::runtime_error("Socket binding failed");
    }
    LOG_INFO("Socket bound to port " + std::to_string(port));

    if (listen(this->serverSocket, 5) < 0) {
        throw std::runtime_error("Socket listening failed");
    }
    LOG_INFO("Socket is listening");

    struct pollfd pfd;
    pfd.fd = this->serverSocket;
    pfd.events = POLLIN;
    this->pollfds.push_back(pfd);

    LOG_INFO("IRC server started on port " + std::to_string(port));

    while (true) {
        int pollCount = poll(&this->pollfds[0], this->pollfds.size(), -1);
        if (pollCount < 0) {
            throw std::runtime_error("Poll failed");
        }

        for (size_t i = 0; i < this->pollfds.size(); ++i) {
            if (this->pollfds[i].revents & POLLIN) {
                if (this->pollfds[i].fd == this->serverSocket) {
                    this->acceptNewClient();
                } else {
                    this->processClientMessage(this->pollfds[i].fd);
                }
            }
        }
    }
}

void IRCServer::stop() {
    close(this->serverSocket);
    ClientManager::getInstance().~ClientManager();
    this->pollfds.clear();
    LOG_INFO("Server stopped");


}

void IRCServer::acceptNewClient() {
    try {
        int clientSocket = accept(this->serverSocket, NULL, NULL);
        if (clientSocket < 0) {
            throw std::runtime_error("Client connection acceptance failed");
        }

        ClientManager::getInstance().addClient(clientSocket);

        struct pollfd pfd;
        pfd.fd = clientSocket;
        pfd.events = POLLIN;
        this->pollfds.push_back(pfd);

        LOG_INFO("New client connected with socket: " + std::to_string(clientSocket));
    } catch (const std::exception &e) {
        LOG_ERROR("Exception occurred while accepting a client: " + std::string(e.what()));
    }
}

void IRCServer::processClientMessage(int clientSocket) {
    Client *client = ClientManager::getInstance().getClient(clientSocket);

    try {
        std::vector<std::string> messages = client->receiveMessages();
        for (std::vector<std::string>::iterator it = messages.begin(); it != messages.end(); ++it) {
            LOG_DEBUG("Received from client " + std::to_string(clientSocket) + ": " + *it);
            std::istringstream iss(*it);
            std::string commandName;
            std::vector<std::string> args;
            std::string arg;

            iss >> commandName;
            while (iss >> arg) {
                args.push_back(arg);
            }

            if (client->getRegistrationStep() != "REGISTERED") {
                this->handleRegistration(clientSocket, commandName, args);
            } else {
                this->handleCommand(clientSocket, commandName, args);
            }
        }
    } catch (const std::exception &e) {
        LOG_ERROR("Exception occurred while handling a client: " + std::string(e.what()));
        close(clientSocket);
        this->removeClient(clientSocket);
    }
}

void IRCServer::handleRegistration(int clientSocket, const std::string& commandName, const std::vector<std::string>& args) {
    Client *client = ClientManager::getInstance().getClient(clientSocket);
    CommandFactory &commandFactory = CommandFactory::getInstance();

    try {
        Command *command = commandFactory.getCommand(commandName);
        if (commandName == "CAP") {
            command->execute(clientSocket, args);

        } else if (commandName == "PASS"  && client->getRegistrationStep() == "PASS") {
            command->execute(clientSocket, args);
            client->setRegistrationStep("NICK");

        } else if (commandName == "NICK" && client->getRegistrationStep() == "NICK") {
            command->execute(clientSocket, args);
            client->setRegistrationStep("USER");

        } else if (commandName == "USER"  && client->getRegistrationStep() == "USER") {
            command->execute(clientSocket, args);
            client->setRegistrationStep("REGISTERED");

            ClientManager::getInstance().sendMessageToClient(clientSocket, ":server 001 " + client->getNickname() + " :Welcome to the Internet Relay Network " + client->getNickname() + "\r\n"); // 환영 메시지
            ClientManager::getInstance().sendMessageToClient(clientSocket, ":server 002 " + client->getNickname() + " :Your host is server, running version 1.0\r\n"); // 서버 정보
            ClientManager::getInstance().sendMessageToClient(clientSocket, ":server 003 " + client->getNickname() + " :This server was created at some point\r\n"); // 서버 시작 시간
            ClientManager::getInstance().sendMessageToClient(clientSocket, ":server 004 " + client->getNickname() + " server 1.0 ao mtov\r\n"); // 서버 정보와 모드 지원
            ClientManager::getInstance().sendMessageToClient(clientSocket, ":server 005 " + client->getNickname() + " CHANTYPES=# CHANMODES=beI,k,l,imnpst\r\n"); // 서버 기능
            ClientManager::getInstance().sendMessageToClient(clientSocket, ":server 251 " + client->getNickname() + " :There are 10 users and 0 services on 1 servers\r\n"); // 사용자 수
            ClientManager::getInstance().sendMessageToClient(clientSocket, ":server 252 " + client->getNickname() + " 5 :operator(s) online\r\n"); // 오퍼레이터 수
            ClientManager::getInstance().sendMessageToClient(clientSocket, ":server 253 " + client->getNickname() + " 0 :unknown connection(s)\r\n"); // 미확인 사용자 수
            ClientManager::getInstance().sendMessageToClient(clientSocket, ":server 254 " + client->getNickname() + " 5 :channels formed\r\n"); // 생성된 채널 수
            ClientManager::getInstance().sendMessageToClient(clientSocket, ":server 255 " + client->getNickname() + " :I have 10 users, 0 services and 1 servers\r\n"); // 총 사용자 수
            ClientManager::getInstance().sendMessageToClient(clientSocket, ":server 375 " + client->getNickname() + " :- server Message of the Day -\r\n"); // MOTD 시작
            ClientManager::getInstance().sendMessageToClient(clientSocket, ":server 372 " + client->getNickname() + " :- Welcome to the IRC server!\r\n"); // MOTD 내용
            ClientManager::getInstance().sendMessageToClient(clientSocket, ":server 376 " + client->getNickname() + " :End of MOTD command\r\n"); // MOTD 끝
        } else {
            ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR:" + client->getRegistrationStep() + " command is expected to register\r\n");
            LOG_ERROR("Client " + std::to_string(clientSocket) + " tried to send command without registering");
            return;
        }
    } catch (const std::exception &e) {
        ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: " + std::string(e.what()) + "\r\n");
        LOG_ERROR("Exception occurred while handling registration command from client " + std::to_string(clientSocket) + ": " + std::string(e.what()));
    }
}

void IRCServer::handleCommand(int clientSocket, const std::string& commandName, const std::vector<std::string>& args) {
    try {
        CommandFactory &commandFactory = CommandFactory::getInstance();
        Command *command = commandFactory.getCommand(commandName);
        if (command) {
            command->execute(clientSocket, args);
        } else {
            ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: Unknown command\r\n");
            LOG_ERROR("Unknown command received from client " + std::to_string(clientSocket) + ": " + commandName);
        }
    } catch (const std::exception &e) {
        ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: " + std::string(e.what()) + "\r\n");
        LOG_ERROR("Exception occurred while handling command from client " + std::to_string(clientSocket) + ": " + std::string(e.what()));
    }
}

void IRCServer::removeClient(int clientSocket) {
    Client *client = ClientManager::getInstance().getClient(clientSocket);
    if (client) {
        std::vector<std::string> channels = client->getChannels();
        for (std::vector<std::string>::iterator it = channels.begin(); it != channels.end(); ++it) {
            Channel *channel = ChannelManager::getInstance().getChannel(*it);
            if (channel) {
                channel->removeClient(clientSocket);
                channel->broadcastMessage(client->getNickname() + " has left the channel", -1);
            }
        }
    }

    ClientManager::getInstance().removeClient(clientSocket);

    for (std::vector<struct pollfd>::iterator it = this->pollfds.begin(); it != this->pollfds.end(); ++it) {
        if (it->fd == clientSocket) {
            this->pollfds.erase(it);
            break;
        }
    }
    LOG_INFO("Client removed: " + std::to_string(clientSocket));
}

int IRCServer::getServerSocket() const {
    return this->serverSocket;
}

void IRCServer::setServerSocket(int socket) {
    this->serverSocket = socket;
}

std::string IRCServer::getServerPassword() const {
    return this->serverPassword;
}

void IRCServer::setServerPassword(const std::string &password) {
    this->serverPassword = password;
}
