#pragma once

#include "MyString.h"
#include"date.h"

class Payment
{
private:
	MyString cardNumber;
	MyString cardHolderName;
	Date expiryDate;
	MyString cvv;

public:
	Payment();
	Payment(const Payment& other);
	Payment(const MyString& cardNumber,
		const MyString& holderName,
		const Date& date, const MyString& cvv);
	Payment& operator=(const Payment& other);

	void WriteIntoFile(std::ofstream& fout);
	void ReadFromFile(std::ifstream& fin);

	//setters
	void setCard(const Payment& card);

	//validators
	bool ValidateCvv(const MyString& cvv) const;
	bool ValidateCardNumber(const MyString& cardNumber) const;
	bool ValidateCardHolderName(const MyString& cardHolderName) const;
	bool ValidateExpirationDate(const Date& date) const;
	bool ValidateCard(const Payment& card);
};

