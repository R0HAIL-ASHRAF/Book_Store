#pragma once

#include "MyString.h"
#include "MyVector.h"
#include "Product.h"
#include "Classic.h"

class Store
{
private:
	MyString storeId;
	MyString storeName;
	Address storeAddress;
	MyVector<Product*> products;
	MyVector<Customer*> customers;

public:
	Store();
	Store(const Store& other);
	Store(const MyString& _storeId, const MyString& _storeName,
		const Address& _address);
	Store& operator = (const Store& other);

	//adders
	void AddCustomer(Classic*& customer);

	//getters
	MyVector<Product*> GetProducts() const;
	MyVector<Customer*> GetCustomers() const;

};