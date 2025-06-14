#include "OrderPanel.h"
#include <numbers>


OrderPanel::OrderPanel(wxWindow* parent, Order*& order)
    : wxPanel(parent, wxID_ANY),
    m_order(order),
    m_status("Pending"),
    m_orderDate(CurrentDate()),
    m_deliveryDate(CurrentDateAddDays(7)),
    m_totalPrice(0),
    loginpanel(loginPanel::GetInstance(parent))
{
    CreateControls();
    
}
Date OrderPanel::CurrentDate()
{
    wxDateTime now = wxDateTime::Now();

    int day = now.GetDay();
    int month = now.GetMonth() + 1;
    int year = now.GetYear();
    return Date(day, month, year);

}
Date OrderPanel::CurrentDateAddDays(int n)
{
    wxDateTime now = wxDateTime::Now();
    wxDateTime future = now.Add(wxDateSpan::Days(n));

    int day = future.GetDay();
    int month = static_cast<int>(future.GetMonth()) + 1;
    int year = future.GetYear();

    return Date(day, month, year);
}

void OrderPanel::CreateControls()
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* title = new wxStaticText(this, wxID_ANY, "Place Order");
    title->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    mainSizer->Add(title, 0, wxALL, 10);

    wxStaticBox* combinedBox = new wxStaticBox(this, wxID_ANY, " Shipping & Payment Information");
    wxStaticBoxSizer* combinedSizer = new wxStaticBoxSizer(combinedBox, wxHORIZONTAL);

    wxBoxSizer* addressSideSizer = new wxBoxSizer(wxVERTICAL);
    wxStaticText* addressLabel = new wxStaticText(this, wxID_ANY, "Shipping Address");
    addressLabel->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    addressSideSizer->Add(addressLabel, 0, wxBOTTOM, 5);

    wxFlexGridSizer* addressGrid = new wxFlexGridSizer(2, 5, 15);
    addressGrid->AddGrowableCol(1);

    addressGrid->Add(new wxStaticText(this, wxID_ANY, "House Number:"), 0, wxALIGN_CENTER_VERTICAL);
    m_addressHouse = new wxTextCtrl(this, wxID_ANY);
    addressGrid->Add(m_addressHouse, 1, wxEXPAND);

    addressGrid->Add(new wxStaticText(this, wxID_ANY, "City:"), 0, wxALIGN_CENTER_VERTICAL);
    m_addressCity = new wxTextCtrl(this, wxID_ANY);
    addressGrid->Add(m_addressCity, 1, wxEXPAND);

    addressGrid->Add(new wxStaticText(this, wxID_ANY, "Province:"), 0, wxALIGN_CENTER_VERTICAL);
    m_addressProvince = new wxTextCtrl(this, wxID_ANY);
    addressGrid->Add(m_addressProvince, 1, wxEXPAND);

    addressGrid->Add(new wxStaticText(this, wxID_ANY, "Country:"), 0, wxALIGN_CENTER_VERTICAL);
    m_addressCountry = new wxTextCtrl(this, wxID_ANY);
    addressGrid->Add(m_addressCountry, 1, wxEXPAND);

    addressSideSizer->Add(addressGrid, 1, wxEXPAND);
    combinedSizer->Add(addressSideSizer, 1, wxEXPAND | wxALL, 10);

    wxStaticLine* verticalLine = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(2, -1), wxLI_VERTICAL);
    combinedSizer->Add(verticalLine, 0, wxEXPAND | wxTOP | wxBOTTOM, 10);

    wxBoxSizer* paymentSideSizer = new wxBoxSizer(wxVERTICAL);
    wxStaticText* paymentLabel = new wxStaticText(this, wxID_ANY, "Payment Information");
    paymentLabel->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    paymentSideSizer->Add(paymentLabel, 0, wxBOTTOM, 5);

    wxFlexGridSizer* paymentGrid = new wxFlexGridSizer(2, 5, 15);
    paymentGrid->AddGrowableCol(1);

    paymentGrid->Add(new wxStaticText(this, wxID_ANY, "Card Number:"), 0, wxALIGN_CENTER_VERTICAL);
    m_cardNumber = new wxTextCtrl(this, wxID_ANY);
    paymentGrid->Add(m_cardNumber, 1, wxEXPAND);

    paymentGrid->Add(new wxStaticText(this, wxID_ANY, "Card Holder:"), 0, wxALIGN_CENTER_VERTICAL);
    m_cardHolder = new wxTextCtrl(this, wxID_ANY);
    paymentGrid->Add(m_cardHolder, 1, wxEXPAND);

    paymentGrid->Add(new wxStaticText(this, wxID_ANY, "Expiry Date:"), 0, wxALIGN_CENTER_VERTICAL);
    wxBoxSizer* expirySizer = new wxBoxSizer(wxHORIZONTAL);
    m_cardExpiryMonth = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(40, -1));
    m_cardExpiryYear = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(60, -1));
    expirySizer->Add(m_cardExpiryMonth, 0, wxRIGHT, 5);
    expirySizer->Add(new wxStaticText(this, wxID_ANY, "/"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
    expirySizer->Add(m_cardExpiryYear, 0);
    paymentGrid->Add(expirySizer, 0);

    paymentGrid->Add(new wxStaticText(this, wxID_ANY, "CVV:"), 0, wxALIGN_CENTER_VERTICAL);
    m_cardCVV = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(60, -1));
    paymentGrid->Add(m_cardCVV, 0);

    paymentSideSizer->Add(paymentGrid, 1, wxEXPAND);
    combinedSizer->Add(paymentSideSizer, 1, wxEXPAND | wxALL, 10);

    mainSizer->Add(combinedSizer, 0, wxEXPAND | wxALL, 10);

    wxStaticBox* summaryBox = new wxStaticBox(this, wxID_ANY, "Order Summary");
    wxStaticBoxSizer* summarySizer = new wxStaticBoxSizer(summaryBox, wxVERTICAL);

    m_orderSummary = new wxStaticText(this, wxID_ANY, "No cart selected");
    summarySizer->Add(m_orderSummary, 0, wxALL, 10);

    wxFlexGridSizer* infoGrid = new wxFlexGridSizer(2, 10, 15);
    infoGrid->Add(new wxStaticText(this, wxID_ANY, "Status:"), 0, wxALIGN_CENTER_VERTICAL);
    infoGrid->Add(new wxStaticText(this, wxID_ANY, m_status), 0, wxALIGN_CENTER_VERTICAL);

    infoGrid->Add(new wxStaticText(this, wxID_ANY, "Order Date:"), 0, wxALIGN_CENTER_VERTICAL);
    infoGrid->Add(new wxStaticText(this, wxID_ANY, m_orderDate.ToString()), 0, wxALIGN_CENTER_VERTICAL);

    infoGrid->Add(new wxStaticText(this, wxID_ANY, "Estimated Delivery:"), 0, wxALIGN_CENTER_VERTICAL);
    infoGrid->Add(new wxStaticText(this, wxID_ANY, m_deliveryDate.ToString()), 0, wxALIGN_CENTER_VERTICAL);

    summarySizer->Add(infoGrid, 0, wxEXPAND | wxALL, 10);
    mainSizer->Add(summarySizer, 0, wxEXPAND | wxALL, 10);

    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    wxButton* backBtn = new wxButton(this, ID_BackButtonOP, "Back");
    wxButton* refreshBtn = new wxButton(this, ID_RefreshListOP, "Refresh");
    wxButton* cancelBtn = new wxButton(this, ID_CancelOrderOP, "Cancel");
    wxButton* placeOrderBtn = new wxButton(this, ID_PlaceOrderOP, "Place Order");


    buttonSizer->Add(backBtn, 0, wxALL, 5);
    buttonSizer->Add(refreshBtn, 0, wxALL, 5);
    buttonSizer->Add(cancelBtn, 0, wxALL, 5);
    buttonSizer->AddStretchSpacer();
    buttonSizer->Add(placeOrderBtn, 0, wxALL, 5);

    refreshBtn->Bind(wxEVT_BUTTON, &OrderPanel::OnRefreshList, this);
    
    mainSizer->Add(buttonSizer, 0, wxEXPAND | wxALL, 10);

    SetSizer(mainSizer);

}

