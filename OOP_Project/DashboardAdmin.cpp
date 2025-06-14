#include "DashboardAdmin.h"

DashboardAdmin::DashboardAdmin(wxWindow* parent)
    : wxPanel(parent, wxID_ANY),
    admin(Admin::GetInstance(parent)),
    stores(MyVector<StoreManager*>()),
    
    rightClickedIndex{-1}
{
    InitData();
    SetupUI();
}

void DashboardAdmin::SetupUI()
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    CreateHeader(mainSizer);

    mainSizer->Add(new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 1), wxLI_HORIZONTAL),
        0, wxEXPAND | wxTOP | wxBOTTOM, 10);

    wxBoxSizer* horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

    // Left panel
    wxPanel* storeListPanel = new wxPanel(this);
    CreateStoreList(storeListPanel);
   
    horizontalSizer->Add(storeListPanel, 1, wxEXPAND | wxALL, 5);

    // Right panel
    wxPanel* adminDetailsPanel = new wxPanel(this);
    wxBoxSizer* rightSizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* adminTitle = new wxStaticText(adminDetailsPanel, wxID_ANY, "ADMIN INFO");
    adminTitle->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    rightSizer->Add(adminTitle, 0, wxALL, 10);

    wxString nameStr = "Name: ";
    nameStr.append(admin->GetName().ToString());

    wxString emailStr = "Email: ";
    emailStr.append(admin->GetEmail());

    wxString usernameStr = "Username: ";
    usernameStr.append(admin->getUserName());

    wxStaticText* nameText = new wxStaticText(adminDetailsPanel, wxID_ANY, nameStr);
    wxStaticText* emailText = new wxStaticText(adminDetailsPanel, wxID_ANY, emailStr);
    wxStaticText* usernameText = new wxStaticText(adminDetailsPanel, wxID_ANY, usernameStr);

    rightSizer->Add(nameText, 0, wxALL, 5);
    rightSizer->Add(emailText, 0, wxALL, 5);
    rightSizer->Add(usernameText, 0, wxALL, 5);

    adminDetailsPanel->SetSizer(rightSizer);

    horizontalSizer->Add(adminDetailsPanel, 1, wxEXPAND | wxALL, 5);

    mainSizer->Add(horizontalSizer, 1, wxEXPAND);

    CreateButtonPanel(mainSizer);

    SetSizer(mainSizer);

}

void DashboardAdmin::InitData()
{
    admin->GetStores().clear();
    stores.clear();
    stores = admin->GetStores();   
}

void DashboardAdmin::CreateHeader(wxBoxSizer* mainSizer)
{
    wxPanel* headerPanel = new wxPanel(this);
    headerPanel->SetBackgroundColour(wxColour(170, 51, 106));

    wxBoxSizer* headerSizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* title = new wxStaticText(headerPanel, wxID_ANY, "ADMIN DASHBOARD");
    title->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    title->SetForegroundColour(*wxWHITE);

    headerSizer->Add(title, 0, wxALIGN_CENTER_VERTICAL | wxLEFT, 15);

    headerPanel->SetSizer(headerSizer);
    mainSizer->Add(headerPanel, 0, wxEXPAND);
}

void DashboardAdmin::CreateStoreList(wxPanel* parent)
{
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* title = new wxStaticText(parent, wxID_ANY, "STORES");
    title->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    sizer->Add(title, 0, wxALL, 10);

    m_storeList = new wxListView(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize,
        wxLC_REPORT | wxLC_SINGLE_SEL | wxLC_HRULES | wxLC_VRULES);

    m_storeList->AppendColumn("ID", wxLIST_FORMAT_LEFT, 80);
    m_storeList->AppendColumn("Name", wxLIST_FORMAT_LEFT, 100);
    m_storeList->AppendColumn("Store Name", wxLIST_FORMAT_LEFT, 100);
    m_storeList->AppendColumn("Products", wxLIST_FORMAT_LEFT, 100);
    m_storeList->AppendColumn("Location", wxLIST_FORMAT_LEFT, 200);

    for (int i = 0; i < stores.size(); ++i)
    {
        StoreManager* store = stores.at(i);
        if (!store) {
            wxLogWarning("StoreManager pointer is null at index %d", i);
            continue;
        }

        Store* storePtr = store->GetStore();
        if (!storePtr) {
            wxLogWarning("Store object is null at index %d", i);
            continue;
        }

        MyString storeId = storePtr->GetStoreId();
        MyString storeName = storePtr->GetStoreName();
        MyString storeAddress = storePtr->GetStoreAddress();

        MyString name;
        if (store->GetName().firstName.IsEmpty() && store->GetName().lastName.IsEmpty()) {
            name = "Unknown";
        }
        else {
            name = store->GetName().ToString();
        }

        int productSize = storePtr->GetProductSize();
        wxString productCount = wxString::Format("%d", productSize);

        long index = m_storeList->InsertItem(i, storeId);
        m_storeList->SetItem(index, 1, name);
        m_storeList->SetItem(index, 2, storeName);
        m_storeList->SetItem(index, 3, productCount);
        m_storeList->SetItem(index, 4, storeAddress);
        m_storeList->SetItemPtrData(index, reinterpret_cast<wxUIntPtr>(store));

        if (i % 2 == 0) {
            m_storeList->SetItemBackgroundColour(index, wxColour(240, 240, 240));
        }
    }

    m_storeList->Bind(wxEVT_LIST_ITEM_SELECTED, &DashboardAdmin::OnStoreSelected, this);
    m_storeList->Bind(wxEVT_LIST_ITEM_RIGHT_CLICK, &DashboardAdmin::OnRightClickItem, this);

    sizer->Add(m_storeList, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 10);
    parent->SetSizer(sizer);
}


