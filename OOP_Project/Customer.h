#pragma once

#include "Person.h"
#include "Order.h"
#include "MyVector.h"

class Customer :
    public Person
{
protected:
	MyVector<Order*> orders;
public:
	Customer();
	Customer(const Customer& other);
	Customer(const Login& _login, 
		const MyString& email, const Date& dob, 
		const Name& name, const Address& addr);
	Customer& operator=(const Customer& other);

	// void writeToFile(fstream& fout) const override;
	// void readFromFile(fstream& fin) const override;


	//setters
	void SetLogin(const Login& _login) override;
	void SetName(const Name& _name) override;
	void SetEmail(const MyString& _email) override;
	void SetAddress(const Address& addr) override;
	void SetPerson(const Person& _person) override;
	virtual void AddOrder(Order*& order);

	//getters
	virtual void DisplayCustomer() const;
	MyString GetPersonType() const override;
	MyString getUserName() const override;
	MyString getPassword() const override;
	Name GetName() const override;

	// display
	virtual void DisplayOrders() const;
	virtual void DisplayCustomer() const;

};

