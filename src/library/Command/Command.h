#pragma once

#include <string>

class CommandMachine;



class Command
{
public:
	virtual std::string execute(CommandMachine *machine) const = 0;
};
