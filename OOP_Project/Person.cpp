#include "Person.h"

Person::Person() :email(""), 
birthDate(Date()), fullName(Name()), 
address(Address()),
login()
{
}

Person::Person(const Person& other) 
	:email(other.email),
	birthDate(other.birthDate),
	fullName(other.fullName), 
	address(other.address), 
	login(other.login)
{
}


Person::Person(const Login& _login,  const MyString& email, const Date& dob, const Name& name, const Address& addr) :
	email(email), birthDate(dob),
	fullName(name), address(addr),
	login(_login)
{
}

Person& Person::operator=(const Person& other)
{
	if (this == &other)
		return *this;
	email = other.email;
	birthDate = other.birthDate;
	address = other.address;
	fullName = other.fullName;
	login = other.login;
	return *this;
}

bool Person::operator==(const Person& other) const
{
	if (email == other.email && 
		birthDate == other.birthDate &&
		address == other.address && 
		other.fullName == fullName &&
		other.login == login )
		return true;
	
	return false;
}
bool Person::operator!=(const Person& other) const
{
	if(*this == other)
		return false;
	return true;
}
