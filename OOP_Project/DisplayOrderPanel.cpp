#include "DisplayOrderPanel.h"


DisplayOrderPanel::DisplayOrderPanel(wxWindow* parent, Customer* customer)
    : wxPanel(parent, wxID_ANY),
    customer{customer} , indexMenuList(-1)
{
    CreateControls();
    PopulateOrdersList();
}


void DisplayOrderPanel::CreateControls() {
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    wxPanel* infoPanel = new wxPanel(this, wxID_ANY);
    wxFlexGridSizer* infoSizer = new wxFlexGridSizer(2, 5, 15);

    infoSizer->Add(new wxStaticText(infoPanel, wxID_ANY, "Customer:"));
    infoSizer->Add(new wxStaticText(infoPanel, wxID_ANY, customer->GetName().ToString()));

    infoSizer->Add(new wxStaticText(infoPanel, wxID_ANY, "Email:"));
    infoSizer->Add(new wxStaticText(infoPanel, wxID_ANY, customer->GetEmail()));

    infoSizer->Add(new wxStaticText(infoPanel, wxID_ANY, "Type:"));
    infoSizer->Add(new wxStaticText(infoPanel, wxID_ANY, customer->GetPersonType()));

    infoPanel->SetSizer(infoSizer);
    mainSizer->Add(infoPanel, 0, wxEXPAND | wxALL, 10);

    m_ordersList = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
        wxLC_REPORT | wxLC_SINGLE_SEL | wxBORDER_SUNKEN);

    m_ordersList->InsertColumn(0, "Order ID", wxLIST_FORMAT_LEFT, 100);
    m_ordersList->InsertColumn(1, "Date", wxLIST_FORMAT_CENTER, 120);
    m_ordersList->InsertColumn(2, "Total", wxLIST_FORMAT_RIGHT, 100);
    m_ordersList->InsertColumn(3, "Status", wxLIST_FORMAT_CENTER, 100);
    m_ordersList->InsertColumn(4, "Shipping Address", wxLIST_FORMAT_CENTER, 250);

    mainSizer->Add(m_ordersList, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 10);

    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    m_backBtn = new wxButton(this, ID_BackDisplayOrder, "Back");
    m_refreshBtn = new wxButton(this, ID_RefreshDisplayOrder, "Refresh");

    buttonSizer->Add(m_backBtn, 0, wxALL, 5);
    buttonSizer->Add(m_refreshBtn, 0, wxALL, 5);

    mainSizer->Add(buttonSizer, 0, wxALIGN_RIGHT | wxRIGHT | wxBOTTOM, 10);

    SetSizer(mainSizer);

    m_refreshBtn->Bind(wxEVT_BUTTON, &DisplayOrderPanel::OnRefresh, this);
    m_ordersList->Bind(wxEVT_LIST_ITEM_RIGHT_CLICK, &DisplayOrderPanel::OnRightClickItem, this);

    SetupContextMenu();
}

void DisplayOrderPanel::PopulateOrdersList() {
   m_ordersList->DeleteAllItems();
   
   customer->ReadOrdersFromFile();

   MyVector<Order*> orders = customer->GetOrders();

    for (size_t i = 0; i < orders.size(); i++) {
        Order* order = orders.at(i);

        long index = m_ordersList->InsertItem(i, wxString::Format("%zu", i + 1));

        m_ordersList->SetItem(index, 1, order->GetOrderDate().ToString());

        m_ordersList->SetItem(index, 2,
            wxString::Format("Rs %d", static_cast<int>(order->GetTotalPrice())));

        m_ordersList->SetItem(index, 3, order->GetOrderStatus());
        m_ordersList->SetItem(index, 4, order->GetShippingAddress().ToString());

        m_ordersList->SetItemData(index, reinterpret_cast<wxUIntPtr>(order));
    }

}
void DisplayOrderPanel::SetCustomer(Customer* cust)
{
    if(cust == nullptr)
        return;
    customer = cust;
    
    PopulateOrdersList();
}

void DisplayOrderPanel::SetupContextMenu() {
    m_ordersList->Bind(wxEVT_CONTEXT_MENU, [this](wxContextMenuEvent& event){});
}

void DisplayOrderPanel::RefreshOrders() {
    PopulateOrdersList();
}

void DisplayOrderPanel::OnBack(wxCommandEvent& event) {
    wxWindow* parent = GetParent();
    if (parent) {
        parent->Close();
    }
}

void DisplayOrderPanel::OnRefresh(wxCommandEvent& event) {
    RefreshOrders();
}

void DisplayOrderPanel::OnRightClickItem(wxListEvent& event) {
    indexMenuList = event.GetIndex();

    wxCommandEvent menuEvent(wxEVT_MENU, ID_RightClickViewOrder);
    menuEvent.SetInt(indexMenuList);

    if (wxEvtHandler* parentHandler = GetParent()) {
        parentHandler->ProcessEvent(menuEvent);
    }
}