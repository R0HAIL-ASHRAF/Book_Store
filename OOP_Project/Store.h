#pragma once

#include "MyString.h"
#include "MyVector.h"
#include "Product.h"
#include "Classic.h"
#include<fstream>
#include <wx/mstream.h>
#include"Book.h"
#include"Stationary.h"
#include"log.h"


class Store
{
private:
	MyString storeId;
	MyString storeName;
	Address storeAddress;
	MyVector<Product*> products;
	MyString fileName;
	MyString fileName2;

public:
	Store() = delete;
	Store(const Store& other);
	Store(const MyString& _storeId, const MyString& _storeName,
		const Address& _address);
	Store& operator = (const Store& other);

	//adders
	void LoadAllProductsFromFile();
	void LoadAllBooks();
	void LoadAllStationary();

	void WriteIntoFile();
	void WriteAllBooks(std::ofstream& fout, Book* product);
	void WriteAllStationary(std::ofstream& fout, Stationary* product) ;

	void WriteStoreInfoIntoFile(std::ofstream& fout);
	void ReadStoreInfoFromFile(std::ifstream& fin);

	//getters
	MyVector<Product*> GetProducts() ;
	Store GetStoreInfo() const;
	MyString GetStoreId() const;
	MyString GetStoreName() const;
	MyString GetStoreAddress() const;
	int GetProductSize() const;
	MyString GetBookFileName() const;
	MyString GetStatFileName() const;
	
	void OpenFiles();
	// displays   not defined yet 
	void DisplayStore() const;
	void DisplayProducts() const;
	void DisplayCustomers() const;
	void DisplayProduct(const MyString& productId) const;
	void DisplayCustomer(const MyString& customerId) const;
	void DisplayProductByCategory(const MyString& category) const;
	~Store();

	int GetStoreSize();

};