#include "CommandInsert.h"

#include <sstream>

#include <boost/format.hpp>

#include "CommandMachine.h"

const char *const SQL_REQEST_TEMPLATE = "INSERT INTO %s VALUES(%s, '%s');";



CommandInsert::CommandInsert(const std::string &table, const std::string &id, const std::string &name)
	: _table { table }
	, _id { id }
	, _name { name }
{
}



std::string CommandInsert::execute(CommandMachine *machine) const
{
	std::stringstream ss;
	
	std::string error;
	std::string request = (boost::format { SQL_REQEST_TEMPLATE } % _table % _id % _name).str();
	bool isOk = machine->runRequest(request, error);
	ss << (isOk ? "OK" : error) << std::endl;

	return ss.str();
}
