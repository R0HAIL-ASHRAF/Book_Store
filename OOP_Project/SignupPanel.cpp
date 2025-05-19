#include "SignupPanel.h"
#include"IDs.h"

//SignupPanel::SignupPanel(wxWindow* parent)
//    : wxPanel(parent, wxID_ANY)
//{
//    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
//
//    // Form title
//    wxStaticText* title = new wxStaticText(this, wxID_ANY, "Create Your Account",
//        wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
//    title->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
//    mainSizer->Add(title, 0, wxALL | wxEXPAND, 10);
//
//    // Grid for form elements
//    wxFlexGridSizer* formGrid = new wxFlexGridSizer(2, wxSize(10, 10));
//    formGrid->AddGrowableCol(1, 1);
//
//    // Username
//    formGrid->Add(new wxStaticText(this, wxID_ANY, "Username:"), 0, wxALIGN_CENTER_VERTICAL);
//    getUserName = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
//    formGrid->Add(getUserName, 1, wxEXPAND);
//
//    // Name fields
//    formGrid->Add(new wxStaticText(this, wxID_ANY, "First Name:"), 0, wxALIGN_CENTER_VERTICAL);
//    getFirstName = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
//    formGrid->Add(getFirstName, 1, wxEXPAND);
//
//    formGrid->Add(new wxStaticText(this, wxID_ANY, "Last Name:"), 0, wxALIGN_CENTER_VERTICAL);
//    getLastName = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
//    formGrid->Add(getLastName, 1, wxEXPAND);
//
//    // Email
//    formGrid->Add(new wxStaticText(this, wxID_ANY, "Email:"), 0, wxALIGN_CENTER_VERTICAL);
//    getEmail = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
//    formGrid->Add(getEmail, 1, wxEXPAND);
//
//    // Birth date
//    wxBoxSizer* birthDateSizer = new wxBoxSizer(wxHORIZONTAL);
//    getDay = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(40, -1));
//    getMonth = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(40, -1));
//    getYear = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(60, -1));
//    birthDateSizer->Add(getDay, 0, wxRIGHT, 5);
//    birthDateSizer->Add(new wxStaticText(this, wxID_ANY, "/"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
//    birthDateSizer->Add(getMonth, 0, wxRIGHT, 5);
//    birthDateSizer->Add(new wxStaticText(this, wxID_ANY, "/"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
//    birthDateSizer->Add(getYear, 0);
//
//    formGrid->Add(new wxStaticText(this, wxID_ANY, "Birth Date (DD/MM/YYYY):"), 0, wxALIGN_CENTER_VERTICAL);
//    formGrid->Add(birthDateSizer, 1, wxEXPAND);
//
//    // Address fields
//    formGrid->Add(new wxStaticText(this, wxID_ANY, "House Number:"), 0, wxALIGN_CENTER_VERTICAL);
//    getHouseNumber = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
//    formGrid->Add(getHouseNumber, 1, wxEXPAND);
//
//    formGrid->Add(new wxStaticText(this, wxID_ANY, "City:"), 0, wxALIGN_CENTER_VERTICAL);
//    getCity = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
//    formGrid->Add(getCity, 1, wxEXPAND);
//
//    formGrid->Add(new wxStaticText(this, wxID_ANY, "Province/State:"), 0, wxALIGN_CENTER_VERTICAL);
//    getProvince = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
//    formGrid->Add(getProvince, 1, wxEXPAND);
//
//    formGrid->Add(new wxStaticText(this, wxID_ANY, "Country:"), 0, wxALIGN_CENTER_VERTICAL);
//    getCountry = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
//    formGrid->Add(getCountry, 1, wxEXPAND);
//
//    // Password fields
//    formGrid->Add(new wxStaticText(this, wxID_ANY, "Password:"), 0, wxALIGN_CENTER_VERTICAL);
//    getPassword = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
//    formGrid->Add(getPassword, 1, wxEXPAND);
//
//    formGrid->Add(new wxStaticText(this, wxID_ANY, "Confirm Password:"), 0, wxALIGN_CENTER_VERTICAL);
//    getConfirmPassword = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
//    formGrid->Add(getConfirmPassword, 1, wxEXPAND);
//
//    mainSizer->Add(formGrid, 1, wxALL | wxEXPAND, 10);
//
//    // Signup button
//    wxButton* signupButton = new wxButton(this, ID_SignupSubmitButton, "Sign Up");
//    mainSizer->Add(signupButton, 0, wxALIGN_CENTER | wxALL, 10);
//
//    SetSizerAndFit(mainSizer);
//}

