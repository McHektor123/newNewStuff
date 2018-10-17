#pragma once
#include <string>
#include <iterator>

using namespace std;
class Row
{
public:
	Row(int number,string title, int length, string gerne);
	~Row();

	string getTitle() { return m_title; }
	int getLength() { return m_length; }
	int getNumber() { return m_number; }
	string getGerne() { return m_gerne; }
private:
	int m_number;
	string m_title;
	int m_length;
	string m_gerne;
	int current_index;
};
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
