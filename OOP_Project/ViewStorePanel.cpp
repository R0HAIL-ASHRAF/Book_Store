#include "ViewStorePanel.h"


ViewStorePanel::ViewStorePanel(wxWindow* parent, StoreManager* storeManager)
    : wxPanel(parent, wxID_ANY), storeManager(storeManager), 
    rightClickedIndex{-1}, orders{MyVector<Order*>()}, 
    admin{Admin::GetInstance(parent)}, tempOrder{nullptr}
{
    SetupUI();
  
}

void ViewStorePanel::SetStore(StoreManager*& store)
{
    storeManager = store;
}

MyString ViewStorePanel::GetBookFileName()
{
    return storeManager->GetStore()->GetBookFileName();
}

MyString ViewStorePanel::GetStationaryFileName()
{
    return storeManager->GetStore()->GetStatFileName();
}

ViewStorePanel::~ViewStorePanel()
{
    delete storeManager;
    orders.clear();
}


void ViewStorePanel::SetupUI()
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    wxScrolledWindow* scrolledWindow = new wxScrolledWindow(this, wxID_ANY);
    scrolledWindow->SetScrollRate(10, 10);
    wxBoxSizer* scrollSizer = new wxBoxSizer(wxVERTICAL);
    scrolledWindow->SetSizer(scrollSizer);

    wxStaticText* header = new wxStaticText(scrolledWindow, wxID_ANY, "STORE DETAILS");
    header->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    header->SetForegroundColour(wxColour(50, 100, 180));
    scrollSizer->Add(header, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 15);

    wxStaticBox* megaStoreBox = new wxStaticBox(scrolledWindow, wxID_ANY, "");
    wxStaticBoxSizer* megaStoreSizer = new wxStaticBoxSizer(megaStoreBox, wxVERTICAL);



    // store box

    wxStaticBox* storeBox = new wxStaticBox(scrolledWindow, wxID_ANY, "Store Information");
    wxStaticBoxSizer* storeSizer = new wxStaticBoxSizer(storeBox, wxVERTICAL);

    wxFlexGridSizer* storeGrid = new wxFlexGridSizer(2, 10, 15);
    storeGrid->AddGrowableCol(1, 1);

    wxStaticText* storeIdLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Store ID:");
    storeIdLabel->SetFont(storeIdLabel->GetFont().Bold());
    storeGrid->Add(storeIdLabel, 0, wxALIGN_CENTER_VERTICAL | wxLEFT, 5);

    storeIdText = new wxStaticText(scrolledWindow, wxID_ANY, storeManager->GetStore()->GetStoreId());
    storeGrid->Add(storeIdText, 1, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);

    wxStaticText* storeNameLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Store Name:");
    storeNameLabel->SetFont(storeNameLabel->GetFont().Bold());
    storeGrid->Add(storeNameLabel, 0, wxALIGN_CENTER_VERTICAL | wxLEFT, 5);

    storeNameText = new wxStaticText(scrolledWindow, wxID_ANY, storeManager->GetStore()->GetStoreName());
    storeGrid->Add(storeNameText, 1, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);

    wxStaticText* addressLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Address:");
    addressLabel->SetFont(addressLabel->GetFont().Bold());
    storeGrid->Add(addressLabel, 0, wxALIGN_TOP | wxLEFT, 5);

    addressText = new wxStaticText(scrolledWindow, wxID_ANY, storeManager->GetStore()->GetStoreAddress(), wxDefaultPosition, wxDefaultSize, wxST_ELLIPSIZE_END);
    storeGrid->Add(addressText, 1, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);

    wxStaticText* productCountLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Products Available:");
    productCountLabel->SetFont(productCountLabel->GetFont().Bold());
    storeGrid->Add(productCountLabel, 0, wxALIGN_CENTER_VERTICAL | wxLEFT, 5);

    productCountText = new wxStaticText(scrolledWindow, wxID_ANY, MyString(storeManager->GetStore()->GetProductSize()));
    storeGrid->Add(productCountText, 1, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);

    storeSizer->Add(storeGrid, 0, wxEXPAND | wxALL, 10);


    // manager box 

    wxStaticBox* managerBox = new wxStaticBox(scrolledWindow, wxID_ANY, "Manager Details");
    wxStaticBoxSizer* managerSizer = new wxStaticBoxSizer(managerBox, wxVERTICAL);

    wxFlexGridSizer* managerGrid = new wxFlexGridSizer(2, 10, 15);
    managerGrid->AddGrowableCol(1, 1);

    wxStaticText* managerNameLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Manager Name:");
    managerNameLabel->SetFont(managerNameLabel->GetFont().Bold());
    managerGrid->Add(managerNameLabel, 0, wxALIGN_CENTER_VERTICAL | wxLEFT, 5);

    managerNameText = new wxStaticText(scrolledWindow, wxID_ANY, storeManager->GetName().ToString());
    managerGrid->Add(managerNameText, 1, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);

    wxStaticText* emailLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Email:");
    emailLabel->SetFont(emailLabel->GetFont().Bold());
    managerGrid->Add(emailLabel, 0, wxALIGN_CENTER_VERTICAL | wxLEFT, 5);

    emailText = new wxStaticText(scrolledWindow, wxID_ANY, storeManager->GetEmail());
    managerGrid->Add(emailText, 1, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);

    wxStaticText* usernameLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Username:");
    usernameLabel->SetFont(usernameLabel->GetFont().Bold());
    managerGrid->Add(usernameLabel, 0, wxALIGN_CENTER_VERTICAL | wxLEFT, 5);

    usernameText = new wxStaticText(scrolledWindow, wxID_ANY, storeManager->getUserName());
    managerGrid->Add(usernameText, 1, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);

    

    managerSizer->Add(managerGrid, 0, wxEXPAND | wxALL, 10);
    megaStoreSizer->Add(storeSizer, 1, wxEXPAND);
    megaStoreSizer->Add(managerSizer, 1, wxEXPAND);

    
    // order box

    wxStaticBox* orderBox = new wxStaticBox(scrolledWindow, wxID_ANY, "Orders");
    wxStaticBoxSizer* orderBoxSizer = new wxStaticBoxSizer(orderBox, wxVERTICAL);

    orderList = new wxListCtrl(scrolledWindow, wxID_ANY, wxDefaultPosition,
        wxSize(400, 200), wxLC_REPORT | wxLC_SINGLE_SEL | wxLC_HRULES | wxLC_VRULES);

    orderList->AppendColumn("No.", wxLIST_FORMAT_CENTER, 50);
    orderList->AppendColumn("Customer Name", wxLIST_FORMAT_LEFT, 180);
    orderList->AppendColumn("Price", wxLIST_FORMAT_CENTER, 50);
    orderList->AppendColumn("Status", wxLIST_FORMAT_CENTER, 80);
    orderList->AppendColumn("Date", wxLIST_FORMAT_CENTER, 80);
    orderList->AppendColumn("No. of Products", wxLIST_FORMAT_CENTER, 120);

    orderBoxSizer->Add(orderList, 1, wxEXPAND | wxALL, 10);

    wxBoxSizer* rowSizer = new wxBoxSizer(wxHORIZONTAL);

    rowSizer->Add(megaStoreSizer, 1, wxEXPAND | wxRIGHT, 10);
    rowSizer->Add(orderBoxSizer, 1, wxEXPAND);

    scrollSizer->Add(rowSizer, 0, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 15);
    // product box

    wxStaticBox* productsBox = new wxStaticBox(scrolledWindow, wxID_ANY, "Products");
    wxStaticBoxSizer* productsSizer = new wxStaticBoxSizer(productsBox, wxVERTICAL);

    productsList = new wxListCtrl(scrolledWindow, wxID_ANY,
        wxDefaultPosition, wxSize(-1, 200),
        wxLC_REPORT | wxLC_SINGLE_SEL | wxLC_HRULES | wxLC_VRULES);

    productsList->AppendColumn("ID", wxLIST_FORMAT_CENTRE, 80);
    productsList->AppendColumn("Name", wxLIST_FORMAT_CENTRE, 300);
    productsList->AppendColumn("Type", wxLIST_FORMAT_CENTRE, 100);
    productsList->AppendColumn("Price", wxLIST_FORMAT_CENTRE, 80);

    productsList->DeleteAllItems();
    MyVector<Product*> products;
    products = storeManager->GetStore()->GetProducts();

    for (int i = 0; i < products.size(); i++) {
        long index = productsList->InsertItem(i, products.at(i)->getProductID());
        productsList->SetItem(index, 1, products.at(i)->getProductName());
        productsList->SetItem(index, 2, products.at(i)->getProductCategory());
        productsList->SetItem(index, 3, wxString::Format("%d", products.at(i)->getPrice()));
        if (i % 2 == 0) {
            productsList->SetItemBackgroundColour(i, wxColour(255, 188, 217));

        }
    }

    productsSizer->Add(productsList, 1, wxEXPAND | wxALL, 10);
    scrollSizer->Add(productsSizer, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 15);

    wxPanel* buttonPanel = new wxPanel(this);

    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    wxButton* refreshBtn = new wxButton(buttonPanel, ID_RefreshBtnStoreView, "Refresh");
    wxButton* addProductBtn = new wxButton(buttonPanel, ID_AddProductBtnStoreView, "Add Book");
    wxButton* addStatBtn = new wxButton(buttonPanel, ID_AddStatBtnStoreView, "Add Stationary");
    wxButton* backBtn = new wxButton(buttonPanel, ID_BackViewStore, "back");


    refreshBtn->SetBackgroundColour(wxColour(219, 0, 107));
    refreshBtn->SetForegroundColour(*wxWHITE);
    refreshBtn->SetWindowStyle(wxBORDER_NONE);

    addProductBtn->SetBackgroundColour(wxColour(219, 0, 107));
    addProductBtn->SetForegroundColour(*wxWHITE);
    addProductBtn->SetWindowStyle(wxBORDER_NONE);

    addStatBtn->SetBackgroundColour(wxColour(219, 0, 107));
    addStatBtn->SetForegroundColour(*wxWHITE);
    addStatBtn->SetWindowStyle(wxBORDER_NONE);

    backBtn->SetBackgroundColour(wxColour(219, 0, 107));
    backBtn->SetForegroundColour(*wxWHITE);
    backBtn->SetWindowStyle(wxBORDER_NONE);

    buttonSizer->Add(refreshBtn, 0, wxALL, 5);
    buttonSizer->Add(addProductBtn, 0, wxALL, 5);
    buttonSizer->Add(addStatBtn, 0, wxALL, 5);
    buttonSizer->Add(backBtn, 0, wxALL, 5);
    buttonPanel->SetSizer(buttonSizer);

    mainSizer->Add(scrolledWindow, 1, wxEXPAND);
    mainSizer->Add(buttonPanel, 0, wxEXPAND);

    SetSizer(mainSizer);

    refreshBtn->Bind(wxEVT_BUTTON, &ViewStorePanel::OnRefresh, this);
    productsList->Bind(wxEVT_LIST_ITEM_RIGHT_CLICK, &ViewStorePanel::OnRightClickItem, this);
    //orderList->Bind(wxEVT_LIST_ITEM_RIGHT_CLICK, &ViewStorePanel::OnRighClickOrder, this);

}


