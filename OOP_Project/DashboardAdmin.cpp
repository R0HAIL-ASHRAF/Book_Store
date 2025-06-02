#include "DashboardAdmin.h"

DashboardAdmin::DashboardAdmin(wxWindow* parent)
    : wxPanel(parent, wxID_ANY),
    admin(Admin::GetInstance(parent))
{
    InitData();
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    CreateHeader(mainSizer);
    mainSizer->Add(new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 1), wxLI_HORIZONTAL),
        0, wxEXPAND | wxTOP | wxBOTTOM, 10);

    wxSplitterWindow* splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D);

    wxPanel* storeListPanel = new wxPanel(splitter);
    CreateStoreList(storeListPanel);

    wxPanel* detailsPanel = new wxPanel(splitter);
    CreateDetailsPanel(detailsPanel);

    splitter->SplitVertically(storeListPanel, detailsPanel, 300);
    splitter->SetMinimumPaneSize(200);
    mainSizer->Add(splitter, 1, wxEXPAND);

    CreateButtonPanel(mainSizer);

    SetSizer(mainSizer);
    SetBackgroundColour(wxColour(240, 245, 250));
}

void DashboardAdmin::InitData()
{
    stores.clear();
    for (size_t i = 0; i < admin->GetStores().size(); i++) {
        stores.push(admin->GetStores().at(i)->GetStore());
    }
}

void DashboardAdmin::CreateHeader(wxBoxSizer* mainSizer)
{
    wxPanel* headerPanel = new wxPanel(this);
    headerPanel->SetBackgroundColour(wxColour(50, 100, 180));

    wxBoxSizer* headerSizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* title = new wxStaticText(headerPanel, wxID_ANY, "ADMIN DASHBOARD");
    title->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    title->SetForegroundColour(*wxWHITE);
    headerSizer->Add(title, 0, wxALIGN_CENTER_VERTICAL | wxLEFT, 15);

    // Stats
    m_statsText = new wxStaticText(headerPanel, wxID_ANY,
        wxString::Format("Stores: %d | Products: %d | Customers: %d",
            stores.size(),
            GetTotalProducts(),//product size yet to calculate
            admin->GetCustomers().size()));
    m_statsText->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    m_statsText->SetForegroundColour(*wxWHITE);
    headerSizer->AddStretchSpacer();
    headerSizer->Add(m_statsText, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 15);

    headerPanel->SetSizer(headerSizer);
    mainSizer->Add(headerPanel, 0, wxEXPAND);
}

void DashboardAdmin::CreateStoreList(wxPanel* parent)
{
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    // Title
    wxStaticText* title = new wxStaticText(parent, wxID_ANY, "STORES");
    title->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    sizer->Add(title, 0, wxALL, 10);

    // Store list
    m_storeList = new wxListView(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize,
        wxLC_REPORT | wxLC_SINGLE_SEL | wxLC_HRULES | wxLC_VRULES);
    m_storeList->AppendColumn("ID", wxLIST_FORMAT_LEFT, 50);
    m_storeList->AppendColumn("Name", wxLIST_FORMAT_LEFT, 150);
    m_storeList->AppendColumn("Location", wxLIST_FORMAT_LEFT, 100);
    // m_storeList->AppendColumn("Products", wxLIST_FORMAT_RIGHT, 80);
    // m_storeList->AppendColumn("Customers", wxLIST_FORMAT_RIGHT, 80);

    // Populate stores
    for (size_t i = 0; i < stores.size(); ++i) {
        Store* store = stores[i];
        long index = m_storeList->InsertItem(i, store->GetStoreId());
        m_storeList->SetItem(index, 1, store->GetStoreName());
       m_storeList->SetItem(index, 2, store->GetStoreAddress());
      // m_storeList->SetItem(index, 3, wxString::Format("%d", ));
      //  m_storeList->SetItem(index, 4, wxString::Format("%d", store->GetCustomerCount()));

       
        m_storeList->SetItemPtrData(index, reinterpret_cast<wxUIntPtr>(store));

        // Alternate row colors
        if (i % 2 == 0) {
            m_storeList->SetItemBackgroundColour(index, wxColour(240, 240, 240));
        }
    }

    // Bind selection event
    m_storeList->Bind(wxEVT_LIST_ITEM_SELECTED, &DashboardAdmin::OnStoreSelected, this);

    sizer->Add(m_storeList, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 10);
    parent->SetSizer(sizer);
}

