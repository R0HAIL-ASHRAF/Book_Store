#pragma once

#include <wx/wx.h>
#include"MyVector.h"
#include<fstream>
#include "Classic.h"




class loginPanel : public wxPanel 
{
private:
    static loginPanel* instance;
    wxTextCtrl* m_usernameField;
    wxTextCtrl* m_passwordField;
    MyVector<Classic*>* customers;

    void SetupUI();
    loginPanel(wxWindow* parent);
    
public:
    static loginPanel* GetInstance(wxWindow* parent);
    bool ValidateLogin() const;
    void AddCustomer(Classic *& person);
    void clearTextCtrl();
    void FromFile();
	MyVector<Classic*>* GetCustomers() const;
   


    ~loginPanel();
};