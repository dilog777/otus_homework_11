#pragma once

#include <memory>

#include "ClientMessageHandler.h"

class CommandExecutor;



class ClientCommandExecutor : public ClientMessageHandler
{
public:
	ClientCommandExecutor();

	void ClientConnected(const ClientId &clientId) override;

	void ClientSendMessage(const ClientId &clientId, const std::string &message) override;

	void ClientDisconnected(const ClientId &clientId) override;

private:

	std::shared_ptr<CommandExecutor> _executor;
};
