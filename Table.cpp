#include "pch.h"
#include "Table.h"
#include "Collumn.h"
#include "Utils.h"
#include "Writer.h"
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

Table::Table(vector<Collumn*> Collumn) : m_Collumns(Collumn)
{
}

Table::~Table()
{
}

//insert datas
 void Table::insertValues(string title, int length, string gerne, int rating) {
	 if (!emptyIndex.empty()) {
		 Collumn *co = new  Collumn(emptyIndex[0], title, length, gerne, rating);
		 m_Collumns.push_back((co));
		 cout << "Inserted entry with title: " << title << endl;
		 cout << "Number of entries: " << m_Collumns.size() << endl;
		 emptyIndex.erase(emptyIndex.begin());
	 }
	 else{
		 Collumn *co = new  Collumn(Utils::getGreatestIndex(m_Collumns), title, length, gerne, rating);
		 m_Collumns.push_back((co));
		 cout << "Inserted entry with title: " << title << endl;
		 cout << "Number of entries: " << m_Collumns.size() << endl;
	 }
 
}

 //delete data with number as key
 void Table::deleteWithNumber(int searchNumber, bool deleteAll) {
	 int index = 0;
	 for (auto i = m_Collumns.begin(); i != m_Collumns.end(); ) {
		 auto it = m_Collumns.begin()[index];
		 if (it->getNumber() == searchNumber) {
			 emptyIndex.push_back(it->getNumber());
			 i = m_Collumns.erase(i);
			 cout << "Deleted entry: title" << it->getTitle() << " length=" << it->getLength() 
				  << " gerne=" << it->getGerne() << " rating=" << it->getRating() << " number=" << it->getNumber() << "." << endl;
			 cout << "Number of left entries: " << m_Collumns.size() << "." << endl;
			 if (!deleteAll) break;
			}
		 else {
			++index;
			++i;
		 }
	 }
 
 }

 //delete data with length as key
 void Table::deleteWithLength(int searchLength, bool deleteAll) {
	 int index = 0;
	 for (auto i = m_Collumns.begin(); i != m_Collumns.end(); ) {
		 auto it = m_Collumns.begin()[index];
		 if (it->getLength() == searchLength) {
			 emptyIndex.push_back(it->getNumber());
			 i = m_Collumns.erase(i);
			 cout << "Deleted entry: title" << it->getTitle() << " length=" << it->getLength()
				 << " gerne=" << it->getGerne() << " rating=" << it->getRating() << " number=" << it->getNumber() << "." << endl;			 cout << "Number of left entries: " << m_Collumns.size() << "." << endl;
			 if (!deleteAll) break;
		 }
		 else {
			 ++index;
			 ++i;
		 }
	 }
 
 }

 //delete data with rating as key
 void Table::deleteWithRating(int searchrating, bool deleteAll) {
	 int index = 0;
	 for (auto i = m_Collumns.begin(); i != m_Collumns.end(); ) {
		 auto it = m_Collumns.begin()[index];
		 if (it->getRating() == searchrating) {
			 emptyIndex.push_back(it->getNumber());
			 i = m_Collumns.erase(i);
			 cout << "Deleted entry: title" << it->getTitle() << " length=" << it->getLength()
				 << " gerne=" << it->getGerne() << " rating=" << it->getRating() << " number=" << it->getNumber() << "." << endl;			 cout << "Number of left entries: " << m_Collumns.size() << "." << endl;
			 if (!deleteAll) break;
		 }
		 else {
			 ++index;
			 ++i;
		 }
	 }
 
 }

 //delete data with genre as key
 void Table::deleteWitGerne(string searchGerne, bool deleteAll) {
	 int index = 0;
	 for (auto i = m_Collumns.begin(); i != m_Collumns.end(); ) {
		 auto it = m_Collumns.begin()[index];
		 if (it->getGerne() == searchGerne) {
			 emptyIndex.push_back(it->getNumber());
			 i = m_Collumns.erase(i);
			 cout << "Deleted entry: title" << it->getTitle() << " length=" << it->getLength()
				 << " gerne=" << it->getGerne() << " rating=" << it->getRating() << " number=" << it->getNumber() << "." << endl;			 cout << "Number of left entries: " << m_Collumns.size() << "." << endl;
			 if (!deleteAll) break;
		 }
		 else {
			 ++index;
			 ++i;
		 }
	 }
 
 }

 //delete data with title as key
 void Table::deleteWitTitle(string searchTitle, bool deleteAll) {
	 int index = 0;
	 for (auto i = m_Collumns.begin(); i != m_Collumns.end(); ) {
		 auto it = m_Collumns.begin()[index];
		 if (it->getTitle() == searchTitle) {
			 emptyIndex.push_back(it->getNumber());
			 i = m_Collumns.erase(i);
			 cout << "Deleted entry: title" << it->getTitle() << " length=" << it->getLength()
				 << " gerne=" << it->getGerne() << " rating=" << it->getRating() << " number=" << it->getNumber() << "." << endl;			 cout << "Number of left entries: " << m_Collumns.size() << "." << endl;
			 if (!deleteAll) break;
		 }
		 else {
			 ++index;
			 ++i;
		 }
	 }
 
 }

 //select data with genre oder title as key
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

 //if no result is found by the Inputstring, this function is called is look for a suggestion
 vector<string> Table::Suggestion(string Input) const {
	 double errorChance=1.0;
	 set<string> duplicates; 
	 vector<string> suggestions;
	 int temp,res;
	 unsigned int i,j;
	 string gerne,title;
	 for (auto it : m_Collumns) {
		 gerne = it->getGerne();
		 title = it->getTitle();
		 vector<string> key{gerne, title};
		 for (auto k : key) {
			 temp = 0;
			 res = 0;
			 i = 0;
			 j = 0;
			 while (i <= Input.length() - 1 && j <= k.length() - 1) {
				 if (k[j] == toupper(Input[i]) || k[j] == tolower(Input[i])) {
					 ++temp;
					 ++j;
					 ++i;
				 }
				 if (k[j] != Input[i] && k.length() > Input.length()) {
					 ++j;
				 }
				 if (k[j] != Input[i] && k.length() < Input.length()) {
					 ++i;
				 }
				 if (k[j] != Input[i] && k.length() == Input.length()) {
					 ++i;
					 ++j;
				 }
			 }
			 res = Utils::getMax(res, temp);
			 //give the best fiting suggestion, this might produce more than one finding
			 if ((Input.length() < k.length() && float(Input.length()) / float(k.length()) >= 0.42) || k.length() <= Input.length() || isTrueSubString(Input)) {
				 if (res / Input.length() >= errorChance) {
				 	 if (duplicates.insert(k).second) {
				 	 	 if (res / Input.length() > errorChance) {
				 	 		 suggestions.clear();
				 	 	 }
				 	 	 errorChance = res / Input.length();
						 if (errorChance >= 0.8) {
				 	 	 suggestions.push_back(k);
						 }
				 	 }
				 }
			 }
		 }
	 }
	 return  suggestions;
 }

 //check if the string is connected substring of an entry
 bool Table::isTrueSubString(string Input) const {
	 int res, temp;
	 unsigned int i, j;
	 string gerne, title;
	 for (auto it : m_Collumns) {
		 gerne = it->getGerne();
		 title = it->getTitle();
		 vector<string> key{ gerne, title };
		 for (auto k : key) {
			 temp = 0;
			 res = 0;
			 i = 0;
			 j = 0;
			 if (k.length() > Input.length()) {
				 while (i <= Input.length() - 1) {
					 if (k[j] == toupper(Input[i]) || k[j] == tolower(Input[i])) {
						 ++temp;
					 }
					 ++i;
					 ++j;
				 }
			 }
			 res = Utils::getMax(res, temp);
			 }
		 if (res >= 4) {
			return true;
			break;
		 }
	 }
	return false;
 }