void ViewStorePanel::UpdateStoreInfo()
{
    if (!storeManager)
        return;

    storeIdText->SetLabel(storeManager->GetStore()->GetStoreId());
    storeNameText->SetLabel(storeManager->GetStoreName());
    addressText->SetLabel(storeManager->GetStore()->GetStoreAddress());
    productCountText->SetLabel(wxString::Format("%d", storeManager->GetStore()->GetProducts().size()));

    managerNameText->SetLabel(storeManager->GetName().ToString());
    emailText->SetLabel(storeManager->GetEmail());
    usernameText->SetLabel(storeManager->getUserName());

    productsList->DeleteAllItems();
    MyVector<Product*> products;
    products = storeManager->GetStore()->GetProducts();

    for (int i = 0; i < products.size(); i++) {
        long index = productsList->InsertItem(i, products.at(i)->getProductID());
        productsList->SetItem(index, 1, products.at(i)->getProductName());
        productsList->SetItem(index, 2, products.at(i)->getProductCategory());
        productsList->SetItem(index, 3, wxString::Format("%d", products.at(i)->getPrice()));
        if (i % 2 == 0) {
            productsList->SetItemBackgroundColour(i, wxColour(255, 188, 217));

        }
    }
}

void ViewStorePanel::SetOrders(const MyVector<Order*>& order)
{
    orders.clear();
    orders = order;
}

