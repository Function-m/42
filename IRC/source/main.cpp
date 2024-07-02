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
