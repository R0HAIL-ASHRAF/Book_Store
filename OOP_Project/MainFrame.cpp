#include "MainFrame.h"
#include "IDs.h"

MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title)   
{
    this->SetBackgroundColour(wxColour(255, 188, 217));
    m_mainSizer = new wxBoxSizer(wxVERTICAL);

    //  panels
    m_loginPanel = loginPanel::GetInstance(this);
    m_dashboardUser = new DashboardUser(this);
    m_signupPanel = new SignupPanel(this);
    m_adminPanel = new DashboardAdmin(this);

    m_adminPanel->Hide();
    m_signupPanel->Hide();
	m_loginPanel->Show();
    m_dashboardUser->Hide();

    
    m_mainSizer->Add(m_loginPanel, 1, wxEXPAND);
    m_mainSizer->Add(m_dashboardUser, 1, wxEXPAND);
    m_mainSizer->Add(m_signupPanel, 1, wxEXPAND);
    m_mainSizer->Add(m_adminPanel, 1, wxEXPAND);
    
    // Use stack-allocated size to avoid memory leak
    wxSize sizeFrame(1250, 700);
    m_loginPanel->SetMinSize(sizeFrame);
    m_dashboardUser->SetMinSize(sizeFrame);
    m_signupPanel->SetMinSize(sizeFrame);
    m_adminPanel->SetMinSize(sizeFrame);

    SetSizer(m_mainSizer);
    SetMinSize(sizeFrame);
        
	// binding events 
    Bind(wxEVT_BUTTON, &MainFrame::OnLoginSuccess, this, ID_LoginButton);
    Bind(wxEVT_BUTTON, &MainFrame::OnShowSignup, this, ID_SignupButton);
    Bind(wxEVT_BUTTON, &MainFrame::OnSignupComplete, this, ID_SignupSubmitButton);
    Bind(wxEVT_BUTTON, &MainFrame::OnLogout, this, ID_LogoutButton);
    Bind(wxEVT_BUTTON, &MainFrame::SignUpLoginBtnSuccess, this, ID_LoginSignupButton);
}
MainFrame::~MainFrame()
{
    Unbind(wxEVT_BUTTON, &MainFrame::OnLoginSuccess, this, ID_LoginButton);
    Unbind(wxEVT_BUTTON, &MainFrame::OnShowSignup, this, ID_SignupButton);
    Unbind(wxEVT_BUTTON, &MainFrame::OnSignupComplete, this, ID_SignupSubmitButton);
    Unbind(wxEVT_BUTTON, &MainFrame::OnLogout, this, ID_LogoutButton);
    Unbind(wxEVT_BUTTON, &MainFrame::SignUpLoginBtnSuccess, this, ID_LoginSignupButton);


}


void MainFrame::OnLogout(wxCommandEvent& event) {
    m_dashboardUser->Hide();
    m_loginPanel->clearTextCtrl();
    m_loginPanel->Show();
}

void MainFrame::OnLoginSuccess(wxCommandEvent& event)
{
    if (m_loginPanel->ValidateLogin())
    {
       // adding the dashboard here
        SwitchToDashboard();
    }
    else
    {
        wxMessageBox("Invalid credentials", "Login Error", wxOK | wxICON_ERROR);
    }
}

void MainFrame::OnShowSignup(wxCommandEvent& event)
{
    SwitchToSignupPage();
    
}

void MainFrame::OnSignupComplete(wxCommandEvent& event)
{
   
    if (!m_signupPanel->ValidateSignup()) {
        m_signupPanel->OnSignup();
    }
    else {
        wxMessageBox("Signup successful! Please log in.", "Success", wxOK | wxICON_INFORMATION);
        Classic* tempPerson = new Classic(*m_signupPanel->getPerson());
        m_loginPanel->AddCustomer(tempPerson);
        m_signupPanel->IntoFile();
        m_signupPanel->clearTextCtrls();
        SwitchToLoginPage();
    }
}

void MainFrame::SignUpLoginBtnSuccess(wxCommandEvent& event) {
    m_loginPanel->Show();
    m_signupPanel->Hide();
    m_dashboardUser->Hide();
    Layout();

}

void MainFrame::SwitchToDashboard()
{
    m_loginPanel->Hide();
    m_signupPanel->Hide();
    m_dashboardUser->Show();
    Layout();
}

void MainFrame::SwitchToLoginPage()
{
    m_dashboardUser->Hide();
    m_signupPanel->Hide();
    m_loginPanel->Show();
    Layout();
}

void MainFrame::SwitchToSignupPage()
{
    m_loginPanel->Hide();
    m_dashboardUser->Hide();
    m_signupPanel->Show();
    Layout();
}


