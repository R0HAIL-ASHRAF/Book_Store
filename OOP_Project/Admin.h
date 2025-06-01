#pragma once

#include "Person.h"
#include"MyVector.h"
#include "StoreManager.h"

class Admin : public Person
{
private:
	static int AdminCount;
	MyVector<StoreManager*> stores;

	/*Admin(const Admin& other) = delete;
	Admin& operator=(const Admin& other) = delete;
	*/

public:
	Admin();
	Admin* GetInstance();

	// void writeToFile(fstream& fout) const;
	//// void readFromFile(fstream& fin) const;

	////setters
	//void AddStoreManager(StoreManager* store);
	//void RemoveStoreManager(StoreManager* store);
	//void ChangeStoreManager(StoreManager *storeManager, Store* store);
	//void AddProductToStore(Product* product, StoreManager* store);
	//void RemoveProductFromStore(Product* product, StoreManager* store);
	//void AddCustomerToStore(Customer* customer, StoreManager* store);
	//void RemoveCustomerFromStore(Customer* customer, StoreManager* store);
	void SetLogin(const Login& _login) override;
	void SetName(const Name& _name) override;
	void SetEmail(const MyString& _email) override;
	void SetAddress(const Address& addr) override;
	void SetPerson(const Person& _person) override;

	////getters
	//MyString GetStoresData() const;
	//MyString GetProductDetails() const;
	//MyString GetCustomerList() const;
	//MyString GetCustomerListByStore(Store* store) const;
	//MyString GetStoreManagerList() const;
	//MyString GetProductListByStore(Store* store) const;
	MyString GetPersonType() const override;
	Name GetName() const override;
	MyString GetPersonType() const override;
	MyString getUserName() const override;
	MyString getPassword() const override;

	// display not defined yet
	void DisplayProducts() const;
	void DisplayStores() const;
	void DisplayStoreManagers() const;
	void DisplayCustomers() const;
	void DisplayStoreManager(StoreManager* storeManager) const;
	void DisplayAllStoreManagers() const;

	
};

