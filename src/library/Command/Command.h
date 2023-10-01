#pragma once

class CommandMachine;


class Command
{
public:
	virtual void execute(CommandMachine *machine) const = 0;
};
