#pragma once
#include <vector>
#include "Collumn.h"

class Utils
{
public:
	Utils();
	~Utils();
	static int getMin(int a, int b);
	static int getMax(int a, int b);
	static int getGreatestIndex(vector<Collumn*> vec1);
	static int getLongestName(vector<Collumn*> vec1);
};

