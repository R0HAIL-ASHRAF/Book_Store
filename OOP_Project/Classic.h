#pragma once
#include "Customer.h"
class Classic : public Customer
{
private:
	static int discountRate;

public:
	Classic();
	Classic(const Classic& other);
	Classic(const Login& _login,
		const MyString& email, const Date& dob,
		const Name& name, const Address& addr);
	Classic& operator=(const Classic& other);

	// void writeToFile(fstream& fout) const override;
	// void readFromFile(fstream& fin) const override;

	//setters
	void AddOrder(Order*& order) override;
	void SetLogin(const Login& _login) override;
	void SetName(const Name& _name) override;
	void SetEmail(const MyString& _email) override;
	void SetAddress(const Address& addr) override;
	void SetPerson(const Person& _person) override;

	//getters
	MyString GetPersonType() const override;
	MyString getUserName() const override;
	MyString getPassword() const override;
	Name GetName() const override;

	//dipslay
	void DisplayCustomer() const override; // not defined yet
	
};