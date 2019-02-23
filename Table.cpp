#include "pch.h"
#include "Table.h"
#include <string>
#include <algorithm>
#include <vector>
#include <set>
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
		 Collumn *co = new  Collumn(getGreatestIndex(), title, length, gerne, rating);
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
	 bool hasOutput=false;
	 if (m_Collumns.size() == 0)
	 {
		cout << "No entry found" << endl;
	 }
	 for (auto it : m_Collumns) {
		 if (it->getTitle() == searchString || it->getGerne() == searchString || "*" == searchString ) {
			 cout << "Index: " << it->getNumber() << " , "
				  << "Title: " << it->getTitle() << " , "
				  << "Length: " << it->getLength() << " minutes" << " , "
				  << "Gerne: " << it->getGerne() << ", "
				  << "Rating: " << it->getRating() << " stars " <<endl;
			 hasOutput = true;
		 }
	 }
	 if (!hasOutput && !Suggestion(searchString).empty()) {
		 unsigned int s=0;
		 vector<string> Suggestions = Suggestion(searchString);
		 cout << "Do you mean: "<< endl;
		 for (auto i : Suggestion(searchString)) {
			 cout << "'" << i << "'" ;
			 ++s;
			 if (Suggestion(searchString).size() > 1 && s < Suggestion(searchString).size()) {
				 cout << " or "  ;
			 }
		 }
		 cout << " ?" << endl;
	 }
 }

 //get the highest index
 int Table::getGreatestIndex() {
	 int Maximum = 0;
	 for (auto it : m_Collumns) {
		 Maximum=it->getNumber() > Maximum ? it->getNumber() : Maximum;
	 }
	 return Maximum + 1;
 }

 //get the smaller of two number
 int Table::getMin(int a, int b) const {
	 int Minimum = 0;
	 Minimum = a < b ? a : b;
	 return Minimum + 1;
 }

 //get the smaller of two number
 int Table::getMax(int a, int b) const {
	 int Maximum = 0;
	 Maximum = a > b ? a : b;
	 return Maximum ;
 }

 //if no result is found by the Inputstring, this function is called is look for a suggestion
 vector<string> Table::Suggestion(string Input) const {
	 int temp = 0;
	 int res = 0;
	 unsigned int i=0;
	 unsigned int j = 0;
	 set<string> duplicates; 
	 vector<string> suggestions;
	 for (auto it : m_Collumns) {
		 while ( i <= Input.length()-1 && j <= it->getGerne().length()-1) {
			 if (it->getGerne()[j] == Input[i] || it->getGerne()[j] == toupper(Input[i]) || it->getGerne()[j] == tolower(Input[i])) {
				 ++temp;
				 ++j;
				 ++i;
			 }
			 if (it->getGerne()[j] != Input[i] && it->getGerne().length() > Input.length()) {
				 ++j;
			 }
			 if (it->getGerne()[j] != Input[i] && it->getGerne().length() < Input.length()) {
				 ++i;
			 }
			 if (it->getGerne()[j] != Input[i] && it->getGerne().length() == Input.length()) {
				 ++i;
				 ++j;
			 }
		 }
		 res = getMax(res, temp);
		 //if the input is 80% correct with found word, its an suggestion
		 if (res / Input.length() >= 0.8 && ((it->getGerne().length() > Input.length() && float(Input.size())/float(it->getGerne().size()) >= 0.42) || it->getGerne().length() < Input.length())) {
			 if (duplicates.insert(it->getGerne()).second) {
				 suggestions.push_back(it->getGerne());
			 }
		 }
		 res = 0;
		 temp = 0;
		 i = 0;
		 j = 0;

		 while (i <= Input.length()-1 && j <= it->getTitle().length()-1) {
			 if (it->getTitle()[j] == Input[i] || it->getTitle()[j] == toupper(Input[i]) || it->getTitle()[j] == tolower(Input[i])) {
				 ++temp;
				 ++j;
				 ++i;
			 }
			 if (it->getTitle()[j] != Input[i] && it->getTitle().length() > Input.length()) {
				 ++j;
			 }
			 if (it->getTitle()[j] != Input[i] && it->getTitle().length() < Input.length()) {
				 ++i;
			 }
			 if (it->getTitle()[j] != Input[i] && it->getTitle().length() == Input.length()) {
				 ++i;
				 ++j;
			 }
		 }
		 res = getMax(res, temp);
		 //if the input is 80% correct with found word, its an suggestion
		 if (res / Input.length() >= 0.8 && ((it->getTitle().length() > Input.length() && float(Input.length()) / float(it->getTitle().length()) >= 0.42) || it->getTitle().length() < Input.length())) {
			 if (duplicates.insert(it->getGerne()).second) {
				 suggestions.push_back(it->getTitle());
			 }
		 }
		 res = 0;
		 temp = 0;
		 i = 0;
		 j = 0;
	 }
	 return  suggestions;
 } 
