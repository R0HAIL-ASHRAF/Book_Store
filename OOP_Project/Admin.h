#pragma once

#include<wx\wx.h>		
#include "Person.h"
#include"MyVector.h"
#include "StoreManager.h"
#include "LoginPanel.h"



class Admin : public Person
{
private:
	static Admin* instance;
	MyVector<StoreManager*> stores;
	MyVector<Customer*> customers;
	loginPanel* loginPanelInstance;
	wxWindow* mainWindowPointer;

	/*Admin(const Admin& other) = delete;
	Admin& operator=(const Admin& other) = delete;
	*/

public:
	Admin(wxWindow* window);
	static Admin* GetInstance(wxWindow* window);
	void SetMainWindow(wxWindow* window);
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
	void SetCustomers(const MyVector<Classic*>& _customers);
	//getters
	
	//MyString GetStoresData() const;
	//MyString GetProductDetails() const;
	//MyString GetCustomerList() const;
	//MyString GetCustomerListByStore(Store* store) const;
	//MyString GetStoreManagerList() const;
	//MyString GetProductListByStore(Store* store) const;
	MyString GetPersonType() const override;
	Name GetName() const override;
	MyString getUserName() const override;
	MyString getPassword() const override;
	MyVector<Customer*> GetCustomers() const;
	MyVector<StoreManager*> GetStores() const;


	// display not defined yet
	void DisplayProducts() const;
	void DisplayStores() const;
	void DisplayStoreManagers() const;
	void DisplayCustomers() const;
	void DisplayStoreManager(StoreManager* storeManager) const;
	void DisplayAllStoreManagers() const;

	
};

