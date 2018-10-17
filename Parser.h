#pragma once
#include <string>
#include "Table.h"

class Parser
{
public:
	Parser();
	~Parser();
	static void parseString(Table &tab, string Input);
};

