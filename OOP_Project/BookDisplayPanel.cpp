#include "BookDisplayPanel.h"

BookDisplayPanel::BookDisplayPanel(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    SetBackgroundColour(wxColour(255, 188, 217));
    CreateControls();
}

void BookDisplayPanel::CreateControls()
{
    // Main sizer with padding
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->AddSpacer(15);

    // Create a bordered panel for content
    wxPanel* contentPanel = new wxPanel(this, wxID_ANY);
    contentPanel->SetBackgroundColour(*wxWHITE);
    wxBoxSizer* contentSizer = new wxBoxSizer(wxHORIZONTAL);
    contentPanel->SetSizer(contentSizer);

    // Left side - Book cover
    wxPanel* coverPanel = new wxPanel(contentPanel, wxID_ANY);
    coverPanel->SetBackgroundColour(wxColour(245, 245, 245));
    wxBoxSizer* coverSizer = new wxBoxSizer(wxVERTICAL);
    coverPanel->SetSizer(coverSizer);

    m_imagePreview = new wxStaticBitmap(coverPanel, wxID_ANY, wxNullBitmap,
        wxDefaultPosition, wxSize(180, 240));
    coverSizer->Add(m_imagePreview, 0, wxALL, 15);
    coverSizer->AddSpacer(10);

    // Add a placeholder if no image
    wxStaticText* noCoverText = new wxStaticText(coverPanel, wxID_ANY, "No Cover Image");
    noCoverText->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL));
    noCoverText->SetForegroundColour(wxColour(150, 150, 150));
    coverSizer->Add(noCoverText, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 15);
    m_noCoverText = noCoverText;

    contentSizer->Add(coverPanel, 0, wxEXPAND | wxALL, 5);

    // Right side - Book details
    wxPanel* detailsPanel = new wxPanel(contentPanel, wxID_ANY);
    detailsPanel->SetBackgroundColour(*wxWHITE);
    wxBoxSizer* detailsSizer = new wxBoxSizer(wxVERTICAL);
    detailsPanel->SetSizer(detailsSizer);

    // Title with nice styling
    m_titleText = new wxStaticText(detailsPanel, wxID_ANY, "",
        wxDefaultPosition, wxDefaultSize,
        wxALIGN_LEFT | wxST_ELLIPSIZE_END);
    m_titleText->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    m_titleText->SetForegroundColour(wxColour(50, 50, 50));
    detailsSizer->Add(m_titleText, 0, wxTOP | wxLEFT | wxRIGHT | wxEXPAND, 10);

    // Author with subtle styling
    m_authorText = new wxStaticText(detailsPanel, wxID_ANY, "");
    m_authorText->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    m_authorText->SetForegroundColour(wxColour(100, 100, 100));
    detailsSizer->Add(m_authorText, 0, wxLEFT | wxRIGHT | wxBOTTOM | wxEXPAND, 10);

    // Separator line
    detailsSizer->Add(new wxStaticLine(detailsPanel, wxID_ANY,
        wxDefaultPosition, wxSize(-1, 1),
        wxLI_HORIZONTAL),
        0, wxEXPAND | wxLEFT | wxRIGHT, 10);
    detailsSizer->AddSpacer(10);

    // Details grid
    wxFlexGridSizer* grid = new wxFlexGridSizer(2, 10, 15);
    grid->AddGrowableCol(1, 1);

    // Helper function to create styled label-value pairs
    auto AddDetailRow = [&](const wxString& label, wxStaticText** valueCtrl) {
        wxStaticText* labelCtrl = new wxStaticText(detailsPanel, wxID_ANY, label + ":");
        labelCtrl->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
        labelCtrl->SetForegroundColour(wxColour(120, 120, 120));
        grid->Add(labelCtrl, 0, wxALIGN_CENTER_VERTICAL | wxLEFT, 10);

        *valueCtrl = new wxStaticText(detailsPanel, wxID_ANY, "");
        (*valueCtrl)->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
        grid->Add(*valueCtrl, 1, wxALIGN_CENTER_VERTICAL | wxRIGHT, 10);
        };

    // Add all detail rows
    AddDetailRow("Genre", &m_genreText);
    AddDetailRow("Publisher", &m_publisherText);
    AddDetailRow("Published", &m_yearText);
    AddDetailRow("Pages", &m_pagesText);
    AddDetailRow("Language", &m_languageText);
    AddDetailRow("Price", &m_priceText);

    detailsSizer->Add(grid, 0, wxEXPAND | wxBOTTOM, 15);

    // Description with scrollable area
    wxStaticBox* descBox = new wxStaticBox(detailsPanel, wxID_ANY, "Description");
    descBox->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    wxStaticBoxSizer* descSizer = new wxStaticBoxSizer(descBox, wxVERTICAL);

    wxStaticText* descText = new wxStaticText(detailsPanel, wxID_ANY, "",
        wxDefaultPosition, wxSize(-1, 100),
        wxTE_MULTILINE | wxTE_READONLY | wxTE_WORDWRAP | wxBORDER_NONE);
    descText->SetBackgroundColour(*wxWHITE);
    m_descriptionText = descText;
    descSizer->Add(descText, 1, wxEXPAND | wxALL, 5);

    detailsSizer->Add(descSizer, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 10);

    contentSizer->Add(detailsPanel, 1, wxEXPAND | wxALL, 5);

    // Add shadow effect to content panel
    contentPanel->SetWindowStyle(wxBORDER_SIMPLE);
    contentPanel->SetBackgroundColour(*wxWHITE);

    mainSizer->Add(contentPanel, 1, wxEXPAND | wxLEFT | wxRIGHT, 15);
    mainSizer->AddSpacer(15);

    SetSizer(mainSizer);
    Layout();
}

void BookDisplayPanel::SetBookInfo(const Book& book)
{
    // Set all text fields
    m_titleText->SetLabel(book.getProductName());
    m_authorText->SetLabel(book.GetAuthorName());
    m_genreText->SetLabel(book.GetBookType());
    m_publisherText->SetLabel(book.GetPublisherName());
    m_yearText->SetLabel(book.GetBookEdition());
    m_pagesText->SetLabel(wxString::Format("%d pages", book.GetPages()));
    m_priceText->SetLabel(wxString::Format("Rs %.2f", book.getPrice()));
    m_languageText->SetLabel(book.GetBookLanguage());
    
    m_descriptionText->SetLabel(book.getDescription());

    // Handle book cover image
    wxImage image = book.GetProductImage();
    if (image.IsOk()) {
        // Scale image while maintaining aspect ratio
        wxImage scaled = image.Copy();
        double aspect = (double)image.GetWidth() / image.GetHeight();
        int newWidth = 180;
        int newHeight = 240;

        if (aspect > 0.75) { // Wider than standard book aspect
            newHeight = (int)(newWidth / aspect);
        }
        else { // Taller than standard book aspect
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

    // Adjust layout
    Layout();
}