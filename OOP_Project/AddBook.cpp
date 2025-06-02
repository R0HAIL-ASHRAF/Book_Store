#include "AddBook.h"


AddBook::AddBook(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    InitUI();
}

void AddBook::InitUI()
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    // Form title
    wxStaticText* title = new wxStaticText(this, wxID_ANY, "Add New Book");
    title->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    mainSizer->Add(title, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 15);

    // Create form sizer
    wxFlexGridSizer* formSizer = new wxFlexGridSizer(2, wxSize(10, 10));
    formSizer->AddGrowableCol(1, 1);
    formSizer->SetFlexibleDirection(wxBOTH);

    // Product ID
    formSizer->Add(new wxStaticText(this, wxID_ANY, "Book ID:"),
        0, wxALIGN_CENTER_VERTICAL | wxLEFT, 5);
    m_productIdCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1));
    formSizer->Add(m_productIdCtrl, 1, wxEXPAND | wxRIGHT, 5);

    // Book Title (Product Name)
    formSizer->Add(new wxStaticText(this, wxID_ANY, "Title:"),
        0, wxALIGN_CENTER_VERTICAL | wxLEFT, 5);
    m_productNameCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1));
    formSizer->Add(m_productNameCtrl, 1, wxEXPAND | wxRIGHT, 5);

    // Author (replaces Category)
    formSizer->Add(new wxStaticText(this, wxID_ANY, "Author:"),
        0, wxALIGN_CENTER_VERTICAL | wxLEFT, 5);
    m_authorCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1));
    formSizer->Add(m_authorCtrl, 1, wxEXPAND | wxRIGHT, 5);

    // Genre (additional book attribute)
    formSizer->Add(new wxStaticText(this, wxID_ANY, "Genre:"),
        0, wxALIGN_CENTER_VERTICAL | wxLEFT, 5);
    wxArrayString genres;
    genres.Add("Fiction");
    genres.Add("Non-Fiction");
    genres.Add("Science Fiction");
    genres.Add("Fantasy");
    genres.Add("Mystery");
    genres.Add("Romance");
    genres.Add("Biography");
    m_genreCtrl = new wxComboBox(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1), genres, wxCB_DROPDOWN);
    formSizer->Add(m_genreCtrl, 1, wxEXPAND | wxRIGHT, 5);

   
    // Publisher (additional book attribute)
    formSizer->Add(new wxStaticText(this, wxID_ANY, "Publisher:"),
        0, wxALIGN_CENTER_VERTICAL | wxLEFT, 5);
    m_publisherCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1));
    formSizer->Add(m_publisherCtrl, 1, wxEXPAND | wxRIGHT, 5);

    // Publication Year (additional book attribute)
    formSizer->Add(new wxStaticText(this, wxID_ANY, "Publication Year:"),
        0, wxALIGN_CENTER_VERTICAL | wxLEFT, 5);
    m_yearCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(100, -1));
    formSizer->Add(m_yearCtrl, 0, wxALIGN_LEFT | wxRIGHT, 5);

    formSizer->Add(new wxStaticText(this, wxID_ANY, "Language:"),
        0, wxALIGN_CENTER_VERTICAL | wxLEFT, 5);
    m_languageCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1));
    formSizer->Add(m_languageCtrl, 1, wxEXPAND | wxRIGHT, 5);


    // Pages (additional book attribute)
    formSizer->Add(new wxStaticText(this, wxID_ANY, "Pages:"),
        0, wxALIGN_CENTER_VERTICAL | wxLEFT, 5);
    m_pagesCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(100, -1));
    formSizer->Add(m_pagesCtrl, 0, wxALIGN_LEFT | wxRIGHT, 5);

    // Description
    formSizer->Add(new wxStaticText(this, wxID_ANY, "Synopsis:"),
        0, wxALIGN_TOP | wxLEFT, 5);
    m_descriptionCtrl = new wxTextCtrl(this, wxID_ANY, "",
        wxDefaultPosition, wxSize(200, 100),
        wxTE_MULTILINE);
    formSizer->Add(m_descriptionCtrl, 1, wxEXPAND | wxRIGHT, 5);

    // Price
    formSizer->Add(new wxStaticText(this, wxID_ANY, "Price (Rs):"),
        0, wxALIGN_CENTER_VERTICAL | wxLEFT, 5);
    m_priceCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(100, -1));
    formSizer->Add(m_priceCtrl, 0, wxALIGN_LEFT | wxRIGHT, 5);

    // Image Upload
    formSizer->Add(new wxStaticText(this, wxID_ANY, "Book Cover:"),
        0, wxALIGN_CENTER_VERTICAL | wxLEFT, 5);

    wxBoxSizer* imageSizer = new wxBoxSizer(wxHORIZONTAL);
    m_imagePicker = new wxFilePickerCtrl(this, wxID_ANY,
        wxEmptyString,
        "Select book cover image",
        "Image files (*.jpg;*.png)|*.jpg;*.png",
        wxDefaultPosition, wxDefaultSize,
        wxFLP_OPEN | wxFLP_FILE_MUST_EXIST);
    m_imagePicker->Bind(wxEVT_FILEPICKER_CHANGED, &AddBook::OnImageSelected, this);

    m_imagePreview = new wxStaticBitmap(this, wxID_ANY,
        wxNullBitmap,
        wxDefaultPosition, wxSize(150, 200)); // Larger size for book covers
    m_imagePreview->SetBackgroundColour(wxColour(240, 240, 240));

    imageSizer->Add(m_imagePicker, 1, wxEXPAND | wxRIGHT, 10);
    imageSizer->Add(m_imagePreview, 0, wxALIGN_CENTER_VERTICAL);
    formSizer->Add(imageSizer, 1, wxEXPAND | wxRIGHT, 5);

    mainSizer->Add(formSizer, 0, wxEXPAND | wxALL, 15);

    // Add separator
    mainSizer->Add(new wxStaticLine(this), 0, wxEXPAND | wxLEFT | wxRIGHT, 15);

    // Add buttons
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    wxButton* cancelBtn = new wxButton(this, wxID_CANCEL, "Cancel");
    wxButton* saveBtn = new wxButton(this, wxID_OK, "Save Book");
    saveBtn->SetBackgroundColour(wxColour(70, 160, 70));
    saveBtn->SetForegroundColour(*wxWHITE);

    buttonSizer->AddStretchSpacer();
    buttonSizer->Add(cancelBtn, 0, wxALL, 5);
    buttonSizer->Add(saveBtn, 0, wxALL, 5);

    mainSizer->Add(buttonSizer, 0, wxEXPAND | wxALL, 10);

    SetSizer(mainSizer);

    // Bind save button event
    saveBtn->Bind(wxEVT_BUTTON, &AddBook::OnSaveProduct, this);
}

