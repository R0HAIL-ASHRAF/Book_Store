#include "SignupPanel.h"
#include"IDs.h"


SignupPanel::SignupPanel(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    wxBoxSizer* outerSizer = new wxBoxSizer(wxVERTICAL);
    outerSizer->AddStretchSpacer(1); 

    wxBoxSizer* formContainer = new wxBoxSizer(wxVERTICAL);
    formContainer->SetMinSize(wxSize(600, -1));

    wxStaticText* title = new wxStaticText(this, wxID_ANY, "Create Your Account");
    title->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    title->SetForegroundColour(wxColour(50, 100, 200));
    formContainer->Add(title, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 15);

    wxFlexGridSizer* formGrid = new wxFlexGridSizer(2, wxSize(15, 10));
    formGrid->AddGrowableCol(1, 1);

    getUserName = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(250, -1));
    AddFormField(formGrid, "Username:", getUserName);

    getFirstName = new wxTextCtrl(this, wxID_ANY);
    AddFormField(formGrid, "First Name:", getFirstName);

    getLastName = new wxTextCtrl(this, wxID_ANY);
    AddFormField(formGrid, "Last Name:", getLastName);

    getEmail = new wxTextCtrl(this, wxID_ANY);
    AddFormField(formGrid, "Email:", getEmail);

    wxBoxSizer* dobSizer = new wxBoxSizer(wxHORIZONTAL);
    getDay = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(40, -1));
    getMonth = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(40, -1));
    getYear = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(60, -1));

    dobSizer->Add(getDay, 0, wxRIGHT, 5);
    dobSizer->Add(new wxStaticText(this, wxID_ANY, "/"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
    dobSizer->Add(getMonth, 0, wxRIGHT, 5);
    dobSizer->Add(new wxStaticText(this, wxID_ANY, "/"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
    dobSizer->Add(getYear, 0);

    formGrid->Add(new wxStaticText(this, wxID_ANY, "Date of Birth:"), 0, wxALIGN_CENTER_VERTICAL);
    formGrid->Add(dobSizer, 1, wxEXPAND);

    getHouseNumber = new wxTextCtrl(this, wxID_ANY);
    AddFormField(formGrid, "Address:", getHouseNumber);

    getCity = new wxTextCtrl(this, wxID_ANY);
    AddFormField(formGrid, "City:", getCity);

    getProvince = new wxTextCtrl(this, wxID_ANY);
    AddFormField(formGrid, "State/Province:", getProvince);

    getCountry = new wxTextCtrl(this, wxID_ANY);
    AddFormField(formGrid, "Country:", getCountry);

    getPassword = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
    AddFormField(formGrid, "Password:", getPassword);

    getConfirmPassword = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
    AddFormField(formGrid, "Confirm Password:", getConfirmPassword);

    wxStaticText* pwHint = new wxStaticText(this, wxID_ANY,
        "Password must contain at least 8 characters, including uppercase, lowercase, and numbers");
    pwHint->SetFont(wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL));
    pwHint->SetForegroundColour(wxColour(100, 100, 100));
    formGrid->Add(new wxStaticText(this, wxID_ANY, ""), 0);
    formGrid->Add(pwHint, 0, wxTOP, -5);

    formContainer->Add(formGrid, 0, wxALL | wxEXPAND, 15);

    wxBoxSizer* btnSizer = new wxBoxSizer(wxHORIZONTAL);

    // signup button
    wxButton* signupButton = new wxButton(this, ID_SignupSubmitButton, "Create Account");
    btnSizer->Add(signupButton, 0, wxALIGN_CENTRE, 20);

    btnSizer->AddStretchSpacer(0);
    
    // back to login button
    wxButton* loginButton = new wxButton(this, ID_LoginSignupButton, "Login");
    btnSizer->Add(loginButton, 1, wxALIGN_CENTRE, 15);

    formContainer->Add(btnSizer, 1, wxALIGN_CENTER,20);
   
    outerSizer->Add(formContainer, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 20);
    outerSizer->AddStretchSpacer(1);

    SetSizer(outerSizer);

}

void SignupPanel::AddFormField(wxSizer* sizer, const wxString& label, wxWindow* control)
{
    wxStaticText* labelCtrl = new wxStaticText(this, wxID_ANY, label);
    labelCtrl->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    sizer->Add(labelCtrl, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
    sizer->Add(control, 1, wxEXPAND);
}

void SignupPanel::OnSignup() {
    if (!ValidateSignup())
    {
        wxMessageBox("Please fill in all required fields", "Error", wxOK | wxICON_ERROR);
        return ;
    }

    if (getPassword->GetValue() != getConfirmPassword->GetValue())
    {
        wxMessageBox("Passwords do not match", "Error", wxOK | wxICON_ERROR);
        return ;
    }

    wxMessageBox("Account created successfully!", "Success", wxOK | wxICON_INFORMATION);

    clearTextCtrls();
    
}

bool SignupPanel::ValidateSignup() 
{

    if (getUserName->GetValue().IsEmpty() ||
        getFirstName->GetValue().IsEmpty() ||
        getLastName->GetValue().IsEmpty() ||
        getEmail->GetValue().IsEmpty() ||
        getPassword->GetValue().IsEmpty()) {
        return false;
    }
    return true;
}

Classic* SignupPanel::getPerson() const
{
    MyString tempUserName = getUserName->GetValue();
    MyString tempFirstName = getFirstName->GetValue();
    MyString tempLastName = getLastName->GetValue();
    MyString tempEmail = getEmail->GetValue();
    MyString tempDay = getDay->GetValue();
    MyString tempMonth = getMonth->GetValue();
    MyString tempYear = getYear->GetValue();
    MyString tempHouseNumber = getHouseNumber->GetValue();
    MyString tempCity = getCity->GetValue();
    MyString tempProvince = getProvince->GetValue();
    MyString tempCountry = getCountry->GetValue();
    MyString tempPassword = getPassword->GetValue();


    Classic* persons = new Classic(Login(tempUserName, tempPassword),
        tempEmail, Date(tempDay.StringToInt(), tempMonth.StringToInt(), tempYear.StringToInt()),
        Name(tempFirstName, tempLastName),
        Address(tempHouseNumber, tempCity, tempProvince, tempCountry));

    return persons;
}

void SignupPanel::clearTextCtrls() const
{
    getUserName->Clear();
    getFirstName->Clear();
    getLastName->Clear();
    getEmail->Clear();
    getDay->Clear();
    getMonth->Clear();
    getYear->Clear();
    getHouseNumber->Clear();
    getCity->Clear();
    getProvince->Clear();
    getCountry->Clear();
    getPassword->Clear();
    getConfirmPassword->Clear();
}

void SignupPanel::IntoFile() {
    MyString tempUserName = getUserName->GetValue();
    MyString tempFirstName = getFirstName->GetValue();
    MyString tempLastName = getLastName->GetValue();
    MyString tempEmail = getEmail->GetValue();
    MyString tempDay = getDay->GetValue();
    MyString tempMonth = getMonth->GetValue();
    MyString tempYear = getYear->GetValue();
    MyString tempHouseNumber = getHouseNumber->GetValue();
    MyString tempCity = getCity->GetValue();
    MyString tempProvince = getProvince->GetValue();
    MyString tempCountry = getCountry->GetValue();
    MyString tempPassword = getPassword->GetValue();

    std::ofstream fout("Users.bin", std::ios::binary | std::ios::app);
    if (!fout.is_open()) {
        wxLogError("Failed to open Users.bin(signupPanel)");
        return;
    }

    tempUserName.WriteToStream(fout);
    tempFirstName.WriteToStream(fout);
    tempLastName.WriteToStream(fout);
    tempEmail.WriteToStream(fout);
    tempDay.WriteToStream(fout);
    tempMonth.WriteToStream(fout);
    tempYear.WriteToStream(fout);
    tempHouseNumber.WriteToStream(fout);
    tempCity.WriteToStream(fout);
    tempProvince.WriteToStream(fout);
    tempCountry.WriteToStream(fout);
    tempPassword.WriteToStream(fout);

    fout.close();
}
