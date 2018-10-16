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
	void insertValues(string title, int length, string gerne);
	void deleteValues(int searchNumber, string searchTitle, int searchLength, string searchGerne);
	void selectValues(string searchString) const;
	void selectValues(int searchInt) const;
	int	 getMax();
	vector<Collumn*> getCollumns() { return m_Collumns; }
private:
	vector<Collumn*> m_Collumns;
	int currentIndex = 0;
	int *ptr; 


};