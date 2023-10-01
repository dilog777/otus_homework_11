#include "CommandSymmetricDifference.h"

#include <format>

#include "CommandMachine.h"

const char *const SQL_REQEST_PART_TEMPLATE = "SELECT {0:}.* FROM {0:} LEFT JOIN {1:} ON {0:}.id = {1:}.id WHERE {1:}.id IS NULL";
const char *const SQL_REQEST_TEMPLATE = "{0:} UNION {1:} ORDER BY id;";



CommandSymmetricDifference::CommandSymmetricDifference(const std::string &table1, const std::string &table2)
	: _table1 { table1 }
	, _table2 { table2 }
{
}



void CommandSymmetricDifference::execute(CommandMachine *machine) const
{
	SqlServer::Answer answer;
	std::string error;

	std::string requestPart1 = std::format(SQL_REQEST_PART_TEMPLATE, _table1, _table2);
	std::string requestPart2 = std::format(SQL_REQEST_PART_TEMPLATE, _table2, _table1);
	std::string request = std::format(SQL_REQEST_TEMPLATE, requestPart1, requestPart2);

	[[maybe_unused]] bool isOk = machine->runRequest(request, answer, error);

	//assert(isOk && error.empty());
}
