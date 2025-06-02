#include "Book.h"

Book::Book()
	:Product(), authorName{ MyString() }, publisherName{ MyString() },
	bookType(MyString()), pages(0), bookLanguage(MyString()),
	bookEdition(MyString())
{
}

Book::Book(const Book& other)
	: Product(other),
	authorName(other.authorName), publisherName(other.publisherName),
	bookType(other.bookType), pages(other.pages),
	bookLanguage(other.bookLanguage), bookEdition(other.bookEdition)
{
}

Book::Book(const MyString& id, const MyString& name,
	const MyString& desc, int price, wxImage image,
	const MyString& author, const MyString& publisher,
	const MyString& type, const MyString& language,
	const MyString& edition, int pages)

	:Product(id, name, "Book", desc, price, image), 
	authorName(author), publisherName(publisher),
	bookType(type), pages(pages), bookLanguage(language),
	bookEdition(edition)
{
}

Book& Book::operator=(const Book& other)
{
	if(this == &other)
		return *this;
	static_cast<Product&>(*this) = other;
	authorName = other.authorName;
	publisherName = other.publisherName;
	bookType = other.bookType;
	pages = other.pages;
	bookEdition = other.bookEdition;
	bookLanguage = other.bookLanguage;
	return *this;
}

void Book::SetPrice(int price)
{
	if (price > -1)
		price = price;
	price = 0;
}

void Book::SetProductDescription(const MyString& desc)
{
	description = desc;
}

MyString Book::getProductID() const
{
	return productId;
}

MyString Book::getProductName() const
{
	return productName;
}

MyString Book::getProductCategory() const
{
	return productCategory;
}

MyString Book::getDescription() const
{
	return description;
}

int Book::getPrice() const
{
	return price;
}

MyString Book::GetAuthorName() const
{
	return authorName;
}

MyString Book::GetPublisherName() const
{
	return publisherName;
}

MyString Book::GetBookType() const
{
	return bookType;
}
void Book::Display() const 
{

}


void Book::SetProductCategory(const MyString& category)
{
	productCategory = category;
}

void Book::SetProductName(const MyString& name)
{
	productName = name;
}

void Book::SetProductID(const MyString& id)
{
	productId = id;
}

void Book::SetProductImage(const wxImage& image)
{
	productImage = image;
}

void Book::SetAuthorName(const MyString& author)
{
	authorName = author;
}

void Book::SetPublisherName(const MyString& publisher)
{
	publisherName = publisher;
}

void Book::SetBookType(const MyString& type)
{
	bookType = type;
}

void Book::SetBookLanguage(const MyString& language)
{
	bookLanguage = language;
}

void Book::SetBookEdition(const MyString& edition)
{
	bookEdition = edition;
}

void Book::SetPages(int pages)
{
	this->pages = pages;
}
