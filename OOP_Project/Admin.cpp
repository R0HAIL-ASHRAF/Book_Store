#include "Admin.h"

Admin* Admin::instance = new Admin();

Admin::Admin()
	:Person(), stores(MyVector<StoreManager*>())
{
	
	
}
Admin* Admin::GetInstance()
{
	return instance;
}
void Admin::SetMainWindow(wxWindow* window) {
	if (window == nullptr) {
		wxLogError("SetMainWindow: received null wxWindow pointer!");
		return;
	}

	mainWindowPointer = window;
	loginPanelInstance = loginPanel::GetInstance(mainWindowPointer);
	SetCustomers(*loginPanelInstance->GetCustomers());
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

void Admin::SetCustomers(const MyVector<Classic*>& _customers)
{
	for(int i = 0; i< _customers.size(); i++)
	{
		customers.push(_customers[i]);
	}
}
MyVector <Customer*> Admin::GetCustomers() const
{
	return customers;
}