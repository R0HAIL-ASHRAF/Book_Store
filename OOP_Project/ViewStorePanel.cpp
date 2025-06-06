#include "ViewStorePanel.h"


ViewStorePanel::ViewStorePanel(wxWindow* parent, StoreManager* storeManager)
    : wxPanel(parent, wxID_ANY), storeManager(storeManager)
{
    SetupUI();
    UpdateStoreInfo();
}

void ViewStorePanel::SetupUI()
{

  
    #include <wx/notebook.h> // Add this include to resolve wxNotebook type specifier error
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->AddSpacer(10);

    // Header with store name
    wxStaticText* header = new wxStaticText(this, wxID_ANY, "STORE DETAILS");
    header->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    header->SetForegroundColour(wxColour(50, 100, 180));
    mainSizer->Add(header, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

    // Create notebook for tabs
    wxNotebook* notebook = new wxNotebook(this, wxID_ANY);

    // Store Info Tab
    wxPanel* storeInfoTab = new wxPanel(notebook);
    CreateStoreInfoTab(storeInfoTab);

    // Manager Info Tab
    wxPanel* managerInfoTab = new wxPanel(notebook);
    CreateManagerInfoTab(managerInfoTab);

    // Products Tab
    wxPanel* productsTab = new wxPanel(notebook);
    CreateProductsTab(productsTab);

    notebook->AddPage(storeInfoTab, "Store Information");
    notebook->AddPage(managerInfoTab, "Manager Details");
    notebook->AddPage(productsTab, "Products");

    mainSizer->Add(notebook, 1, wxEXPAND | wxALL, 10);

    // Button panel
    wxPanel* buttonPanel = new wxPanel(this);
    buttonPanel->SetBackgroundColour(wxColour(220, 230, 240));

    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    wxButton* refreshBtn = new wxButton(buttonPanel, ID_RefreshBtnStoreView, "Refresh");
    wxButton* editBtn = new wxButton(buttonPanel, ID_EditBtnStoreView, "Edit Store");
    wxButton* addProductBtn = new wxButton(buttonPanel, ID_AddProductBtnStoreView, "Add Product");

    // Style buttons
    refreshBtn->SetBackgroundColour(wxColour(100, 150, 200));
    editBtn->SetBackgroundColour(wxColour(70, 160, 70));
    addProductBtn->SetBackgroundColour(wxColour(180, 80, 50));

    refreshBtn->SetForegroundColour(*wxWHITE);
    editBtn->SetForegroundColour(*wxWHITE);
    addProductBtn->SetForegroundColour(*wxWHITE);

    buttonSizer->Add(refreshBtn, 0, wxALL, 5);
    buttonSizer->Add(editBtn, 0, wxALL, 5);
    buttonSizer->Add(addProductBtn, 0, wxALL, 5);

    buttonPanel->SetSizer(buttonSizer);
    mainSizer->Add(buttonPanel, 0, wxEXPAND);

    SetSizer(mainSizer);

    // Bind events
    //refreshBtn->Bind(wxEVT_BUTTON, &ViewStorePanel::OnRefresh, this);
    //editBtn->Bind(wxEVT_BUTTON, &ViewStorePanel::OnEdit, this);
    //addProductBtn->Bind(wxEVT_BUTTON, &ViewStorePanel::OnAddProduct, this);
}

void ViewStorePanel::CreateStoreInfoTab(wxPanel* parent)
{
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    parent->SetSizer(sizer);

    wxFlexGridSizer* grid = new wxFlexGridSizer(2, 10, 15);
    grid->AddGrowableCol(1, 1);

    // Store ID
    grid->Add(new wxStaticText(parent, wxID_ANY, "Store ID:"), 0, wxALIGN_CENTER_VERTICAL | wxLEFT, 10);
    storeIdText = new wxStaticText(parent, wxID_ANY, "");
    grid->Add(storeIdText, 1, wxALIGN_CENTER_VERTICAL | wxRIGHT, 10);

    // Store Name
    grid->Add(new wxStaticText(parent, wxID_ANY, "Store Name:"), 0, wxALIGN_CENTER_VERTICAL | wxLEFT, 10);
    storeNameText = new wxStaticText(parent, wxID_ANY, "");
    grid->Add(storeNameText, 1, wxALIGN_CENTER_VERTICAL | wxRIGHT, 10);

    // Address
    grid->Add(new wxStaticText(parent, wxID_ANY, "Address:"), 0, wxALIGN_TOP | wxLEFT, 10);
    addressText = new wxStaticText(parent, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxST_ELLIPSIZE_END);
    grid->Add(addressText, 1, wxALIGN_CENTER_VERTICAL | wxRIGHT, 10);

    // Product Count
    grid->Add(new wxStaticText(parent, wxID_ANY, "Products Available:"), 0, wxALIGN_CENTER_VERTICAL | wxLEFT, 10);
    productCountText = new wxStaticText(parent, wxID_ANY, "");
    grid->Add(productCountText, 1, wxALIGN_CENTER_VERTICAL | wxRIGHT, 10);

    sizer->Add(grid, 0, wxEXPAND | wxALL, 15);
}

void ViewStorePanel::CreateManagerInfoTab(wxPanel* parent)
{
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    parent->SetSizer(sizer);

    wxFlexGridSizer* grid = new wxFlexGridSizer(2, 10, 15);
    grid->AddGrowableCol(1, 1);

    // Full Name
    grid->Add(new wxStaticText(parent, wxID_ANY, "Manager Name:"), 0, wxALIGN_CENTER_VERTICAL | wxLEFT, 10);
    managerNameText = new wxStaticText(parent, wxID_ANY, "");
    grid->Add(managerNameText, 1, wxALIGN_CENTER_VERTICAL | wxRIGHT, 10);

    // Email
    grid->Add(new wxStaticText(parent, wxID_ANY, "Email:"), 0, wxALIGN_CENTER_VERTICAL | wxLEFT, 10);
    emailText = new wxStaticText(parent, wxID_ANY, "");
    grid->Add(emailText, 1, wxALIGN_CENTER_VERTICAL | wxRIGHT, 10);

    // Login Info
    grid->Add(new wxStaticText(parent, wxID_ANY, "Username:"), 0, wxALIGN_CENTER_VERTICAL | wxLEFT, 10);
    usernameText = new wxStaticText(parent, wxID_ANY, "");
    grid->Add(usernameText, 1, wxALIGN_CENTER_VERTICAL | wxRIGHT, 10);

    // Birth Date
    grid->Add(new wxStaticText(parent, wxID_ANY, "Password:"), 0, wxALIGN_CENTER_VERTICAL | wxLEFT, 10);
    passwordText = new wxStaticText(parent, wxID_ANY, "");
    grid->Add(passwordText, 1, wxALIGN_CENTER_VERTICAL | wxRIGHT, 10);

    sizer->Add(grid, 0, wxEXPAND | wxALL, 15);
}

void ViewStorePanel::CreateProductsTab(wxPanel* parent)
{
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    parent->SetSizer(sizer);

    products = new ProductListView(parent, storeManager->GetStore()->GetProducts());
    sizer->Add(products, 1, wxEXPAND | wxALL, 10);
}

void ViewStorePanel::UpdateStoreInfo()
{
    if (!storeManager) 
        return;

    storeIdText->SetLabel(storeManager->GetStore()->GetStoreId());
    storeNameText->SetLabel(storeManager->GetStoreName());
    addressText->SetLabel(storeManager->GetStore()->GetStoreAddress());
    productCountText->SetLabel(wxString::Format("%d", storeManager->GetStore()->GetProducts().size()));

    // Manager Info
    managerNameText->SetLabel(storeManager->GetName().ToString());
    emailText->SetLabel(storeManager->GetEmail());
    usernameText->SetLabel(storeManager->getUserName());
    passwordText->SetLabel(storeManager->getPassword());

    //// Products
    //products->DeleteAllItems();
    //MyVector<Product*> products = storeManager->GetStore()->GetProducts();
    //for (size_t i = 0; i < products.size(); i++) {
    //    Product* p = products[i];
    //    long index = products.at(i)->InsertItem(i, p->GetProductId());
    //    m_productsList->SetItem(index, 1, p->GetProductName());
    //    m_productsList->SetItem(index, 2, p->GetProductType());
    //    m_productsList->SetItem(index, 3, wxString::Format("%.2f", p->GetPrice()));
    //}
}

void ViewStorePanel::OnRefresh(wxCommandEvent& event)
{
    UpdateStoreInfo();
    wxMessageBox("Store information refreshed!", "Info", wxOK | wxICON_INFORMATION);
}

void ViewStorePanel::OnEdit(wxCommandEvent& event)
{
    // TODO: Implement edit functionality
    wxMessageBox("Edit store functionality will be implemented here", "Info", wxOK | wxICON_INFORMATION);
}

void ViewStorePanel::OnAddProduct(wxCommandEvent& event)
{
    // TODO: Implement add product functionality
    wxMessageBox("Add product functionality will be implemented here", "Info", wxOK | wxICON_INFORMATION);
}