#include "CommandTruncate.h"

#include <boost/format.hpp>

#include "CommandMachine.h"

const char *const SQL_REQEST_TEMPLATE = "DELETE FROM %s;";



CommandTruncate::CommandTruncate(const std::string &table)
	: _table { table }
{
}



void CommandTruncate::execute(CommandMachine *machine) const
{
	SqlServer::Answer answer;
	std::string error;
	std::string request = (boost::format { SQL_REQEST_TEMPLATE } % _table).str();
	[[maybe_unused]] bool isOk = machine->runRequest(request, answer, error);

	//assert(isOk && error.empty());
}
