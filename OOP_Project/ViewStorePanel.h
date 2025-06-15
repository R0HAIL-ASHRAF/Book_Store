#pragma once  
#include <wx/wx.h>  
#include<wx/listctrl.h>
#include "StoreManager.h"
#include"IDs.h"
#include"ProductListView.h"
#include"Admin.h"


class ViewStorePanel : public wxPanel  
{  
private:  
     
    Admin* admin;
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
    

    void OnDeleteItem(wxCommandEvent& event);

public:  
    wxListCtrl* orderList;
    wxListCtrl* productsList;
    MyVector<Order*> orders;
    StoreManager* storeManager;

    void SetOrders(const MyVector<Order*>& order);
    void OnRightClickItem(wxListEvent& event);
    void UpdateStoreInfo();
    void UpdateStoreOrders();

    void OnRefresh(wxCommandEvent& event);
    void SetMenuListIndex(int i);
    int GetMenuListIndex();

    ViewStorePanel(wxWindow* parent, StoreManager* storeManager);  
    void SetStore(StoreManager*& store);
    MyString GetBookFileName();
    MyString GetStationaryFileName();
    ~ViewStorePanel() override;
};
