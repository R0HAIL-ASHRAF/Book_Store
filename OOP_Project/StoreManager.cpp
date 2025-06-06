#include "StoreManager.h"

StoreManager::StoreManager()
	:Person(),store(Store())
{
}

StoreManager::StoreManager(const Login& _login, const MyString& email, const Date& dob, const Name& name, const Address& addr, Store store)
	:Person(_login, email, dob, name, addr), store{Store()}
{
}

StoreManager::StoreManager(const StoreManager& other)
	:Person(other)
{
	store = other.store;
}
StoreManager& StoreManager::operator=(const StoreManager& other) 
{
	if (this == &other)
		return *this;

	static_cast<Person&>(*this) = other;
	store = other.store;
	return *this;
}
Store* StoreManager::GetStore() const
{
	return new Store(store);
}

wxArrayString StoreManager::DisplayCustomer() const
{
	return wxArrayString();
}

void StoreManager::SetStore(Store store)
{
	this->store = store;
}

MyString StoreManager::getUserName() const
{
	return login.getUsername();
}

MyString StoreManager::getPassword() const
{
	return login.getPassword();
}
MyString StoreManager::GetPersonType() const
{
	return "StoreManager";
}


Name StoreManager::GetName() const
{
	return fullName;
}

void StoreManager::SetLogin(const Login& _login)
{
	login = _login;
}

void StoreManager::SetName(const Name& _name)
{
	fullName = _name;
}

void StoreManager::SetEmail(const MyString& _email)
{
	email = _email;
}

void StoreManager::SetAddress(const Address& addr)
{
	address = addr;
}

void StoreManager::SetPerson(const Person& _person)
{
	Person::operator=(_person);
}
MyString StoreManager::GetStoreName() const
{
	return fullName.ToString();

}

MyString StoreManager::GetEmail() const
{
	return email;
}