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
	//Iterator for the Rows
	struct It
		{
		Row* vec_;
		int pointer_;

		It(Row* vec) : vec_{ vec }, pointer_{ 0 } {}

		It(Row* vec, int size) : vec_{ vec }, pointer_{ size } {}

		bool operator!=(const It other) const
		{
			return !(*this == other);
		}

		bool operator==(const It other) const
		{
			return pointer_ == other.pointer_;
		}

		It operator++()
		{
			++pointer_;
			return *this;
		}

		It operator--()
		{
			--pointer_;
			return *this;
		}

		It operator++(int)
		{
			It tmp(*this);
			++pointer_;
			return tmp;
		}

		Row* operator*() 
		{
			return vec_;
		}
	};
