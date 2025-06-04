#pragma once

#include"wx/wx.h"
#include"loginPanel.h"
#include"DashboardUser.h"
#include"SignupPanel.h"
#include"Classic.h"
#include"DashboardAdmin.h"
#include "AddBook.h"
#include "BookDisplayPanel.h"



class MainFrame: public wxFrame
{
public:
    MainFrame(const wxString& title);
    
private:
   
    //Panels
    
    loginPanel* m_loginPanel;
    DashboardUser* m_dashboardUser;
    wxBoxSizer* m_mainSizer;
    DashboardAdmin* m_adminPanel;
    SignupPanel* m_signupPanel;
	AddBook* m_addBookPanel;
	BookDisplayPanel* m_bookDisplayPanel;
    
    // btns event handlers
    void OnLoginSuccess(wxCommandEvent& event);
    void OnShowSignup(wxCommandEvent& event);
    void OnSignupComplete(wxCommandEvent& event);
    void SignUpLoginBtnSuccess(wxCommandEvent& event);
    void OnLogout(wxCommandEvent& event);
    void OnAddBook(wxCommandEvent& event);
	void OnSaveProduct(wxCommandEvent& event);
    // panel changing 
    void SwitchToDashboard();
    void SwitchToLoginPage();
    void SwitchToSignupPage();
	void SwitchToAdminDashboard();

    ~MainFrame();

};