void AddBook::OnImageSelected(wxFileDirPickerEvent& event)
{
    wxString path = event.GetPath();
    if (path.IsEmpty() || !wxFileExists(path)) {
        return;
    }

    if (m_productImage.LoadFile(path)) {
        // Scale image for preview while maintaining aspect ratio
        wxImage scaledImage = m_productImage;
        wxSize previewSize = m_imagePreview->GetSize();
        double aspectRatio = static_cast<double>(m_productImage.GetWidth()) / m_productImage.GetHeight();

        if (aspectRatio > 0.75) { // Wider than standard book aspect
            scaledImage.Rescale(previewSize.GetWidth(),
                previewSize.GetWidth() / aspectRatio,
                wxIMAGE_QUALITY_HIGH);
        }
        else { // Taller than standard book aspect
            scaledImage.Rescale(previewSize.GetHeight() * aspectRatio,
                previewSize.GetHeight(),
                wxIMAGE_QUALITY_HIGH);
        }

        m_imagePreview->SetBitmap(wxBitmap(scaledImage));
        m_imagePath = MyString(path);
        Refresh();
    }
    else {
        wxMessageBox("Failed to load image!", "Error", wxOK | wxICON_ERROR);
    }
}

void AddBook::OnSaveProduct(wxCommandEvent& event)
{
    // Validate inputs
    if (m_productIdCtrl->GetValue().IsEmpty() ||
        m_productNameCtrl->GetValue().IsEmpty() ||
        m_authorCtrl->GetValue().IsEmpty() ||
		m_languageCtrl->GetValue().IsEmpty() ||
        m_priceCtrl->GetValue().IsEmpty()) {
        wxMessageBox("Please fill in all required fields", "Error", wxOK | wxICON_ERROR);
        return;
    }

    // Validate price
    long price;
    if (!m_priceCtrl->GetValue().ToLong(&price)) {
        wxMessageBox("Please enter a valid price", "Error", wxOK | wxICON_ERROR);
        return;
    }

    // Validate year
    long year;
    if (!m_yearCtrl->GetValue().IsEmpty() && !m_yearCtrl->GetValue().ToLong(&year)) {
        wxMessageBox("Please enter a valid publication year", "Error", wxOK | wxICON_ERROR);
        return;
    }

    // Validate pages
    long pages;
    if (!m_pagesCtrl->GetValue().IsEmpty() && !m_pagesCtrl->GetValue().ToLong(&pages)) {
        wxMessageBox("Please enter a valid page count", "Error", wxOK | wxICON_ERROR);
        return;
    }

    // Create book object (replace with your actual Book class)
    Book newBook;
    newBook.SetProductID(MyString(m_productIdCtrl->GetValue()));
    newBook.SetProductName(MyString(m_productNameCtrl->GetValue()));
    newBook.SetAuthorName(MyString(m_authorCtrl->GetValue()));
    newBook.SetBookType(MyString(m_genreCtrl->GetValue()));
    newBook.SetPublisherName(MyString(m_publisherCtrl->GetValue()));
	newBook.SetBookLanguage(MyString(m_languageCtrl->GetValue()));
    if (!m_yearCtrl->GetValue().IsEmpty()) {
        newBook.SetBookEdition(MyString(m_yearCtrl->GetValue()).StringToInt());
    }
    if (!m_pagesCtrl->GetValue().IsEmpty()) {
        newBook.SetPages(MyString(m_pagesCtrl->GetValue()).StringToInt());
    }
    newBook.SetProductDescription(MyString(m_descriptionCtrl->GetValue()));
    newBook.SetPrice(price);

    if (!m_imagePath.IsEmpty()) {
        newBook.SetProductImage(m_productImage);
    }

    // TODO: Save book to database or storage
    wxMessageBox("Book saved successfully!", "Success", wxOK | wxICON_INFORMATION);

    // Clear form
    ClearForm();
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
    m_imagePicker->SetPath(wxEmptyString);
    m_imagePreview->SetBitmap(wxNullBitmap);
    m_productImage.Destroy();
    m_imagePath.clear();
}