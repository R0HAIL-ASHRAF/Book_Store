#include "date.h"
#include<iostream>

Date::Date() : day{ 1 }, month{ 1 }, year{ 2000 }
{
}

Date::Date(int d, int m, int y) : day{ d }, month{ m }, year{ y }
{
}

Date::Date(const Date& other) : day{ other.day }, month{ other.month }, year{ other.year }
{
}

Date& Date::operator=(const Date& other)
{
	if (this == &other)
		return *this;
	day = other.day;
	month = other.month;
	year = other.year;
	return *this;

}

bool Date::operator==(const Date& other) const
{
	if (day == other.day && month == other.month && year == other.year)
		return true;
	return false;
}

bool Date::operator!=(const Date& other) const
{
	if(*this == other)
	return false;
	return true;
}

MyString Date::ToStringForFile() const
{
	MyString date;
	date.AppendArray(MyString(day));
	date.AppendArray(" ");
	date.AppendArray(MyString(month));
	date.AppendArray(" ");
	date.AppendArray(MyString(year));
	return date;
}



MyString Date::ToString() const
{
	MyString date;
	date.AppendArray(MyString(day));
	date.AppendArray("-");
	date.AppendArray(MyString(month));
	date.AppendArray("-");
	date.AppendArray(MyString(year));
	return date;
}



std::ostream& operator<<(std::ostream& os, const Date& d)
{
	os << d.day <<" " << d.month<<" " << d.year;
	return os;
}
