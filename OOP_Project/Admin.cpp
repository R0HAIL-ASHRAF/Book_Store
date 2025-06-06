#include "Admin.h"

Admin* Admin::instance = nullptr;

Admin::Admin(wxWindow* window)
	:Person(), stores(MyVector<StoreManager*>())
{
	SetMainWindow(window);
	
	
}
Admin* Admin::GetInstance(wxWindow* window)
{
	if (instance == nullptr) {
		instance = new Admin(window);
		
		

	}
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
	SetLogin(Login("admin", "admin123"));
	SetName(Name("Rohail ", "Ashraf"));
	SetEmail("rohailashraf087@gmail.com");
	SetAddress(Address("House # 123", "Lahore", "Punjab", "Pakistan"));

	// setting date of the admin is missing
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
	// wxLogMessage("Customer count in Admin: %d", customers.size());
	return customers;
}

MyVector<StoreManager*> Admin::GetStores() const
{
	return stores;
}


MyString Admin::GetEmail() const
{
	return email;
}