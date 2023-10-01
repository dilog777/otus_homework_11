#pragma once

#include <string>

#include "Command.h"



class CommandTruncate : public Command
{
public:
	CommandTruncate(const std::string &table);

	void execute(CommandMachine *machine) const override;

private:
	std::string _table;
};
