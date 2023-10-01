#include <iostream>

#include "ClientCommandExecutor.h"
#include "ClientServer.h"
#include "StringConverter.hpp"

#include "SqlServer.h"

const char *const USAGE_MESSAGE = "Usage: join_server <port>";



void printServerAnswer(const SqlServer::Answer &answer)
{
	std::cout << "Answer:" << std::endl;
	for (const auto &hdr : answer._headers)
		std::cout << hdr << '\t';

	std::cout << std::endl;

	for (const auto &row : answer._rows)
	{
		for (const auto &data : row)
			std::cout << data << '\t';

		std::cout << std::endl;
	}
	std::cout << "Answer end" << std::endl;
}



int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << USAGE_MESSAGE << std::endl;
		return EXIT_FAILURE;
	}

	auto port = StringConverter::stringToType<ClientServer::Port>(argv[1]);

	SqlServer srv;

	std::string dbName = "cpp_sqlite_db.sqlite";
	std::string error;
	if (!srv.open(dbName, error))
	{
		std::cout << error << std::endl;
		return EXIT_FAILURE;
	}

    std::string request;
	while (true)
	{
		std::cout << "Enter: ";
		std::getline(std::cin, request);
		if (request == "break")
			break;

		SqlServer::Answer answer;
		if (!srv.runRequest(request, answer, error))
		{
			std::cout << error << std::endl;
			continue;
		}

		printServerAnswer(answer);
	}

	srv.close();


	auto commandExecutor = std::make_shared<ClientCommandExecutor>();
	ClientServer server(commandExecutor);

	server.run(port);

	return EXIT_SUCCESS;
}
