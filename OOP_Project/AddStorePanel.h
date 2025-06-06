#pragma once

#include <wx/wx.h>
#include "MyString.h"
#include "Address.h"
#include <wx/statline.h>
#include"IDs.h"
#include"Store.h"



class AddStorePanel : public wxPanel
{
public:
    AddStorePanel(wxWindow* parent);

    MyString GetStoreId() const;
    MyString GetStoreName() const;
    Address GetStoreAddress() const;
    void SetupUI();
    Store SetStore();

private:
    wxTextCtrl* firstNameCtrl;
    wxTextCtrl* lastNameCtrl;
    wxTextCtrl* emailCtrl;
    wxTextCtrl* dayCtrl;
    wxTextCtrl* monthCtrl;
    wxTextCtrl* yearCtrl;
    wxTextCtrl* personHouseNumberCtrl;
    wxTextCtrl* personProvinceCtrl;
    wxTextCtrl* personCityCtrl;
    wxTextCtrl* personCountryCtrl;
    wxTextCtrl* usernameCtrl;
    wxTextCtrl* passwordCtrl;

    wxTextCtrl* storeIdCtrl;
    wxTextCtrl* storeNameCtrl;
    wxTextCtrl* houseNumberCtrl;
    wxTextCtrl* provinceCtrl;
    wxTextCtrl* cityCtrl;
    wxTextCtrl* countryCtrl;

    void OnSubmit(wxCommandEvent& event);
};

