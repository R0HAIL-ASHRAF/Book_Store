#include "LoginPanel.h"
#include"IDs.h"
loginPanel::loginPanel(wxWindow* parent)
    : wxPanel(parent)
{
    SetupUI();
    Person* Admin = new Person(Login("Admin", "1234"), "Admin", "admin@gmail.com", Date(12, 2, 2023), Name("Rohail", "Ashraf"),
        Address("53-B", "Lahore", "Punjab", "Pakistan"));
    addPerson(Admin);
}

loginPanel::loginPanel(wxWindow* parent, wxWindowID id)
{
     SetupUI();
}

void loginPanel::addPerson(Person*& person)
{
    persons.push(person);
}

bool loginPanel::ValidateLogin() const
{
    wxString username = m_usernameField->GetValue();
    wxString password = m_passwordField->GetValue();
    for (int i = 0; i < persons.size(); i++) {
        if (username == persons.at(i)->getUserName() &&
            password == persons.at(i)->getPassword() ) {
            return true;
        }
    }
    return false;
   
}

void loginPanel::SetupUI()
{
    // Load the image
    wxImage::AddHandler(new wxJPEGHandler());
    wxImage::AddHandler(new wxPNGHandler());
    wxImage logoImg("assets/images/loginPage.png", wxBITMAP_TYPE_ANY);
    if (!logoImg.IsOk() ) {
        wxLogError("Failed to load logo image");
        return;
    }
    
    wxBitmap logoBmp(logoImg.Scale(400, 400));  // Resize if needed
    wxStaticBitmap* logo = new wxStaticBitmap(this, wxID_ANY, logoBmp);


    // login form sizer
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    wxFont* staticTextFontSize = new wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_MEDIUM);
    
    // Login 
    wxStaticText* loginLabel = new wxStaticText(this, wxID_ANY, "Please Login");
    loginLabel->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    mainSizer->Add(loginLabel, 0, wxALIGN_CENTER, 10);

    // Username box
    wxBoxSizer* userSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText* userNameText = new wxStaticText(this, wxID_ANY, "Username:");
    userNameText->SetFont(*staticTextFontSize);
    userSizer->Add(userNameText, 0, wxRIGHT | wxALIGN_CENTER_VERTICAL, 5);
    m_usernameField = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(250, -1));
    userSizer->Add(m_usernameField, 1);
    mainSizer->Add(userSizer, 0, wxEXPAND | wxALL, 10);

    // Password box
    wxBoxSizer* passSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText* passwordText = new wxStaticText(this, wxID_ANY, "Password:");
    passwordText->SetFont(*staticTextFontSize);
    passSizer->Add(passwordText, 0, wxRIGHT | wxALIGN_CENTER_VERTICAL, 5);
    m_passwordField = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(250, -1), wxTE_PASSWORD);
    passSizer->Add(m_passwordField, 1);
    mainSizer->Add(passSizer, 0, wxEXPAND | wxALL, 10);

    // Login button 

    wxButton* loginBtn = new wxButton(this, ID_LoginButton, "Login");
    loginBtn->SetDefault();
    mainSizer->Add(loginBtn, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 15);

    // sign up button 

	wxButton* signUpBtn = new wxButton(this, ID_SignupButton, "Sign Up");
	signUpBtn->SetDefault();
	mainSizer->Add(signUpBtn, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 15);

    wxBoxSizer* contentSizer = new wxBoxSizer(wxHORIZONTAL);
    contentSizer->AddSpacer(20);
    contentSizer->Add(logo, 0, wxALIGN_CENTER_VERTICAL | wxALL, 10);  // Image on the left
    contentSizer->AddSpacer(30);
    contentSizer->Add(mainSizer, 0, wxALIGN_CENTER_VERTICAL);
    contentSizer->AddSpacer(20);

    // Add top-level sizer for vertical centering
    wxBoxSizer* outerSizer = new wxBoxSizer(wxVERTICAL);
    outerSizer->AddStretchSpacer(1);
    outerSizer->Add(contentSizer, 0, wxALIGN_CENTER);
    outerSizer->AddStretchSpacer(1);
    
    SetSizerAndFit(outerSizer);
    m_usernameField->SetFocus();
}
