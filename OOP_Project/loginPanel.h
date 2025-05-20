#pragma once

#include <wx/wx.h>
#include"MyVector.h"
#include "Person.h" 
#include<fstream>

class loginPanel : public wxPanel 
{
private:
    wxTextCtrl* m_usernameField;
    wxTextCtrl* m_passwordField;
    MyVector<Person*> persons;

    void SetupUI();

public:
    loginPanel(wxWindow* parent);
    bool ValidateLogin() const;
    void addPerson(Person*& person);
    void clearTextCtrl();
    void FromFile();

    
};