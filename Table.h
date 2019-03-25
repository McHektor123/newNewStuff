#pragma once
#include <string>
#include <vector>
#include "Row.h"

using namespace std;

class Table
{
public:
	Table(vector<Row*> Row);
	virtual ~Table();
	void insertValues(string title, int length, string gerne, int rating) ;
	void deleteWithInt(int searchNumber, bool deleteAll, auto x(Row*)-> int);
	void deleteWitString(string searchGerne, bool deleteAll, auto x(Row*)->string);
	void selectValues(string searchString) const;
	vector<string> Suggestion(string Input) const;
	vector<Row*> getRows() const { return m_Rows; }
private:
	vector<Row*> m_Rows;
	int index; 
	vector<int> unusedIndex;
};