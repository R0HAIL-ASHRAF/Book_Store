#pragma once

#include "Person.h"
#include"MyVector.h"
#include "Store.h"

class Admin : public Person
{
private:
	static int AdminCount;
	MyVector<Store*>* stores;

	Admin(const Admin& other) = delete;
	Admin& operator=(const Admin& other) = delete;
	Admin(const Login& _login,
		const MyString& email, const Date& dob,
		const Name& name, const Address& addr);

public:
	Admin();
	static Admin* GetInstance();

	void writeToFile(fstream& fout) const;
	void readFromFile(fstream& fin) const;

	//setters
	void AddStore(Store* store);
	void RemoveStore(Store* store);
	void ChangeStoreManager(Person* person, Store* store);
	void AddProductToStore(Product* product, Store* store);
	void RemoveProductFromStore(Product* product, Store* store);
	void AddCustomerToStore(Customer* customer, Store* store);
	void RemoveCustomerFromStore(Customer* customer, Store* store);

	//getters
	MyString GetStoresData() const;
	MyString GetProductDetails() const;
	MyString GetCustomerList() const;
	MyString GetCustomerListByStore(Store* store) const;
	MyString GetStoreManagerList() const;
	MyString GetProductListByStore(Store* store) const;


	// display
	void DisplayProducts() const;
	void DisplayStores() const;
	void DisplayStoreManagers() const;
	void DisplayCustomers() const;


	
};

