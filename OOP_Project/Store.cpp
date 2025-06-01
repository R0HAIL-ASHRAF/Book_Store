#include "Store.h"
#include "StoreManager.h"

Store::Store()
	:storeId{MyString()}, storeName{MyString()},
	storeAddress{Address()},
	products{MyVector<Product>()}, 
	customers{MyVector<Customer*>()}
{
}

Store::Store(const Store& other)
	:storeId{ other.storeId }, 
	storeName{ other.storeName },
	storeAddress{ other.storeAddress }
{
	for (int i = 0; i < other.products.size(); i++) {
		products.at(i) = other.products.at(i);
	}
	for (int i = 0; i < other.customers.size(); i++) {
		customers.at(i) = other.customers.at(i);
	}
}

Store::Store(const MyString& _storeId, const MyString& _storeName, const Address& _address)
	:storeId{_storeId}, storeName{_storeName},
	storeAddress{_address}, 
	products{ MyVector<Product>() },
	customers{ MyVector<Customer*>() }
{
	
}


Store& Store::operator=(const Store& other)
{
	if (this == &other)
		return *this;

	storeId = other.storeId;
	storeName = other.storeName;
	storeAddress = other.storeAddress;

	for (int i = 0; i < other.products.size(); i++) {
		products.push( other.products.at(i));
	}
	for (int i = 0; i < other.customers.size(); i++) {
		customers.push(other.customers.at(i));
	}
}

void Store::AddCustomer(Classic*& customer)
{
	customers.push(customer);
}

MyVector<Product> Store::GetProducts() const
{
	return products;
}

MyVector<Customer*> Store::GetCustomers() const
{
	return customers;
}