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
	void insertValues(string title, int length, string gerne);
	void deleteWithNumber(int searchNumber, bool onlyFirst);
	void deleteWithLenght(int searchNumber, bool onlyFirst);
	void deleteWitTitle(string searchGerne, bool onlyFirst);
	void deleteWitGerne(string searchGerne, bool onlyFirst);
	void selectValues(string searchString) const;
	void selectValues(int searchInt) const;
	int	 getMax();
	vector<Row*> getRows() { return m_Rows; }
private:
	vector<Row*> m_Rows;
	int currentIndex = 0;
	int *ptr; 
	vector<int> emptyIndex;

};