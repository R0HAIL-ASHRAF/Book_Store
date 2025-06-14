#include "Name.h"


Name::Name() :firstName(""), lastName("")
{
}

Name::Name(const MyString& f, const MyString& l) : firstName(f), lastName(l)
{
}

Name::Name(const Name& other) :firstName(other.firstName), lastName(other.lastName)
{
}

Name& Name::operator=(const Name& other)
{
	if (this == &other)
		return *this;
	firstName = other.firstName;
	lastName = other.lastName;
	return *this;
}

bool Name::operator==(const Name& other) const
{
	if (firstName == other.firstName && lastName == other.lastName)
		return true;
	return false;
}

bool Name::operator!=(const Name& other) const
{
	if (*this == other)
		return false;
	return true;
}

ostream& operator<<(ostream& os, const Name& n)
{
	os << n.firstName << " " << n.lastName;
	return os;
}

MyString Name::ToString() const 
{
	MyString name = firstName;
	name.AppendArray(" ");
	name.AppendArray(lastName);
	name.AppendArray('\0');
	return name;
}