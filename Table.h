#pragma once
#include <string>
#include <vector>
#include "Collumn.h"

using namespace std;

class Table
{
public:
	Table(vector<Collumn*> Collumn);
	virtual ~Table();
	void insertValues(string title, int length, string gerne, int rating);
	void deleteWithNumber(int searchNumber, bool deleteAll);
	void deleteWithLength(int searchLength, bool deleteAll);
	void deleteWithRating(int searchrating, bool deleteAll);
	void deleteWitTitle(string searchTitle, bool deleteAll);
	void deleteWitGerne(string searchGerne, bool deleteAll);
	void selectValues(string searchString) const;
	vector<string> Suggestion(string Input) const;
	bool isTrueSubString(string Input) const;
	vector<Collumn*> getCollumns() { return m_Collumns; }
private:
	vector<Collumn*> m_Collumns;
	int *ptr; 
	vector<int> emptyIndex;
};