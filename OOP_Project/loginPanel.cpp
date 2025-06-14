#include "LoginPanel.h"
#include"IDs.h"

loginPanel* loginPanel::instance = nullptr;
loginPanel::loginPanel(wxWindow* parent)
    : wxPanel(parent), m_activeCustomer{nullptr}
{
	
    customers = new MyVector<Classic*>();
    SetupUI();
   this->FromFile();
   
}

loginPanel* loginPanel::GetInstance(wxWindow* parent)
{
    if (instance == nullptr) {
		instance = new loginPanel(parent);
    }
    return instance;

}

MyVector<Classic*>* loginPanel::GetCustomers() const
{
    return new MyVector<Classic*>(*customers);
}

Customer* loginPanel::GetActiveCustomer()
{
    return m_activeCustomer;
}

MyString loginPanel::GetUsername() const
{
    return m_usernameField->GetValue();
}

MyString loginPanel::GetPassword() const
{
    return m_passwordField->GetValue();
}

void loginPanel::AddCustomer(Classic *& customer)
{
    customers->push(customer);
}

bool loginPanel::ValidateLoginForCustomers() const
{
    MyString username = m_usernameField->GetValue();
    MyString password = m_passwordField->GetValue();
    for (int i = 0; i < customers->size(); i++) {
        Customer* customer = customers->at(i);
        if (username == customer->getUserName() && password == customer->getPassword()) {
            const_cast<loginPanel*>(this)->m_activeCustomer = customer;
            return true;
        }
    }

    return false;
   
}

void loginPanel::SetupUI()
{   
    wxImage::AddHandler(new wxJPEGHandler());
    wxImage::AddHandler(new wxPNGHandler());
   
    wxImage logoImg("assets/images/loginPage.png", wxBITMAP_TYPE_ANY);
    if (!logoImg.IsOk()) {
        wxLogError("Failed to load logo image");
        return;
    }

    wxBitmap logoBmp(logoImg.Scale(700, 700));  
    wxStaticBitmap* logo = new wxStaticBitmap(this, wxID_ANY, logoBmp);

    wxFont* labelFont = new wxFont(14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    wxFont* headingFont = new wxFont(22, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

    wxPanel* formPanel = new wxPanel(this);
    formPanel->SetBackgroundColour(wxColour(255, 245, 247)); 
    formPanel->SetWindowStyle(wxBORDER_SIMPLE);

    
    wxBoxSizer* formSizer = new wxBoxSizer(wxVERTICAL);

   
    wxStaticText* loginLabel = new wxStaticText(formPanel, wxID_ANY, "Welcome Back!");
    loginLabel->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    loginLabel->SetForegroundColour(wxColour(50, 100, 200));
    formSizer->Add(loginLabel, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 15);

    // Username field
    wxBoxSizer* userSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText* userNameText = new wxStaticText(formPanel, wxID_ANY, "Username:");
    userNameText->SetFont(*labelFont);
    userSizer->Add(userNameText, 0, wxRIGHT | wxALIGN_CENTER_VERTICAL, 5);
    m_usernameField = new wxTextCtrl(formPanel, wxID_ANY, "", wxDefaultPosition, wxSize(250, -1));
    m_usernameField->SetHint("Enter your username");
    userSizer->Add(m_usernameField, 1);
    formSizer->Add(userSizer, 0, wxEXPAND | wxALL, 10);

    // Password field
    wxBoxSizer* passSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText* passwordText = new wxStaticText(formPanel, wxID_ANY, "Password:");
    passwordText->SetFont(*labelFont);
    passSizer->Add(passwordText, 0, wxRIGHT | wxALIGN_CENTER_VERTICAL, 5);
    m_passwordField = new wxTextCtrl(formPanel, wxID_ANY, "", wxDefaultPosition, wxSize(250, -1), wxTE_PASSWORD);
    m_passwordField->SetHint("Enter your password");
    passSizer->Add(m_passwordField, 1);
    formSizer->Add(passSizer, 0, wxEXPAND | wxALL, 10);

    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    wxButton* loginBtn = new wxButton(formPanel, ID_LoginButton, "Login");
    wxButton* signUpBtn = new wxButton(formPanel, ID_SignupButton, "Sign Up");
    buttonSizer->Add(loginBtn,wxRIGHT);
    buttonSizer->Add(signUpBtn);

    formSizer->Add(buttonSizer, 0,wxALIGN_CENTER | wxTOP | wxBOTTOM, 15);
    formPanel->SetSizer(formSizer);

    wxBoxSizer* contentSizer = new wxBoxSizer(wxHORIZONTAL);
    contentSizer->AddSpacer(20);
    contentSizer->Add(logo, 0, wxALIGN_CENTER_VERTICAL | wxALL, 20);
    contentSizer->AddSpacer(20);
    contentSizer->Add(formPanel, 0, wxALIGN_CENTER_VERTICAL | wxALL, 20);
    contentSizer->AddSpacer(20);

    wxBoxSizer* outerSizer = new wxBoxSizer(wxVERTICAL);
    outerSizer->AddStretchSpacer(1);
    outerSizer->Add(contentSizer, 0, wxALIGN_CENTER);
    outerSizer->AddStretchSpacer(1);

    SetSizerAndFit(outerSizer);
    m_usernameField->SetFocus();
}

void loginPanel::clearTextCtrl() {
    m_usernameField->Clear();
    m_passwordField->Clear();
}

void loginPanel::FromFile() {
    MyString tempUserName;
    MyString tempFirstName;
    MyString tempLastName;
    MyString tempEmail;
    MyString tempDay;
    MyString tempMonth;
    MyString tempYear;
    MyString tempHouseNumber;
    MyString tempCity;
    MyString tempProvince;
    MyString tempCountry;
    MyString tempPassword;

    std::ifstream fin("Users.bin", std::ios::binary);
    if (!fin.is_open()) {
        Logger::getInstance().writeError("Failed to open file(Users.bin)");
        return;
    }

    while (true) {
        tempUserName.ReadFromStream(fin);
        if (fin.eof()) 
            break;

        tempFirstName.ReadFromStream(fin);
        tempLastName.ReadFromStream(fin);
        tempEmail.ReadFromStream(fin);
        tempDay.ReadFromStream(fin);
        tempMonth.ReadFromStream(fin);
        tempYear.ReadFromStream(fin);
        tempHouseNumber.ReadFromStream(fin);
        tempCity.ReadFromStream(fin);
        tempProvince.ReadFromStream(fin);
        tempCountry.ReadFromStream(fin);
        tempPassword.ReadFromStream(fin);

        if (!fin) 
            break;

        Classic* customer = new Classic(
            Login(tempUserName, tempPassword),
            tempEmail,
            Date(tempDay.StringToInt(), tempMonth.StringToInt(), tempYear.StringToInt()),
            Name(tempFirstName, tempLastName),
            Address(tempHouseNumber, tempCity, tempProvince, tempCountry)
        );

        AddCustomer(customer);
    }
    

    fin.close();
}

loginPanel::~loginPanel()
{
    delete customers;
}
