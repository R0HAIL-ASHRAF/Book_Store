#include "Product.h"
#include "Book.h"

Product::Product()
	:productImage(new wxImage()),
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
	wxImage*& image)
	:productId{id}, productName(name),
	productCategory(category),
	description(desc), price(price),
	productImage(new wxImage(*image))
{
}

Product& Product::operator=(const Product& other)
{
	if (this == &other)
		return *this;

	productImage = new wxImage(*other.productImage);
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

wxImage* Product::GetProductImage() const
{
	return productImage;
}

void Product::WriteProductIntoFileCart(std::ofstream& fout)
{
	productId.WriteToStream(fout);
	productName.WriteToStream(fout);
	MyString(price).WriteToStream(fout);
}

Product* Product::ReadProductFromFileCart(std::ifstream& fin)
{
	productId.ReadFromStream(fin);
	productName.ReadFromStream(fin);
	MyString temp;
	temp.ReadFromStream(fin);
	price = temp.StringToInt();
	wxImage* img = new wxImage();
	return new Product(productId, productName, "", "", price,img );
}

void Product::Display() const
{
}
void Product::WriteProductIntoFile(std::ofstream& fout)
{

}

void Product::ReadProductFromFile(std::ifstream& fin)
{

}