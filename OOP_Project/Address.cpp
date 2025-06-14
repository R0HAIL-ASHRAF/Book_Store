#include "Address.h"
#include<iostream>

Address::Address() :city(""), country(""), province(""), houseNumber("")
{
}

Address::Address(MyString _houseNumber, const MyString& c, const MyString& _province, const MyString& co) 
	:city(c), country(co), houseNumber{_houseNumber}, province{_province}
{
}

Address::Address(const Address& other) 
	:city(other.city), country(other.country), houseNumber{other.houseNumber}, province{other.province}
{
}

Address& Address::operator=(const Address& other)
{
	if (this == &other)
		return *this;
	city = other.city;
	province = other.province;
	houseNumber = other.houseNumber;
	country = other.country;
	return *this;
}

bool Address::operator==(const Address& other) const
{
	if(houseNumber == other.houseNumber && city == other.city &&
		province == other.province && country == other.country)
		return true;
	return false;
}

bool Address::operator!=(const Address& other) const
{
	if(*this == other)
	return false;
	return true;
}

MyString Address::ToString() const
{
	MyString add;
	add.AppendArray(houseNumber);
	add.AppendArray(", ");
	add.AppendArray(city);
	add.AppendArray(", ");
	add.AppendArray(province);
	add.AppendArray(", ");
	add.AppendArray(country);
	add.AppendArray(".");
	add.AppendArray("\0");
	return add;
}



ostream& operator<<(ostream& os, const Address& a)
{
	os << a.houseNumber << ", " << a.city << ", " << a.province << ", " << a.country;
	return os;
	
}
