#pragma once
#include <string>
#include <iterator>

using namespace std;
class Row
{
public:
	Row(int number,string title, int length, string gerne, int rating);
	~Row();
	string getTitle() const { return m_title; }
	int getLength() const { return m_length; }
	int getNumber() const { return m_number; }
	int getRating() const { return m_rating; }
	string getGerne() const { return m_gerne; }

private:
	int m_number;
	string m_title;
	int m_length;
	string m_gerne;
	int m_rating;
};
	
