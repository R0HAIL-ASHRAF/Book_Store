#pragma once

#include<wx\wx.h>		
#include "Person.h"
#include"MyVector.h"
#include "StoreManager.h"
#include "LoginPanel.h"
#include"Premium.h"



class Admin : public Person
{
private:
	static Admin* instance;
	MyVector<StoreManager*> stores;
	MyVector<Customer*> customers;
	loginPanel* loginPanelInstance;
	wxWindow* mainWindowPointer;

public:
	Admin(wxWindow* window);
	static void DestroyInstance();
	static Admin* GetInstance(wxWindow* window);
	void SetMainWindow(wxWindow* window);

	bool ValidateStoreManagers() const;
	int GetIndexOfUser() const;
	void ConvertStatus();
	
	void SetLogin(const Login& _login) override;
	void SetName(const Name& _name) override;
	void SetEmail(const MyString& _email) override;
	void SetAddress(const Address& addr) override;
	void SetPerson(const Person& _person) override;
	void SetCustomers(const MyVector<Classic*>& _customers);
	
	//Adders
	void AddStoreManager(StoreManager* storeManager);

	//getters
	
	MyString GetPersonType() const override;
	Name GetName() const override;
	MyString getUserName() const override;
	MyString getPassword() const override;
	MyVector<Customer*> GetCustomers() const;
	MyVector<StoreManager*> GetStores() const;
	MyString GetEmail() const override;

	void WriteStoreManagersToFile() const;
	void ReadStoreManagersFromFile();

	// display not defined yet
	void DisplayProducts() const;
	void DisplayStores() const;
	void DisplayStoreManagers() const;
	void DisplayCustomers() const;
	void DisplayStoreManager(StoreManager* storeManager) const;
	void DisplayAllStoreManagers() const;
	~Admin();
	
};

