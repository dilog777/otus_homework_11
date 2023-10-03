#pragma once

#include "Command.h"



class CommandInsert : public Command
{
public:
	CommandInsert(const std::string &table, const std::string &id, const std::string &name);

	std::string execute(CommandMachine *machine) const override;

private:
	std::string _table;
	std::string _id;
	std::string _name;
};
