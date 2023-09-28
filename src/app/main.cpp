#include <iostream>

//#include "ClientCommandExecutor.h"
#include "ClientServer.h"
#include "StringConverter.hpp"

const char *const USAGE_MESSAGE = "Usage: join_server <port>";



int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << USAGE_MESSAGE << std::endl;
		return EXIT_FAILURE;
	}

	auto port = StringConverter::stringToType<ClientServer::Port>(argv[1]);

//	auto commandExecutor = std::make_shared<ClientCommandExecutor>(blockSize);
//	ClientServer server(commandExecutor);
	ClientServer server(nullptr);

	server.run(port);

	return EXIT_SUCCESS;
}
