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
	m_addBookPanel = new AddBook(this);
	m_bookDisplayPanel = new BookDisplayPanel(this);
    m_addStorePanel = new AddStorePanel(this);
    m_viewStorePanel = new ViewStorePanel(this, new StoreManager(
        Login("Rohail", "1234"), "StoreManager@gmail.com", 
        Date(12, 2, 2024), Name("Store", "Manager"),
        Address("53-B", "Lahore", "Punjab", "Pakistan"),
        Store("Store01", "HEHE STORE", Address("53-B", "Lahore", "Punjab", "Pakistan"))));

	/*m_bookDisplayPanel->SetBackgroundColour(wxColour(255, 188, 217));

    Book book =  m_addBookPanel->ReadSingleBook();
	m_bookDisplayPanel->SetBookInfo(book);*/

    m_addStorePanel->Hide();
    m_bookDisplayPanel->Hide();
    m_adminPanel->Hide();
    m_signupPanel->Hide();
	m_loginPanel->Hide();
    m_dashboardUser->Hide();
	m_addBookPanel->Hide();
    m_viewStorePanel->Show();
    
    m_mainSizer->Add(m_loginPanel, 1, wxEXPAND);
    m_mainSizer->Add(m_dashboardUser, 1, wxEXPAND);
    m_mainSizer->Add(m_signupPanel, 1, wxEXPAND);
    m_mainSizer->Add(m_adminPanel, 1, wxEXPAND);
	m_mainSizer->Add(m_addBookPanel, 1, wxEXPAND);
    m_mainSizer->Add(m_bookDisplayPanel, 1, wxEXPAND);
    m_mainSizer->Add(m_addStorePanel, 1, wxEXPAND);
    m_mainSizer->Add(m_viewStorePanel, 1, wxEXPAND);


    // Use stack-allocated size to avoid memory leak
    wxSize sizeFrame(1250, 700);
    m_loginPanel->SetMinSize(sizeFrame);
    m_dashboardUser->SetMinSize(sizeFrame);
    m_signupPanel->SetMinSize(sizeFrame);
    m_adminPanel->SetMinSize(sizeFrame);
	m_addBookPanel->SetMinSize(sizeFrame);
    m_bookDisplayPanel->SetMinSize(sizeFrame);
    m_addStorePanel->SetMinSize(sizeFrame);
    m_viewStorePanel->SetMinSize(sizeFrame);

    SetSizer(m_mainSizer);
    SetMinSize(sizeFrame);
        
	// binding events 
    Bind(wxEVT_BUTTON, &MainFrame::OnLoginSuccess, this, ID_LoginButton);
    Bind(wxEVT_BUTTON, &MainFrame::OnShowSignup, this, ID_SignupButton);
    Bind(wxEVT_BUTTON, &MainFrame::OnSignupComplete, this, ID_SignupSubmitButton);
    Bind(wxEVT_BUTTON, &MainFrame::OnLogout, this, ID_LogoutButton);
    Bind(wxEVT_BUTTON, &MainFrame::SignUpLoginBtnSuccess, this, ID_LoginSignupButton);
    Bind(wxEVT_BUTTON, &MainFrame::OnLogout, this, ID_LogoutButtonAdmin);
    Bind(wxEVT_BUTTON, &MainFrame::OnAddBook, this, ID_AddBook);
	Bind(wxEVT_BUTTON, &MainFrame::OnSaveProduct, this, ID_SaveProductButton);

}
MainFrame::~MainFrame()
{
    Unbind(wxEVT_BUTTON, &MainFrame::OnLoginSuccess, this, ID_LoginButton);
    Unbind(wxEVT_BUTTON, &MainFrame::OnShowSignup, this, ID_SignupButton);
    Unbind(wxEVT_BUTTON, &MainFrame::OnSignupComplete, this, ID_SignupSubmitButton);
    Unbind(wxEVT_BUTTON, &MainFrame::OnLogout, this, ID_LogoutButton);
    Unbind(wxEVT_BUTTON, &MainFrame::SignUpLoginBtnSuccess, this, ID_LoginSignupButton);


}



void MainFrame::OnLoginSuccess(wxCommandEvent& event)
{
    if (m_loginPanel->ValidateLogin())
    {
       
        SwitchToDashboard();
    }
    else if (m_loginPanel->GetUsername() == m_adminPanel->GetAdminUserName() &&
             m_loginPanel->GetPassword() == m_adminPanel->GetAdminPassword())
    {
		SwitchToAdminDashboard();
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

void MainFrame::OnSaveProduct(wxCommandEvent& event)
{
    if(!m_addBookPanel->ValidateBook())
    {
        return;
    }
    m_addBookPanel->IntoFile();
    // TODO: Save book to database or storage
    wxMessageBox("Book saved successfully!", "Success", wxOK | wxICON_INFORMATION);

    // Clear form
    m_addBookPanel->ClearForm();
    SwitchToAdminDashboard();
}

void MainFrame::SwitchToDashboard()
{
    m_loginPanel->Hide();
    m_signupPanel->Hide();
    m_dashboardUser->Show();
    m_adminPanel->Hide();
    m_addBookPanel->Hide();

    Layout();
}

void MainFrame::SwitchToLoginPage()
{
    m_dashboardUser->Hide();
    m_signupPanel->Hide();
    m_loginPanel->Show();
    m_adminPanel->Hide();
    m_addBookPanel->Hide();

    Layout();
}

void MainFrame::SwitchToSignupPage()
{
    m_loginPanel->Hide();
    m_dashboardUser->Hide();
    m_signupPanel->Show();
    m_adminPanel->Hide();
    m_addBookPanel->Hide();


    Layout();
}

void MainFrame::SwitchToAdminDashboard()
{
    m_loginPanel->Hide();
    m_signupPanel->Hide();
    m_dashboardUser->Hide();
    m_adminPanel->Show();
    m_addBookPanel->Hide();

	Layout();
}

void MainFrame::OnLogout(wxCommandEvent& event) {
    m_dashboardUser->Hide();
    m_loginPanel->clearTextCtrl();
    m_signupPanel->Hide();
    m_adminPanel->Hide();
    m_addBookPanel->Hide();
    m_loginPanel->Show();
}

void MainFrame::OnAddBook(wxCommandEvent& event) {
    m_addBookPanel->Show();
    m_loginPanel->Hide();
    m_dashboardUser->Hide();
    m_signupPanel->Hide();
    m_adminPanel->Hide();
    Layout();
}
