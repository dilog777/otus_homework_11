#pragma once

#include <string>



class ClientMessageHandler
{
public:
	virtual ~ClientMessageHandler() = default;

	virtual std::string processClientMessage(const std::string &message) = 0;
};
