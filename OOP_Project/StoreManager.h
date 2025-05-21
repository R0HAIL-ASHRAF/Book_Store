#pragma once

#include<wx\wx.h>
#include "Person.h"
#include "Store.h"

class StoreManager : public Person
{
private:
	Store* store;
public:
	StoreManager();
	StoreManager(const StoreManager& other);
	StoreManager& operator=(const StoreManager& other);
	
	//display
	wxArrayString DisplayCustomer() const;

	// getters
	Store* GetStore() const;

	// setters
	void SetStore(Store* store);

	// virtual
	MyString getUserName() const override;
	MyString getPassword() const override;
	MyString GetPersonType() const override;

};

