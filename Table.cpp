#include "pch.h"
#include "Table.h"
#include <string>
#include <vector>
#include <iostream>
#include "Collumn.h"


using namespace std;

Table::Table(vector<Collumn*> Collumn) : m_Collumns(Collumn)
{
}

Table::~Table()
{
}

 void Table::insertValues(string title, int length, string gerne, int rating) {
	 if (!emptyIndex.empty()) {
		 Collumn *co = new  Collumn(emptyIndex[0], title, length, gerne, rating);
		 m_Collumns.push_back((co));
		 cout << "Inserted entry with title: " << title << endl;
		 cout << "Number of entries: " << m_Collumns.size() << endl;
		 emptyIndex.erase(emptyIndex.begin());
	 }
	 else{
		 Collumn *co = new  Collumn(getMax(), title, length, gerne, rating);
		 m_Collumns.push_back((co));
		 cout << "Inserted entry with title: " << title << endl;
		 cout << "Number of entries: " << m_Collumns.size() << endl;
	 }
}

 void Table::deleteWithNumber(int searchNumber, bool onlyFirst) {
	 int index = 0;
	 for (auto i = m_Collumns.begin(); i != m_Collumns.end(); ) {
		 auto it = m_Collumns.begin()[index];
		 if (it->getNumber() == searchNumber) {
			 emptyIndex.push_back(it->getNumber());
			 i = m_Collumns.erase(i);
			 cout << "Deleted entry with title: " << it->getTitle() << "." << endl;
			 cout << "Number of left entries: " << m_Collumns.size() << "." << endl;
			 if (onlyFirst) break;
			}
		 else {
			++index;
			++i;
		 }
	}
 }

 void Table::deleteWithLength(int searchLength, bool onlyFirst) {
	 int index = 0;
	 for (auto i = m_Collumns.begin(); i != m_Collumns.end(); ) {
		 auto it = m_Collumns.begin()[index];
		 if (it->getLength() == searchLength) {
			 emptyIndex.push_back(it->getNumber());
			 i = m_Collumns.erase(i);
			 cout << "Deleted entry with title: " << it->getTitle() << "." << endl;
			 cout << "Number of left entries: " << m_Collumns.size() << "." << endl;
			 if (onlyFirst) break;
		 }
		 else {
			 ++index;
			 ++i;
		 }
	 }
 }

 void Table::deleteWithRating(int searchrating, bool onlyFirst) {
	 int index = 0;
	 for (auto i = m_Collumns.begin(); i != m_Collumns.end(); ) {
		 auto it = m_Collumns.begin()[index];
		 if (it->getLength() == searchrating) {
			 emptyIndex.push_back(it->getNumber());
			 i = m_Collumns.erase(i);
			 cout << "Deleted entry with title: " << it->getTitle() << "." << endl;
			 cout << "Number of left entries: " << m_Collumns.size() << "." << endl;
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
	 for (auto i = m_Collumns.begin(); i != m_Collumns.end(); ) {
		 auto it = m_Collumns.begin()[index];
		 if (it->getGerne() == searchGerne) {
			 emptyIndex.push_back(it->getNumber());
			 i = m_Collumns.erase(i);
			 cout << "Deleted entry with title: " << it->getTitle() << "." << endl;
			 cout << "Number of left entries: " << m_Collumns.size() << "." << endl;
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
	 for (auto i = m_Collumns.begin(); i != m_Collumns.end(); ) {
		 auto it = m_Collumns.begin()[index];
		 if (it->getTitle() == searchTitle) {
			 emptyIndex.push_back(it->getNumber());
			 i = m_Collumns.erase(i);
			 cout << "Deleted entry with title: " << it->getTitle() << "." << endl;
			 cout << "Number of left entries: " << m_Collumns.size() << "." << endl;
			 if (onlyFirst) break;
		 }
		 else {
			 ++index;
			 ++i;
		 }
	 }
 }

 void Table::selectValues(string searchString) const {
	 if (m_Collumns.size() == 0)
	 {
		cout << "No entry found" << endl;
	 }
	 for (auto it : m_Collumns) {
		 if (it->getTitle() == searchString || it->getGerne() == searchString || "*" == searchString 
			 || to_string(it->getNumber())== searchString || to_string(it->getLength()) == searchString
			 || to_string(it->getRating()) == searchString) {
			 cout << "Index: " << it->getNumber() << " , "
				  << "Title: " << it->getTitle() << " , "
				  << "Length: " << it->getLength() << " minutes" << " , "
				  << "Gerne: " << it->getGerne() << ", "
				  << "Rating: " << it->getRating() << " stars " <<endl;
		 }
	 }
 }

 int Table::getMax() {
	 int Maximum = 0;
	 for (auto it : m_Collumns) {
		 Maximum=it->getNumber() > Maximum ? it->getNumber() : Maximum;
	 }
	 return Maximum + 1;
 }
