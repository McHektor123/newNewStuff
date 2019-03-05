#pragma once
#include <vector>
#include "Table.h"

class Writer
{
public:
	Writer();
	~Writer();
	static void print(vector<Collumn*> vec);
};

