#include "Store.h"
#include "StoreManager.h"

Store::Store()
	:storeId{MyString()}, storeName{MyString()},
	storeAddress{Address()},
	products{MyVector<Product*>()}	
{
    LoadAllProductsFromFile();
}

Store::Store(const Store& other)
	:storeId{ other.storeId }, 
	storeName{ other.storeName },
	storeAddress{ other.storeAddress }
{
	for (int i = 0; i < other.products.size(); i++) {
		products.at(i) = other.products.at(i);
	}

	
}

Store::Store(const MyString& _storeId, const MyString& _storeName, const Address& _address)
	:storeId{_storeId}, storeName{_storeName},
	storeAddress{_address}, 
	products{ MyVector<Product*>() }
{
}

Store& Store::operator=(const Store& other)
{
	if (this == &other)
		return *this;

	storeId = other.storeId;
	storeName = other.storeName;
	storeAddress = other.storeAddress;

	for (int i = 0; i < other.products.size(); i++) {
		products.push( other.products.at(i));
	}
	
}

void Store::LoadAllProductsFromFile()
{
    LoadAllBooks();
    LoadAllStationary();
}

void Store::LoadAllBooks()
{
    MyString productId;
    MyString productName;
    MyString author;
    MyString genre;
    MyString publisher;
    MyString year;
    MyString pages;
    MyString description;
    MyString price;
    MyString language;
    wxImage productImage;
    
    MyString fileName = "Books_";
    fileName.AppendArray(storeId);
    fileName.AppendArray(".bin");

    std::ifstream fin(fileName.ToCharArray(), std::ios::binary);
    if (!fin.is_open()) {
        wxLogError("Failed to open %s", fileName.ToCharArray());
        return;
    }

    while (!fin.eof()) {
        productId.ReadFromStream(fin);
        productName.ReadFromStream(fin);
        author.ReadFromStream(fin);
        genre.ReadFromStream(fin);
        publisher.ReadFromStream(fin);
        year.ReadFromStream(fin);
        pages.ReadFromStream(fin);
        description.ReadFromStream(fin);
        price.ReadFromStream(fin);
        language.ReadFromStream(fin);

        Book book(productId, productName, description,
            price.StringToInt(), productImage, author,
            publisher, genre, language, year,
            pages.StringToInt());

        size_t imgSize = 0;
        fin.read(reinterpret_cast<char*>(&imgSize), sizeof(imgSize));
        if (!fin.good() || fin.eof()) {
            wxLogError("Returned Early");
            return;
        }

        if (imgSize > 0) {
            std::vector<unsigned char> buffer(imgSize);
            fin.read(reinterpret_cast<char*>(buffer.data()), imgSize);
            if (!fin.good()) {
                wxLogError("Failed to read image data from Products.bin(AddBook.cpp)");
                return;
            }
            wxMemoryInputStream memStream(buffer.data(), imgSize);
            if (productImage.LoadFile(memStream, wxBITMAP_TYPE_PNG)) {
                book.SetProductImage(productImage);
            }
        }
        else {
            book.SetProductImage(wxNullImage);
        }
        products.push(new Book(book));
    }

}

void Store::LoadAllStationary()
{
    // still need to define 
    // like the books
}


MyVector<Product*> Store::GetProducts() const
{
	return products;
}

void Store::WriteIntoFile()
{
    for (int i = 0; i < products.size(); i++) {
        if (products.at(i)->getProductCategory() == "book")
        {
            Book* book = dynamic_cast<Book*>(products.at(i));
            if (book != nullptr) {
                WriteAllBooks(book);
            }
        }
        else if (products.at(i)->getProductCategory() == "stationary")
        {
            Stationary* stat = dynamic_cast<Stationary*>(products.at(i));
            if (stat != nullptr) {
                WriteAllStationary(stat);
            }
        }
    }

    // WriteAllStationary();
}

void Store::WriteAllBooks(Book* product)
{
    MyString fileName = "Books_";
    fileName.AppendArray(storeId);
    fileName.AppendArray(".bin");
    
    std::ofstream fout(fileName.ToCharArray(),
                        std::ios::binary | std::ios::app);

    if (!fout.is_open()) {
        wxLogError("Failed to open %s", fileName.ToCharArray());
        return;
    }

    product->getProductID().WriteToStream(fout);
    product->getProductName().WriteToStream(fout);
    product->GetAuthorName().WriteToStream(fout);
    product->GetBookType().WriteToStream(fout);
    product->GetPublisherName().WriteToStream(fout);
    product->GetBookEdition().WriteToStream(fout);
    MyString pages = product->GetPages();
    pages.WriteToStream(fout);

    product->getDescription().WriteToStream(fout);
    MyString price = product->getPrice();

    price.WriteToStream(fout);
    product->GetBookLanguage().WriteToStream(fout);
    wxImage* productImage = new wxImage(product->GetProductImage());

    wxMemoryOutputStream memStream;
    if (productImage->IsOk()) {
        if (productImage->SaveFile(memStream, wxBITMAP_TYPE_PNG)) {
            size_t imgSize = memStream.GetSize();
            std::vector<char> imgBuffer(imgSize);
            memStream.CopyTo(imgBuffer.data(), imgSize);
            fout.write(reinterpret_cast<const char*>(&imgSize), sizeof(imgSize));
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
    fout.close();
}

void Store::WriteAllStationary(Product* product) 
{
    // to write same as book
}



Store Store::GetStoreInfo() const
{
	return *this;
}

MyString Store::GetStoreId() const
{
	return storeId;
}

MyString Store::GetStoreName() const
{
	return storeName;
}

MyString Store::GetStoreAddress() const
{
	return storeAddress.ToString();
}

int Store::GetProductSize() const
{
	return products.size();
}

Store::~Store()
{
    WriteIntoFile();
}