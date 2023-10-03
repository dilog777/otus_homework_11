#include "CommandTruncate.h"

#include <sstream>

#include <boost/format.hpp>

#include "CommandMachine.h"

const char *const SQL_REQEST_TEMPLATE = "DELETE FROM %s;";



CommandTruncate::CommandTruncate(const std::string &table)
	: _table { table }
{
}



std::string CommandTruncate::execute(CommandMachine *machine) const
{
	std::stringstream ss;
	
	std::string error;
	std::string request = (boost::format { SQL_REQEST_TEMPLATE } % _table).str();
	bool isOk = machine->runRequest(request, error);
	ss << (isOk ? "OK" : error) << std::endl;

	return ss.str();
}
