#ifndef DASHBOARDPANEL_H
#define DASHBOARDPANEL_H

#include <wx/wx.h>

class DashboardUser : public wxPanel
{
public:
    DashboardUser(wxWindow* parent);

    void SetWelcomeMessage(const wxString& username);

private:
    wxStaticText* m_welcomeLabel;
    wxButton* m_logoutButton;

    void OnLogout(wxCommandEvent& event);
    void SetupUI();

    wxDECLARE_EVENT_TABLE();
};

#endif // DASHBOARDPANEL_H
