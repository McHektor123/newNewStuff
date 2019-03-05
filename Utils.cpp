#include <vector>
#include <functional>
#include "Collumn.h"
#include "pch.h"
#include "Utils.h"


Utils::Utils()
{
}


Utils::~Utils()
{
}

//get the smaller of two number
int Utils::getMin(int a, int b) {
	int Minimum = 0;
	Minimum = a < b ? a : b;
	return Minimum + 1;
}

//get the smaller of two number
int Utils::getMax(int a, int b) {
	int Maximum = 0;
	Maximum = a > b ? a : b;
	return Maximum;
}

//TODO merge this functions to one
//get the highest index
int Utils::getGreatestIndex(vector<Collumn*> vec1) {
	int Maximum = 0;
	for (auto it : vec1) {
		Maximum = it->getNumber() > Maximum ? it->getNumber() : Maximum;
	}
	return Maximum + 1;
}

//get the longest name
int Utils::getLongestName(vector<Collumn*> vec1) {
	unsigned int Maximum = 0;
	for (auto it : vec1) {
		Maximum = it->getTitle().length() > Maximum ? it->getTitle().length() : Maximum;
	}
	return Maximum;
}
