#pragma once

#include <memory>

#include "CommandMachine.h"

class Command;



class CommandExecutor : public CommandMachine
{
public:
	CommandExecutor();

	void execute(const std::shared_ptr<Command> &command);

	// CommandMachine interface
	bool runRequest(const std::string &request, SqlServer::Answer &answer, std::string &error) override;

private:
	std::shared_ptr<SqlServer> _sqlServer;

	void init();
};
