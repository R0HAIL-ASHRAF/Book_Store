#ifndef SIGNUPPANEL_H  
#define SIGNUPPANEL_H  

#include <wx/wx.h>  

class SignupPanel : public wxPanel  
{  
public:  
    SignupPanel(wxWindow* parent);  
    void OnSignup();
    bool ValidateSignup();
private:  

    // Declare form fields  
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

    
};  

#endif

