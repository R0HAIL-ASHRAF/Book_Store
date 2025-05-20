#pragma once
#include"wx/wx.h"
#include"loginPanel.h"
#include"DashboardUser.h"
#include"SignupPanel.h"
class MainFrame: public wxFrame
{
public:
    MainFrame(const wxString& title);

private:
    SignupPanel* m_signupPanel;
    loginPanel* m_loginPanel;
    DashboardUser* m_dashboardUser;
    wxBoxSizer* m_mainSizer;

    void OnLogout(wxCommandEvent& event);
    void OnLoginSuccess(wxCommandEvent& event);
    void OnShowSignup(wxCommandEvent& event);
    void OnSignupComplete(wxCommandEvent& event);
    void SignUpLoginBtnSuccess(wxCommandEvent& event);
    void SwitchToDashboard();

    void SwitchToLoginPage();
    void SwitchToSignupPage();

    ~MainFrame();

};

