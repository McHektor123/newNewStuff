#include "pch.h"
#include "Table.h"
#include <string>
#include <vector>
#include <iostream>
#include "Collumn.h"
#include "iterator.h"


using namespace std;

Table::Table(vector<Collumn*> Collumns) : m_Collumns(Collumns)
{
}

Table::~Table()
{
}

 void Table::insertValues(Table t, string title, int length, string gerne) {
	auto it = t.getCollumns()[0];
	 if(currentIndex != 0)
		  it = t.getCollumns()[currentIndex - 1];
	 Collumn col(currentIndex, title, length, gerne);
	 Collumn *co = &col;
	 t.m_Collumns.emplace_back((co));
	 if (it->getNumber()+1 != (it++)->getNumber()) {
		 currentIndex = it->getNumber() + 1;
	 }
	 if (it->getNumber() - 1  != (it--)->getNumber()) {
		 currentIndex = it->getNumber() - 1;
	 }
	 else {
		 currentIndex = getMax(t);
	 }
}

 void Table::deleteValues(Table t, int searchNumber,  string searchTitle, int searchLength, string searchGerne) {
	 auto it = t.getCollumns()[0];
	 for (size_t index = 0; index != t.m_Collumns.size(); index++, it++) {
		 if (it->getGerne() == searchGerne || it->getTitle() == searchTitle || it->getLength() == searchLength || it->getNumber() == searchNumber) {
		 t.m_Collumns.erase(t.m_Collumns.begin() +it->getNumber() -1);
		}
		 currentIndex= it->getNumber();
	 }
 }

 void Table::selectValues(Table t, string searchString, int searchInt) {


 }
 //test
 int Table::getMax(Table t) {
	 int Maximum = 0;
	 auto it= t.getCollumns()[0];
	 for (size_t index = 0; index != t.m_Collumns.size(); index++, it++) {
		 Maximum=it->getNumber() > Maximum ? it->getNumber() : Maximum;
	 }
	 return Maximum;
 }

 void Table::getNumber(Table t, string searchTitle, int searchLength, string searchGerne) const {
	 auto it = t.getCollumns()[0];
	 for (size_t index = 0; index != t.m_Collumns.size(); index++, it++) {
		 if (it->getGerne() == searchGerne || it->getTitle() == searchTitle || it->getLength() == searchLength) {
			 cout << it->getNumber() << endl;
		 }
	 }
 }


