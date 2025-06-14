#include "Classic.h"

int Classic::discountRate = 2;

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

void Classic::AddOrder(Order*& order)
{
	orders.push(order);
}


void Classic::SetLogin(const Login& _login)
{
	login = _login;
}

void Classic::SetName(const Name& _name)
{
	fullName = _name;
}

void Classic::SetEmail(const MyString& _email)
{
	email = _email;
}

void Classic::SetAddress(const Address& addr)
{
	address = addr;
}

void Classic::SetPerson(const Person& _person)
{
	Person::operator=(_person);
}

MyString Classic::GetPersonType() const
{
	return "Classic";
}
MyString Classic::getUserName() const
{
	return login.getUsername();
}
MyString Classic::getPassword() const
{
	return login.getPassword();
}
Name Classic::GetName() const
{
	return fullName;
}

void Classic::DisplayCustomer() const
{
}

MyString Classic::GetEmail() const
{
	return email;
}

MyVector<Order*>& Classic::GetOrders()
{
	return orders;
}

Date Classic::GetDate() {
	return birthDate;
}
Address Classic::GetAddress() {
	return address;
}