void DashboardAdmin::CreateDetailsPanel(wxPanel* parent)
{
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    // Title
    wxStaticText* title = new wxStaticText(parent, wxID_ANY, "STORE DETAILS");
    title->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    sizer->Add(title, 0, wxALL, 10);

    // Details will be updated when store is selected
    m_storeDetails = new wxStaticText(parent, wxID_ANY,
        "Select a store from the list to view details");
    m_storeDetails->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    sizer->Add(m_storeDetails, 0, wxALL, 20);

    // Add some space for future details
    sizer->AddStretchSpacer();
    parent->SetSizer(sizer);
}

void DashboardAdmin::CreateButtonPanel(wxBoxSizer* mainSizer)
{
    wxPanel* buttonPanel = new wxPanel(this);
    buttonPanel->SetBackgroundColour(wxColour(220, 230, 240));

    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    // View Products Button
    wxButton* productsBtn = new wxButton(buttonPanel, ID_ViewProducts, "View Products");
    productsBtn->SetBackgroundColour(wxColour(70, 160, 70));
    productsBtn->SetForegroundColour(*wxWHITE);
    buttonSizer->Add(productsBtn, 0, wxALL, 5);

    // View Store Button
    wxButton* storeBtn = new wxButton(buttonPanel, ID_ViewStore, "View Store");
    storeBtn->SetBackgroundColour(wxColour(60, 120, 200));
    storeBtn->SetForegroundColour(*wxWHITE);
    buttonSizer->Add(storeBtn, 0, wxALL, 5);

    // View Customers Button
    wxButton* customersBtn = new wxButton(buttonPanel, ID_ViewCustomers, "View Customers");
    customersBtn->SetBackgroundColour(wxColour(180, 80, 50));
    customersBtn->SetForegroundColour(*wxWHITE);
    buttonSizer->Add(customersBtn, 0, wxALL, 5);

    buttonSizer->AddStretchSpacer();

    // Logout Button
    wxButton* logoutBtn = new wxButton(buttonPanel, ID_LogoutButton, "Logout");
    logoutBtn->SetBackgroundColour(wxColour(200, 60, 60));
    logoutBtn->SetForegroundColour(*wxWHITE);
    buttonSizer->Add(logoutBtn, 0, wxALL, 5);

    // Bind button events
    productsBtn->Bind(wxEVT_BUTTON, &DashboardAdmin::OnViewProducts, this);
    storeBtn->Bind(wxEVT_BUTTON, &DashboardAdmin::OnViewStore, this);
    customersBtn->Bind(wxEVT_BUTTON, &DashboardAdmin::OnViewCustomers, this);
    logoutBtn->Bind(wxEVT_BUTTON, &DashboardAdmin::OnLogout, this);

    buttonPanel->SetSizer(buttonSizer);
    mainSizer->Add(buttonPanel, 0, wxEXPAND);
}

int DashboardAdmin::GetTotalProducts() const
{
    int total = 0;
    for (int i = 0; i < stores.size();i++) {
        total += stores.at(i)->GetProductSize();
    }
    return total;
}

void DashboardAdmin::OnStoreSelected(wxListEvent& event)
{
   
}

void DashboardAdmin::OnViewProducts(wxCommandEvent& event)
{
    // Implement product view functionality
    wxMessageBox("View Products clicked", "Info", wxOK | wxICON_INFORMATION);
}

void DashboardAdmin::OnViewStore(wxCommandEvent& event)
{
    // Implement store view functionality
    wxMessageBox("View Store clicked", "Info", wxOK | wxICON_INFORMATION);
}

void DashboardAdmin::OnViewCustomers(wxCommandEvent& event)
{
    // Implement customer view functionality
    wxMessageBox("View Customers clicked", "Info", wxOK | wxICON_INFORMATION);
}

void DashboardAdmin::OnLogout(wxCommandEvent& event)
{
    // Implement logout functionality
    wxMessageBox("Logout clicked", "Info", wxOK | wxICON_INFORMATION);
    // Typically you would close this panel and show login panel
}