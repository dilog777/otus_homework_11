#pragma once

#include <string>

#include "Command.h"



class CommandIntersection : public Command
{
public:
	CommandIntersection(const std::string &table1, const std::string &table2);

	void execute(CommandMachine *machine) const override;

private:
	std::string _table1;
	std::string _table2;
};
