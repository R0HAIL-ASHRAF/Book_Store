#pragma once

#include"wx/wx.h"
#include"loginPanel.h"
#include"DashboardUser.h"
#include"SignupPanel.h"
#include"Classic.h"
#include"DashboardAdmin.h"



class MainFrame: public wxFrame
{
public:
    MainFrame(const wxString& title);
    void OnLogout(wxCommandEvent& event);

private:
   
    //Panels
    
    loginPanel* m_loginPanel;
    DashboardUser* m_dashboardUser;
    wxBoxSizer* m_mainSizer;
    DashboardAdmin* m_adminPanel;
    SignupPanel* m_signupPanel;

    
    // btns event handlers
    void OnLoginSuccess(wxCommandEvent& event);
    void OnShowSignup(wxCommandEvent& event);
    void OnSignupComplete(wxCommandEvent& event);
    void SignUpLoginBtnSuccess(wxCommandEvent& event);

    // panel changing 
    void SwitchToDashboard();
    void SwitchToLoginPage();
    void SwitchToSignupPage();
	void SwitchToAdminDashboard();

    ~MainFrame();

};

