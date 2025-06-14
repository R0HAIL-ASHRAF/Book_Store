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
	wxImage*& image, const MyString& type,
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
	return "stationary";
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

wxImage* Stationary::GetProductImage() const
{
	return productImage;
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
	if (productImage != nullptr)
		delete productImage;
	productImage = new wxImage(image);
}


void Stationary::ReadProductFromFile(std::ifstream& fin)
{
	productId.ReadFromStream(fin);
	productName.ReadFromStream(fin);
	
	stationaryType.ReadFromStream(fin);
	stationaryBrand.ReadFromStream(fin);
	stationaryColor.ReadFromStream(fin);
	description.ReadFromStream(fin);
	MyString temp;
	temp.ReadFromStream(fin);
	price = temp.StringToInt();

	// Handle image loading
	size_t imgSize = 0;
	fin.read(reinterpret_cast<char*>(&imgSize), sizeof(imgSize));

	if (imgSize > 0) {
		std::vector<unsigned char> buffer(imgSize);
		fin.read(reinterpret_cast<char*>(buffer.data()), imgSize);

		wxMemoryInputStream memStream(buffer.data(), imgSize);
		if (!productImage->LoadFile(memStream, wxBITMAP_TYPE_PNG)) {
			wxLogError("Failed to load stationary image");
		}
	}


}

void Stationary::WriteProductIntoFile(std::ofstream& fout)
{

	productId.WriteToStream(fout);
	productName.WriteToStream(fout);
	stationaryType.WriteToStream(fout);
	stationaryBrand.WriteToStream(fout);
	stationaryColor.WriteToStream(fout);
	description.WriteToStream(fout);

	MyString(price).WriteToStream(fout);

	// Handle image saving
	size_t imgSize = 0;

	if (productImage && productImage->IsOk()) {
		wxMemoryOutputStream memStream;
		if (productImage->SaveFile(memStream, wxBITMAP_TYPE_PNG)) {
			imgSize = memStream.GetSize();
			fout.write(reinterpret_cast<const char*>(&imgSize), sizeof(imgSize));

			std::vector<char> imgBuffer(imgSize);
			memStream.CopyTo(imgBuffer.data(), imgSize);
			fout.write(imgBuffer.data(), imgSize);
		}
		else {
			wxLogError("Failed to save stationary image");
		}
	}
	else {
		fout.write(reinterpret_cast<const char*>(&imgSize), sizeof(imgSize));
	}

}
