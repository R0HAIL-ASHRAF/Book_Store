#pragma once

#include<wx\wx.h>
#include "Person.h"
#include "Store.h"

class StoreManager : public Person
{
private:
	Store store;
public:
	StoreManager();
	StoreManager(const StoreManager& other);
	StoreManager& operator=(const StoreManager& other);
	
	//display
	wxArrayString DisplayCustomer() const;
	void DisplayStore() const;
	
	// getters
	Store* GetStore() const;
	

	// setters
	void SetStore(Store store);
	void SetLogin(const Login& _login) override;
	void SetName(const Name& _name) override;
	void SetEmail(const MyString& _email) override;
	void SetAddress(const Address& addr) override;
	void SetPerson(const Person& _person) override;

	// virtual
	MyString getUserName() const override;
	MyString getPassword() const override;
	MyString GetPersonType() const override;
	Name GetName() const override;
};

