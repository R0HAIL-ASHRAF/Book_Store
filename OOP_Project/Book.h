#pragma once

#include "Product.h"
#include"MyString.h"
#include "Person.h"

class Book :public Product
{
private:
	MyString bookId;
	MyString bookName;
	MyString authorName;
	MyString publisherName;
	MyString bookType;
	MyString bookLanguage;
	MyString bookEdition;
	int pages;

public:
	Book();
	Book(const Book& other);
	Book(const MyString& id, const MyString& name,
		const MyString& author,
		const MyString& publisher, 
		const MyString& type,
		const MyString& language, 
		const MyString& edition, int pages);
	Book& operator=(const Book& other);

	void writeToFile(fstream& fout) const override;
	void readFromFile(fstream& fin) const override;

	//setter
	void SetPrice(int price) override;
	void SetProductDescription(const MyString& desc) override;
	//getter
	MyString getProductID() const  override;
	MyString getProductName() const override;
	MyString getProductCategory() const override;
	MyString getDescription() const override;
	int getPrice() const override;
	MyString GetBookId() const;
	MyString GetbookName() const;
	MyString GetAuthorName() const;
	MyString GetPublisherName() const;
	MyString GetBookType() const;
	

	//display book
	void DisplayBook() const override;
	
	
};


