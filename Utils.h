#pragma once
#include <vector>
#include "Row.h"

class Utils
{
public:
	Utils();
	~Utils();
	static int getMin(int a, int b);
	static int getMax(int a, int b);
	static int getGreatest(vector<Row*> vec1, auto x(Row*)-> int);
	static auto length(Row* it) -> int ;
	static auto rating(Row* it) -> int;
	static auto number(Row* it) -> int;
	static auto title(Row* it)->string;
	static auto gerne(Row* it)->string;
};

