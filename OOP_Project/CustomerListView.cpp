#include "CustomerListView.h"

CustomerListView::CustomerListView(wxWindow* parent, MyVector<Customer*> customers)
    : wxListView(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize,
        wxLC_REPORT | wxLC_SINGLE_SEL),
    m_customers(customers) {

    AppendColumn("ID", wxLIST_FORMAT_LEFT, 60);
    AppendColumn("Name", wxLIST_FORMAT_LEFT, 150);
    AppendColumn("Email", wxLIST_FORMAT_LEFT, 200);
    AppendColumn("Status", wxLIST_FORMAT_LEFT, 100);
    RefreshList();
}

void CustomerListView::RefreshList()  
{
    

    for (size_t i = 0; i < m_customers.size(); ++i) {
      
        long index = InsertItem(i, wxString::Format("%s", m_customers.at(i)->GetPersonType().ToCharArray()));
        SetItem(index, 1, m_customers.at(i)->getPassword());
        SetItem(index, 2, m_customers.at(i)->GetPersonType());
        SetItem(index, 3, m_customers.at(i)->getUserName());
       
        SetItemPtrData(index, reinterpret_cast<wxUIntPtr>(m_customers.at(i)));
        if (i % 2 == 0) {
            SetItemBackgroundColour(index, wxColour(240, 240, 240));
        }
    }
}