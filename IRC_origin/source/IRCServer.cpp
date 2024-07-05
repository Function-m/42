#include "IRCServer.hpp"
#include <fcntl.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sstream>
#include <stdexcept>
#include "ChannelManager.hpp"
#include "ClientManager.hpp"
#include "Command.hpp"
#include "StringUtils.hpp"

IRCServer &IRCServer::getInstance() {
    static IRCServer instance;
    return instance;
}

void IRCServer::run(int port, const std::string &password) {
    this->serverPassword = password;
    this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (this->serverSocket < 0) {
        throw IRCServer::FatalError("Socket creation failed");
    }
    StringUtils::logInfo("Socket created successfully");

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(this->serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        throw IRCServer::FatalError("Socket binding failed");
    }
    StringUtils::logInfo("Socket bound to port " + StringUtils::toString(port));

    if (listen(this->serverSocket, 5) < 0) {
        throw IRCServer::FatalError("Socket listening failed");
    }
    StringUtils::logInfo("Socket is listening");

    struct pollfd pfd;
    pfd.fd = this->serverSocket;
    pfd.events = POLLIN;
    this->pollfds.push_back(pfd);

    StringUtils::logInfo("IRC server started on port " + StringUtils::toString(port));

    while (true) {
        try {
        int pollCount = poll(&this->pollfds[0], this->pollfds.size(), -1);
        if (pollCount < 0) {
            throw IRCServer::GeneralError("Poll failed");
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
        } catch (const IRCServer::GeneralError &e) {
            sleep(3);
            StringUtils::logError("General exception occurred while running the server: " + std::string(e.what()));
        }
    }
}

void IRCServer::stop() {
    close(this->serverSocket);
    ClientManager::getInstance().~ClientManager();
    this->pollfds.clear();
    StringUtils::logInfo("Server stopped");
}

void IRCServer::acceptNewClient() {
    int clientSocket = accept(this->serverSocket, NULL, NULL);
    if (clientSocket < 0) {
        throw IRCServer::GeneralError("Client connection acceptance failed");
    }

    ClientManager::getInstance().addClient(clientSocket);

    struct pollfd pfd;
    pfd.fd = clientSocket;
    pfd.events = POLLIN;
    this->pollfds.push_back(pfd);

    StringUtils::logInfo("New client connected with socket: " + StringUtils::toString(clientSocket));
}

void IRCServer::processClientMessage(int clientSocket) {
    Client *client = ClientManager::getInstance().getClient(clientSocket);

    try {
        std::vector<std::string> messages = client->receiveMessages();
        for (std::vector<std::string>::iterator it = messages.begin(); it != messages.end(); ++it) {
            StringUtils::logDebug("Received from client " + StringUtils::toString(clientSocket) + ": " + *it);
            std::istringstream iss(*it);
            std::string commandName;
            std::vector<std::string> args;
            std::string arg;

            iss >> commandName;
            while (iss >> arg) {
                args.push_back(arg);
            }

            if (client->getRegistrationStep() != Client::REGISTERED) {
                this->handleRegistration(clientSocket, commandName, args);
            } else {
                this->handleCommand(clientSocket, commandName, args);
            }
        }
    } catch (const Client::FatalError &e) {
        close(clientSocket);
        ClientManager::getInstance().removeClient(clientSocket);
    } catch (const Client::GeneralError &e) {
        ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: " + std::string(e.what()) + "\r\n");
    }
}

void IRCServer::handleRegistration(int clientSocket, const std::string& commandName, const std::vector<std::string>& args) {
    Client *client = ClientManager::getInstance().getClient(clientSocket);
    CommandFactory &commandFactory = CommandFactory::getInstance();

    Command *command = commandFactory.getCommand(commandName);
    if (commandName == "CAP") {
        command->execute(clientSocket, args);

    } else if (commandName == "PASS"  && client->getRegistrationStep() == Client::PASS) {
        command->execute(clientSocket, args);
        client->setRegistrationStep(Client::NICK);

    } else if (commandName == "NICK" && client->getRegistrationStep() == Client::NICK) {
        command->execute(clientSocket, args);
        client->setRegistrationStep(Client::USER);

    } else if (commandName == "USER" && client->getRegistrationStep() == Client::USER) {
        command->execute(clientSocket, args);
        client->setRegistrationStep(Client::REGISTERED);

        ClientManager::getInstance().sendMessageToClient(clientSocket, ":IRCserver 001 " + client->getUserInfo(Client::NICK) + " :Welcome to the Internet Relay Network " + client->getUserInfo(Client::NICK) + "\r\n"); // 환영 메시지
        ClientManager::getInstance().sendMessageToClient(clientSocket, ":IRCserver 002 " + client->getUserInfo(Client::NICK) + " :Your host is IRCServer, running version 1.0\r\n"); // 서버 정보
        ClientManager::getInstance().sendMessageToClient(clientSocket, ":IRCserver 003 " + client->getUserInfo(Client::NICK) + " :This server was created at 00:00:00\r\n"); // 서버 시작 시간
        ClientManager::getInstance().sendMessageToClient(clientSocket, ":IRCserver 004 " + client->getUserInfo(Client::NICK) + " IRCserver 1.0  itkol\r\n"); // 서버 정보와 모드 지원
        ClientManager::getInstance().sendMessageToClient(clientSocket, ":IRCserver 005 " + client->getUserInfo(Client::NICK) + " CHANTYPES=# CHANMODES=itkol :are supported on this server\r\n");
        ClientManager::getInstance().sendMessageToClient(clientSocket, ":IRCserver 251 " + client->getUserInfo(Client::NICK) + " :There are" + StringUtils::toString(ClientManager::getInstance().countClients()) + "users and 0 services on 1 servers\r\n"); // 사용자 수
        ClientManager::getInstance().sendMessageToClient(clientSocket, ":IRCserver 252 " + client->getUserInfo(Client::NICK) + " 0 :operator(s) online\r\n"); // 오퍼레이터 수
        ClientManager::getInstance().sendMessageToClient(clientSocket, ":IRCserver 253 " + client->getUserInfo(Client::NICK) + " 0 :unknown connection(s)\r\n"); // 미확인 사용자 수
        ClientManager::getInstance().sendMessageToClient(clientSocket, ":IRCserver 254 " + client->getUserInfo(Client::NICK) + StringUtils::toString(ChannelManager::getInstance().countChannels()) + ":channels formed\r\n"); // 생성된 채널 수
        ClientManager::getInstance().sendMessageToClient(clientSocket, ":IRCserver 255 " + client->getUserInfo(Client::NICK) + " :I have " + StringUtils::toString(ClientManager::getInstance().countClients()) + " users, 0 services and 1 servers\r\n"); // 총 사용자 수
        ClientManager::getInstance().sendMessageToClient(clientSocket, ":IRCserver 375 " + client->getUserInfo(Client::NICK) + " :- server Message of the Day -\r\n"); // MOTD 시작
        ClientManager::getInstance().sendMessageToClient(clientSocket, ":IRCserver 372 " + client->getUserInfo(Client::NICK) + " :-\n"
                                                                                                                    + "                      /^--^\\     /^--^\\     /^--^\\\n"
                                                                                                                    + "                      \\____/     \\____/     \\____/\n"
                                                                                                                    + "                     /      \\   /      \\   /      \\\n"
                                                                                                                    + "                    |        | |        | |        |\n"
                                                                                                                    + "                     \\__  __/   \\__  __/   \\__  __/\n"
                                                                                                                    + "|^|^|^|^|^|^|^|^|^|^|^|^\\ \\^|^|^|^/ /^|^|^|^|^\\ \\^|^|^|^|^|^|^|^|^|^|^|^|\n"
                                                                                                                    + "| | | | | | | | | | | | |\\ \\| | |/ /| | | | | | \\ \\ | | | | | | | | | | |\n"
                                                                                                                    + "| | | | | | | | | | | | / / | | |\\ \\| | | | | |/ /| | | | | | | | | | | |\n"
                                                                                                                    + "| | | | | | | | | | | | \\/| | | | \\/| | | | | |\\/ | | | | | | | | | | | |\n"
                                                                                                                    + "#########################################################################\n"
                                                                                                                    + "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |\n"
                                                                                                                    + "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |\r\n"); // MOTD 내용
        ClientManager::getInstance().sendMessageToClient(clientSocket, ":IRCServer 376 " + client->getUserInfo(Client::NICK) + " :End of MOTD command\r\n"); // MOTD 끝
    } else {
        ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR:" + commandName + " command is not allowed at this stage\r\n");
        StringUtils::logError("Client " + StringUtils::toString(clientSocket) + " tried to send command without registering");
        return;
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
            StringUtils::logError("Unknown command received from client " + StringUtils::toString(clientSocket) + ": " + commandName);
        }
    } catch (const std::exception &e) {
        ClientManager::getInstance().sendMessageToClient(clientSocket, "ERROR: " + std::string(e.what()) + "\r\n");
        StringUtils::logError("Exception occurred while handling command from client " + StringUtils::toString(clientSocket) + ": " + std::string(e.what()));
    }
}

void IRCServer::removeClient(int clientSocket) {
    Client *client = ClientManager::getInstance().getClient(clientSocket);
    if (client) {
        std::set<std::string> channels = client->getChannels();
        for (std::set<std::string>::iterator it = channels.begin(); it != channels.end(); ++it) {
            Channel *channel = ChannelManager::getInstance().getChannel(*it);
            if (channel) {
                channel->removeClient(clientSocket);
                channel->broadcastMessage(client->getUserInfo(Client::NICK) + " has left the channel", -1);
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
    StringUtils::logInfo("Client removed: " + StringUtils::toString(clientSocket));
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
