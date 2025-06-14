#include "Payment.h"

Payment::Payment()
	:cardNumber(MyString()), cardHolderName(MyString()), 
	expiryDate(Date()), cvv(MyString()) 
{
}

Payment::Payment(const Payment& other)
	:cardNumber(other.cardNumber), 
	cardHolderName(other.cardHolderName),
	expiryDate(other.expiryDate), 
	cvv(other.cvv)
{
}

Payment::Payment(const MyString& cardNumber, const MyString& holderName, const Date& date, const MyString& cvv)
	:cardNumber(cardNumber), 
	cardHolderName(holderName), 
	expiryDate(date), 
	cvv(cvv) 
{
}

Payment& Payment::operator=(const Payment& other)
{
	if (this == &other)
		return *this;

	cardNumber = other.cardNumber;
	cardHolderName = other.cardHolderName;
	expiryDate = other.expiryDate;
	cvv = other.cvv;
	return *this;
}

void Payment::setCard(const Payment& card)
{
	cardNumber = card.cardNumber;
	cardHolderName = card.cardHolderName;
	expiryDate = card.expiryDate;
	cvv = card.cvv;
}

bool Payment::ValidateCvv(const MyString& cvv) const
{
	if(cvv == this->cvv)
		return true;
	return false;
}

bool Payment::ValidateCardNumber(const MyString& cardNumber) const
{
	if(cardNumber == this->cardNumber)
		return true;
	return false;
}

bool Payment::ValidateCardHolderName(const MyString& cardHolderName) const
{
	if(cardHolderName == this->cardHolderName)
		return true;
	return false;
}

bool Payment::ValidateExpirationDate(const Date& date) const
{
	if(date == this->expiryDate)
		return true;
	return false;
}

bool Payment::ValidateCard(const Payment& card)
{
	if(ValidateCardNumber(card.cardNumber) && 
	   ValidateCardHolderName(card.cardHolderName) && 
	   ValidateExpirationDate(card.expiryDate) && 
	   ValidateCvv(card.cvv))
		return true;
	return false;
}

void Payment::WriteIntoFile(std::ofstream& fout)
{
	cardNumber.WriteToStream(fout);
	cardHolderName.WriteToStream(fout);
	MyString(expiryDate.day).WriteToStream(fout);
	MyString(expiryDate.month).WriteToStream(fout);
	MyString(expiryDate.year).WriteToStream(fout);
	cvv.WriteToStream(fout);


}


void Payment::ReadFromFile(std::ifstream& fin)
{
	cardNumber.ReadFromStream(fin);
	cardHolderName.ReadFromStream(fin);
	MyString(expiryDate.day).ReadFromStream(fin);
	MyString(expiryDate.month).ReadFromStream(fin);
	MyString(expiryDate.year).ReadFromStream(fin);
	cvv.ReadFromStream(fin);


}