#include "IRCServer.hpp"

int main(int argc, char* argv[]) {
	if (argc != 3) {
		std::cerr << "Usage: " << argv[0] << " <port> <password>" << std::endl;
		return EXIT_FAILURE;
	}

	int port = std::atoi(argv[1]);
	std::string password = argv[2];

	try {
		IRCServer::getInstance().run(port, password);
	} catch (const std::exception& e) {
		std::cerr << "Exception occurred while running the server: " << e.what() << std::endl;
		IRCServer::getInstance().stop();
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
