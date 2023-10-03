#include "CommandExecutor.h"

#include <cassert>

#include <boost/format.hpp>

#include "Command/Command.h"
#include "CommandFactory.h"
#include "SqlServer.h"
#include "SqlTableData.h"

const char *const SQL_DB_NAME = "cpp_sqlite_db.sqlite";
const char *const SQL_CREATE_TABLE_TEMPLATE = "CREATE TABLE IF NOT EXISTS %1% (id int PRIMARY KEY, name text);";



CommandExecutor::CommandExecutor()
	: _sqlServer { new SqlServer }
{
	init();
}



std::string CommandExecutor::processClientMessage(const std::string &message)
{
	std::string error;
	auto command = CommandFactory::makeCommand(message, error);
	if (!error.empty())
		return error;

	return command->execute(this);
}



bool CommandExecutor::runRequest(const std::string &request, std::string &error)
{
	return _sqlServer->runRequest(request, error, nullptr);
}



bool CommandExecutor::runRequest(const std::string &request, std::string &error, SqlTableData *answer)
{
	return _sqlServer->runRequest(request, error, answer);
}



void CommandExecutor::init()
{
	std::string error;
	bool isOk;

	isOk = _sqlServer->open(SQL_DB_NAME, error);
	assert(isOk && error.empty());

	std::string request1 = (boost::format { SQL_CREATE_TABLE_TEMPLATE } % "A").str();
	isOk = _sqlServer->runRequest(request1, error, nullptr);
	assert(isOk && error.empty());

	std::string request2 = (boost::format { SQL_CREATE_TABLE_TEMPLATE } % "B").str();
	isOk = _sqlServer->runRequest(request1, error, nullptr);
	assert(isOk && error.empty());
}
