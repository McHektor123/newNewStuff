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
	 if (!emptyIndex.empty()) {
		 Row *co = new  Row(emptyIndex[0], title, length, gerne);
		 m_Rows.push_back((co));
		 cout << "Inserted entry with title: " << title << endl;
		 cout << "Number of entries: " << m_Rows.size() << endl;
		 emptyIndex.erase(emptyIndex.begin());
	 }
	 else{
		 Row *co = new  Row(getMax(), title, length, gerne);
		 m_Rows.push_back((co));
		 cout << "Inserted entry with title: " << title << endl;
		 cout << "Number of entries: " << m_Rows.size() << endl;
	 }
}

 void Table::deleteWithNumber(int searchNumber, bool onlyFirst) {
	 int index = 0;
	 for (auto i = m_Rows.begin(); i != m_Rows.end(); ) {
		 auto it = m_Rows.begin()[index];
		 if (it->getNumber() == searchNumber) {
			 emptyIndex.push_back(it->getNumber());
			 i = m_Rows.erase(i);
			 cout << "Deleted entry with title: " << it->getTitle() << "." << endl;
			 cout << "Number of left entries: " << m_Rows.size() << "." << endl;
			 if (onlyFirst) break;
			}
		 else {
			++index;
			++i;
		 }
	}
 }

 void Table::deleteWithLenght(int searchLength, bool onlyFirst) {
	 int index = 0;
	 for (auto i = m_Rows.begin(); i != m_Rows.end(); ) {
		 auto it = m_Rows.begin()[index];
		 if (it->getLength() == searchLength) {
			 emptyIndex.push_back(it->getNumber());
			 i = m_Rows.erase(i);
			 cout << "Deleted entry with title: " << it->getTitle() << "." << endl;
			 cout << "Number of left entries: " << m_Rows.size() << "." << endl;
			 if (onlyFirst) break;
		 }
		 else {
			 ++index;
			 ++i;
		 }
	 }
 }

 void Table::deleteWitGerne(string searchGerne, bool onlyFirst) {
	 int index = 0;
	 for (auto i = m_Rows.begin(); i != m_Rows.end(); ) {
		 auto it = m_Rows.begin()[index];
		 if (it->getGerne() == searchGerne) {
			 emptyIndex.push_back(it->getNumber());
			 i = m_Rows.erase(i);
			 cout << "Deleted entry with title: " << it->getTitle() << "." << endl;
			 cout << "Number of left entries: " << m_Rows.size() << "." << endl;
			 if (onlyFirst) break;
		 }
		 else {
			 ++index;
			 ++i;
		 }
	 }
 }

 void Table::deleteWitTitle(string searchTitle, bool onlyFirst) {
	 int index = 0;
	 for (auto i = m_Rows.begin(); i != m_Rows.end(); ) {
		 auto it = m_Rows.begin()[index];
		 if (it->getTitle() == searchTitle) {
			 emptyIndex.push_back(it->getNumber());
			 i = m_Rows.erase(i);
			 cout << "Deleted entry with title: " << it->getTitle() << "." << endl;
			 cout << "Number of left entries: " << m_Rows.size() << "." << endl;
			 if (onlyFirst) break;
		 }
		 else {
			 ++index;
			 ++i;
		 }
	 }
 }

 void Table::selectValues(string searchString) const {
	 for (auto it : m_Rows) {
		 if (it->getTitle() == searchString || it->getGerne() == searchString || "*" == searchString) {
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
	 return Maximum + 1;
 }
