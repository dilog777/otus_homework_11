#include "CommandFactory.h"

#include <cassert>

#include <boost/algorithm/string.hpp>

#include "Command/CommandInsert.h"
#include "Command/CommandIntersection.h"
#include "Command/CommandSymmetricDifference.h"
#include "Command/CommandTruncate.h"

const char *const CMD_INSERT = "INSERT";
const char *const CMD_INTERSECTION = "INTERSECTION";
const char *const CMD_SYMMETRIC_DIFFERENCE = "SYMMETRIC_DIFFERENCE";
const char *const CMD_TRUNCATE = "TRUNCATE";



std::shared_ptr<Command> CommandFactory::makeCommand(const std::string &str, std::string &error)
{
	const std::string errorPrefix = "Command parsing error: ";
	
	if (str.empty())
	{
		error = errorPrefix + "command is empty";
		return {};
	}
	
	std::vector<std::string> tokens;
	boost::split(tokens, str, boost::algorithm::is_space());
	assert(tokens.size() > 0);

	std::string cmdName = tokens.at(0);
	if (cmdName == CMD_INSERT)
	{
		if (tokens.size() != 4)
		{
			error = errorPrefix + "INSERT command must have three arguments";
			return {};
		}

		std::string table = tokens.at(1);
		std::string id = tokens.at(2);
		std::string name = tokens.at(3);
		return std::make_shared<CommandInsert>(table, id, name);
	}
	else if (str == CMD_INTERSECTION)
	{
		if (tokens.size() != 1)
		{
			error = errorPrefix + "SYMMETRIC_DIFFERENCE command must have no arguments";
			return {};
		}

		std::string table1 = "A";
		std::string table2 = "B";
		return std::make_shared<CommandIntersection>(table1, table2);
	}
	else if (str == CMD_SYMMETRIC_DIFFERENCE)
	{
		if (tokens.size() != 1)
		{
			error = errorPrefix + "SYMMETRIC_DIFFERENCE command must have no arguments";
			return {};
		}

		std::string table1 = "A";
		std::string table2 = "B";
		return std::make_shared<CommandSymmetricDifference>(table1, table2);
	}
	else if (str == CMD_TRUNCATE)
	{
		if (tokens.size() != 2)
		{
			error = errorPrefix + "TRUNCATE command must have one argument";
			return {};
		}
		
		std::string table = tokens.at(1);
		return std::make_shared<CommandTruncate>(table);
	}

	error = errorPrefix + "command is undefined";
	return {};
}
