#pragma once
#include "Customer.h"
class Patreon : public Customer
{
private:
    static int discountRate;
    MyString PatreonId;
    bool isActivePatreon;
public:
	Patreon();
	Patreon(const Patreon& other);
	Patreon(const Login& _login,
		const MyString& email, const Date& dob,
		const Name& name, const Address& addr);
	Patreon& operator=(const Patreon& other);

	// void writeToFile(fstream& fout) const override;
	// void readFromFile(fstream& fin) const override;

	//setters
	void AddOrder(Order*& order) override;
	void SetLogin(const Login& _login) override;
	void SetName(const Name& _name) override;
	void SetEmail(const MyString& _email) override;
	void SetAddress(const Address& addr) override;
	void SetPerson(const Person& _person) override;

	void SetPatreonMember(const MyString& PatreonId);
	void RemovePatreonMember();

	//getters
	MyString GetPersonType() const override;
	MyString getUserName() const override;
	MyString getPassword() const override;
	Name GetName() const override;
	MyString GetEmail() const override;
	MyString GetPatreonId() const;
	bool IsActivePatreon() const;
	MyVector<Order*>& GetOrders() override;


	Date GetDate() override;
	Address GetAddress() override;

	//dipslay
	void DisplayCustomer() const override; // not defined yet
};

