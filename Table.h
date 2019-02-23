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
	void deleteWithNumber(int searchNumber, bool onlyFirst);
	void deleteWithLength(int searchLength, bool onlyFirst);
	void deleteWithRating(int searchrating, bool onlyFirst);
	void deleteWitTitle(string searchTitle, bool onlyFirst);
	void deleteWitGerne(string searchGerne, bool onlyFirst);
	void selectValues(string searchString) const;
	vector<string> Suggestion(string Input) const;
	int	getGreatestIndex();
	int getMin(int a, int b) const;
	int getMax(int a, int b) const;
	vector<Collumn*> getCollumns() { return m_Collumns; }
private:
	vector<Collumn*> m_Collumns;
	int *ptr; 
	vector<int> emptyIndex;

};