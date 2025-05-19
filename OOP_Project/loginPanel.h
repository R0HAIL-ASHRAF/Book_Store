#pragma once
#include <wx/wx.h>
#include"MyVector.h"
#include "Person.h" 
#include<fstream>

class loginPanel : public wxPanel {
public:
    loginPanel(wxWindow* parent);
    bool ValidateLogin() const;
    wxString GetUsername() const { return m_usernameField->GetValue(); }
    void addPerson(Person*& person);
    void clearTextCtrl();
    void FromFile();


private:
    void SetupUI();

   
    
    
    wxTextCtrl* m_usernameField;
    wxTextCtrl* m_passwordField;
    MyVector<Person*> persons; 

    
};