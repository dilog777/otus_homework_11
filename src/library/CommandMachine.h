#pragma once

#include <string>

#include "SqlServer.h"



class CommandMachine
{
public:
	virtual ~CommandMachine() = default;

	virtual bool runRequest(const std::string &request, SqlServer::Answer &answer, std::string &error) = 0;
};
