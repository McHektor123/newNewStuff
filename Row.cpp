#include "pch.h"
#include "Row.h"

using namespace std;
Row::Row(int number,  string title, int length, string gerne, int rating) : m_number(number), m_title(title), m_length(length), m_gerne(gerne), m_rating(rating)
{
}


Row::~Row()
{
}
