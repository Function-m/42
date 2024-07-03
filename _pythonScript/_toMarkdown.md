## ../IRC/Makefile
``` Maekefile
# 글자 ANSI 정의
BOLD        =   \033[1m
GREEN       =   \033[0;32m
INIT_ANSI   =   \033[0m     # 초기화

# 실행 파일 이름
NAME = ircserv
DEBUG_NAME = ircserv_debug

# 소스 파일 및 오브젝트 파일 찾기 및 정의
SRC_DIR = source
INCLUDE_DIR = include
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/objs
DEP_DIR = $(BUILD_DIR)/deps
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEBUG_OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/debug_%.o)
DEPENDS = $(OBJECTS:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)
DEBUG_DEPENDS = $(DEBUG_OBJECTS:$(OBJ_DIR)/debug_%.o=$(DEP_DIR)/debug_%.d)

# 컴파일러 설정
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INCLUDE_DIR)
DEBUG_CXXFLAGS = $(CXXFLAGS) -DENABLE_DEBUG -g

# 기본 타겟 설정
.PHONY: all clean fclean re debug

# 'make all' 또는 'make' 규칙
all: $(NAME)
	@echo "\n$(GREEN)$(BOLD)Build complete.$(INIT_ANSI)"

# 실행 파일 빌드 규칙
$(NAME): $(OBJECTS)
	@echo "\n$(GREEN)Linking...$(INIT_ANSI)"
	$(CXX) $(CXXFLAGS) -o $@ $^

# 디버그 빌드 규칙
debug: $(DEBUG_NAME)
	@echo "\n$(GREEN)$(BOLD)Debug build complete.$(INIT_ANSI)"

# 디버그 실행 파일 빌드 규칙
$(DEBUG_NAME): $(DEBUG_OBJECTS)
	@echo "\n$(GREEN)Linking debug build...$(INIT_ANSI)"
	$(CXX) $(DEBUG_CXXFLAGS) -o $@ $^

# 오브젝트 파일 및 의존성 파일 빌드 규칙
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "\n$(GREEN)Compiling $< and generating dependencies...$(INIT_ANSI)"
	@mkdir -p $(OBJ_DIR) $(DEP_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@ -MF $(DEP_DIR)/$*.d

# 디버그 오브젝트 파일 및 의존성 파일 빌드 규칙
$(OBJ_DIR)/debug_%.o: $(SRC_DIR)/%.cpp
	@echo "\n$(GREEN)Compiling $< for debug and generating dependencies...$(INIT_ANSI)"
	@mkdir -p $(OBJ_DIR) $(DEP_DIR)
	$(CXX) $(DEBUG_CXXFLAGS) -MMD -MP -c $< -o $@ -MF $(DEP_DIR)/debug_$*.d

# 'make clean' 규칙
clean:
	@echo "\n$(GREEN)Cleaning...$(INIT_ANSI)"
	rm -rf $(BUILD_DIR)
	@echo "\n$(GREEN)$(BOLD)Cleaned.$(INIT_ANSI)"

# 'make fclean' 규칙
fclean:
	@echo "\n$(GREEN)FCleaning...$(INIT_ANSI)"
	rm -rf $(BUILD_DIR) $(NAME) $(DEBUG_NAME)
	@echo "\n$(GREEN)$(BOLD)Cleaned.$(INIT_ANSI)"

# 'make re' 규칙
re:
	$(MAKE) clean
	$(MAKE) all

# 의존성 파일 포함
-include $(DEPENDS)
-include $(DEBUG_DEPENDS)

```
## ../IRC/README.md
```markdown
# IRC Server Project

## 프로젝트 설명
이 프로젝트는 C++98을 사용하여 IRC(Internet Relay Chat) 서버를 구현하는 것입니다. 이 서버는 여러 클라이언트가 동시에 접속하여 실시간으로 메시지를 주고받을 수 있도록 합니다. 프로젝트는 싱글톤 패턴, 커맨드 패턴, 팩토리 패턴 등의 디자인 패턴을 사용하여 구조화되었습니다.

## 파일 구조
```
project_root/
├── include/
│   ├── IRCServer.hpp
│   ├── Command.hpp
│   └── Client.hpp
├── source/
│   ├── main.cpp
│   ├── IRCServer.cpp
│   ├── Command.cpp
│   └── Client.cpp
├── Makefile
└── README.md
```

## 설치 및 빌드 방법

### 요구 사항
- c++ 컴파일러
- make

### 빌드
1. 프로젝트 루트 디렉토리에서 `make` 명령을 실행하여 프로젝트를 빌드합니다.
    ```sh
    make
    ```

2. 빌드가 완료되면 `ircserv` 실행 파일이 생성됩니다.

### 클린 빌드
1. `make clean` 명령을 실행하여 생성된 객체 파일과 실행 파일을 삭제합니다.
    ```sh
    make clean
    ```

2. 필요시 `make fclean` 명령을 실행하여 모든 빌드 파일을 삭제하고 완전한 클린 빌드를 수행합니다.
    ```sh
    make fclean
    ```

3. `make re` 명령을 실행하여 클린 빌드 후 다시 빌드합니다.
    ```sh
    make re
    ```

## 사용 방법
1. 서버를 실행합니다.
    ```sh
    ./ircserv <port> <password>
    ```

    - `<port>`: 서버가 수신할 포트 번호.
    - `<password>`: 클라이언트가 서버에 연결할 때 필요한 비밀번호.

2. 클라이언트가 서버에 연결하여 다양한 IRC 명령어를 사용할 수 있습니다.
    - 예: `NICK`, `USER`, `JOIN`, `PART`, `PRIVMSG`, `QUIT`

## 지원되는 명령어
### 클라이언트 명령어 (모든 사용자가 사용할 수 있는 명령어)
- `NICK <nickname>`: 클라이언트의 닉네임을 설정합니다.
- `USER <username> <hostname> <servername> <realname>`: 클라이언트의 사용자 정보를 설정합니다.
- `JOIN <channel>`: 지정된 채널에 참여합니다.
- `PART <channel>`: 지정된 채널에서 나갑니다.
- `PRIVMSG <recipient> :<message>`: 수신자에게 개인 메시지를 보냅니다. 수신자는 유저 또는 채널일 수 있습니다.
- `QUIT [<message>]`: 서버 연결을 종료합니다. 선택적으로 종료 메시지를 보낼 수 있습니다.
### 오퍼레이터 명령어 (관리자 권한이 필요한 명령어)
- `KICK <channel> <user> [<comment>]`: 지정된 채널에서 유저를 강퇴합니다. 선택적으로 강퇴 사유를 입력할 수 있습니다.
- `INVITE <nickname> <channel>`: 유저를 채널에 초대합니다.
- `TOPIC <channel> [<topic>]`: 채널의 주제를 설정하거나 조회합니다.
- `MODE <channel> <mode> [<params>]`: 채널의 모드를 설정합니다.

---

## 사용된 함수
### 함수 분류

IRC 서버 프로젝트에서 사용할 함수들을 용도에 따라 분류하면 다음과 같습니다:

#### 1. 소켓 관련 함수
이 함수들은 네트워크 소켓의 생성, 바인딩, 연결 및 수락을 담당합니다.

- **socket**: 네트워크 통신에 사용할 소켓을 생성합니다.
- **bind**: 소켓에 로컬 주소를 할당합니다.
- **listen**: 소켓을 수신 대기 상태로 만듭니다.
- **accept**: 대기 중인 연결을 수락합니다.
- **connect**: 소켓을 원격 호스트에 연결합니다.
- **setsockopt**: 소켓 옵션을 설정합니다.
- **getsockname**: 소켓의 로컬 주소를 가져옵니다.

#### 2. 데이터 전송 및 수신 함수
이 함수들은 소켓을 통해 데이터를 보내고 받는 역할을 합니다.

- **send**: 소켓을 통해 데이터를 보냅니다.
- **recv**: 소켓을 통해 데이터를 받습니다.
- **inet_addr**: IP 주소 문자열을 네트워크 바이트 순서의 32비트 주소로 변환합니다.
- **inet_ntoa**: 네트워크 바이트 순서의 32비트 주소를 IP 주소 문자열로 변환합니다.

#### 3. 주소 및 호스트 관련 함수
이 함수들은 네트워크 주소 및 호스트 정보를 다룹니다.

- **getprotobyname**: 프로토콜 이름으로 프로토콜 엔트리를 찾습니다.
- **gethostbyname**: 호스트 이름으로 호스트 엔트리를 찾습니다.
- **getaddrinfo**: 호스트 이름과 서비스 이름을 IP 주소와 포트 번호로 변환합니다.
- **freeaddrinfo**: getaddrinfo 함수로 할당된 메모리를 해제합니다.

#### 4. 바이트 순서 변환 함수
이 함수들은 바이트 순서를 변환합니다.

- **htons**: 호스트 바이트 순서에서 네트워크 바이트 순서로 16비트 값을 변환합니다.
- **htonl**: 호스트 바이트 순서에서 네트워크 바이트 순서로 32비트 값을 변환합니다.
- **ntohs**: 네트워크 바이트 순서에서 호스트 바이트 순서로 16비트 값을 변환합니다.
- **ntohl**: 네트워크 바이트 순서에서 호스트 바이트 순서로 32비트 값을 변환합니다.

#### 5. 멀티플렉싱 함수
이 함수들은 여러 파일 디스크립터의 상태를 동시에 검사하여 I/O 이벤트를 처리합니다.

- **poll**: 여러 파일 디스크립터의 이벤트를 모니터링합니다.
- **select**: 여러 파일 디스크립터의 이벤트를 모니터링합니다.
- **kqueue**: (FreeBSD, macOS) 여러 이벤트를 모니터링합니다.
- **epoll**: (Linux) 여러 파일 디스크립터의 이벤트를 모니터링합니다.

#### 6. 시스템 관련 함수
이 함수들은 시스템 레벨의 작업을 처리합니다.

- **close**: 파일 디스크립터를 닫습니다.
- **signal**: 신호 핸들러를 설정합니다.
- **sigaction**: 신호에 대한 동작을 정의합니다.
- **lseek**: 파일 내 위치를 설정합니다.
- **fstat**: 파일의 상태 정보를 얻습니다.
- **fcntl**: 파일 디스크립터의 동작을 변경합니다.

```
## ../IRC/include/ClientManager.hpp
```c++
#ifndef CLIENTMANAGER_HPP
#define CLIENTMANAGER_HPP

#include <map>
#include "Client.hpp"

class ClientManager {
public:
	static ClientManager& getInstance();
	void addClient(int socket, Client* client);
	void removeClient(int socket);
	Client* getClient(int socket);
	Client* getClient(const std::string& nickname);

private:
	ClientManager() {}
	ClientManager(const ClientManager&);
	ClientManager& operator=(const ClientManager&);

	std::map<int, Client*> clients;
};

#endif // CLIENTMANAGER_HPP

```
## ../IRC/include/Channel.hpp
```c++
#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <string>
#include <vector>
#include "Client.hpp"

class Channel {
public:
	Channel(const std::string& name);
	~Channel();

	std::string getName() const;
	void addClient(int clientSocket);
	void removeClient(int clientSocket);
	void broadcastMessage(const std::string& message, int senderSocket);

private:
	std::string channelName;
	std::vector<int> clientSockets;
};

#endif // CHANNEL_HPP

```
## ../IRC/include/ChannelManager.hpp
```c++
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

```
## ../IRC/include/_Debug.hpp
```c++
#ifndef _DEBUG_HPP
#define _DEBUG_HPP

#ifdef ENABLE_DEBUG
#include <iostream>
#define  LOG(message) std::cout << "\x1b[36m[LOG] \x1b[0m " << message << std::endl
#else
#define LOG(message)
#endif

#endif // _DEBUG_HPP

```
## ../IRC/include/Command.hpp
```c++
#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <vector>
#include <string>
#include <map>

// Command abstract class
class Command {
public:
	virtual ~Command() {}
	virtual void execute(int clientSocket, const std::vector<std::string>& args) = 0;
};

// NICK command class
class NickCommand : public Command {
public:
	void execute(int clientSocket, const std::vector<std::string>& args);
};

// USER command class
class UserCommand : public Command {
public:
	void execute(int clientSocket, const std::vector<std::string>& args);
};

// JOIN command class
class JoinCommand : public Command {
public:
	void execute(int clientSocket, const std::vector<std::string>& args);
};

// PART command class
class PartCommand : public Command {
public:
	void execute(int clientSocket, const std::vector<std::string>& args);
};

// PRIVMSG command class
class PrivmsgCommand : public Command {
public:
	void execute(int clientSocket, const std::vector<std::string>& args);
};

// KICK command class
class KickCommand : public Command {
public:
	void execute(int clientSocket, const std::vector<std::string>& args);
};

// INVITE command class
class InviteCommand : public Command {
public:
	void execute(int clientSocket, const std::vector<std::string>& args);
};

// TOPIC command class
class TopicCommand : public Command {
public:
	void execute(int clientSocket, const std::vector<std::string>& args);
};

// MODE command class
class ModeCommand : public Command {
public:
	void execute(int clientSocket, const std::vector<std::string>& args);
};

// Command factory class
class CommandFactory {
public:
	CommandFactory();
	~CommandFactory();
	Command* getCommand(const std::string& commandName);

private:
	std::map<std::string, Command*> commands;
};

#endif // COMMAND_HPP

```
## ../IRC/include/IRCServer.hpp
```c++
#ifndef IRCSERVER_HPP
#define IRCSERVER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <poll.h>

class IRCServer {
public:
	static IRCServer& getInstance();
	void start(int port, const std::string& password);
	void stop();
	int getServerSocket() const;
	void setServerSocket(int socket);
	std::string getServerPassword() const;
	void setServerPassword(const std::string& password);

private:
	IRCServer() {}
	IRCServer(const IRCServer&);
	IRCServer& operator=(const IRCServer&);
	void acceptNewClient();
	void processClientMessage(int clientSocket);
	void removeClient(int clientSocket);

	int serverSocket;
	std::string serverPassword;
	std::vector<struct pollfd> pollfds;
};

#endif // IRCSERVER_HPP

```
## ../IRC/include/Client.hpp
```c++
#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <vector>

class Client {
public:
	Client(int socket);
	~Client();

	int getSocket() const;
	void setSocket(int socket);
	std::string getNickname() const;
	void setNickname(const std::string& nickname);

	void sendMessage(const std::string& message);
	std::vector<std::string> receiveMessages();

private:
	int clientSocket;
	std::string nickname;
	std::string commandBuffer;
};

#endif // CLIENT_HPP

```
## ../IRC/source/IRCServer.cpp
```c++
#include "IRCServer.hpp"
#include "_Debug.hpp"
#include <netinet/in.h>
#include <unistd.h>
#include <sstream>
#include <fcntl.h>
#include <stdexcept>
#include "ClientManager.hpp"
#include "ChannelManager.hpp"
#include "Command.hpp"

IRCServer& IRCServer::getInstance() {
	static IRCServer instance;
	return instance;
}

void IRCServer::start(int port, const std::string& password) {
	try {
		this->serverPassword = password;
		this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
		if (this->serverSocket < 0) {
			throw std::runtime_error("Socket creation failed");
		}
		LOG("Socket created successfully");

		sockaddr_in serverAddr;
		serverAddr.sin_family = AF_INET;
		serverAddr.sin_port = htons(port);
		serverAddr.sin_addr.s_addr = INADDR_ANY;

		if (bind(this->serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
			throw std::runtime_error("Socket binding failed");
		}
		LOG("Socket bound to port");

		if (listen(this->serverSocket, 5) < 0) {
			throw std::runtime_error("Socket listening failed");
		}
		LOG("Socket is listening");

		struct pollfd pfd;
		pfd.fd = this->serverSocket;
		pfd.events = POLLIN;
		this->pollfds.push_back(pfd);

		LOG("IRC server started on port " + std::to_string(port));

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
	} catch (const std::exception& e) {
		std::cerr << "Exception occurred while running the server: " << e.what() << std::endl;
		this->stop();
	}
}

void IRCServer::stop() {
	close(this->serverSocket);
	ClientManager::getInstance().~ClientManager();
	this->pollfds.clear();
	LOG("Server stopped");
}

void IRCServer::acceptNewClient() {
	try {
		int clientSocket = accept(this->serverSocket, NULL, NULL);
		if (clientSocket < 0) {
			throw std::runtime_error("Client connection acceptance failed");
		}

		Client* client = new Client(clientSocket);
		ClientManager::getInstance().addClient(clientSocket, client);

		struct pollfd pfd;
		pfd.fd = clientSocket;
		pfd.events = POLLIN;
		this->pollfds.push_back(pfd);

		LOG("New client connected with socket: " + std::to_string(clientSocket));
	} catch (const std::exception& e) {
		std::cerr << "Exception occurred while accepting a client: " << e.what() << std::endl;
	}
}

void IRCServer::processClientMessage(int clientSocket) {
	Client* client = ClientManager::getInstance().getClient(clientSocket);
	CommandFactory commandFactory;

	try {
		std::vector<std::string> messages = client->receiveMessages();
		for (std::vector<std::string>::iterator it = messages.begin(); it != messages.end(); ++it) {
			LOG("Received from client " + std::to_string(clientSocket) + ": " + *it);
			std::istringstream iss(*it);
			std::string commandName;
			std::vector<std::string> args;
			std::string arg;

			iss >> commandName;
			while (iss >> arg) {
				args.push_back(arg);
			}

			Command* command = commandFactory.getCommand(commandName);
			if (command) {
				LOG("Executing command: " + commandName + " from client: " + std::to_string(clientSocket));
				command->execute(clientSocket, args);
			} else {
				client->sendMessage("ERROR: Unknown command\n");
			}
		}
	} catch (const std::exception& e) {
		std::cerr << "Exception occurred while handling a client: " << e.what() << std::endl;
		close(clientSocket);
		this->removeClient(clientSocket);
	}
}

void IRCServer::removeClient(int clientSocket) {
	ClientManager::getInstance().removeClient(clientSocket);

	for (std::vector<struct pollfd>::iterator it = this->pollfds.begin(); it != this->pollfds.end(); ++it) {
		if (it->fd == clientSocket) {
			this->pollfds.erase(it);
			break;
		}
	}
	LOG("Client removed: " + std::to_string(clientSocket));
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

void IRCServer::setServerPassword(const std::string& password) {
	this->serverPassword = password;
}

```
## ../IRC/source/Client.cpp
```c++
#include "Client.hpp"
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

```
## ../IRC/source/Channel.cpp
```c++
#include "Channel.hpp"
#include <algorithm>
#include "ClientManager.hpp"

Channel::Channel(const std::string& name) : channelName(name) {}

Channel::~Channel() {}

std::string Channel::getName() const {
	return this->channelName;
}

void Channel::addClient(int clientSocket) {
	this->clientSockets.push_back(clientSocket);
}

void Channel::removeClient(int clientSocket) {
	this->clientSockets.erase(std::remove(this->clientSockets.begin(), this->clientSockets.end(), clientSocket), this->clientSockets.end());
}

void Channel::broadcastMessage(const std::string& message, int senderSocket) {
	ClientManager& clientManager = ClientManager::getInstance();
	for (std::vector<int>::iterator it = this->clientSockets.begin(); it != this->clientSockets.end(); ++it) {
		if (*it != senderSocket) {
			Client* client = clientManager.getClient(*it);
			if (client) {
				client->sendMessage(message);
			}
		}
	}
}

```
## ../IRC/source/ChannelManager.cpp
```c++
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

```
## ../IRC/source/Command.cpp
```c++
#include "Command.hpp"
#include "_Debug.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <sstream>
#include <stdexcept>
#include "IRCServer.hpp"
#include "ClientManager.hpp"
#include "ChannelManager.hpp"

// NICK command class implementation
void NickCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 2) {
		send(clientSocket, "ERROR: Nickname required\n", 24, 0);
		return;
	}
	std::string nickname = args[1];
	Client* client = ClientManager::getInstance().getClient(clientSocket);
	if (client) {
		client->setNickname(nickname);
		LOG("Client " + std::to_string(clientSocket) + " set nickname to " + nickname);
	}
}

// USER command class implementation
void UserCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 5) {
		send(clientSocket, "ERROR: USER command requires 4 parameters\n", 41, 0);
		return;
	}
	// Handle USER command
	LOG("USER command received from client " + std::to_string(clientSocket));
}

// JOIN command class implementation
void JoinCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 2) {
		send(clientSocket, "ERROR: Channel name required\n", 29, 0);
		return;
	}
	std::string channelName = args[1];
	ChannelManager& channelManager = ChannelManager::getInstance();
	Channel* channel = channelManager.getChannel(channelName);
	if (!channel) {
		channelManager.createChannel(channelName);
		channel = channelManager.getChannel(channelName);
		LOG("Channel created: " + channelName);
	}
	channel->addClient(clientSocket);
	Client* client = ClientManager::getInstance().getClient(clientSocket);
	if (client) {
		std::string joinMessage = client->getNickname() + " has joined the channel\n";
		channel->broadcastMessage(joinMessage, clientSocket);
		LOG("Client " + std::to_string(clientSocket) + " joined channel " + channelName);
	}
}

// PART command class implementation
void PartCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 2) {
		send(clientSocket, "ERROR: Channel name required\n", 29, 0);
		return;
	}
	std::string channelName = args[1];
	Channel* channel = ChannelManager::getInstance().getChannel(channelName);
	if (channel) {
		channel->removeClient(clientSocket);
		Client* client = ClientManager::getInstance().getClient(clientSocket);
		if (client) {
			std::string partMessage = client->getNickname() + " has left the channel\n";
			channel->broadcastMessage(partMessage, clientSocket);
			LOG("Client " + std::to_string(clientSocket) + " left channel " + channelName);
		}
	}
}

// PRIVMSG command class implementation
void PrivmsgCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 3) {
		send(clientSocket, "ERROR: Recipient and message required\n", 38, 0);
		return;
	}
	std::string recipient = args[1];
	std::string message = args[2];
	Channel* channel = ChannelManager::getInstance().getChannel(recipient);
	if (channel) {
		Client* client = ClientManager::getInstance().getClient(clientSocket);
		if (client) {
			std::string privMessage = client->getNickname() + ": " + message + "\n";
			channel->broadcastMessage(privMessage, clientSocket);
			LOG("Client " + std::to_string(clientSocket) + " sent message to channel " + recipient + ": " + message);
		}
	}
}

// KICK command class implementation
void KickCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 3) {
		send(clientSocket, "ERROR: User to kick and reason required\n", 40, 0);
		return;
	}
	std::string channelName = args[1];
	std::string userToKick = args[2];
	Channel* channel = ChannelManager::getInstance().getChannel(channelName);
	if (channel) {
		Client* kickClient = ClientManager::getInstance().getClient(userToKick);
		if (kickClient) {
			channel->removeClient(kickClient->getSocket());
			Client* client = ClientManager::getInstance().getClient(clientSocket);
			if (client) {
				std::string kickMessage = userToKick + " was kicked from the channel by " + client->getNickname() + "\n";
				channel->broadcastMessage(kickMessage, clientSocket);
				LOG("Client " + std::to_string(clientSocket) + " kicked " + userToKick + " from channel " + channelName);
			}
		}
	}
}

// INVITE command class implementation
void InviteCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 3) {
		send(clientSocket, "ERROR: User to invite and channel name required\n", 48, 0);
		return;
	}
	std::string userToInvite = args[1];
	std::string channelName = args[2];
	Client* inviteClient = ClientManager::getInstance().getClient(userToInvite);
	if (inviteClient) {
		std::string inviteMessage = "You have been invited to join " + channelName + "\n";
		inviteClient->sendMessage(inviteMessage);
		LOG("Client " + std::to_string(clientSocket) + " invited " + userToInvite + " to channel " + channelName);
	}
}

// TOPIC command class implementation
void TopicCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 3) {
		send(clientSocket, "ERROR: Channel name and topic required\n", 40, 0);
		return;
	}
	std::string channelName = args[1];
	std::string topic = args[2];
	Channel* channel = ChannelManager::getInstance().getChannel(channelName);
	if (channel) {
		std::string topicMessage = "Topic for " + channelName + " set to: " + topic + "\n";
		channel->broadcastMessage(topicMessage, -1);
		LOG("Topic for channel " + channelName + " set to: " + topic);
	}
}

// MODE command class implementation
void ModeCommand::execute(int clientSocket, const std::vector<std::string>& args) {
	if (args.size() < 3) {
		send(clientSocket, "ERROR: Channel name and mode required\n", 37, 0);
		return;
	}
	// Mode implementation can vary depending on requirements
	std::string modeMessage = "Mode command executed\n";
	send(clientSocket, modeMessage.c_str(), modeMessage.size(), 0);
	LOG("Mode command executed by client " + std::to_string(clientSocket));
}

// Command factory class implementation
CommandFactory::CommandFactory() {
	this->commands["NICK"] = new NickCommand();
	this->commands["USER"] = new UserCommand();
	this->commands["JOIN"] = new JoinCommand();
	this->commands["PART"] = new PartCommand();
	this->commands["PRIVMSG"] = new PrivmsgCommand();
	this->commands["KICK"] = new KickCommand();
	this->commands["INVITE"] = new InviteCommand();
	this->commands["TOPIC"] = new TopicCommand();
	this->commands["MODE"] = new ModeCommand();
}

CommandFactory::~CommandFactory() {
	for (std::map<std::string, Command*>::iterator it = this->commands.begin(); it != this->commands.end(); ++it) {
		delete it->second;
	}
}

Command* CommandFactory::getCommand(const std::string& commandName) {
	if (this->commands.find(commandName) != this->commands.end()) {
		return this->commands[commandName];
	} else {
		return NULL;
	}
}

```
## ../IRC/source/main.cpp
```c++
#include "IRCServer.hpp"

int main(int argc, char* argv[]) {
	if (argc != 3) {
		std::cerr << "Usage: " << argv[0] << " <port> <password>" << std::endl;
		return 1;
	}

	int port = std::atoi(argv[1]);
	std::string password = argv[2];

	try {
		IRCServer::getInstance().start(port, password);
	} catch (const std::exception& e) {
		std::cerr << "Exception occurred while starting the server: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}

```
## ../IRC/source/ClientManager.cpp
```c++
#include "ClientManager.hpp"
#include "_Debug.hpp"

ClientManager& ClientManager::getInstance() {
	static ClientManager instance;
	return instance;
}

void ClientManager::addClient(int socket, Client* client) {
	this->clients[socket] = client;
	LOG("Client added with socket: " + std::to_string(socket));
}

void ClientManager::removeClient(int socket) {
	if (this->clients.find(socket) != this->clients.end()) {
		delete this->clients[socket];
		this->clients.erase(socket);
		LOG("Client removed with socket: " + std::to_string(socket));
	}
}

Client* ClientManager::getClient(int socket) {
	if (this->clients.find(socket) != this->clients.end()) {
		return this->clients[socket];
	} else {
		return NULL;
	}
}

Client* ClientManager::getClient(const std::string& nickname) {
	for (std::map<int, Client*>::iterator it = this->clients.begin(); it != this->clients.end(); ++it) {
		if (it->second->getNickname() == nickname) {
			return it->second;
		}
	}
	return NULL;
}

```
