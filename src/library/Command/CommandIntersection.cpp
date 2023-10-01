#include "CommandIntersection.h"

#include <boost/format.hpp>

#include "CommandMachine.h"

const char *const SQL_REQEST_TEMPLATE = "SELECT %1%.*, %2%.name FROM %1% JOIN %2% ON %1%.id = %2%.id;";



CommandIntersection::CommandIntersection(const std::string &table1, const std::string &table2)
	: _table1 { table1 }
	, _table2 { table2 }
{
}



void CommandIntersection::execute(CommandMachine *machine) const
{
	SqlServer::Answer answer;
	std::string error;
	std::string request = (boost::format { SQL_REQEST_TEMPLATE } % _table1 % _table2).str();
	[[maybe_unused]] bool isOk = machine->runRequest(request, answer, error);

	//assert(isOk && error.empty());
}
