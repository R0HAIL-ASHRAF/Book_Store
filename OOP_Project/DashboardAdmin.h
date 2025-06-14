#pragma once

#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/splitter.h>
#include <wx/statline.h>
#include "Admin.h"
#include "StoreManager.h"
#include"IDs.h"
#include "ViewStorePanel.h"


class DashboardAdmin : public wxPanel
{

private:
    Admin* admin;
    int rightClickedIndex;
	
   
    wxStaticText* m_statsText;
    wxStaticText* m_storeDetails;

    void SetupUI();
    void InitData();
    void CreateHeader(wxBoxSizer* mainSizer);
    void CreateStoreList(wxPanel* parent);
    void CreateButtonPanel(wxBoxSizer* mainSizer);

public:
    void OnRefreshStoreList(wxCommandEvent& event);
    int GetMenuListIndex();
    void OnRightClickItem(wxListEvent& event);
    void OnDeleteItem(wxCommandEvent& event);
    void SetMenuListIndex(int index);
    wxListView* m_storeList;
    MyVector<StoreManager*> stores;
    DashboardAdmin(wxWindow* parent);
    MyString GetAdminUserName() const;
    MyString GetAdminPassword() const;
    void OnStoreSelected(wxListEvent& event);
};
