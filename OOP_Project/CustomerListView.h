#pragma once
#include <wx/wx.h>
#include <wx/listctrl.h>
#include "Classic.h" 

class CustomerListView : public wxListView 
{
private:
    MyVector<Customer*> m_customers;
public:
    CustomerListView(wxWindow* parent, MyVector<Customer*> customers);
    void RefreshList();
};