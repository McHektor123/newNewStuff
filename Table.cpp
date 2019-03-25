#include "pch.h"
#include "Table.h"
#include "Row.h"
#include "Utils.h"
#include "Writer.h"
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

Table::Table(vector<Row*> Row) : m_Rows(Row)
{
}

Table::~Table()
{
}

//insert datas
 void Table::insertValues(string title, int length, string gerne, int rating) {
	 if (!unusedIndex.empty()) {
		 Row *co = new Row(unusedIndex[0], title, length, gerne, rating);
		 Row c2 = *co;
		 Row *c1 = &c2;
		 m_Rows.push_back((co));
		 cout << "Inserted entry with title: " << title << endl;
		 cout << "Number of entries: " << m_Rows.size() << endl;
		 unusedIndex.erase(unusedIndex.begin());
	 }
	 else{
		 Row *co = new  Row(index, title, length, gerne, rating);
		 index++;
		 Row c2 = *co;
		 Row *c1 = &c2;
		 m_Rows.push_back((co));
		 cout << "Inserted entry with title: " << title << endl;
		 cout << "Number of entries: " << m_Rows.size() << endl;
	 }
}

 //delete data with a int as key
 void Table::deleteWithInt(int searchNumber, bool deleteAll,  auto x(Row*)-> int) {
	 int index = 0;
	 for (auto i = m_Rows.begin(); i != m_Rows.end(); ) {
		 auto &it = m_Rows.begin()[index];
		 if (x(it) == searchNumber) {
			 unusedIndex.push_back(it->getNumber());
			 delete *i;
			 i = m_Rows.erase(i);
			 cout << "Deleted entry: title=" << it->getTitle() << " length=" << it->getLength() 
				  << " gerne=" << it->getGerne() << " rating=" << it->getRating() << " number=" << it->getNumber() << "." << endl;
			 cout << "Number of left entries: " << m_Rows.size() << "." << endl;
			 if (!deleteAll) break;
			}
		 else {
			++index;
			++i;
		 }
	 }
 }

 //delete data with a string as key
 void Table::deleteWitString(string searchGerne, bool deleteAll, auto x(Row*)-> string) {
	 int index = 0;
	 for (auto i = m_Rows.begin(); i != m_Rows.end(); ) {
		 auto &it = m_Rows.begin()[index];
		 if (x(it) == searchGerne) {
			 unusedIndex.push_back(it->getNumber());
			 i = m_Rows.erase(i);
			 cout << "Deleted entry: title=" << it->getTitle() << " length=" << it->getLength()
				 << " gerne=" << it->getGerne() << " rating=" << it->getRating() << " number=" << it->getNumber() << "." << endl;			 cout << "Number of left entries: " << m_Rows.size() << "." << endl;
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
	 if (m_Rows.size() == 0)
	 {
		cout << "No entry found" << endl;
		hasOutput = true;
	 }
	 for (auto it : m_Rows) {
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
	 if (!hasOutput && Suggestion(searchString).empty()) {
		 cout << "No entry match to the given key" << endl;
	 }
 }

 //if no result is found by the Inputstring, this function is called is look for a suggestion
 vector<string> Table::Suggestion(string Input) const {
	 double errorChance=1.0;
	 set<string> duplicates; 
	 vector<string> suggestions;
	 unsigned int i,j,temp,t1,t2,subCount,res;
	 string gerne,title;
	 bool trueSubString=false;
	 for (auto it : m_Rows) {
		 res = 0;
		 gerne = it->getGerne();
		 title = it->getTitle();
		 vector<string> key{gerne, title};
		 for (auto k : key) {
			 i = 0;
			 j = 0;
			 t1 = 0;
			 t2 = 0;
			 temp = 0;
			 subCount = 0;
			 while (i <= Input.length() - 1 && j <= k.length() - 1) {
				 if (toupper(k[j]) == toupper(Input[i])) {
					 ++temp;
					 ++j;
					 ++i;
				 }
				 if (k.length() > Input.length()) {
					 if (k[j] != Input[i]) {
						++j;
					 }
					 while (t1 <= Input.length() - 1) {
						 if (toupper(k[t2]) == toupper(Input[t1])) {
							 ++subCount;
						 }
						 ++t1;
						 ++t2;
					 }
					 if (subCount >= 4) {
						 trueSubString = true;
					 }
				 }
				 if (k[j] != Input[i] && k.length() < Input.length()) {
					 ++i;
				 }
				 if (k[j] != Input[i] && k.length() == Input.length()) {
					 ++i;
					 ++j;
				 }
			 res = Utils::getMax(res, temp);
			 }
			 //give the best fiting suggestion, this might produce more than one finding
			 if ((Input.length() < k.length() && float(Input.length()) / float(k.length()) >= 0.42) || k.length() <= Input.length() || trueSubString) {
				 if (res / Input.length() >= errorChance) {
				 	 if (duplicates.insert(k).second) {
				 	 	 if (float(res) / float(Input.length()) > errorChance) {
				 	 		 suggestions.clear();
				 	 	 }
				 	 	 errorChance = float(res) / float(Input.length());
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