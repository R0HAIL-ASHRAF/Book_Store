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

	MyString GetPersonType() const override;
	void AddOrder(Order*& order);
	MyString getUserName() const override;
	MyString getPassword() const override;
};

