#pragma once

#include "MyString.h"
#include <wx/image.h>

class Product
{
private:
	wxImage productImage;
	MyString productId;
	MyString productName;
	MyString productCategory;
	MyString description;
	int price;
public:
	Product();
	Product(const Product& other);
	Product(const MyString& id, const MyString& name,
		const MyString& category, const MyString& desc,
		int price, const wxImage& image);
	Product& operator=(const Product& other);

	// virtual void writeToFile(fstream& fout) const;
	// virtual void readFromFile(fstream& fin) const;

	//setter
	virtual void SetPrice(int price);
	virtual void SetProductDescription(const MyString& desc);
	//getter
	virtual MyString getProductID() const;
	virtual MyString getProductName() const;
	virtual MyString getProductCategory() const;
	virtual MyString getDescription() const;
	virtual int getPrice() const;
	

	//display not defoined yet
	virtual void DisplayBook() const;

};

