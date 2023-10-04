#include "CommandSymmetricDifference.h"

#include <sstream>

#include <boost/algorithm/string/join.hpp>
#include <boost/format.hpp>

#include "CommandMachine.h"
#include "SqlTableData.h"

const char *const SQL_REQEST_PART1_TEMPLATE = "SELECT %1%.id as id, %1%.name, %2%.name FROM %1% LEFT JOIN %2% ON %1%.id = %2%.id WHERE %2%.id IS NULL";
const char *const SQL_REQEST_PART2_TEMPLATE = "SELECT %1%.id as id, %2%.name, %1%.name FROM %1% LEFT JOIN %2% ON %1%.id = %2%.id WHERE %2%.id IS NULL";
const char *const SQL_REQEST_TEMPLATE = "%1% UNION %2% ORDER BY id;";



CommandSymmetricDifference::CommandSymmetricDifference(const std::string &table1, const std::string &table2)
	: _table1 { table1 }
	, _table2 { table2 }
{
}



std::string CommandSymmetricDifference::execute(CommandMachine *machine) const
{
	std::stringstream ss;

	SqlTableData answer;
	std::string error;

	std::string requestPart1 = (boost::format { SQL_REQEST_PART1_TEMPLATE } % _table1 % _table2).str();
	std::string requestPart2 = (boost::format { SQL_REQEST_PART2_TEMPLATE } % _table2 % _table1).str();
	std::string request = (boost::format { SQL_REQEST_TEMPLATE } % requestPart1 % requestPart2).str();

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
