#pragma once
#include <string>
#include <vector>
#include "Collumn.h"

using namespace std;

class Table
{
public:
	Table(vector<Collumn*> Collumns);
	virtual ~Table();
	void insertValues(Table t, string title, int length, string gerne);
	void deleteValues(Table t, int searchNumber, string searchTitle, int searchLength, string searchGerne);
	void selectValues(Table t, string searchString, int searchInt);
	int	 getMax(Table t);
	void getNumber(Table t, string searchTitle, int searchLength, string searchGerne) const;
	vector<Collumn*> getCollumns() { return m_Collumns; }
private:
	vector<Collumn*> m_Collumns;
	int currentIndex = 0;
	int *ptr; 


};