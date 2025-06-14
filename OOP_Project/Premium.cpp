#include "Premium.h"

int Premium::discountRate = 0;

Premium::Premium()
	:Customer(), isActivePremiumMember{true}
{
}

Premium::Premium(const Premium& other)
	:Customer(other), 
	isActivePremiumMember{ other.isActivePremiumMember }
{
}

Premium::Premium(const Login& _login, const MyString& email, const Date& dob, const Name& name, const Address& addr)
	:Customer(_login, email, dob, name, addr),
	isActivePremiumMember{ true }
{
}

Premium& Premium::operator=(const Premium& other)
{
	if(this == &other)
		return *this;

	static_cast<Customer&>(*this) = other;
	isActivePremiumMember = other.isActivePremiumMember;
	return *this;
}

void Premium::AddOrder(Order*& order)
{
	orders.push(order);
}


void Premium::SetLogin(const Login& _login)
{
	login = _login;
}

void Premium::SetName(const Name& _name)
{
	fullName = _name;
}

void Premium::SetEmail(const MyString& _email)
{
	email = _email;
}

void Premium::SetAddress(const Address& addr)
{
	address = addr;
}

void Premium::SetPerson(const Person& _person)
{
	Person::operator=(_person);
}

void Premium::SetPremiumMember()
{
		isActivePremiumMember = true;
}

void Premium::RemovePremiumMember()
{
	isActivePremiumMember = false;
}

MyString Premium::GetPersonType() const
{
	return "Premium";
}
MyString Premium::getUserName() const
{
	return login.getUsername();
}
MyString Premium::getPassword() const
{
	return login.getPassword();
}
Name Premium::GetName() const
{
	return fullName;
}


bool Premium::IsActivePremiumMember() const
{
	return isActivePremiumMember;
}

void Premium::DisplayCustomer() const
{
}

MyString Premium::GetEmail() const
{
	return email;
}

MyVector<Order*>& Premium::GetOrders()
{
	return orders;
}


Date Premium::GetDate() {
	return birthDate;
}
Address Premium::GetAddress() {
	return address;
}