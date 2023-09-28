#pragma once

#include <string>



class SqlServer
{
public:
	SqlServer(const std::string &str);
	~SqlServer();


private:
	class Impl;
	Impl *_impl { nullptr };
};
