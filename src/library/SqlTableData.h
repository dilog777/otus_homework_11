#pragma once

#include <string>
#include <vector>



struct SqlTableData
{
	std::vector<std::string> _headers;
	std::vector<std::vector<std::string>> _rows;
};
