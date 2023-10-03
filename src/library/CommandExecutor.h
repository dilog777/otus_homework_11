#pragma once

#include <memory>
#include <string>

#include "ClientMessageHandler.h"
#include "CommandMachine.h"

class Command;
class SqlServer;



class CommandExecutor : public ClientMessageHandler, public CommandMachine
{
public:
	CommandExecutor();

	// ClientMessageHandler interface
	std::string processClientMessage(const std::string &message) override;

	// CommandMachine interface
	bool runRequest(const std::string &request, std::string &error) override;
	bool runRequest(const std::string &request, std::string &error, SqlTableData *answer) override;

private:
	std::shared_ptr<SqlServer> _sqlServer;

	void init();
};