void OrderPanel::RefreshCart(Cart* userCart)
{
    m_order->SetCart(*userCart);
    m_totalPrice = 0;
    for (int i = 0; i < userCart->GetPoducts().size(); i++) {
        m_totalPrice += m_order->GetCart()->GetPoducts().at(i)->getPrice();
    }
    m_order->SetPrice(m_totalPrice);

    if (m_order->GetCart()) {
        UpdateOrderSummary();
    }
    else {
        m_orderSummary->SetLabel("No cart found");
    }
}
void OrderPanel::UpdateOrderSummary()
{
    Cart* cart = m_order->GetCart();
    int items = m_order->GetCart()->GetPoducts().size();
    if (cart) {
        m_totalPrice = 0;
        for (int i = 0; i < items; i++) {
            m_totalPrice += m_order->GetCart()->GetPoducts().at(i)->getPrice();
        }
        wxString summary = wxString::Format(
            "Items: %d\nTotal Price: Rs %d",
            items, m_totalPrice );
        

        m_orderSummary->SetLabel(summary);
    }
    else {
        m_orderSummary->SetLabel("No cart found");
    }
}

void OrderPanel::SetCartOrderPanel(Cart* cart)
{
    m_order->SetCart(*cart);
    itemCount = cart->GetProductCount();
}

