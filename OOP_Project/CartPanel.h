#pragma once
#include"wx/wx.h"
#include <wx/listctrl.h>
#include "Cart.h"
#include "MyVector.h"

class CartPanel :
    public wxPanel
{
private:
    MyVector<Cart**> carts;
    wxListCtrl* m_cartListCtrl;
    wxButton* m_checkoutButton;
    wxButton* m_removeButton;
    wxButton* m_clearButton;
    wxStaticText* m_totalPriceLabel;
};

