#include "ViewCartPanel.h"

ViewCartPanel::ViewCartPanel(wxWindow* parent)
    : wxPanel(parent, wxID_ANY), m_totalPrice(0)
{
    CreateControls();
}

void ViewCartPanel::CreateControls()
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* title = new wxStaticText(this, wxID_ANY, "Your Shopping Cart");
    title->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    mainSizer->Add(title, 0, wxALL, 10);

    m_cartList = new wxListCtrl(this, wxID_ANY,
        wxDefaultPosition, wxDefaultSize,
        wxLC_REPORT | wxLC_SINGLE_SEL);
    m_cartList->AppendColumn("Product", wxLIST_FORMAT_LEFT, 200);
    m_cartList->AppendColumn("Price", wxLIST_FORMAT_RIGHT, 100);
    m_cartList->AppendColumn("Category", wxLIST_FORMAT_LEFT, 150);
    mainSizer->Add(m_cartList, 1, wxEXPAND | wxLEFT | wxRIGHT, 10);

    wxStaticBox* paymentBox = new wxStaticBox(this, wxID_ANY, "Payment Information");
    wxStaticBoxSizer* paymentSizer = new wxStaticBoxSizer(paymentBox, wxVERTICAL);

    m_cardInfoText = new wxStaticText(this, wxID_ANY, "Card: Not set");
    paymentSizer->Add(m_cardInfoText, 0, wxALL, 5);
    mainSizer->Add(paymentSizer, 0, wxEXPAND | wxALL, 10);

    wxBoxSizer* totalSizer = new wxBoxSizer(wxHORIZONTAL);
    totalSizer->Add(new wxStaticText(this, wxID_ANY, "Total:"), 0, wxALIGN_CENTER_VERTICAL);
    totalSizer->AddSpacer(10);

    m_totalText = new wxStaticText(this, wxID_ANY, "Rs 0");
    m_totalText->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    totalSizer->Add(m_totalText, 0, wxALIGN_CENTER_VERTICAL);

    mainSizer->Add(totalSizer, 0, wxALIGN_RIGHT | wxRIGHT | wxBOTTOM, 15);
    // Buttons
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    wxButton* backButton = new wxButton(this, ID_BackCart, "Back");
    wxButton* deleteButton = new wxButton(this, ID_DeleteCart, "Delete");
    wxButton* refreshButton = new wxButton(this, ID_RefreshCart, "Refresh");
    wxButton* proceedButton = new wxButton(this, ID_ProceedCart, "Proceed");

    buttonSizer->Add(backButton, 0, wxALL, 5);
    buttonSizer->Add(deleteButton, 0, wxALL, 5);
    buttonSizer->Add(refreshButton, 0, wxALL, 5);
    buttonSizer->AddStretchSpacer(); 
    buttonSizer->Add(proceedButton, 0, wxALL, 5);

    mainSizer->Add(buttonSizer, 0, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 10);

    SetSizer(mainSizer);

    refreshButton->Bind(wxEVT_BUTTON, &ViewCartPanel::OnRefreshClicked, this);

}

void ViewCartPanel::SetCartItems(const MyVector<Product*>& items)
{
    m_products = items;
    m_cartList->DeleteAllItems();

    for (int i = 0; i < m_products.size(); i++) {
        long index = m_cartList->InsertItem(i, m_products.at(i)->getProductName());
        m_cartList->SetItem(index, 1, wxString::Format("Rs %d", m_products.at(i)->getPrice()));
        m_cartList->SetItem(index, 2, m_products.at(i)->getProductCategory().ToCharArray());
        m_cartList->SetItemData(index, i);
    }
    UpdateTotal();
}

void ViewCartPanel::SetPaymentInfo(const MyString& cardNumber, const MyString& cardHolderName,
    const Date& expiryDate, const MyString& cvv)
{
    m_cardNumber = cardNumber;
    m_cardHolderName = cardHolderName;
    m_expiryDate = expiryDate;
    m_cvv = cvv;

    MyString maskedCard = "**** **** **** ";
    maskedCard.AppendArray(wxString(m_cardNumber.ToCharArray()).Right(4));

    MyString TempString = "Card: ";
    TempString.AppendArray(maskedCard);
    TempString.AppendArray("(");
    TempString.AppendArray(cardHolderName);
    TempString.AppendArray(")");
    m_cardInfoText->SetLabel(TempString);
}

void ViewCartPanel::UpdateTotal()
{
    m_totalPrice = 0;
    for (int i = 0; i < m_products.size(); i++) {
        m_totalPrice += m_products.at(i)->getPrice();
    }
    m_totalText->SetLabel(wxString::Format("Rs %d", m_totalPrice));
}

void ViewCartPanel::AddProducts(Product*& prod)
{
    m_products.push(prod);
    
}

Cart*& ViewCartPanel::GetCart()
{
    Cart* cart = new Cart(
       new Payment(m_cardNumber, m_cardHolderName, m_expiryDate, m_cvv),
        m_products, m_totalPrice
    );
    return cart;
}

void ViewCartPanel::SetProductsCart(MyVector<Product*> prods)
{
    m_products = prods;
}


void ViewCartPanel::OnRefreshClicked(wxCommandEvent& event) {

    SetCartItems(m_products);
    UpdateTotal();
}

ViewCartPanel::~ViewCartPanel()
{
    m_products.clear();
}
