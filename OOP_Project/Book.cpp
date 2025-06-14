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
	const MyString& desc, int price, wxImage*& image,
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
	return "book";
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
int Book::GetPages() const
{
	return pages;
}
void Book::Display() const 
{

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
	if (productImage != nullptr)
	{
		delete productImage;
		productImage = nullptr;
	}
	productImage = new wxImage(image);
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


wxImage* Book::GetProductImage() const
{
	return productImage;
}

MyString Book::GetBookEdition() const
{
	return bookEdition;
}

MyString Book::GetBookLanguage() const
{
	return bookLanguage;
}


void Book::ReadProductFromFile(std::ifstream& fin)
{
	productId.ReadFromStream(fin);


	productName.ReadFromStream(fin);
	authorName.ReadFromStream(fin);
	bookType.ReadFromStream(fin);
	publisherName.ReadFromStream(fin);
	bookEdition.ReadFromStream(fin);
	MyString temp;
	temp.ReadFromStream(fin);
	pages = temp.StringToInt();

	description.ReadFromStream(fin);
	temp.ReadFromStream(fin);
	price = temp.StringToInt();
	bookLanguage.ReadFromStream(fin);

	wxImage* productImage = new wxImage();

	size_t imgSize = 0;
	fin.read(reinterpret_cast<char*>(&imgSize), sizeof(imgSize));

	if (imgSize > 0) {
		std::vector<unsigned char> buffer(imgSize);
		fin.read(reinterpret_cast<char*>(buffer.data()), imgSize);

		wxMemoryInputStream memStream(buffer.data(), imgSize);
		if (productImage->LoadFile(memStream, wxBITMAP_TYPE_PNG)) {
		}
		else {
			delete productImage;
			productImage = new wxImage(wxNullImage);
		}
	}
	else {
		delete productImage;
		productImage = new wxImage(wxNullImage);
	}

}

void Book::WriteProductIntoFile(std::ofstream& fout)
{


	productId.WriteToStream(fout);
	productName.WriteToStream(fout);
	authorName.WriteToStream(fout);
	bookType.WriteToStream(fout);
	publisherName.WriteToStream(fout);
	bookEdition.WriteToStream(fout);

	MyString(pages).WriteToStream(fout);

	description.WriteToStream(fout);
	MyString(price).WriteToStream(fout);

	bookLanguage.WriteToStream(fout);

	

	wxMemoryOutputStream memStream;
	if (productImage && productImage->IsOk()) {
		if (productImage->SaveFile(memStream, wxBITMAP_TYPE_PNG)) {
			size_t imgSize = memStream.GetSize();
			fout.write(reinterpret_cast<const char*>(&imgSize), sizeof(imgSize));

			std::vector<char> imgBuffer(imgSize);
			memStream.CopyTo(imgBuffer.data(), imgSize);
			fout.write(imgBuffer.data(), imgSize);
		}
		else {
			size_t imgSize = 0;
			fout.write(reinterpret_cast<const char*>(&imgSize), sizeof(imgSize));
		}
	}
	else {
		size_t imgSize = 0;
		fout.write(reinterpret_cast<const char*>(&imgSize), sizeof(imgSize));
	}
}