Order* OrderPanel::ValidateOrder()
{
    if (!m_order->GetCart()) {
        wxMessageBox("No Cart!", "Error", wxOK | wxICON_ERROR);
        return nullptr;
    }
    if (m_addressHouse->GetValue().IsEmpty() ||
        m_addressCity->GetValue().IsEmpty() ||
        m_addressCountry->GetValue().IsEmpty()) {
        wxMessageBox("Please fill in all required address fields", "Error", wxOK | wxICON_ERROR);
        return nullptr;
    }

    if (m_cardNumber->GetValue().IsEmpty() ||
        m_cardHolder->GetValue().IsEmpty() ||
        m_cardCVV->GetValue().IsEmpty()) {
        wxMessageBox("Please fill in all payment information", "Error", wxOK | wxICON_ERROR);
        return nullptr;
    }

    m_order->SetDeliveryDate(m_deliveryDate);
    m_order->SetStatus("pending");
    m_order->SetOrderDate(m_orderDate);
    m_order->SetPrice(0);
    m_order->SetShippingAddress(
        Address(m_addressHouse->GetValue(),
            m_addressCity->GetValue(),
            m_addressProvince->GetValue(),
            m_addressCountry->GetValue()
        )
    );
    return m_order;
}

void OrderPanel::OnCancelOrder(wxCommandEvent& event)
{
    UpdateOrderSummary();
}

void OrderPanel::OnBack(wxCommandEvent& event)
{
    wxCommandEvent backEvent(wxEVT_BUTTON, ID_BackButtonOP);
    GetParent()->GetEventHandler()->ProcessEvent(backEvent);
}

void OrderPanel::OnRefreshList(wxCommandEvent& event)
{ 
    wxCommandEvent refreshEvent(wxEVT_BUTTON, ID_RefreshListOP);
    GetParent()->GetEventHandler()->ProcessEvent(refreshEvent);
}

Address OrderPanel::GetShippingAddress() const
{
    return Address(
        m_addressHouse->GetValue(),
        m_addressCity->GetValue(),
        m_addressProvince->GetValue(),
        m_addressCountry->GetValue()
    );
}

MyString OrderPanel::GetCardNumber() const 
{ 
    return m_cardNumber->GetValue(); 
}
MyString OrderPanel::GetCardHolderName() const 
{ 
    return m_cardHolder->GetValue(); 
}

Date OrderPanel::GetExpiryDate() const
{
    int month = MyString(m_cardExpiryMonth->GetValue()).StringToInt();
    int year = MyString(m_cardExpiryYear->GetValue()).StringToInt();
    return Date(0,month, year);
}

MyString OrderPanel::GetCVV() const 
{ 
    return m_cardCVV->GetValue(); 
}