void ViewStorePanel::UpdateStoreOrders()
{
    int k = 0;
    orders.clear();
    for (int i = 0; i < admin->GetCustomers().size(); i++) {

        for (int j = 0; j < admin->GetCustomers().at(i)->GetOrders().size(); j++) {
            orders.push(admin->GetCustomers().at(i)->GetOrders().at(j));

            long index = orderList->InsertItem(i, wxString::Format("%d", k + 1));
            orderList->SetItem(index, 1, admin->GetCustomers().at(i)->GetName().ToString());
            orderList->SetItem(index, 2, wxString::Format("%d", admin->GetCustomers().at(i)->GetOrders().at(j)->GetTotalPrice()));
            orderList->SetItem(index, 3, admin->GetCustomers().at(i)->GetOrders().at(j)->GetOrderStatus());
            orderList->SetItem(index, 4, admin->GetCustomers().at(i)->GetOrders().at(j)->GetOrderDate().ToString());
            orderList->SetItem(index, 5, wxString::Format("%d", admin->GetCustomers().at(i)->GetOrders().at(j)->GetCart()->GetPoducts().size()));
            k++;
            if (k % 2 == 0) {
                orderList->SetItemBackgroundColour(i, wxColour(255, 188, 217));

            }
        }
    }
}

void ViewStorePanel::OnRefresh(wxCommandEvent& event)
{
    UpdateStoreInfo();
}

