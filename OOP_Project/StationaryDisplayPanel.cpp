#include "StationaryDisplayPanel.h"


StationaryDisplayPanel::StationaryDisplayPanel(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    SetBackgroundColour(wxColour(255, 188, 217));
    CreateControls();
}

void StationaryDisplayPanel::CreateControls()
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    wxPanel* contentPanel = new wxPanel(this, wxID_ANY);
    contentPanel->SetBackgroundColour(wxColor(255, 209, 220));
    wxBoxSizer* contentSizer = new wxBoxSizer(wxHORIZONTAL);
    contentPanel->SetSizer(contentSizer);

    wxPanel* coverPanel = new wxPanel(contentPanel, wxID_ANY);
    coverPanel->SetBackgroundColour(wxColor(255, 209, 220));
    wxBoxSizer* coverSizer = new wxBoxSizer(wxVERTICAL);
    coverPanel->SetSizer(coverSizer);

    m_imagePreview = new wxStaticBitmap(coverPanel, wxID_ANY, wxNullBitmap,
        wxDefaultPosition, wxSize(180, 240));
    coverSizer->Add(m_imagePreview, 0, wxALL, 15);
    coverSizer->AddSpacer(10);

    wxStaticText* noCoverText = new wxStaticText(coverPanel, wxID_ANY, "No Cover Image");
    noCoverText->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL));
    noCoverText->SetForegroundColour(wxColour(150, 150, 150));
    coverSizer->Add(noCoverText, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 15);
    m_noCoverText = noCoverText;

    contentSizer->Add(coverPanel, 0, wxEXPAND | wxALL, 5);

    wxPanel* detailsPanel = new wxPanel(contentPanel, wxID_ANY);
    detailsPanel->SetBackgroundColour(wxColor(255, 209, 220));
    wxBoxSizer* detailsSizer = new wxBoxSizer(wxVERTICAL);
    detailsPanel->SetSizer(detailsSizer);

    m_productNameText = new wxStaticText(detailsPanel, wxID_ANY, "",
        wxDefaultPosition, wxDefaultSize,
        wxALIGN_LEFT | wxST_ELLIPSIZE_END);
    m_productNameText->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    detailsSizer->Add(m_productNameText, 0, wxTOP | wxLEFT | wxRIGHT | wxEXPAND, 10);

    detailsSizer->Add(new wxStaticLine(detailsPanel, wxID_ANY,
        wxDefaultPosition, wxSize(-1, 1),
        wxLI_HORIZONTAL),
        0, wxEXPAND | wxLEFT | wxRIGHT, 10);
    detailsSizer->AddSpacer(10);

    wxFlexGridSizer* grid = new wxFlexGridSizer(2, 10, 15);
    grid->AddGrowableCol(1, 1);

    auto AddDetailRow = [&](const wxString& label, wxStaticText** valueCtrl) {
        wxStaticText* labelCtrl = new wxStaticText(detailsPanel, wxID_ANY, label + ":");
        labelCtrl->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
        grid->Add(labelCtrl, 0, wxALIGN_CENTER_VERTICAL | wxLEFT, 10);

        *valueCtrl = new wxStaticText(detailsPanel, wxID_ANY, "");
        (*valueCtrl)->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
        grid->Add(*valueCtrl, 1, wxALIGN_CENTER_VERTICAL | wxRIGHT, 10);
        };

    AddDetailRow("Brand", &m_stationaryBrandText);
    AddDetailRow("Color", &m_stationaryColorText);
    AddDetailRow("Type", &m_stationaryTypeText);
    AddDetailRow("Price", &m_priceText);

    detailsSizer->Add(grid, 0, wxEXPAND | wxBOTTOM, 15);

    wxStaticBox* descBox = new wxStaticBox(detailsPanel, wxID_ANY, "Description");
    descBox->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    wxStaticBoxSizer* descSizer = new wxStaticBoxSizer(descBox, wxVERTICAL);

    wxStaticText* descText = new wxStaticText(detailsPanel, wxID_ANY, "",
        wxDefaultPosition, wxSize(-1, 100),
        wxTE_MULTILINE | wxTE_READONLY | wxTE_WORDWRAP | wxBORDER_NONE);
    descText->SetBackgroundColour(wxColor(255, 209, 220));
    m_descriptionText = descText;
    descSizer->Add(descText, 1, wxEXPAND | wxALL, 5);

    detailsSizer->Add(descSizer, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 10);

    contentSizer->Add(detailsPanel, 1, wxEXPAND | wxALL, 5);

    contentPanel->SetWindowStyle(wxBORDER_SIMPLE);
    contentPanel->SetBackgroundColour(wxColor(255, 209, 220));

    mainSizer->Add(contentPanel, 1, wxEXPAND | wxALL, 15);

    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    wxButton* backBtn = new wxButton(this, ID_BackBtnVS, "Back");

    buttonSizer->AddStretchSpacer();
    buttonSizer->Add(backBtn, 0, wxALIGN_CENTER | wxBOTTOM, 10);
    buttonSizer->AddStretchSpacer();

    mainSizer->Add(buttonSizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 15);
    mainSizer->AddSpacer(5);

    SetSizer(mainSizer);
    Layout();
}

void StationaryDisplayPanel::SetStationaryInfo(const Stationary& book)
{
    m_productNameText->SetLabel(book.getProductName());
    m_stationaryTypeText->SetLabel(book.getStationaryType());
    m_stationaryColorText->SetLabel(book.getStationaryColor());
    m_stationaryBrandText->SetLabel(book.getStationaryBrand());
    m_priceText->SetLabel(MyString(book.getPrice()));
    

    m_descriptionText->SetLabel(book.getDescription());

    if (book.GetProductImage()->IsOk()) {
     
        wxImage scaled = book.GetProductImage()->Copy();
        double aspect = (double)book.GetProductImage()->GetWidth() / book.GetProductImage()->GetHeight();
        int newWidth = 180;
        int newHeight = 240;

        if (aspect > 0.75) {
            newHeight = (int)(newWidth / aspect);
        }
        else {
            newWidth = (int)(newHeight * aspect);
        }

        scaled.Rescale(newWidth, newHeight, wxIMAGE_QUALITY_HIGH);
        m_imagePreview->SetBitmap(wxBitmap(scaled));
        m_noCoverText->Hide();
    }
    else {
        m_imagePreview->SetBitmap(wxNullBitmap);
        m_noCoverText->Show();
    }
    Layout();
}