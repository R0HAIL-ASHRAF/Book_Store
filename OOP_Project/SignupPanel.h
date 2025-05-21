#ifndef SIGNUPPANEL_H  
#define SIGNUPPANEL_H  

#include"MyVector.h"
#include "Classic.h" 
#include <wx/wx.h>  
#include "loginPanel.h"

class SignupPanel : public wxPanel  
{  
public:  
    SignupPanel(wxWindow* parent);
    void AddFormField(wxSizer* sizer, const wxString& label, wxWindow* control);
    void OnSignup();
    bool ValidateSignup();
    Classic* getPerson() const;
    void clearTextCtrls()const;
    void IntoFile();
private:    
    wxTextCtrl* getUserName;  
    wxTextCtrl* getFirstName;  
    wxTextCtrl* getLastName;  
    wxTextCtrl* getEmail;  
    wxTextCtrl* getDay;  
    wxTextCtrl* getMonth;  
    wxTextCtrl* getYear;  
    wxTextCtrl* getHouseNumber;  
    wxTextCtrl* getCity;  
    wxTextCtrl* getProvince;  
    wxTextCtrl* getCountry;  
    wxTextCtrl* getPassword;  
    wxTextCtrl* getConfirmPassword;  
    
private://functions

};  

#endif

