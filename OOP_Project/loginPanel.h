#pragma once

#include <wx/wx.h>
#include"MyVector.h"
#include<fstream>
#include "Classic.h"
#include"Login.h"




class loginPanel : public wxPanel 
{
private:
    Customer* m_activeCustomer;
    static loginPanel* instance;
    wxTextCtrl* m_usernameField;
    wxTextCtrl* m_passwordField;
    MyVector<Classic*>* customers;

    void SetupUI();
    loginPanel(wxWindow* parent);
    
public:
    static loginPanel* GetInstance(wxWindow* parent);
    bool ValidateLoginForCustomers() const;
    void AddCustomer(Classic *& person);
    void clearTextCtrl();
    void FromFile();
	MyVector<Classic*>* GetCustomers() const;
    Customer* GetActiveCustomer();
    MyString GetUsername() const;
	MyString GetPassword() const;


    ~loginPanel();
};