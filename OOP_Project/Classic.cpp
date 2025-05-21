#include "Classic.h"

int Classic::discountRate = 2;//percent

Classic::Classic()
	:Customer()
{
}

Classic::Classic(const Classic& other)
	:Customer(other)
{
}

Classic::Classic(const Login& _login, const MyString& email, const Date& dob, const Name& name, const Address& addr)
	:Customer(_login, email, dob, name, addr)
{
}

Classic& Classic::operator=(const Classic& other)
{
	if (this == &other)
		return *this;

	static_cast<Customer&>(*this) = other;
	return *this;
}

MyString Classic::GetPersonType() const
{
	return "Classic";
}