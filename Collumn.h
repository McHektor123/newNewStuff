#pragma once
#include <string>
#include <iterator>

using namespace std;
class Collumn
{
public:
	Collumn(int number,string title, int length, string gerne);
	~Collumn();

	string getTitle() { return m_title; }
	int getLength() { return m_length; }
	int getNumber() { return m_number; }
	string getGerne() { return m_gerne; }

	void setCurrentIndex(int index) { current_index = index; }
private:
	int m_number;
	string m_title;
	int m_length;
	string m_gerne;
	int current_index;
};
	struct It
		{
		Collumn vec_;
		int pointer_;

		It(Collumn vec) : vec_{ vec }, pointer_{ 0 } {}

		It(Collumn vec, int size) : vec_{ vec }, pointer_{ size } {}

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

		Collumn operator*() const
		{
			return vec_;
		}
	};



