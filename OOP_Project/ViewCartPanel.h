#pragma once
#include <wx/wx.h>
#include "MyString.h"
#include "Date.h"
#include "Product.h"
#include<wx/listctrl.h>
#include"MyVector.h"
#include"IDs.h"
#include"Cart.h"


class ViewCartPanel : public wxPanel
{
public:
    
    ViewCartPanel(wxWindow* parent);
    void SetCartItems(const MyVector<Product*>& items);
    void SetPaymentInfo(const MyString& cardNumber, const MyString& cardHolderName,
        const Date& expiryDate, const MyString& cvv);
    void UpdateTotal();
    void AddProducts(Product*& prod);
    Cart*& GetCart();
    void SetProductsCart(MyVector<Product*> prods);
    void OnRefreshClicked(wxCommandEvent& event);

    ~ViewCartPanel();

private:
    void CreateControls();
    void OnViewProduct(wxCommandEvent& event);

    wxListCtrl* m_cartList;
    wxStaticText* m_totalText;
    wxStaticText* m_cardInfoText;

    MyString m_cardNumber;
    MyString m_cardHolderName;
    Date m_expiryDate;
    MyString m_cvv;
    MyVector<Product*> m_products;
    int m_totalPrice;

   
};