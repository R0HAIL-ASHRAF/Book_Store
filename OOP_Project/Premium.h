#pragma once

#include "Customer.h"

class Premium :public Customer
{
private:
	static int discountRate;
	bool isActivePremiumMember;
public:
	Premium();
	Premium(const Premium& other);
	Premium(const Login& _login,
		const MyString& email, const Date& dob,
		const Name& name, const Address& addr);
	Premium& operator=(const Premium& other);

	// void writeToFile(fstream& fout) const override;
	// void readFromFile(fstream& fin) const override;

	//setters
	void AddOrder(Order*& order) override;
	void SetLogin(const Login& _login) override;
	void SetName(const Name& _name) override;
	void SetEmail(const MyString& _email) override;
	void SetAddress(const Address& addr) override;
	void SetPerson(const Person& _person) override;
	void SetPremiumMember();
	void RemovePremiumMember();

	//getters
	MyString GetPersonType() const override;
	
	MyString getUserName() const override;
	MyString getPassword() const override;
	Name GetName() const override;
	MyString GetEmail() const override;
	bool IsActivePremiumMember() const;
	MyVector<Order*>& GetOrders() override;

	Date GetDate() override;
	Address GetAddress() override;
	//dipslay
	void DisplayCustomer() const override; //not defined yet
};

