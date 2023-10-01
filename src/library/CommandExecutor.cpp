#include "CommandExecutor.h"

#include <cassert>
#include <format>

#include "Command/Command.h"

const char *const SQL_DB_NAME = "cpp_sqlite_db.sqlite";
const char *const SQL_CREATE_TABLE_TEMPLATE = "CREATE TABLE IF NOT EXISTS {} (id int PRIMARY KEY, name text);";



CommandExecutor::CommandExecutor()
	: _sqlServer { new SqlServer }
{
	init();
}



void CommandExecutor::execute(const std::shared_ptr<Command> &command)
{
	command->execute(this);
}



bool CommandExecutor::runRequest(const std::string &request, SqlServer::Answer &answer, std::string &error)
{
	return _sqlServer->runRequest(request, answer, error);
}



void CommandExecutor::init()
{
	SqlServer::Answer answer;
	std::string error;
	bool isOk;

	isOk = _sqlServer->open(SQL_DB_NAME, error);
	assert(isOk && error.empty());

	std::string request1 = std::format(SQL_CREATE_TABLE_TEMPLATE, "A");
	isOk = _sqlServer->runRequest(request1, answer, error);
	assert(isOk && error.empty());

	std::string request2 = std::format(SQL_CREATE_TABLE_TEMPLATE, "B");
	isOk = _sqlServer->runRequest(request1, answer, error);
	assert(isOk && error.empty());
}
