#pragma once

#include "Product.h"
#include"MyString.h"
#include "Person.h"
#include <wx/mstream.h>


class Book :public Product
{
private:
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
		const MyString& desc, int price,
		wxImage*& image,
		const MyString& author,
		const MyString& publisher, 
		const MyString& type,
		const MyString& language, 
		const MyString& edition, int pages);
	Book& operator=(const Book& other);


	//setter
	void SetPrice(int price) override;
	void SetProductDescription(const MyString& desc) override;
	void SetProductName(const MyString& name)override;
	void SetProductID(const MyString& id) override;
	void SetProductImage(const wxImage& image)override;

	void SetAuthorName(const MyString& author);
	void SetPublisherName(const MyString& publisher);
	void SetBookType(const MyString& type);
	void SetBookLanguage(const MyString& language);
	void SetBookEdition(const MyString& edition);
	void SetPages(int pages);
	//getter
	MyString getProductID() const  override;
	MyString getProductName() const override;
	MyString getProductCategory() const override;
	MyString getDescription() const override;
	int getPrice() const override;
	wxImage* GetProductImage() const override;
	MyString GetBookEdition() const;
	MyString GetBookLanguage() const;
	MyString GetAuthorName() const;
	MyString GetPublisherName() const;
	MyString GetBookType() const;
	int GetPages() const;

	//display book not defined tyet 
	void Display() const override;
	
	void WriteProductIntoFile(std::ofstream& fout) override;
	void ReadProductFromFile(std::ifstream& fin) override;
	
};


