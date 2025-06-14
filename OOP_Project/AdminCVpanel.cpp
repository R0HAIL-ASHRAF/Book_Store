#include "AdminCVpanel.h"

AdminCVpanel::AdminCVpanel(wxWindow* parent)
	: wxPanel(parent, wxID_ANY)
{
	SetupUI(parent);
}
void AdminCVpanel::SetupUI(wxWindow* parent)
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

   
    m_welcomeLabel = new wxStaticText(this, wxID_ANY, "CUSTOMERS LIST!");
    m_welcomeLabel->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    mainSizer->Add(m_welcomeLabel, 0, wxALIGN_CENTER | wxTOP, 30);

    mainSizer->AddSpacer(20);
    mainSizer->Add(new wxStaticText(this, wxID_ANY, "Customer List:"),
        0, wxALIGN_LEFT | wxLEFT, 15);


    Admin* admin = Admin::GetInstance(parent);
    MyVector<Customer*> customers = admin->GetCustomers();
    m_customerListView = new CustomerListView(this, customers);
    wxLogMessage("Customer count in admin: %d", customers.size());
    mainSizer->Add(m_customerListView, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 15);

    mainSizer->AddStretchSpacer();
    m_logoutButton = new wxButton(this, ID_LogoutButton, "Logout");
    mainSizer->Add(m_logoutButton, 0, wxALIGN_RIGHT | wxRIGHT | wxBOTTOM, 10);

    SetSizer(mainSizer);
}
