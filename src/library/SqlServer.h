#pragma once

#include <string>
#include <vector>

struct sqlite3;



class SqlServer
{
public:
	struct Answer
	{
		std::vector<std::string> _headers;
		std::vector<std::vector<std::string>> _rows;
	};
	
	~SqlServer();

	bool open(const std::string &dbName, std::string &error);
	bool runRequest(const std::string &request, Answer &answer, std::string &error);
	bool close();

private:
	sqlite3 *_handle { nullptr };
};
