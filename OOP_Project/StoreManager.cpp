#include "StoreManager.h"

StoreManager::StoreManager()
	:Person(),store(new Store())
{
}

StoreManager::StoreManager(const StoreManager& other)
	:Person(other)
{
	store = new Store(*other.store);
}
StoreManager& StoreManager::operator=(const StoreManager& other) 
{
	if (this == &other)
		return *this;

	static_cast<Person&>(*this) = other;
	delete store;
	store = new Store(*other.store);
	return *this;
}
Store* StoreManager::GetStore() const
{
	return new Store(*store);
}

wxArrayString StoreManager::DisplayCustomer() const
{
	wxArrayString list;
	MyVector<Customer*> customerList = store->GetCustomers();
	for (int i = 0; i < customerList.size(); i++) {
		list.Add(customerList.at(i)->getUserName());
	}
	return list;
}

void StoreManager::SetStore(Store* store)
{
	delete store;
	store = new Store(*store);
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