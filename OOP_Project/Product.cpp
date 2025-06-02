#include "Product.h"
#include "Book.h"

Product::Product()
	:productImage(wxImage()),
	productId(MyString()),
	productName(MyString()),
	productCategory(MyString()),
	description(MyString()),
	price(0)
{
}

Product::Product(const Product& other)
	:productImage(other.productImage),
	productId(other.productId),
	productName(other.productName),
	productCategory(other.productCategory),
	description(other.description),
	price(other.price)
{
}

Product::Product(const MyString& id, const MyString& name,
	const MyString& category,
	const MyString& desc, int price,
	const wxImage& image)
	:productId{id}, productName(name),
	productCategory(category),
	description(desc), price(price),
	productImage(image)
{
}

Product& Product::operator=(const Product& other)
{
	if (this == &other)
		return *this;

	productImage = other.productImage;
	productId = other.productId;
	productName = other.productName;
	productCategory = other.productCategory;
	description = other.description;
	price = other.price;
	return *this;
}

void Product::SetPrice(int price)
{
	if (price > -1)
		this->price = price;
	this->price = 0;
}

void Product::SetProductDescription(const MyString& desc)
{
	description = desc;
}

void Product::SetProductCategory(const MyString& category)
{
}

void Product::SetProductName(const MyString& name)
{
}

void Product::SetProductID(const MyString& id)
{
}

void Product::SetProductImage(const wxImage& image)
{
}

MyString Product::getProductID() const
{
	return productId;
}

MyString Product::getProductName() const
{
	return productName;
}

MyString Product::getProductCategory() const
{
	return productCategory;
}

MyString Product::getDescription() const
{
	return description;
}

int Product::getPrice() const
{
	return price;
}

void Product::Display() const
{
}
