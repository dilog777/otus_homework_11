#include "CommandInsert.h"

#include <format>

#include "CommandMachine.h"

const char *const SQL_REQEST_TEMPLATE = "INSERT INTO {} VALUES({}, '{}');";



CommandInsert::CommandInsert(const std::string &table, const std::string &id, const std::string &name)
	: _table { table }
	, _id { id }
	, _name { name }
{
}



void CommandInsert::execute(CommandMachine *machine) const
{
	SqlServer::Answer answer;
	std::string error;
	std::string request = std::format(SQL_REQEST_TEMPLATE, _table, _id, _name);
	[[maybe_unused]] bool isOk = machine->runRequest(request, answer, error);

	//assert(isOk && error.empty());
}
