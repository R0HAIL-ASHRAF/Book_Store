#pragma once

#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/splitter.h>
#include <wx/statline.h>
#include "Admin.h"
#include "Store.h"
#include"IDs.h"

class DashboardAdmin : public wxPanel 
{

private:
    Admin* admin;
	MyVector<Store*> stores;
    wxListView* m_storeList;
    wxStaticText* m_statsText;
    wxStaticText* m_storeDetails;

    void InitData();
    void CreateHeader(wxBoxSizer* mainSizer);
    void CreateStoreList(wxPanel* parent);
    void CreateDetailsPanel(wxPanel* parent);
    void CreateButtonPanel(wxBoxSizer* mainSizer);

    int GetTotalProducts() const;

    void OnStoreSelected(wxListEvent& event);

    void OnViewProducts(wxCommandEvent& event);
    void OnViewStore(wxCommandEvent& event);
    void OnViewCustomers(wxCommandEvent& event);
    void OnLogout(wxCommandEvent& event);

public:
    DashboardAdmin(wxWindow* parent);

};
