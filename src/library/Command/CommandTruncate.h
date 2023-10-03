#pragma once

#include "Command.h"



class CommandTruncate : public Command
{
public:
	CommandTruncate(const std::string &table);

	std::string execute(CommandMachine *machine) const override;

private:
	std::string _table;
};
