#include "DashboardUser.h"
#include "MainFrame.h"  
#include"IDs.h"


DashboardUser::DashboardUser(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    SetupUI();
}

void DashboardUser::SetupUI()
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    // Welcome label
    m_welcomeLabel = new wxStaticText(this, wxID_ANY, "Welcome to the Dashboard!");
    m_welcomeLabel->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    mainSizer->Add(m_welcomeLabel, 0, wxALIGN_CENTER | wxTOP, 30);

    // Add some content
    mainSizer->AddSpacer(20);
    mainSizer->Add(new wxStaticText(this, wxID_ANY, "Customer List:"),
        0, wxALIGN_LEFT | wxLEFT, 15);

 //   // Add the CustomerListView (using your MyVector<Classic*>* customers)
	//MyVector<Customer*> customers = Admin::GetInstance()->GetCustomers();
 //   m_customerListView = new CustomerListView(this,customers);
 //   mainSizer->Add(m_customerListView, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 15);

    // Add logout button at bottom
    mainSizer->AddStretchSpacer();
    m_logoutButton = new wxButton(this, ID_LogoutButton, "Logout");
    mainSizer->Add(m_logoutButton, 0, wxALIGN_RIGHT | wxRIGHT | wxBOTTOM, 10);

    SetSizer(mainSizer);
}

void DashboardUser::SetWelcomeMessage(const wxString& username)
{
    m_welcomeLabel->SetLabel(wxString::Format("Welcome, %s!", username));
    Layout();
}