SignupPanel::SignupPanel(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    // Main outer sizer for vertical centering
    wxBoxSizer* outerSizer = new wxBoxSizer(wxVERTICAL);
    outerSizer->AddStretchSpacer(1); // Push content down

    // Form container with maximum width
    wxBoxSizer* formContainer = new wxBoxSizer(wxVERTICAL);
    formContainer->SetMinSize(wxSize(600, -1)); // Limit maximum width

    // Form title with improved styling
    wxStaticText* title = new wxStaticText(this, wxID_ANY, "Create Your Account");
    title->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    title->SetForegroundColour(wxColour(50, 100, 200)); // Blue color
    formContainer->Add(title, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 15);

    // Form grid with improved spacing
    wxFlexGridSizer* formGrid = new wxFlexGridSizer(2, wxSize(15, 10));
    formGrid->AddGrowableCol(1, 1);

    // Add form fields using existing text controls
    getUserName = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(250, -1));
    AddFormField(formGrid, "Username*:", getUserName);

    getFirstName = new wxTextCtrl(this, wxID_ANY);
    AddFormField(formGrid, "First Name*:", getFirstName);

    getLastName = new wxTextCtrl(this, wxID_ANY);
    AddFormField(formGrid, "Last Name:", getLastName);

    getEmail = new wxTextCtrl(this, wxID_ANY);
    AddFormField(formGrid, "Email*:", getEmail);

    // Date of birth fields
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

    // Address fields
    getHouseNumber = new wxTextCtrl(this, wxID_ANY);
    AddFormField(formGrid, "Address:", getHouseNumber);

    getCity = new wxTextCtrl(this, wxID_ANY);
    AddFormField(formGrid, "City:", getCity);

    getProvince = new wxTextCtrl(this, wxID_ANY);
    AddFormField(formGrid, "State/Province:", getProvince);

    getCountry = new wxTextCtrl(this, wxID_ANY);
    AddFormField(formGrid, "Country:", getCountry);

    // Password fields
    getPassword = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
    AddFormField(formGrid, "Password*:", getPassword);

    getConfirmPassword = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
    AddFormField(formGrid, "Confirm Password*:", getConfirmPassword);

    // Password requirements hint
    wxStaticText* pwHint = new wxStaticText(this, wxID_ANY,
        "Password must contain at least 8 characters, including uppercase, lowercase, and numbers");
    pwHint->SetFont(wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL));
    pwHint->SetForegroundColour(wxColour(100, 100, 100));
    formGrid->Add(new wxStaticText(this, wxID_ANY, ""), 0); // Empty label
    formGrid->Add(pwHint, 0, wxTOP, -5);

    formContainer->Add(formGrid, 0, wxALL | wxEXPAND, 15);

    // Terms and conditions checkbox
    wxCheckBox* termsCheck = new wxCheckBox(this, wxID_ANY, "I agree to the Terms and Conditions");
    formContainer->Add(termsCheck, 0, wxLEFT | wxBOTTOM, 15);

    // Enhanced signup button with styling
    wxButton* signupButton = new wxButton(this, ID_SignupSubmitButton, "Create Account");
    signupButton->SetBackgroundColour(wxColour(70, 130, 200));
    signupButton->SetForegroundColour(*wxWHITE);
    signupButton->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    formContainer->Add(signupButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 15);

   
    // Add form container to outer sizer
    outerSizer->Add(formContainer, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 20);
    outerSizer->AddStretchSpacer(1); // Push content up

    SetSizer(outerSizer);

    // setting up user here
    
    
    





}

// Helper function to add form fields consistently
void SignupPanel::AddFormField(wxSizer* sizer, const wxString& label, wxWindow* control)
{
    wxStaticText* labelCtrl = new wxStaticText(this, wxID_ANY, label);
    labelCtrl->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    sizer->Add(labelCtrl, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
    sizer->Add(control, 1, wxEXPAND);
}

void SignupPanel::OnSignup() {
    if (getUserName->GetValue().IsEmpty() ||
        getFirstName->GetValue().IsEmpty() ||
        getLastName->GetValue().IsEmpty() ||
        getEmail->GetValue().IsEmpty() ||
        getPassword->GetValue().IsEmpty())
    {
        wxMessageBox("Please fill in all required fields", "Error", wxOK | wxICON_ERROR);
        return ;
    }

    if (getPassword->GetValue() != getConfirmPassword->GetValue())
    {
        wxMessageBox("Passwords do not match", "Error", wxOK | wxICON_ERROR);
        return ;
    }

    // Here you would typically send the data to your backend
    wxMessageBox("Account created successfully!", "Success", wxOK | wxICON_INFORMATION);

    // Clear the form
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

bool SignupPanel::ValidateSignup(){
    if (getUserName->GetValue().IsEmpty() ||
        getFirstName->GetValue().IsEmpty() ||
        getLastName->GetValue().IsEmpty() ||
        getEmail->GetValue().IsEmpty() ||
        getPassword->GetValue().IsEmpty()) {
        return false;
    }
    return true;
}

Person* SignupPanel::getPerson()
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


    Person* persons = new Person(Login(tempUserName, tempPassword),
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
