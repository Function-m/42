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

    std::string getRegistrationStep() const;
    void setRegistrationStep(std::string step);
    
    void sendMessage(const std::string& message);
    std::vector<std::string> receiveMessages();
    std::vector<std::string> getChannels() const;

private:
    int clientSocket;
    std::string nickname;
    std::string registrationStep;
    std::string commandBuffer;
    std::vector<std::string> channels;
};

#endif // CLIENT_HPP
