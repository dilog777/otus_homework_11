#include "CommandIntersection.h"

#include <format>

#include "CommandMachine.h"

const char *const SQL_REQEST_TEMPLATE = "SELECT {0:}.*, {1:}.name FROM {0:} JOIN {1:} ON {0:}.id = {1:}.id;";



CommandIntersection::CommandIntersection(const std::string &table1, const std::string &table2)
	: _table1 { table1 }
	, _table2 { table2 }
{
}



void CommandIntersection::execute(CommandMachine *machine) const
{
	SqlServer::Answer answer;
	std::string error;
	std::string request = std::format(SQL_REQEST_TEMPLATE, _table1, _table2);
	[[maybe_unused]] bool isOk = machine->runRequest(request, answer, error);

	//assert(isOk && error.empty());
}
