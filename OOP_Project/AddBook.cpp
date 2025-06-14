#include "AddBook.h"


AddBook::AddBook(wxWindow* parent)
    : wxPanel(parent, wxID_ANY), 
    m_productImage(new wxImage())
{
    InitUI();
}

void AddBook::InitUI()
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->AddSpacer(10);

    // for title
    wxStaticText* title = new wxStaticText(this, wxID_ANY, "Add New Book");
    title->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    mainSizer->Add(title, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 15);

    wxBoxSizer* formSizer = new wxBoxSizer(wxVERTICAL);

   // id + price
    {
        wxBoxSizer* row = new wxBoxSizer(wxHORIZONTAL);
        row->Add(new wxStaticText(this, wxID_ANY, "Book ID:   "), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
        m_productIdCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1));
        row->Add(m_productIdCtrl, 0, wxRIGHT, 20);

        row->Add(new wxStaticText(this, wxID_ANY, "Price (Rs):"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
        m_priceCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1));
        row->Add(m_priceCtrl, 0);

        formSizer->Add(row, 0, wxEXPAND | wxBOTTOM, 10);
    }

    {
        wxBoxSizer* row = new wxBoxSizer(wxHORIZONTAL);
        row->Add(new wxStaticText(this, wxID_ANY, "Title:         "), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
        m_productNameCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(500, -1));
        row->Add(m_productNameCtrl, 0, wxRIGHT, 20);
        formSizer->Add(row, 0, wxEXPAND | wxBOTTOM, 10);
    }

    // author
    {
        wxBoxSizer* row = new wxBoxSizer(wxHORIZONTAL);
        row->Add(new wxStaticText(this, wxID_ANY, "Author:    "), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
        m_authorCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(500, -1));
        row->Add(m_authorCtrl, 0, wxRIGHT, 20);
        formSizer->Add(row, 0, wxEXPAND | wxBOTTOM, 10);
    }

    
    // genre + year
    {
        wxBoxSizer* row = new wxBoxSizer(wxHORIZONTAL);
        row->Add(new wxStaticText(this, wxID_ANY, "Genre:      "), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
        wxArrayString genres;
        genres.Add("Fiction");
        genres.Add("Non-Fiction");
        genres.Add("Science Fiction");
        genres.Add("Fantasy");
        genres.Add("Mystery");
        genres.Add("Romance");
        genres.Add("Biography");
        m_genreCtrl = new wxComboBox(this, wxID_ANY, "", wxDefaultPosition, wxSize(150, -1), genres, wxCB_DROPDOWN);
        row->Add(m_genreCtrl, 0, wxRIGHT, 20);

        row->Add(new wxStaticText(this, wxID_ANY, "Publication Year/Edition:"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
        m_yearCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(100, -1));
        row->Add(m_yearCtrl, 0);

        formSizer->Add(row, 0, wxEXPAND | wxBOTTOM, 10);
    }

    {
        wxBoxSizer* row = new wxBoxSizer(wxHORIZONTAL);
        row->Add(new wxStaticText(this, wxID_ANY, "Publisher: "), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
        m_publisherCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(500, -1));
        row->Add(m_publisherCtrl, 0, wxRIGHT, 20);
        formSizer->Add(row, 0, wxEXPAND | wxBOTTOM, 10);
    }
   
    {
        wxBoxSizer* row = new wxBoxSizer(wxHORIZONTAL);
        row->Add(new wxStaticText(this, wxID_ANY, "Language:"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
        m_languageCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(250, -1));
        row->Add(m_languageCtrl, 0, wxRIGHT, 20);

        row->Add(new wxStaticText(this, wxID_ANY, "Pages:"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
        m_pagesCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(100, -1));
        row->Add(m_pagesCtrl, 0);

        formSizer->Add(row, 0, wxEXPAND | wxBOTTOM, 10);
    }

    
    formSizer->Add(new wxStaticText(this, wxID_ANY, "Description:"), 0, wxLEFT | wxBOTTOM, 2);
    m_descriptionCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(300, 100), wxTE_MULTILINE);
    formSizer->Add(m_descriptionCtrl, 0, wxEXPAND | wxBOTTOM, 10);

    
    {
        wxBoxSizer* coverAndButtonsSizer = new wxBoxSizer(wxHORIZONTAL);

        // img picker + preview
        wxBoxSizer* imageSizer = new wxBoxSizer(wxHORIZONTAL);
        imageSizer->Add(new wxStaticText(this, wxID_ANY, "Book Cover:   "), 0, wxLEFT | wxBOTTOM, 2);

        m_imagePicker = new wxFilePickerCtrl(this, wxID_ANY, wxEmptyString, "Select book cover image",
            "Image files (*.jpg;*.png)|*.jpg;*.png", wxDefaultPosition, wxSize(180, -1),
            wxFLP_OPEN | wxFLP_FILE_MUST_EXIST);
        m_imagePicker->Bind(wxEVT_FILEPICKER_CHANGED, &AddBook::OnImageSelected, this);

        m_imagePreview = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize(100, 150));
        m_imagePreview->SetBackgroundColour(wxColour(255, 188, 217));

        imageSizer->Add(m_imagePicker, 0, wxRIGHT, 10);
        imageSizer->Add(m_imagePreview, 0, wxALIGN_CENTER_VERTICAL);

        wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
        wxButton* cancelBtn = new wxButton(this, ID_CANCEL, "Cancel", wxDefaultPosition, wxSize(80, 30));
        wxButton* saveBtn = new wxButton(this, ID_SaveProductButton, "Save", wxDefaultPosition, wxSize(80, 30));
        wxButton* clearBtn = new wxButton(this, wxID_ANY, "Clear", wxDefaultPosition, wxSize(80, 30));

        buttonSizer->Add(cancelBtn, 0, wxALL, 5);
        buttonSizer->Add(saveBtn, 0, wxALL, 5);
        buttonSizer->Add(clearBtn, 0, wxALL, 5);

        coverAndButtonsSizer->AddSpacer(10);
        coverAndButtonsSizer->Add(imageSizer, 1, wxEXPAND | wxRIGHT, 20);
        coverAndButtonsSizer->Add(buttonSizer, 0, wxALIGN_CENTER_VERTICAL);
        coverAndButtonsSizer->AddSpacer(40);

        formSizer->Add(coverAndButtonsSizer, 0, wxEXPAND | wxBOTTOM, 10);

        
    }
    mainSizer->Add(formSizer, 0, wxEXPAND | wxALL, 15);

    SetSizer(mainSizer);

}
void AddBook::OnImageSelected(wxFileDirPickerEvent& event)
{
    wxString path = event.GetPath();
    if (path.IsEmpty() || !wxFileExists(path)) {
        return;
    }

    if (m_productImage->LoadFile(path)) {

        //Check image size (PNG compressed)
        wxMemoryOutputStream memStream;
        if (!m_productImage->SaveFile(memStream, wxBITMAP_TYPE_PNG)) {
            wxMessageBox("Failed to process image!", "Error", wxOK | wxICON_ERROR);
            return;
        }

        size_t imageSize = memStream.GetSize();
        if (imageSize > 10 * 1024) { // 10 KB
            wxMessageBox("Selected image must be smaller than 5 KB.", "Image Too Large", wxOK | wxICON_WARNING);
            m_productImage->Destroy(); // Reset image
            m_imagePreview->SetBitmap(wxNullBitmap);
            m_imagePath.clear();
            Refresh();
            return;
        }

        //Image is valid — scale for preview
        wxImage* scaledImage = new wxImage(*m_productImage);
        wxSize previewSize = m_imagePreview->GetSize();
        double aspectRatio = static_cast<double>(m_productImage->GetWidth()) / m_productImage->GetHeight();

        if (aspectRatio > 0.75) {
            scaledImage->Rescale(previewSize.GetWidth(),
                previewSize.GetWidth() / aspectRatio,
                wxIMAGE_QUALITY_HIGH);
        }
        else {
            scaledImage->Rescale(previewSize.GetHeight() * aspectRatio,
                previewSize.GetHeight(),
                wxIMAGE_QUALITY_HIGH);
        }

        m_imagePreview->SetBitmap(wxBitmap(*scaledImage));
        m_imagePath = MyString(path);
        Refresh();
    }
    else {
        wxMessageBox("Failed to load image!", "Error", wxOK | wxICON_ERROR);
    }
}


void AddBook::ClearForm()
{
    m_productIdCtrl->Clear();
    m_productNameCtrl->Clear();
    m_authorCtrl->Clear();
    m_genreCtrl->SetValue("");
    m_publisherCtrl->Clear();
    m_yearCtrl->Clear();
    m_pagesCtrl->Clear();
    m_descriptionCtrl->Clear();
    m_priceCtrl->Clear();
    m_languageCtrl->Clear();
    m_imagePicker->SetPath(wxEmptyString);
    m_imagePreview->SetBitmap(wxNullBitmap);
    m_productImage->Destroy();
    m_imagePath.clear();
}

void AddBook::IntoFile(char* fileName)
{
	std::ofstream fout(fileName, 
        std::ios::out | std::ios::binary | std::ios::app);

    MyString productId = m_productIdCtrl->GetValue();
    MyString productName = m_productNameCtrl->GetValue();
    MyString authorName = m_authorCtrl->GetValue();
    MyString bookType = m_genreCtrl->GetValue();
    MyString publisherName = m_publisherCtrl->GetValue();
    MyString bookEdition = m_yearCtrl->GetValue();
    MyString pages = m_pagesCtrl->GetValue();
    MyString description = m_descriptionCtrl->GetValue();
    MyString price = m_priceCtrl->GetValue();
    MyString language = m_languageCtrl->GetValue();
    wxImage* productImage = new wxImage(*m_productImage);   

    productId.WriteToStream(fout);
    productName.WriteToStream(fout);
    authorName.WriteToStream(fout);
    bookType.WriteToStream(fout);
    publisherName.WriteToStream(fout);
    bookEdition.WriteToStream(fout);
    pages.WriteToStream(fout);
    description.WriteToStream(fout);
    price.WriteToStream(fout);
    language.WriteToStream(fout);

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
bool AddBook::ValidateBook()
{    
    if (m_productIdCtrl->GetValue().IsEmpty() ||
        m_productNameCtrl->GetValue().IsEmpty() ||
        m_authorCtrl->GetValue().IsEmpty() ||
        m_languageCtrl->GetValue().IsEmpty() ||
        m_priceCtrl->GetValue().IsEmpty()) {
        wxMessageBox("Please fill in all required fields", "Error", wxOK | wxICON_ERROR);
        return false;
    }
    long price;
    if (!m_priceCtrl->GetValue().ToLong(&price) || price < 0) {
        wxMessageBox("Please enter a valid price", "Error", wxOK | wxICON_ERROR);
        return false;
    }
    long year;
    if (!m_yearCtrl->GetValue().IsEmpty()) {
        if (!m_yearCtrl->GetValue().ToLong(&year) || year < 0 || year > 9999) {
            wxMessageBox("Please enter a valid publication year (4-digit)", "Error", wxOK | wxICON_ERROR);
            return false;
        }
    }
    long pages;
    if (m_pagesCtrl->GetValue().IsEmpty() || !m_pagesCtrl->GetValue().ToLong(&pages) || pages <= 0) {
        wxMessageBox("Please enter a valid page count", "Error", wxOK | wxICON_ERROR);
        return false;
    }
    return true;
}

Book AddBook::ReadSingleBook()
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
    wxImage* productImage = new wxImage();
    
    std::ifstream fin("Products.bin", std::ios::binary);
    if (!fin.is_open()) {
        wxLogError("Failed to open Products.bin(AddBook.cpp)");
        return Book(); 
    }

    

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
        return book;
    }

    if (imgSize > 0) {
        std::vector<unsigned char> buffer(imgSize);
        fin.read(reinterpret_cast<char*>(buffer.data()), imgSize);
        if (!fin.good()) {
            wxLogError("Failed to read image data from Products.bin(AddBook.cpp)");
            return book;
        }
        wxMemoryInputStream memStream(buffer.data(), imgSize);
        if (productImage->LoadFile(memStream, wxBITMAP_TYPE_PNG)) {
            book.SetProductImage(*productImage);
        }
    }
    else {
        book.SetProductImage(wxNullImage);
    }

    return book;
}

Book AddBook::GetBookFromPanel()
{
    MyString productId = m_productIdCtrl->GetValue();
    MyString productName = m_productNameCtrl->GetValue();
    MyString authorName = m_authorCtrl->GetValue();
    MyString bookType = m_genreCtrl->GetValue();
    MyString publisherName = m_publisherCtrl->GetValue();
    MyString bookEdition = m_yearCtrl->GetValue();
    MyString pages = m_pagesCtrl->GetValue();
    MyString description = m_descriptionCtrl->GetValue();
    MyString price = m_priceCtrl->GetValue();
    MyString language = m_languageCtrl->GetValue();
    wxImage* productImage = new wxImage(*m_productImage);

    return Book(productId, productName, description,
        price.StringToInt(), productImage, authorName,
        publisherName, bookType, language, bookEdition,
		pages.StringToInt());
}