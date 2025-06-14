#include "Store.h"

Store::Store(const Store& other)
    :storeId{ other.storeId },
    storeName{ other.storeName },
    storeAddress{ other.storeAddress },
    fileName(other.fileName),
    fileName2(other.fileName2)
{
	for (int i = 0; i < other.products.size(); i++) {
		products.at(i) = other.products.at(i);
	}
}

Store::Store(const MyString& _storeId, const MyString& _storeName, const Address& _address)
	:storeId{_storeId}, storeName{_storeName},
	storeAddress{_address}, 
	products{ MyVector<Product*>() }, 
    fileName(""), fileName2("")
{
   
    // LoadAllProductsFromFile();
}

Store& Store::operator=(const Store& other)
{
	if (this == &other)
		return *this;

	storeId = other.storeId;
	storeName = other.storeName;
	storeAddress = other.storeAddress;
    fileName = other.fileName;
    fileName2 = other.fileName2;

	for (int i = 0; i < other.products.size(); i++) {
		products.push( other.products.at(i));
	}
    return *this;
}

void Store::LoadAllProductsFromFile()
{
    if (fileName == "" ||
        fileName == "TextFiles/Stores/Stat_.bin")
        return;
    OpenFiles();

    LoadAllBooks();
    LoadAllStationary();
}
void Store::LoadAllBooks() {

    std::ifstream fin(fileName.ToCharArray(), std::ios::binary);
    if (!fin.is_open()) {
        Logger::getInstance().writeError("Failed to open file: ");
        Logger::getInstance().writeError(fileName);
        return;
    }
   

    const size_t MAX_IMAGE_SIZE = 10 * 1024 * 1024; // 10 MB max limit

    int count = 0;
    while (true) {
        if (fin.peek() == EOF) {
            Logger::getInstance().writeError("Reached EOF after reading books");
            break;
        }

        MyString productId;
        productId.ReadFromStream(fin);
        if (!fin) {
            Logger::getInstance().writeError("Stream failed after reading productId");
            break;
        }
        Logger::getInstance().writeError("Read productId");
        Logger::getInstance().writeError(productId);

        MyString productName, author, genre, publisher;
        MyString year, pages, description, price, language;

        productName.ReadFromStream(fin);
        author.ReadFromStream(fin);
        genre.ReadFromStream(fin);
        publisher.ReadFromStream(fin);
        year.ReadFromStream(fin);
        pages.ReadFromStream(fin);
        description.ReadFromStream(fin);
        price.ReadFromStream(fin);
        language.ReadFromStream(fin);

        wxImage* productImage = new wxImage();

        size_t imgSize = 0;
        fin.read(reinterpret_cast<char*>(&imgSize), sizeof(imgSize));
        if (!fin) {
            Logger::getInstance().writeError("Failed to read image size");
            delete productImage;
            productImage = new wxImage(wxNullImage);
        }
        else if (imgSize > MAX_IMAGE_SIZE) {
           
            delete productImage;
            productImage = new wxImage(wxNullImage);
        }
        else if (imgSize > 0) {
            std::vector<unsigned char> buffer(imgSize);
            fin.read(reinterpret_cast<char*>(buffer.data()), imgSize);

            if (!fin) {
                delete productImage;
                productImage = new wxImage(wxNullImage);
            }
            else {
                wxMemoryInputStream memStream(buffer.data(), imgSize);
                if (!productImage->LoadFile(memStream, wxBITMAP_TYPE_PNG)) {
                    Logger::getInstance().writeError("Failed to load image from memory stream");
                    *productImage = wxNullImage;
                }
                
            }
        }
        else {
            delete productImage;
            productImage = new wxImage(wxNullImage);
        }

        Book* newBook = new Book(
            productId, productName, description,
            price.StringToInt(), productImage,
            author, publisher, genre, language,
            year, pages.StringToInt()
        );

        products.push(newBook);
       
    }

    fin.close();
   
}

void Store::LoadAllStationary() {
   
    std::ifstream fin(fileName2.ToCharArray(), std::ios::binary | std::ios::in);
    if (!fin.is_open()) {
        Logger::getInstance().writeError("Failed to open file");
        return;
    }

    int count = 0;
    while (true) {
        MyString productId;
        productId.ReadFromStream(fin);

        if (fin.eof()) {
            Logger::getInstance().writeError("Reached EOF after reading ");
            break;
        }
        if (fin.fail()) {
            Logger::getInstance().writeError("Failed to read product ID at stationary item #");
            Logger::getInstance().writeError (MyString(count + 1));
            break;
        }
        MyString productName, type, brand, color, description, price;
        productName.ReadFromStream(fin);
        type.ReadFromStream(fin);
        brand.ReadFromStream(fin);
        color.ReadFromStream(fin);
        description.ReadFromStream(fin);
        price.ReadFromStream(fin);

        wxImage* productImage = new wxImage();
        size_t imgSize = 0;
        fin.read(reinterpret_cast<char*>(&imgSize), sizeof(imgSize));
        if (!fin) {
            Logger::getInstance().writeError("Failed to read image size for stationary product");
            delete productImage;
            productImage = new wxImage(wxNullImage);
        }
        else if (imgSize > 0) {
           
            std::vector<unsigned char> buffer(imgSize);
            fin.read(reinterpret_cast<char*>(buffer.data()), imgSize);

            if (!fin) {
                Logger::getInstance().writeError("Failed to read stationary image data");
                delete productImage;
                productImage = new wxImage(wxNullImage);
            }
            else {
                wxMemoryInputStream memStream(buffer.data(), imgSize);
                if (!productImage->LoadFile(memStream, wxBITMAP_TYPE_PNG)) {
                    Logger::getInstance().writeError("Failed to load stationary image from memory stream");
                    *productImage = wxNullImage;
                }
            }
        }
        else {
            delete productImage;
            productImage = new wxImage(wxNullImage);
        }

        Stationary* newStat = new Stationary(
            productId, productName, description,
            price.StringToInt(), productImage,
            type, brand, color
        );

        products.push(newStat);
        count++;
       
    }

    fin.close();
}


