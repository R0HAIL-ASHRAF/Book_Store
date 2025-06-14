#pragma once

#include <wx/wx.h>
#include <wx/listctrl.h>
#include"Classic.h"
#include"Patreon.h"
#include"Premium.h"
#include"IDs.h"


class DisplayOrderPanel : public wxPanel {
public:
    Customer* customer;
    int indexMenuList;
    wxListCtrl* m_ordersList;
    DisplayOrderPanel(wxWindow* parent, Customer* customer);
    void RefreshOrders();
    void SetCustomer(Customer* cust);
    
private:
    
    wxButton* m_backBtn;
    wxButton* m_refreshBtn;
   
    void CreateControls();
    void PopulateOrdersList();
    void SetupContextMenu();
   
    void OnBack(wxCommandEvent& event);
    void OnRefresh(wxCommandEvent& event);
    void OnRightClickItem(wxListEvent& event);
    void OnDeleteOrder(wxCommandEvent& event);
    void OnViewOrder(wxCommandEvent& event);

};
