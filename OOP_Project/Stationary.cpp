#include "Stationary.h"

Stationary::Stationary()
	:Product(), stationaryType(MyString()), 
	stationaryBrand(MyString()),stationaryColor(MyString())
{
}

Stationary::Stationary(const Stationary& other)
	:Product(other),
	stationaryType(other.stationaryType), 
	stationaryBrand(other.stationaryBrand),
	stationaryColor(other.stationaryColor)
{
}

Stationary& Stationary::operator=(const Stationary& other)
{
	if(this == &other)
		return *this;
	static_cast<Product&>(*this) = other; 
	stationaryType = other.stationaryType;
	stationaryBrand = other.stationaryBrand;
	stationaryColor = other.stationaryColor;
	return *this;
}

Stationary::Stationary(const MyString& id, const MyString& name,
	const MyString& desc, int price,
	wxImage image, const MyString& type,
	const MyString brand, const MyString& color)

	:Product(id, name, "Book", desc, price, image), 
	stationaryType(type), 
	stationaryBrand(brand),
	stationaryColor(color)
{
}


void Stationary::SetPrice(int price)
{
	if (price > -1)
		price = price;
	price = 0;
}

void Stationary::SetProductDescription(const MyString& desc)
{
	description = desc;
}

void Stationary::SetStationaryType(const MyString& type)
{
	stationaryType = type;
}

void Stationary::SetStationaryBrand(const MyString& brand)
{
	stationaryBrand = brand;
}

void Stationary::SetStationaryColor(const MyString& color)
{
	stationaryColor = color;
}

MyString Stationary::getProductID() const
{
	return productId;
}

MyString Stationary::getProductName() const
{
	return productName;
}

MyString Stationary::getProductCategory() const
{
	return productCategory;
}

MyString Stationary::getDescription() const
{
	return description;
}

int Stationary::getPrice() const
{
	return price;
}

MyString Stationary::getStationaryType() const
{
	return stationaryType;
}

MyString Stationary::getStationaryBrand() const
{
	return stationaryBrand;
}

MyString Stationary::getStationaryColor() const
{
	return stationaryColor;
}

void Stationary::Display() const
{

}

wxImage Stationary::GetProductImage() const
{
	return productImage;
}
void Stationary::SetProductCategory(const MyString& category)
{
	productCategory = category;
}

void Stationary::SetProductName(const MyString& name)
{
	productName = name;
}

void Stationary::SetProductID(const MyString& id)
{
	productId = id;
}

void Stationary::SetProductImage(const wxImage& image)
{
	productImage = image;
}
