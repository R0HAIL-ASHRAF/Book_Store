#include "ProductListView.h"

ProductListView::ProductListView(wxWindow* parent,
    const MyVector<Product*>& products)
    : wxListView(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize,
        wxLC_REPORT | wxLC_SINGLE_SEL),
    m_products(products) {

    AppendColumn("ID", wxLIST_FORMAT_LEFT, 60);
    AppendColumn("Name", wxLIST_FORMAT_LEFT, 150);
    AppendColumn("Category", wxLIST_FORMAT_LEFT, 100);
    AppendColumn("Descrption", wxLIST_FORMAT_LEFT, 300);
    RefreshList();
}

void ProductListView::RefreshList()
{


    for (size_t i = 0; i < m_products.size(); ++i) {

        long index = InsertItem(i, wxString::Format("%s", m_products.at(i)->getProductID().ToCharArray()));
        SetItem(index, 1, m_products.at(i)->getProductName());
        SetItem(index, 2, m_products.at(i)->getProductCategory());
        SetItem(index, 3, m_products.at(i)->getDescription());
        
        SetItemPtrData(index, reinterpret_cast<wxUIntPtr>(m_products.at(i)));

        if (i % 2 == 0) {
            SetItemBackgroundColour(index, wxColour(240, 240, 240));
        }
    }
}