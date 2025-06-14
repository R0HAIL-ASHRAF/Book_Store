#pragma once

#include<wx/wx.h>
#include"Book.h"
#include"Stationary.h"
#include<wx/statline.h>
#include "MyVector.h"
#include <wx/artprov.h>
#include"IDs.h"

class DashboardUser : public wxPanel {
public:
    DashboardUser(wxWindow* parent);
    void SetProducts(const MyVector<Product*>& prods);

private:
    void CreateControls();
    void LoadProducts();
    wxPanel* CreateProductPanel(wxWindow* parent, const Product& product);
    void SetupButtonSizer();

    MyVector<Product*> m_products;
    wxScrolledWindow* m_productsScroller;
    wxBoxSizer* m_mainSizer;
};