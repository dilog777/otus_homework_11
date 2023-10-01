#include "ClientCommandExecutor.h"

#include "Command/Command.h"
#include "CommandExecutor.h"
#include "CommandFactory.h"




ClientCommandExecutor::ClientCommandExecutor()
	: _executor { new CommandExecutor }
{
}



void ClientCommandExecutor::ClientConnected([[maybe_unused]] const ClientId &clientId)
{
}



void ClientCommandExecutor::ClientSendMessage([[maybe_unused]] const ClientId &clientId, const std::string &message)
{
	std::string error;
	auto command = CommandFactory::makeCommand(message, error);


	_executor->execute(command);
}



void ClientCommandExecutor::ClientDisconnected([[maybe_unused]] const ClientId &clientId)
{
}
