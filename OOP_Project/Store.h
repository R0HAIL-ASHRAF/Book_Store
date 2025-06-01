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
	MyVector<Product> products;
	

public:
	Store();
	Store(const Store& other);
	Store(const MyString& _storeId, const MyString& _storeName,
		const Address& _address);
	Store& operator = (const Store& other);

	//adders
	

	//getters
	MyVector<Product> GetProducts() const;
	Store GetStoreInfo() const;

	// displays   not defined yet 
	void DisplayStore() const;
	void DisplayProducts() const;
	void DisplayCustomers() const;
	void DisplayProduct(const MyString& productId) const;
	void DisplayCustomer(const MyString& customerId) const;
	void DisplayProductByCategory(const MyString& category) const;



};