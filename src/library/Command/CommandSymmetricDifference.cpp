#include "CommandSymmetricDifference.h"

#include <boost/format.hpp>

#include "CommandMachine.h"

const char *const SQL_REQEST_PART_TEMPLATE = "SELECT %1%.* FROM %1% LEFT JOIN %2% ON %1%.id = %2%.id WHERE %2%.id IS NULL";
const char *const SQL_REQEST_TEMPLATE = "%1% UNION %2% ORDER BY id;";



CommandSymmetricDifference::CommandSymmetricDifference(const std::string &table1, const std::string &table2)
	: _table1 { table1 }
	, _table2 { table2 }
{
}



void CommandSymmetricDifference::execute(CommandMachine *machine) const
{
	SqlServer::Answer answer;
	std::string error;

	std::string requestPart1 = (boost::format { SQL_REQEST_PART_TEMPLATE } % _table1 % _table2).str();
	std::string requestPart2 = (boost::format { SQL_REQEST_PART_TEMPLATE } % _table2 % _table1).str();
	std::string request = (boost::format { SQL_REQEST_TEMPLATE } % requestPart1 % requestPart2).str();

	[[maybe_unused]] bool isOk = machine->runRequest(request, answer, error);

	//assert(isOk && error.empty());
}
