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
    
    store = new Store();
    wxArrayString list;
    MyVector<Customer*> customerList = store->GetCustomers();
    for (int i = 0; i < customerList.size(); i++) {
        list.Add(customerList.at(i)->getUserName());
    }
    wxListBox* listBox = new wxListBox(this, wxID_ANY, wxPoint(300, 300), wxSize(200, 200), list);

    // Welcome label
    m_welcomeLabel = new wxStaticText(this, wxID_ANY, "Welcome to the Dashboard!");
    m_welcomeLabel->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    mainSizer->Add(m_welcomeLabel, 0, wxALIGN_CENTER | wxTOP, 30);

    // Add some content
    mainSizer->AddSpacer(20);
    mainSizer->Add(new wxStaticText(this, wxID_ANY, "This is your main application interface."),
        0, wxALIGN_CENTER);

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