void DashboardAdmin::CreateButtonPanel(wxBoxSizer* mainSizer)
{
    wxPanel* buttonPanel = new wxPanel(this);

    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
       
    wxButton* customersBtn = new wxButton(buttonPanel, ID_ViewCustomers, "View Customers");
    wxButton* addStoreBtn = new wxButton(buttonPanel, ID_AddStore, "Add Store");
    wxButton* logoutBtn = new wxButton(buttonPanel, ID_LogoutButtonAdmin, "Logout");
    wxButton* refreshBtn = new wxButton(buttonPanel, ID_RefreshBtnStoreManagers, "Refresh");

    buttonSizer->Add(customersBtn, 0, wxALL, 5);
    buttonSizer->Add(refreshBtn, 0, wxALL, 5);
    buttonSizer->Add(addStoreBtn, 0, wxALL, 5);
    buttonSizer->AddStretchSpacer();
    buttonSizer->Add(logoutBtn, 0, wxALL, 5);

    buttonPanel->SetSizer(buttonSizer);
    mainSizer->Add(buttonPanel, 0, wxEXPAND);
    refreshBtn->Bind(wxEVT_BUTTON, &DashboardAdmin::OnRefreshStoreList, this);
}

void DashboardAdmin::OnRefreshStoreList(wxCommandEvent& event)
{
   
    m_storeList->DeleteAllItems();
    admin->GetStores().clear();
    admin->ReadStoreManagersFromFile();

    stores.clear();
    stores = admin->GetStores();

    wxLogMessage("Refreshed: StoreManager count = %d", stores.size());

   
    for (int i = 0; i < stores.size(); ++i)
    {
        StoreManager* store = stores.at(i);
        long index = m_storeList->InsertItem(i, store->GetStore()->GetStoreId());
        m_storeList->SetItem(index, 1, store->GetName().ToString());
        m_storeList->SetItem(index, 2, store->GetStoreName());
        m_storeList->SetItem(index, 3, MyString(store->GetStore()->GetProducts().size()));
        m_storeList->SetItem(index, 4, store->GetStore()->GetStoreAddress());
        m_storeList->SetItemPtrData(index, reinterpret_cast<wxUIntPtr>(store));

        if (i % 2 == 0)
            m_storeList->SetItemBackgroundColour(index, wxColour(240, 240, 240));
    }
   
}

void DashboardAdmin::OnStoreSelected(wxListEvent& event)
{
   
}

int DashboardAdmin::GetMenuListIndex()
{
    return rightClickedIndex;
}

void DashboardAdmin::OnRightClickItem(wxListEvent& event) {
    rightClickedIndex = event.GetIndex();

    wxCommandEvent menuEvent(wxEVT_MENU, ID_RightClickDashboardAdmin);
    menuEvent.SetInt(rightClickedIndex);

    if (wxEvtHandler* parentHandler = GetParent()) {
        parentHandler->ProcessEvent(menuEvent);
    }
}

void DashboardAdmin::SetMenuListIndex(int index)
{
    rightClickedIndex = index;

}
MyString DashboardAdmin::GetAdminUserName() const
{
    return admin->getUserName();
}
MyString DashboardAdmin::GetAdminPassword() const
{
    return admin->getPassword();
}