#pragma once

#include <string>
#include <vector>

struct sqlite3;
struct SqlTableData;



class SqlServer
{
public:
	~SqlServer();

	bool open(const std::string &dbName, std::string &error);
	bool close();

	bool runRequest(const std::string &request, std::string &error, SqlTableData *answer);

private:
	sqlite3 *_handle { nullptr };
};