MyVector<Product*> Store::GetProducts()
{
    products.clear();
    LoadAllProductsFromFile();
	return products;
}
void Store::WriteIntoFile()
{
    if (fileName == "")
        OpenFiles();

    std::ofstream fout(fileName.ToCharArray(), std::ios::binary);
    if (!fout.is_open()) {
        wxLogError("Failed to open book file for writing.");
        return;
    }

    std::ofstream fout2(fileName2.ToCharArray(), std::ios::binary);
    if (!fout2.is_open()) {
        wxLogError("Failed to open stationary file for writing.");
        return;
    }

    for (int i = 0; i < products.size(); i++) {
        if (products.at(i)->getProductCategory() == "book") {
            Book* book = dynamic_cast<Book*>(products.at(i));
            if (book) {
                WriteAllBooks(fout, book); 
            }
        }
        else if (products.at(i)->getProductCategory() == "stationary") {
            Stationary* stat = dynamic_cast<Stationary*>(products.at(i));
            if (stat) {
                WriteAllStationary(fout2, stat);
            }
        }
    }

    fout.close();
    fout2.close();
}

void Store::WriteAllBooks(std::ofstream& fout, Book* product) {
    if (!product) {
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

    const wxImage* productImage = product->GetProductImage();
    wxMemoryOutputStream memStream;

    if (productImage && productImage->IsOk()) {
        if (productImage->SaveFile(memStream, wxBITMAP_TYPE_PNG)) {
            size_t imgSize = memStream.GetSize();
            fout.write(reinterpret_cast<const char*>(&imgSize), sizeof(imgSize));

            std::vector<char> imgBuffer(imgSize);
            memStream.CopyTo(imgBuffer.data(), imgSize);
            fout.write(imgBuffer.data(), imgSize);

            if (!fout.good()) {
                wxLogWarning("Failed to write image data for product ID: %s", product->getProductID().ToCharArray());
            }
        }
        else {
            size_t zeroSize = 0;
            fout.write(reinterpret_cast<const char*>(&zeroSize), sizeof(zeroSize));
            wxLogWarning("Failed to save product image to stream for product ID: %s", product->getProductID().ToCharArray());
        }
    }
    else {
        size_t zeroSize = 0;
        fout.write(reinterpret_cast<const char*>(&zeroSize), sizeof(zeroSize));
    }
}

void Store::WriteAllStationary(std::ofstream& fout, Stationary* product) {
    if (!fout.is_open() || !product) {
        wxLogError("Invalid file or product in WriteAllStationary");
        return;
    }

    product->getProductID().WriteToStream(fout);
    product->getProductName().WriteToStream(fout);
    product->getStationaryType().WriteToStream(fout);
    product->getStationaryBrand().WriteToStream(fout);
    product->getStationaryColor().WriteToStream(fout);
    product->getDescription().WriteToStream(fout);

    MyString price = product->getPrice();
    price.WriteToStream(fout);

    const wxImage* productImage = product->GetProductImage();
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

    if (fout.fail()) {
        wxLogError("Failed to write stationary data");
    }
}

void Store::WriteStoreInfoIntoFile(std::ofstream& fout)
{
    storeId.WriteToStream(fout);
    storeName.WriteToStream(fout);
    storeAddress.houseNumber.WriteToStream(fout);
    storeAddress.city.WriteToStream(fout);
    storeAddress.province.WriteToStream(fout);
    storeAddress.country.WriteToStream(fout);
}

void Store::ReadStoreInfoFromFile(std::ifstream& fin)
{
    storeId.ReadFromStream(fin);
    
    storeName.ReadFromStream(fin);
    storeAddress.houseNumber.ReadFromStream(fin);
    storeAddress.city.ReadFromStream(fin);
    storeAddress.province.ReadFromStream(fin);
    storeAddress.country.ReadFromStream(fin);
    
    OpenFiles();
}
void Store::OpenFiles()
{
    fileName = "TextFiles/Stores/Books_";
    fileName.AppendArray(storeId);
    fileName.AppendArray(".bin");

    std::ofstream file(fileName.ToCharArray(),
        std::ios::binary | std::ios::app);
    file.close();

    fileName2 = "TextFiles/Stores/Stat_";
    fileName2.AppendArray(storeId);
    fileName2.AppendArray(".bin");

    std::ofstream file2(fileName2.ToCharArray(),
        std::ios::binary | std::ios::app);
    file.close();
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

MyString Store::GetBookFileName() const
{
    return fileName;
}

MyString Store::GetStatFileName() const
{
    return fileName2;
}

Store::~Store()
{
    

    for (int i = 0; i < products.size(); i++) {
        delete products.at(i);
    }
    products.clear();

}

int Store::GetStoreSize()
{
    return products.size();
}