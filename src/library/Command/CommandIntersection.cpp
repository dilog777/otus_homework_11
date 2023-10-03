#include "CommandIntersection.h"

#include <sstream>

#include <boost/algorithm/string/join.hpp>
#include <boost/format.hpp>

#include "CommandMachine.h"
#include "SqlTableData.h"

const char *const SQL_REQEST_TEMPLATE = "SELECT %1%.*, %2%.name FROM %1% JOIN %2% ON %1%.id = %2%.id;";



CommandIntersection::CommandIntersection(const std::string &table1, const std::string &table2)
	: _table1 { table1 }
	, _table2 { table2 }
{
}



std::string CommandIntersection::execute(CommandMachine *machine) const
{
	std::stringstream ss;
	
	SqlTableData answer;
	std::string error;
	std::string request = (boost::format { SQL_REQEST_TEMPLATE } % _table1 % _table2).str();

	bool isOk = machine->runRequest(request, error, &answer);
	if (isOk)
	{
		for (const auto &row : answer._rows)
			ss << boost::algorithm::join(row, ",") << std::endl;

		ss << "OK" << std::endl;
	}
	else
	{
		ss << error << std::endl;
	}

	return ss.str();
}
