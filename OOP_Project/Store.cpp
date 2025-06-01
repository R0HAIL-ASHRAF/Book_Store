#include "Store.h"
#include "StoreManager.h"

Store::Store()
	:storeId{MyString()}, storeName{MyString()},
	storeAddress{Address()},
	products{MyVector<Product>()}	
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
	
}

Store::Store(const MyString& _storeId, const MyString& _storeName, const Address& _address)
	:storeId{_storeId}, storeName{_storeName},
	storeAddress{_address}, 
	products{ MyVector<Product>() }
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
	
}



MyVector<Product> Store::GetProducts() const
{
	return products;
}


Store Store::GetStoreInfo() const
{
	return *this;
}
