#pragma once

#include <string>

struct SqlTableData;



class CommandMachine
{
public:
	virtual ~CommandMachine() = default;

	virtual bool runRequest(const std::string &request, std::string &error) = 0;
	virtual bool runRequest(const std::string &request, std::string &error, SqlTableData *result) = 0;
};
