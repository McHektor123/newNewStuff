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
	 Row col(currentIndex, title, length, gerne);
	 Row *co = &col;
	 m_Rows.push_back((co));
	 Row* it = getRows()[0];
	 if(currentIndex != 0)
		  it = getRows()[currentIndex - 1];
	 if (m_Rows.size() >= 3) {
		 if (it->getNumber() != getMax() && it->getNumber() + 1 != (it++)->getNumber()) {
			 currentIndex = it->getNumber() + 1;
		 }
		 if(it->getNumber() !=0 && it->getNumber() - 1 != (it--)->getNumber()) {
			 currentIndex = it->getNumber() - 1;
		 }
		 else {
			 currentIndex = getMax();
		 }
	 }
	 else {
		 currentIndex = getMax() + 1;
	 }
}

 void Table::deleteValues(int searchNumber,  string searchTitle, int searchLength, string searchGerne) {
	 Row* it = m_Rows[0];
	 for (size_t index = 1; index != m_Rows.size(); index++, it++) {
		 if (it->getGerne() == searchGerne || it->getTitle() == searchTitle || it->getLength() == searchLength || it->getNumber() == searchNumber) {
		 m_Rows.erase(m_Rows.begin() + it->getNumber() -1);
		 cout << "Delted entry with title: " << it->getTitle() << "." << endl;
		}
		 currentIndex= it->getNumber();
	 }
 }

 void Table::selectValues(string searchString) const {
	 Row* it = m_Rows[0];
	 for (size_t index = 1; index != m_Rows.size(); index++, it++) {
		 if (it->getGerne() == searchString || it->getTitle() == searchString) {
			 cout << "Index: " << it->getNumber() << " , "
				  << "Title: " << it->getTitle() << " , "
				  << "Length: " << it->getLength() << " , "
				  << "Gerne: " << it->getGerne() << ", " << endl;
		 }
	 }
 }

 void Table::selectValues(int searchInt) const {
	 Row* it = m_Rows[0];
	 for (size_t index = 1; index != m_Rows.size(); index++, it++) {
		 if (it->getNumber() == searchInt || it->getLength() == searchInt ) {
			 cout << "Number: " << it->getNumber() << " , "
				 << "Title: " << it->getTitle() << " , "
				 << "Length: " << it->getLength() << " , "
				 << "Gerne: " << it->getGerne() << ", " << endl;
		 }
	 }
 }

 int Table::getMax() {
	 int Maximum = 0;
	 Row* it= getRows()[0];
	 for (size_t index = 1; index != m_Rows.size(); index++, it++) {
		 Maximum=it->getNumber() > Maximum ? it->getNumber() : Maximum;
	 }
	 return Maximum;
 }
