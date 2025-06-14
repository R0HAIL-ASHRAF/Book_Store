#pragma once

#include <wx/wx.h>
#include "MyString.h"
#include "Date.h"
#include "Order.h"
#include "Address.h"
#include"IDs.h"
#include <wx/statline.h>
#include"loginPanel.h"

class OrderPanel : public wxPanel
{
public:
    Order* m_order;
    loginPanel* loginpanel;

    MyString m_status;
    Date m_orderDate;
    Date m_deliveryDate;
    int m_totalPrice;

    OrderPanel(wxWindow* parent, Order*& order);
    Date CurrentDate();
    Date CurrentDateAddDays(int n);
    void RefreshCart(Cart* availableCarts);
    void RefreshOrder(Order*& order);
    
    // Getters
    Address GetShippingAddress() const;
    MyString GetCardNumber() const;
    MyString GetCardHolderName() const;
    Date GetExpiryDate() const;
    MyString GetCVV() const;
    Order* ValidateOrder();
    void UpdateOrderSummary();
    void SetCartOrderPanel(Cart* cart);

private:
    void CreateControls();
    void OnPlaceOrder(wxCommandEvent& event);
   
    void OnCancelOrder(wxCommandEvent& event);
    void OnBack(wxCommandEvent& event);
    void OnRefreshList(wxCommandEvent& event);
   

    // UI Controls

    wxTextCtrl* m_addressHouse;
    wxTextCtrl* m_addressStreet;
    wxTextCtrl* m_addressCity;
    wxTextCtrl* m_addressProvince;
    wxTextCtrl* m_addressCountry;
    wxTextCtrl* m_cardNumber;
    wxTextCtrl* m_cardHolder;
    wxTextCtrl* m_cardExpiryMonth;
    wxTextCtrl* m_cardExpiryYear;
    wxTextCtrl* m_cardCVV;
    wxStaticText* m_orderSummary;
    int itemCount;
    // Data
    

};