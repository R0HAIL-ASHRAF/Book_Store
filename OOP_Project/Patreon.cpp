#include "Patreon.h"

int Patreon::discountRate = 0;


Patreon::Patreon()
	:Customer(), PatreonId{ 0 }, isActivePatreon{ true}
{
}

Patreon::Patreon(const Patreon& other)
	:Customer(other) ,PatreonId{other.PatreonId}, 
	isActivePatreon{ other.isActivePatreon }
{
}

Patreon::Patreon(const Login& _login, const MyString& email, const Date& dob, const Name& name, const Address& addr)
	:Customer(_login, email, dob, name, addr), PatreonId{ 0 }, isActivePatreon{ true }
{
}

Patreon& Patreon::operator=(const Patreon& other)
{
	if(this == &other)
		return *this;

	static_cast<Customer&>(*this) = other;
	PatreonId = other.PatreonId;
	isActivePatreon = other.isActivePatreon;
	return *this;
}

void Patreon::AddOrder(Order*& order)
{
	orders.push(order);
}


void Patreon::SetLogin(const Login& _login)
{
	login = _login;
}

void Patreon::SetName(const Name& _name)
{
	fullName = _name;
}

void Patreon::SetEmail(const MyString& _email)
{
	email = _email;
}

void Patreon::SetAddress(const Address& addr)
{
	address = addr;
}

void Patreon::SetPerson(const Person& _person)
{
	Person::operator=(_person);
}

void Patreon::SetPatreonMember(const MyString& PatreonId)
{
	this->PatreonId = PatreonId;
}

void Patreon::RemovePatreonMember()
{
	isActivePatreon = false;
}

MyString Patreon::GetPersonType() const
{
	return "Patreon";
}
MyString Patreon::getUserName() const
{
	return login.getUsername();
}
MyString Patreon::getPassword() const
{
	return login.getPassword();
}

MyString Patreon::GetPatreonId() const
{
	return PatreonId;
}

bool Patreon::IsActivePatreon() const
{
	return isActivePatreon;
}
Name Patreon::GetName() const
{
	return fullName;
}

void Patreon::DisplayCustomer() const
{
}

MyString Patreon::GetEmail() const
{
	return email;
}


MyVector<Order*>& Patreon::GetOrders()
{
	return orders;
}



Date Patreon::GetDate() {
	return birthDate;
}
Address Patreon::GetAddress() {
	return address;
}