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

	MyString GetPersonType() const override;
};

