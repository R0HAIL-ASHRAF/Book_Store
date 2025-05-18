#pragma once
#include <wx/wx.h>
#include "Person.h" // Assuming you have this class

class LoginPanel : public wxPanel {
public:
    LoginPanel(wxWindow* parent);
    LoginPanel(wxWindow* parent, wxWindowID id);
    bool ValidateLogin() const;
    wxString GetUsername() const { return m_usernameField->GetValue(); }

private:
    void SetupUI();
    void addPerson(Person*& person);

    wxTextCtrl* m_usernameField;
    wxTextCtrl* m_passwordField;
    wxVector<Person*> persons; // Using wxVector instead of std::vector for wxWidgets compatibility

    // Event handlers
    void OnLogin(wxCommandEvent& event);
    void OnSignup(wxCommandEvent& event);

};