#pragma once

#include "Person.h"
#include "Order.h"
#include "MyVector.h"

class Customer : public Person
{
protected:
	MyVector<Order*> orders;
	MyString fileName;
public:
	Customer();
	Customer(const Customer& other);
	Customer(const Login& _login, 
		const MyString& email, const Date& dob, 
		const Name& name, const Address& addr);
	Customer& operator=(const Customer& other);

	void WriteOrdersToFile();
	void ReadOrdersFromFile();

	Order* ReadOrderFromFile(std::ifstream& fin);
	

	//setters
	void SetLogin(const Login& _login) override;
	void SetName(const Name& _name) override;
	void SetEmail(const MyString& _email) override;
	void SetAddress(const Address& addr) override;
	void SetPerson(const Person& _person) override;
	virtual void AddOrder(Order*& order);
	virtual MyVector<Order*>& GetOrders();
	virtual Date GetDate();
	virtual Address GetAddress();

	//getters
	virtual void DisplayCustomer() const;
	MyString GetPersonType() const override;
	MyString getUserName() const override;
	MyString getPassword() const override;
	Name GetName() const override;
	MyString GetEmail() const override;
	void OpenFile();
	// display
	virtual void DisplayOrders() const;
	~Customer();

};

