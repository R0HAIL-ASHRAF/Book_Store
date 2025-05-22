#pragma once

#include "MyString.h"
#include"date.h"
class Payment
{
private:
	MyString cardNumber;
	MyString cardHolderName;
	Date expirationDate;
	MyString cvv;

public:
	Payment();
	Payment(const Payment& other);
	Payment(const MyString& cardNumber,
		const MyString& holderName,
		const Date& date, const MyString& cvv);
	Payment& operator=(const Payment& other);

	//setters
	void setCardNumber(const MyString& cardNumber);
	void setCardHolderName(const MyString& holderName);
	void setExpirationDate(const Date& date);
	void setCvv(const MyString& cvv);

	//validators
	bool ValidateCvv(const MyString& cvv) const;
	bool ValidateCardNumber(const MyString& cardNumber) const;
	bool ValidateCardHolderName(const MyString& cardHolderName) const;
	bool ValidateExpirationDate(const Date& date) const;

};

