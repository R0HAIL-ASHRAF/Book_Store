#include "Customer.h"

Customer::Customer()
	:Person(), orders{MyVector<Order*>()}
{
}

Customer::Customer(const Customer& other)
	:Person(other)
{
	for (int i = 0; i < other.orders.size(); i++) {
		orders.at(i) = other.orders.at(i);
	}
}

Customer::Customer(const Login& _login, const MyString& email, const Date& dob, const Name& name, const Address& addr)
	:Person(_login, email, dob, name, addr), 
	orders{MyVector<Order*>()}
{
}

Customer& Customer::operator=(const Customer& other)
{
	if (this == &other)
		return *this;
	static_cast<Person&>(*this) = other;
	for (int i = 0; i < other.orders.size(); i++) {
		orders.push(other.orders.at(i));
	}
	return *this;
}

MyString Customer::GetPersonType() const
{
	return "Customer";
}

void Customer::AddOrder(Order*& order)
{
	orders.push(order);
}

MyString Customer::getUserName() const
{
	return login.getUsername();
}
MyString Customer::getPassword() const
{
	return login.getPassword();
}
