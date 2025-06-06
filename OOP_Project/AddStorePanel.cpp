#include "AddStorePanel.h"

AddStorePanel::AddStorePanel(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    SetupUI();
    
}

void AddStorePanel::SetupUI()
{

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->AddSpacer(10);

   
    wxStaticText* title = new wxStaticText(this, wxID_ANY, "Create Your Store");
    title->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    title->SetForegroundColour(wxColour(50, 100, 200));
    mainSizer->Add(title, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 15);

    mainSizer->Add(new wxStaticLine(this), 0, wxEXPAND | wxLEFT | wxRIGHT, 15);

    wxBoxSizer* centerSizer = new wxBoxSizer(wxHORIZONTAL);

    //left Panel
    wxBoxSizer* managerSizer = new wxBoxSizer(wxVERTICAL);
    wxStaticText* personSectionHeader = new wxStaticText(this, wxID_ANY, "About Store Manager");
    personSectionHeader->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    managerSizer->Add(personSectionHeader, 0, wxALIGN_LEFT | wxBOTTOM, 10);

   
    {
        wxBoxSizer* row = new wxBoxSizer(wxHORIZONTAL);
        row->Add(new wxStaticText(this, wxID_ANY, "First/Last Name:"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
        firstNameCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(150, -1));
        row->Add(firstNameCtrl, 0, wxRIGHT, 20);
        lastNameCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(150, -1));
        row->Add(lastNameCtrl, 0, wxEXPAND);
        managerSizer->Add(row, 0, wxEXPAND | wxBOTTOM, 10);
    }


    {
        wxBoxSizer* row = new wxBoxSizer(wxHORIZONTAL);
        row->Add(new wxStaticText(this, wxID_ANY, "Username:"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
        usernameCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(150, -1));
        row->Add(usernameCtrl, 0, wxRIGHT, 20);

        row->Add(new wxStaticText(this, wxID_ANY, "Password:"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
        passwordCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(150, -1));
        row->Add(passwordCtrl, 0, wxEXPAND);
        managerSizer->Add(row, 0, wxEXPAND | wxBOTTOM, 10);
    }

 
    wxBoxSizer* dobSizer = new wxBoxSizer(wxHORIZONTAL);
    dobSizer->Add(new wxStaticText(this, wxID_ANY, "Date of Birth:"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 8);
    dayCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(40, -1));
    monthCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(40, -1));
    yearCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(60, -1));
    dobSizer->Add(dayCtrl, 0, wxRIGHT, 5);
    dobSizer->Add(new wxStaticText(this, wxID_ANY, "/"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
    dobSizer->Add(monthCtrl, 0, wxRIGHT, 5);
    dobSizer->Add(new wxStaticText(this, wxID_ANY, "/"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
    dobSizer->Add(yearCtrl, 0);
    
    managerSizer->Add(dobSizer, 0, wxBOTTOM, 10);

    wxBoxSizer* emailRow = new wxBoxSizer(wxHORIZONTAL);
    emailRow->Add(new wxStaticText(this, wxID_ANY, "Email:"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 8);
    emailCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(300, -1));
    emailRow->Add(emailCtrl, 1, wxEXPAND);
    managerSizer->Add(emailRow, 0, wxEXPAND | wxBOTTOM, 10);

    personHouseNumberCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1));
    personCityCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1));
    personProvinceCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1));
    personCountryCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1));
    
    
        wxBoxSizer* houseRowp = new wxBoxSizer(wxHORIZONTAL);
        houseRowp->Add(new wxStaticText(this, wxID_ANY, "House Number:"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 8);
        houseRowp->Add(personHouseNumberCtrl, 1, wxEXPAND);
        managerSizer->Add(houseRowp, 0, wxEXPAND | wxBOTTOM, 10);

        wxBoxSizer* cityRowp = new wxBoxSizer(wxHORIZONTAL);
        cityRowp->Add(new wxStaticText(this, wxID_ANY, "City:"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 8);
        cityRowp->Add(personCityCtrl, 1, wxEXPAND);
        managerSizer->Add(cityRowp, 0, wxEXPAND | wxBOTTOM, 10);

        wxBoxSizer* provinceRowp = new wxBoxSizer(wxHORIZONTAL);
        provinceRowp->Add(new wxStaticText(this, wxID_ANY, "Province:"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 8);
        provinceRowp->Add(personProvinceCtrl, 1, wxEXPAND);
        managerSizer->Add(provinceRowp, 0, wxEXPAND | wxBOTTOM, 10);

        wxBoxSizer* countryRowp = new wxBoxSizer(wxHORIZONTAL);
        countryRowp->Add(new wxStaticText(this, wxID_ANY, "Country:"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 8);
        countryRowp->Add(personCountryCtrl, 1, wxEXPAND);
        managerSizer->Add(countryRowp, 0, wxEXPAND | wxBOTTOM, 10);


    


    wxStaticLine* verticalLine = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 400), wxLI_VERTICAL);

    //right Panel
    wxBoxSizer* storeSizer = new wxBoxSizer(wxVERTICAL);
    wxStaticText* storeSectionHeader = new wxStaticText(this, wxID_ANY, "About Store");
    storeSectionHeader->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    storeSizer->Add(storeSectionHeader, 0, wxALIGN_LEFT | wxBOTTOM, 10);

    storeIdCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1));
    storeNameCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1));
    houseNumberCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1));
    cityCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1));
    provinceCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1));
    countryCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1));

    wxBoxSizer* idRow = new wxBoxSizer(wxHORIZONTAL);
    idRow->Add(new wxStaticText(this, wxID_ANY, "Store ID:"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 8);
    idRow->Add(storeIdCtrl, 0, wxBOTTOM, 5);
    storeSizer->Add(idRow, 0, wxEXPAND | wxBOTTOM, 10);

    wxBoxSizer* nameRow = new wxBoxSizer(wxHORIZONTAL);
    nameRow->Add(new wxStaticText(this, wxID_ANY, "Store Name:"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 8);
    nameRow->Add(storeNameCtrl, 0, wxBOTTOM, 5);
    storeSizer->Add(nameRow, 0, wxEXPAND | wxBOTTOM, 10);

  

    
        wxBoxSizer* houseRow = new wxBoxSizer(wxHORIZONTAL);
        houseRow->Add(new wxStaticText(this, wxID_ANY, "House Number:"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 8);
        houseRow->Add(houseNumberCtrl, 1, wxEXPAND);
        storeSizer->Add(houseRow, 0, wxEXPAND | wxBOTTOM, 10);

        wxBoxSizer* cityRow = new wxBoxSizer(wxHORIZONTAL);
        cityRow->Add(new wxStaticText(this, wxID_ANY, "City:"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 8);
        cityRow->Add(cityCtrl, 1, wxEXPAND);
        storeSizer->Add(cityRow, 0, wxEXPAND | wxBOTTOM, 10);

        wxBoxSizer* provinceRow = new wxBoxSizer(wxHORIZONTAL);
        provinceRow->Add(new wxStaticText(this, wxID_ANY, "Province:"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 8);
        provinceRow->Add(provinceCtrl, 1, wxEXPAND);
        storeSizer->Add(provinceRow, 0, wxEXPAND | wxBOTTOM, 10);

        wxBoxSizer* countryRow = new wxBoxSizer(wxHORIZONTAL);
        countryRow->Add(new wxStaticText(this, wxID_ANY, "Country:"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 8);
        countryRow->Add(countryCtrl, 1, wxEXPAND);
        storeSizer->Add(countryRow, 0, wxEXPAND | wxBOTTOM, 10);


    

    centerSizer->Add(managerSizer, 1, wxRIGHT, 20);
    centerSizer->Add(verticalLine, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);
    centerSizer->Add(storeSizer, 1, wxLEFT, 20);

    mainSizer->Add(centerSizer, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);

    
    wxButton* submitBtn = new wxButton(this, ID_SubmitStore, "Save Store");
    mainSizer->Add(submitBtn, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);


    mainSizer->Add(new wxStaticLine(this), 0, wxEXPAND | wxLEFT | wxRIGHT, 15);
    wxStaticText* productHeader = new wxStaticText(this, wxID_ANY, "Want to add products to Store!");
    productHeader->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    mainSizer->Add(productHeader, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

    wxBoxSizer* productBtnSizer = new wxBoxSizer(wxHORIZONTAL);
    wxButton* addBookBtn = new wxButton(this, ID_AddBookInStore, "Add Book");
    wxButton* addStationeryBtn = new wxButton(this, ID_AddStationery, "Add Stationery");
    productBtnSizer->Add(addBookBtn, 0, wxALL, 5);
    productBtnSizer->Add(addStationeryBtn, 0, wxALL, 5);
    mainSizer->Add(productBtnSizer, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 5);

    SetSizer(mainSizer);
}


void AddStorePanel::OnSubmit(wxCommandEvent& event)
{
    if (storeIdCtrl->GetValue().IsEmpty() || storeNameCtrl->GetValue().IsEmpty()) {
        wxMessageBox("Store ID and Name are required!", "Error", wxOK | wxICON_ERROR);
        return;
    }

    wxMessageBox("Store saved successfully!", "Success", wxOK | wxICON_INFORMATION);
}

Store AddStorePanel::SetStore() 
{
    MyString storeId = storeIdCtrl->GetValue();
    MyString storeName = storeNameCtrl->GetValue();
    MyString houseNumber = houseNumberCtrl->GetValue();
    MyString province = provinceCtrl->GetValue();
    MyString city = cityCtrl->GetValue();
    MyString country = countryCtrl->GetValue();

    return Store(storeId, storeName, 
        Address(houseNumber, city, province, country)
    );

}