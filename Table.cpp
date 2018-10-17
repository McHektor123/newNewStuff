#include "pch.h"
#include "Table.h"
#include <string>
#include <vector>
#include <iostream>
#include "Row.h"


using namespace std;

Table::Table(vector<Row*> Row) : m_Rows(Row)
{
}

Table::~Table()
{
}

 void Table::insertValues(string title, int length, string gerne) {
	 Row col(1, title, length, gerne);
	 Row *co = &col;
	 m_Rows.push_back((co));

}

 void Table::deleteValues(int searchNumber,  string searchTitle, int searchLength, string searchGerne) {
	for( auto it : m_Rows){
		 if (it->getGerne() == searchGerne || it->getTitle() == searchTitle || it->getLength() == searchLength || it->getNumber() == searchNumber) {
		 currentIndex =it->getNumber();
		 if(it->getNumber() > 0)
			m_Rows.erase(m_Rows.begin() + it->getNumber() - 1);
		 if(it->getNumber() == 0)
			m_Rows.erase(m_Rows.begin() + it->getNumber());
		 cout << "Deleted entry with title: " << it->getTitle() << "." << endl;
		 cout << "Number of left entries: " << m_Rows.size() << "." << endl;
		}
	 }
 }

 void Table::selectValues(string searchString) const {
	 for (auto it : m_Rows) {
		 if (it->getTitle() == searchString || it->getGerne() == searchString) {
			 cout << "Index: " << it->getNumber() << " , "
				  << "Title: " << it->getTitle() << " , "
				  << "Length: " << it->getLength() << " , "
				  << "Gerne: " << it->getGerne() << ", " << endl;
		 }
	 }
 }

 void Table::selectValues(int searchInt) const {
	 for (auto it : m_Rows) {
		 if (it->getNumber() == searchInt || it->getLength() == searchInt ) {
			 cout << "Index: " << it->getNumber() << " , "
				 << "Title: " << it->getTitle() << " , "
				 << "Length: " << it->getLength() << " , "
				 << "Gerne: " << it->getGerne() << ", " << endl;
		 }
	 }
 }

 int Table::getMax() {
	 int Maximum = 0;
	 for (auto it : m_Rows) {
		 Maximum=it->getNumber() > Maximum ? it->getNumber() : Maximum;
	 }
	 return Maximum;
 }
