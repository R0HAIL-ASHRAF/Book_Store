#include "AddStationary.h"

AddStationary::AddStationary(wxWindow* parent)
    : wxPanel(parent, wxID_ANY), m_productImage(new wxImage())
{
    InitUI();
}


void AddStationary::InitUI()
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->AddSpacer(10);

    wxStaticText* title = new wxStaticText(this, wxID_ANY, "Add New Stationary");
    title->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    mainSizer->Add(title, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 15);

    wxBoxSizer* formSizer = new wxBoxSizer(wxVERTICAL);

    {
        wxBoxSizer* row = new wxBoxSizer(wxHORIZONTAL);
        row->Add(new wxStaticText(this, wxID_ANY, "Brand:"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
        m_productNameCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(500, -1));
        row->Add(m_productNameCtrl, 0, wxRIGHT, 20);
        formSizer->Add(row, 0, wxEXPAND | wxBOTTOM, 10);
    }

    // id + price
    {
        wxBoxSizer* row = new wxBoxSizer(wxHORIZONTAL);
        row->Add(new wxStaticText(this, wxID_ANY, "ID :     "), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
        m_productIdCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1));
        row->Add(m_productIdCtrl, 0, wxRIGHT, 20);

        row->Add(new wxStaticText(this, wxID_ANY, "Price (Rs):"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
        m_priceCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(217, -1));
        row->Add(m_priceCtrl, 0);

        formSizer->Add(row, 0, wxEXPAND | wxBOTTOM, 10);
    }

    {
        wxBoxSizer* row = new wxBoxSizer(wxHORIZONTAL);
        row->Add(new wxStaticText(this, wxID_ANY, "Brand:"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
        m_stationaryBrandCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(500, -1));
        row->Add(m_stationaryBrandCtrl, 0, wxRIGHT, 20);
        formSizer->Add(row, 0, wxEXPAND | wxBOTTOM, 10);
    }
    {
        wxBoxSizer* row = new wxBoxSizer(wxHORIZONTAL);
        row->Add(new wxStaticText(this, wxID_ANY, "Color:"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
        m_stationaryColorCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(500, -1));
        row->Add(m_stationaryColorCtrl, 0, wxRIGHT, 20);
        formSizer->Add(row, 0, wxEXPAND | wxBOTTOM, 10);
    }
    
    {
        wxBoxSizer* row = new wxBoxSizer(wxHORIZONTAL);
        row->Add(new wxStaticText(this, wxID_ANY, "Type: "), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
        m_stationaryTypeCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(500, -1));
        row->Add(m_stationaryTypeCtrl, 0, wxRIGHT, 20);
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
        m_imagePicker->Bind(wxEVT_FILEPICKER_CHANGED, &AddStationary::OnImageSelected, this);

        m_imagePreview = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize(100, 150));
        m_imagePreview->SetBackgroundColour(wxColour(255, 188, 217));

        imageSizer->Add(m_imagePicker, 0, wxRIGHT, 10);
        imageSizer->Add(m_imagePreview, 0, wxALIGN_CENTER_VERTICAL);

        wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
        wxButton* cancelBtn = new wxButton(this, ID_CancelBtnAddStat, "Cancel", wxDefaultPosition, wxSize(80, 30));
        wxButton* saveBtn = new wxButton(this, ID_SaveBtnAddStat, "Save", wxDefaultPosition, wxSize(80, 30));
        wxButton* clearBtn = new wxButton(this, ID_ClearBtnAddStat, "Clear", wxDefaultPosition, wxSize(80, 30));

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

void AddStationary::OnImageSelected(wxFileDirPickerEvent& event)
{
    wxString path = event.GetPath();
    if (path.IsEmpty() || !wxFileExists(path)) {
        return;
    }

    if (m_productImage->LoadFile(path)) {

        
        wxMemoryOutputStream memStream;
        if (!m_productImage->SaveFile(memStream, wxBITMAP_TYPE_PNG)) {
            wxMessageBox("Failed to process image!", "Error", wxOK | wxICON_ERROR);
            return;
        }

        size_t imageSize = memStream.GetSize();
        if (imageSize > 10 * 1024) { 
            wxMessageBox("Selected image must be smaller than 5 KB.", "Image Too Large", wxOK | wxICON_WARNING);
            m_productImage->Destroy();
            m_imagePreview->SetBitmap(wxNullBitmap);
            m_imagePath.clear();
            Refresh();
            return;
        }
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

void AddStationary::OnClear(wxCommandEvent& event)
{
    m_productIdCtrl->Clear();
    m_productNameCtrl->Clear();
    m_stationaryTypeCtrl->Clear();
    m_stationaryBrandCtrl->Clear();
    m_stationaryColorCtrl->Clear();
    m_priceCtrl->Clear();
    m_descriptionCtrl->Clear();
    m_imagePicker->SetPath(wxEmptyString);
    m_imagePreview->SetBitmap(wxNullBitmap);
    delete m_productImage;
    m_productImage = new wxImage();
    m_imagePath.clear();
}


void AddStationary::Clear()
{
    m_productIdCtrl->Clear();
    m_productNameCtrl->Clear();
    m_stationaryTypeCtrl->Clear();
    m_stationaryBrandCtrl->Clear();
    m_stationaryColorCtrl->Clear();
    m_priceCtrl->Clear();
    m_descriptionCtrl->Clear();
    m_imagePicker->SetPath(wxEmptyString);
    m_imagePreview->SetBitmap(wxNullBitmap);
    delete m_productImage;
    m_productImage = new wxImage();
    m_imagePath.clear();
}

Stationary AddStationary::GetStationaryFromPanel()
{
    MyString productId = m_productIdCtrl->GetValue();
    MyString productName = m_productNameCtrl->GetValue();
    MyString type = m_stationaryTypeCtrl->GetValue();
    MyString brand = m_stationaryBrandCtrl->GetValue();
    MyString color = m_stationaryColorCtrl->GetValue();
    MyString description = m_descriptionCtrl->GetValue();
    MyString price = m_priceCtrl->GetValue();
    wxImage* productImage = new wxImage(*m_productImage);

    return Stationary(productId, productName, description,
        price.StringToInt(), productImage, type, brand, color);
}

bool AddStationary::ValidateStationary()
{
    if (m_productIdCtrl->GetValue().IsEmpty() ||
        m_productNameCtrl->GetValue().IsEmpty() ||
        m_stationaryTypeCtrl->GetValue().IsEmpty() ||
        m_stationaryBrandCtrl->GetValue().IsEmpty() ||
        m_stationaryColorCtrl->GetValue().IsEmpty() ||
        m_priceCtrl->GetValue().IsEmpty()) {
        wxMessageBox("Please fill in all required fields", "Error", wxOK | wxICON_ERROR);
        return false;
    }
    long price;
    if (!m_priceCtrl->GetValue().ToLong(&price) || price < 0) {
        wxMessageBox("Please enter a valid (non-negative) price", "Error", wxOK | wxICON_ERROR);
        return false;
    }
    return true;
}

void AddStationary::IntoFile(char* fileName)
{
    std::ofstream fout(fileName,
        std::ios::out | std::ios::binary | std::ios::app);

    MyString productId = m_productIdCtrl->GetValue();
    MyString productName = m_productNameCtrl->GetValue();
    MyString type = m_stationaryTypeCtrl->GetValue();
    MyString brand = m_stationaryBrandCtrl->GetValue();
    MyString color = m_stationaryColorCtrl->GetValue();
    MyString description = m_descriptionCtrl->GetValue();
    MyString price = m_priceCtrl->GetValue();
    wxImage* productImage = new wxImage(*m_productImage);



    productId.WriteToStream(fout);
    productName.WriteToStream(fout);
    type.WriteToStream(fout);
    brand.WriteToStream(fout);
    color.WriteToStream(fout);
    description.WriteToStream(fout);
    price.WriteToStream(fout);

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
