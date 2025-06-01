#include "Admin.h"

int Admin::AdminCount = 0;

Admin::Admin()
	:Person(), stores(MyVector<StoreManager*>())
{
	AdminCount++;
}
Admin* Admin::GetInstance()
{
	if (AdminCount == 0) {
		AdminCount++;
		return new Admin();
	}
	return this;
}
MyString Admin::GetPersonType() const
{
	return "Admin";
}

void Admin::DisplayProducts() const
{

}

void Admin::DisplayStores() const
{
}

void Admin::DisplayStoreManagers() const
{
}


void Admin::DisplayCustomers() const
{

}

void Admin::DisplayStoreManager(StoreManager* storeManager) const
{
}

void Admin::DisplayAllStoreManagers() const
{
}

Name Admin::GetName() const
{
	return fullName;
}

MyString Admin::GetPersonType() const
{
	return "Customer";
}



MyString Admin::getUserName() const
{
	return login.getUsername();
}
MyString Admin::getPassword() const
{
	return login.getPassword();
}

void Admin::SetLogin(const Login& _login)
{
	login = _login;
}

void Admin::SetName(const Name& _name)
{
	fullName = _name;
}

void Admin::SetEmail(const MyString& _email)
{
	email = _email;
}

void Admin::SetAddress(const Address& addr)
{
	address = addr;
}

void Admin::SetPerson(const Person& _person)
{
	Person::operator=(_person);
}