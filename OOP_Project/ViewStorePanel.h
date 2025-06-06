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
    StoreManager* storeManager;  

    wxStaticText* storeIdText;  
    wxStaticText* storeNameText;  
    wxStaticText* addressText;  
    wxStaticText* productCountText;  

    wxStaticText* managerNameText;  
    wxStaticText* emailText;  
    wxStaticText* passwordText;  
    wxStaticText* usernameText;  

    ProductListView* products;

    void SetupUI();  
    void CreateStoreInfoTab(wxPanel* parent);  
    void CreateManagerInfoTab(wxPanel* parent);  
    void CreateProductsTab(wxPanel* parent);  
    void UpdateStoreInfo();  

    void OnRefresh(wxCommandEvent& event);  
    void OnEdit(wxCommandEvent& event);  
    void OnAddProduct(wxCommandEvent& event);  

public:  
    ViewStorePanel(wxWindow* parent, StoreManager* storeManager);  
};