void ViewStorePanel::OnRightClickItem(wxListEvent& event)
{
    rightClickedIndex = event.GetIndex();

    wxCommandEvent menuEvent(wxEVT_MENU, ID_RightClickViewStore);
    menuEvent.SetInt(rightClickedIndex);

    if (wxEvtHandler* parentHandler = GetParent()) {
        parentHandler->ProcessEvent(menuEvent);
    }
}
void ViewStorePanel::OnRighClickOrder(wxListEvent& event)
{
    int index = event.GetIndex();
    tempOrder = orders.at(index);
    wxMenu menu;
    menu.Append(ID_MarkAsDone, "Mark as done");
    Bind(wxEVT_MENU, &ViewStorePanel::MarkAsDone, this, ID_MarkAsDone);
    PopupMenu(&menu);
}
void ViewStorePanel::MarkAsDone(wxCommandEvent& event)
{
    int index = orderList->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
    if (index != -1)
    {
        tempOrder->SetStatus("delivered");
    }

}
void ViewStorePanel::OnDeleteItem(wxCommandEvent& event)
{
    if (rightClickedIndex != -1)
    {
        int confirm = wxMessageBox("Delete this product?", "Confirm Deletion", wxYES_NO | wxICON_QUESTION);
        if (confirm == wxYES)
        {
            productsList->DeleteItem(rightClickedIndex);
            storeManager->GetStore()->GetProducts().delete_at(rightClickedIndex);

        }
        rightClickedIndex = -1;
    }
}


void ViewStorePanel::SetMenuListIndex(int index)
{
    rightClickedIndex = index;

}

int ViewStorePanel::GetMenuListIndex()
{
    return rightClickedIndex;
}