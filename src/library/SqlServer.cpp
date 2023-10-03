#include "SqlServer.h"

#include "sqlite3.h"

#include "SqlTableData.h"

const char *const NULL_DATA_STRING = "";



std::vector<std::string> readData(int count, char **data)
{
	std::vector<std::string> result;
	result.reserve(count);

	for (int i = 0; i < count; ++i)
	{
		result.emplace_back(data[i] ? data[i] : NULL_DATA_STRING);
	}

	return result;
}



SqlServer::~SqlServer()
{
	close();
}



bool SqlServer::open(const std::string &dbName, std::string &error)
{
	int rc = sqlite3_open(dbName.c_str(), &_handle);
	if (rc == SQLITE_OK)
		return true;

	error = sqlite3_errmsg(_handle);

	return false;
}



bool SqlServer::close()
{
	if (!_handle)
		return true;

	int rc = sqlite3_close(_handle);

	_handle = nullptr;

	return (rc == SQLITE_OK);
}



bool SqlServer::runRequest(const std::string &request, std::string &error, SqlTableData *answer)
{
	if (!_handle)
		return false;

	auto readAnswer = [](void *ptr, int columns, char **data, char **names) -> int
	{
		if (ptr == nullptr)
			return 0;
		
		SqlTableData *answer = static_cast<SqlTableData *>(ptr);

		if (answer->_headers.empty())
			answer->_headers = readData(columns, names);

		auto row = readData(columns, data);
		answer->_rows.push_back(row);

		return 0;		
	};

	char *errmsg;
	int rc = sqlite3_exec(_handle, request.c_str(), readAnswer, answer, &errmsg);
	if (rc == SQLITE_OK)
		return true;

	error = errmsg;
	sqlite3_free(errmsg);

	return false;
}
