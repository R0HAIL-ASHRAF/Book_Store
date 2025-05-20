#pragma once

#include "MyString.h"
#include "MyVector.h"
#include "Product.h"
#include "Customer.h"

class Store
{
private:
	MyString storeId;
	MyString storeName;
	Address storeAddress;
	MyVector<Product*> products;
	MyVector<Customer*> customers;
};

