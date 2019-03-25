#include <vector>
#include <functional>
#include <string>
#include "Row.h"
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

//get the highest index
int Utils::getGreatest(vector<Row*> vec1, auto x(Row*)-> int) {
	int Maximum = 0;
	for (auto it : vec1) {
		Maximum = x(it) > Maximum ? x(it) : Maximum;
	}
	return Maximum + 1;
}

auto Utils::length(Row* it) -> int{
	return it->getLength();
}

auto Utils::rating(Row* it) -> int{
	return it->getRating();
}

auto Utils::number(Row* it) -> int{
	return it->getRating();
}

auto Utils::title(Row* it) -> string {
	return it->getTitle();
}

auto Utils::gerne(Row* it) -> string {
	return it->getGerne();
}