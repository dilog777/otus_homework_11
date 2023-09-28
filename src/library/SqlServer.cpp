#include "SqlServer.h"

#include <iostream>

#include "sqlite3.h"



class SqlServer::Impl
{
public:
	Impl();

	int test(const std::string &request);

private:

};



SqlServer::Impl::Impl()
{
}



int SqlServer::Impl::test(const std::string &request)
{
	const char *db_name = "cpp_sqlite_db.sqlite";
	// const char* db_name = ":memory:"; // <--- без файла, БД размещается в памяти
	sqlite3 *handle = nullptr;

	if (sqlite3_open(db_name, &handle))
	{
		std::cerr << "Can't open database: " << sqlite3_errmsg(handle) << std::endl;
		sqlite3_close(handle);
		return EXIT_FAILURE;
	}
	std::cout << db_name << " database opened successfully!" << std::endl;

	auto print_results = [](void *, int columns, char **data, char **names) -> int
	{
		for (int i = 0; i < columns; ++i)
			std::cout << names[i] << " = " << (data[i] ? data[i] : "NULL") << std::endl;
		std::cout << std::endl;
		return 0;
	};

	char *errmsg;
	int rc = sqlite3_exec(handle, request.c_str(), print_results, 0, &errmsg);
	if (rc != SQLITE_OK)
	{
		std::cerr << "Can't execute query: " << errmsg << std::endl;
		sqlite3_free(errmsg); // <--- обратите внимание не C-style работу с памятью
		return EXIT_FAILURE;
	}
	sqlite3_close(handle);

	return EXIT_SUCCESS;
}



SqlServer::SqlServer(const std::string &str)
	: _impl { new Impl }
{
	std::cout << str;
}



SqlServer::~SqlServer()
{
	delete _impl;
}
