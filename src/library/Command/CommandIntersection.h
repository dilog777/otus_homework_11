#pragma once

#include "Command.h"



class CommandIntersection : public Command
{
public:
	CommandIntersection(const std::string &table1, const std::string &table2);

	std::string execute(CommandMachine *machine) const override;

private:
	std::string _table1;
	std::string _table2;
};
