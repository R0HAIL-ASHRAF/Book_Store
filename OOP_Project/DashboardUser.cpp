#include "DashboardUser.h"
#include "MainFrame.h"  

wxBEGIN_EVENT_TABLE(DashboardUser, wxPanel)
EVT_BUTTON(wxID_ANY, DashboardUser::OnLogout)
wxEND_EVENT_TABLE()

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
    mainSizer->Add(new wxStaticText(this, wxID_ANY, "This is your main application interface."),
        0, wxALIGN_CENTER);

    // Add logout button at bottom
    mainSizer->AddStretchSpacer();
    m_logoutButton = new wxButton(this, wxID_ANY, "Logout");
    mainSizer->Add(m_logoutButton, 0, wxALIGN_RIGHT | wxRIGHT | wxBOTTOM, 10);

    SetSizer(mainSizer);
}

void DashboardUser::SetWelcomeMessage(const wxString& username)
{
    m_welcomeLabel->SetLabel(wxString::Format("Welcome, %s!", username));
    Layout();
}

void DashboardUser::OnLogout(wxCommandEvent& event)
{
    // Get the parent frame and call its logout method
    MainFrame* frame = dynamic_cast<MainFrame*>(GetParent());
    if (frame)
    {
       //frame->SwitchToLoginPage();  // You would add this method to MainFrame
    }
}