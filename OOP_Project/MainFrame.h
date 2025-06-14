#pragma once

#include"wx/wx.h"
#include"loginPanel.h"
#include"DashboardUser.h"
#include"SignupPanel.h"
#include"Classic.h"
#include"DashboardAdmin.h"
#include "AddBook.h"
#include "BookDisplayPanel.h"
#include"AddStorePanel.h"
#include"ViewStorePanel.h"
#include"AddStationary.h"
#include"StationaryDisplayPanel.h"
#include"ViewCartPanel.h"
#include"OrderPanel.h"
#include"log.h"
#include"DisplayOrderPanel.h"

class MainFrame: public wxFrame
{
public:
    MainFrame(const wxString& title);
    
    Admin* admin;
    void SwitchToViewStore();
private:
    MyVector<Product*> prods;
    wxSize sizeFrame;
    //Panels
    
    loginPanel* m_loginPanel;
    DashboardUser* m_dashboardUser;
    wxBoxSizer* m_mainSizer;
    DashboardAdmin* m_adminPanel;
    SignupPanel* m_signupPanel;
	AddBook* m_addBookPanel;
	BookDisplayPanel* m_bookDisplayPanel;
    AddStorePanel* m_addStorePanel;
    ViewStorePanel* m_viewStorePanel;
	AddStationary* m_addStationaryPanel;
    StationaryDisplayPanel* m_stationaryDisplayPanel;
    ViewCartPanel* m_viewCartPanel;
    OrderPanel* m_orderPanel;
    DisplayOrderPanel* m_displayOrderPanel;

    void OnViewStore(wxCommandEvent& event);
    void OnViewProduct(wxCommandEvent& event);

    void OnRightClickDashboardAdmin(wxCommandEvent& event);
    void OnRightClickViewStore(wxCommandEvent& event);

    void OnRightClickViewOrder(wxCommandEvent& event);
    void BindEvents();
    void InitiallyShowLogin();
    void AddPanelsToMainSizer();
    void OnDeleteItemProduct(wxCommandEvent& event);

    // btns event handlers
    void OnLoginSuccess(wxCommandEvent& event);
    void OnShowSignup(wxCommandEvent& event);
    void OnSignupComplete(wxCommandEvent& event);
    void SignUpLoginBtnSuccess(wxCommandEvent& event);
    void OnLogout(wxCommandEvent& event);
    void OnAddBook(wxCommandEvent& event);
    void OnAddBookViaViewStoreClear(wxCommandEvent& event);
	void OnSaveProductBook(wxCommandEvent& event);
	void OnAddStationary(wxCommandEvent& event);
    void SwitchToDisplayOrder(wxCommandEvent& event);
    void OnSaveProductStationary(wxCommandEvent& event);
	void OnSaveStoreManager(wxCommandEvent& event);
    void OnBackButton(wxCommandEvent& event);
    void OnAddStoreManager(wxCommandEvent& event);
    void OnDeleteItem(wxCommandEvent& event);
    void OnBackButtonProduct(wxCommandEvent& event);
    void OnOrderBtnPressed(wxCommandEvent& event);
    Cart* GetCurrentCustomerCart();
    void OnViewCart(wxCommandEvent& event);
    void OnProceedCart(wxCommandEvent& event);
    void OnDeleteOrder(wxCommandEvent& event);



    bool IsStoreExists();

    // panel changing 
    void SwitchToDashboard();
    void SwitchToLoginPage();
    void SwitchToDisplayBook();
    void SwitchToSignupPage();
	void SwitchToAdminDashboard();
    void SwitchToDisplayStationary();
    void SwitchToOrderPanel();
    void SwitchToDashboardUser();
    void SwtichToCartPanel();
    void SwitchToOrderProceed();
    void SwitchToOrderDisplay();
    void SwitchToViewCartPanel();
    void SetSizeOfPanel();
    ~MainFrame();

    void OnAddToCartClicked(wxCommandEvent& event);
    void OnViewProductPanel(wxCommandEvent& event);
    void OnPlaceOrder(wxCommandEvent& event);
    void OnBackToUser(wxCommandEvent& event);
    void OnRefreshClickedCart(wxCommandEvent& event);
    void OnBackToOrderPanel(wxCommandEvent& event);
    void OnBackButtonProductUser(wxCommandEvent& event);
    void OnViewOrder(wxCommandEvent& event);
};

