#pragma once  
#include <wx/wx.h>  
#include <wx/notebook.h> 
#include<wx/listctrl.h>
#include "StoreManager.h"
#include"IDs.h"
#include"ProductListView.h"

class ViewStorePanel : public wxPanel  
{  
private:  
     

    wxStaticText* storeIdText;  
    wxStaticText* storeNameText;  
    wxStaticText* addressText;  
    wxStaticText* productCountText;  

    wxStaticText* managerNameText;  
    wxStaticText* emailText;  
    wxStaticText* passwordText;  
    wxStaticText* usernameText;  
    wxStaticText* managerAddressText;


   
    int rightClickedIndex;

    void SetupUI();  
    void UpdateStoreInfo();

    void OnRightClickItem(wxListEvent& event);
    void OnDeleteItem(wxCommandEvent& event);

public:  
    wxListCtrl* productsList;
    StoreManager* storeManager;

    void OnRefresh(wxCommandEvent& event);
    void SetMenuListIndex(int i);
    int GetMenuListIndex();

    ViewStorePanel(wxWindow* parent, StoreManager* storeManager);  
    void SetStore(StoreManager*& store);
    MyString GetBookFileName();
    MyString GetStationaryFileName();
};
